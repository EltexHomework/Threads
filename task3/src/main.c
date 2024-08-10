#include "../headers/customer.h"
#include "../headers/shop.h"
#include "../headers/loader.h"
#include "../headers/common.h"

int main(void) {
  /* Allocate memory */
  struct shop** shops = (struct shop**) malloc(sizeof(struct shop*) * SHOPS_AMOUT);
  struct customer** customers = (struct customer**) malloc(sizeof(struct customer*) * CUSTOMERS_AMOUNT);
  struct loader* loader;
  char* names[] = { "1", "2", "3", "4", "5" };
  
  /* Make random */
  srand(time(NULL));
  
  /* Initialize shops */
  for (int i = 0; i < SHOPS_AMOUT; i++) {
    int goods = generate_rand_ranged(0, MAX_SHOP_CAPACITY);
    shops[i] = create_shop(goods, names[i]);
  }
  
  /* Initialize customers */
  for (int i = 0; i < CUSTOMERS_AMOUNT; i++) {
    customers[i] = create_customer(shops, names[i], SHOPS_AMOUT, MAX_DEMAND, SLEEP_TIME);
  }
  
  /* Create loader and run it*/
  loader = create_loader(shops, SHOPS_AMOUT, LOAD_AMOUNT, LOAD_PERIOD);
  run_loader(loader);
  
  /* Run customers */
  for (int i = 0; i < CUSTOMERS_AMOUNT; i++) {
    run_customer(customers[i]);
  }
  
  /* Free customers and join theirs threads */
  for (int i = 0; i < CUSTOMERS_AMOUNT; i++) {
    free_customer(customers[i]);
  }
  free(customers);
  
  /* Stop loading */
  loader->is_loading = 0;
  free(loader);
  
  /* Free shops */
  for (int i = 0; i < SHOPS_AMOUT; i++) {
    free_shop(shops[i]);
  }
  free(shops);
     
  exit(EXIT_SUCCESS);
}
