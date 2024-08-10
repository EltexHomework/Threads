#include "../headers/shop.h"

/**
 * create_shop - used to create an object of shop struct
 * @goods - amount of goods in shop 
 * @name - name of shop 
 *
 * Return: pointer to an object of shop struct 
 */
struct shop* create_shop(int goods, char* name) {
  struct shop* shop = (struct shop*) malloc(sizeof(struct shop));
  
  /* Initialize goods */
  if (goods <= 0)
    print_error("goods are negative or zero");
  shop->goods = goods;
  
  /* Initialize name */
  if (name == NULL)
    print_error("name is null");
  if (strlen(name) == 0)
    print_error("name is empty");
  shop->name = name;
  
  /* Initialize mutex */
  if (pthread_mutex_init(&shop->mutex, NULL) != 0)
    print_error("pthread_mutex_init");

  return shop;
}

/**
 * fill_goods - used to add goods to shop->goods
 * @shop - pointer to an object of shop struct 
 * @amount - amount of goods to fill 
 */
void fill_goods(struct shop* shop, int amount) {
  shop->goods += amount;
}

/**
 * sell_goods - used to sell goods of shop
 * @shop - pointer to an object of shop struct
 * @amount - amount of goods to be sold
 *
 * Return: amount of goods sold  
 */
int sell_goods(struct shop* shop, int amount) {
  /* Requestem more goods than exists */
  if (amount > shop->goods)
    print_error("requested more goods than exists");
  
  shop->goods -= amount;
  return amount;
}

/**
 * free_shop - used to free memory allocated
 * for an object of shop struct
 * @shop - pointer to an object of shop struct
 */
void free_shop(struct shop* shop) {
  pthread_mutex_destroy(&shop->mutex);   
  free(shop);
}

