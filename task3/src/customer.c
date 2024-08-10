#include "../headers/customer.h"
#include <pthread.h>

/**
 * create_customer - used to create an object of
 * customer struct.
 * @shops - pointer to an array of shops
 * @name - name of customer
 * @shops_amount - number of shops
 * @demand - amount of goods to buy
 * @sleep_time - breaktime between shopping
 *
 * Return: pointer to an object of customer struct  
 */
struct customer* create_customer(struct shop** shops, char* name, int shops_amount, 
                                 int demand, int sleep_time) {
  struct customer* customer = (struct customer*) malloc(sizeof(struct customer));
  
  /* Initialize demand */
  if (demand <= 0)
    print_error("demand negative or zero");
  customer->demand = demand;
  
  /* Initialize sleep time */
  if (sleep_time <= 0)
    print_error("sleep_time negative or zero");
  customer->sleep_time = sleep_time;
  
  /* Initialize shops amount */
  if (shops_amount <= 0)
    print_error("shops_amount negative or zero");
  customer->shops_amount = shops_amount;

  /* Initialize shops */
  if (shops == NULL)
    print_error("shops is null");
  customer->shops = shops;
  
  /* Initialize name */
  if (name == NULL)
    print_error("name is null");
  if (strlen(name) == 0)
    print_error("name is empty");
  customer->name = name;

  return customer;
}

/**
 * run_customer - used to start shopping thread
 * @customer - pointer to an object of customer struct
 */
void run_customer(struct customer* customer) {
  printf("Customer %s started\n", customer->name);

  /* Start shopping thread */
  if (pthread_create(&customer->thread, NULL, handle_shopping, (void *) customer) != 0)
    print_error("pthread_create");
}

/**
 * handle_shopping - handler to pass in thread that
 * is used for buying goods for customer
 * @arg - pointer to customer struct, casted inside
 */
void* handle_shopping(void* arg) {
  struct customer* customer = (struct customer*) arg;
  
  /* Buy goods while demand is not fulfilled */
  while (customer->demand != 0) {
    int i = generate_rand_ranged(0, customer->shops_amount);
    buy_goods(customer, customer->shops[i]);
  }
  
  printf("Customer %s fulfilled demand\n", customer->name);
  return NULL;
}

/**
 * buy_goods - used to buy goods from shop to customer
 * @customer - pointer to an objeect of customer struct
 * @shop - pointer to an object of shop struct
 *
 * Return: 0 if successful, -1 is mutex locked 
 */
int buy_goods(struct customer* customer, struct shop* shop) {
  /* Try to lock shop mutex */
  if (pthread_mutex_trylock(&shop->mutex) != 0)
    return -1;
  
  /* Amount of goods to buy */
  int amount = (customer->demand < shop->goods) ? customer->demand : shop->goods;
  /* Amount of bought goods */
  int bought = sell_goods(shop, amount);
   
  customer->demand -= bought;
  printf("Customer %s bought %d goods from %s shop. Demand: %d\n", customer->name, amount, shop->name, customer->demand);
  
  /* Unlock mutex */
  if (pthread_mutex_unlock(&shop->mutex) != 0)
    print_error("pthread_mutex_unlock"); 
  
  /* Breaktime between shopping */
  sleep(customer->sleep_time);
  return 0;
}

/**
 * free_customer - used to free memory allocated for customer
 * @customer - pointer to an object of customer struct
 */
void free_customer(struct customer* customer) {
  pthread_join(customer->thread, NULL);
  free(customer);
}

