#include "../headers/loader.h"
#include <pthread.h>

/**
 * create_loader - used to create an object of 
 * loader struct
 * @shops - pointer to an array of shops structs  
 * @shops_amount - amount of shops in shops array
 * @load_amount - amount of goods to load
 * @load_period - breaktime between loads 
 *
 * Return: pointer to an object of loader struct
 */
struct loader* create_loader(struct shop** shops, int shops_amount, int load_amount, int load_period) {
  struct loader* loader = (struct loader*) malloc(sizeof(struct loader));
  
  /* Initialize load amount */
  if (load_amount <= 0)
    print_error("load_amount negative or zero");
  loader->load_amount = load_amount;
  
  /* Initialize load period */
  if (load_period <= 0)
    print_error("load_period negative or zero");
  loader->load_period = load_period;
  
  /* Initialize shops amount */
  if (shops_amount <= 0)
    print_error("shops_amount negative or zero");
  loader->shops_amount = shops_amount;

  /* Initialize shops */
  if (shops == NULL)
    print_error("shops is null");
  loader->shops = shops;
  
  /* Initialize loading status */
  loader->is_loading = 1;

  return loader;
}

/**
 * run_loader - used to start loading thread
 * @loader - pointer to an object of loader struct
 */
void run_loader(struct loader* loader) {
  printf("Loader started\n");
  if (pthread_create(&loader->thread, NULL, handle_loads, (void*) loader) != 0)
    print_error("pthread_create");
}

/**
 * load_goods - used to load goods by loader to shop. Tries
 * to lock mutex.
 * @loader - pointer to an object of loader struct
 * @shop - pointer to an object of shop struct
 *
 * Return: 0 if successful, -1 if mutex is locked  
 */
int load_goods(struct loader* loader, struct shop* shop) {
  /* Try to lock shop mutex */
  if (pthread_mutex_trylock(&shop->mutex) != 0)
    return -1;
  
  /* Fill goods */
  fill_goods(shop, loader->load_amount);
  printf("Loader loaded %s shop. Goods: %d\n", shop->name, shop->goods);
  
  /* Unlock shop mutex */
  if (pthread_mutex_unlock(&shop->mutex) != 0)
    print_error("pthread_mutex_unlock");
  
  /* Breaktime between loads */
  sleep(loader->load_period);
  return 0;
}

/**
 * handle_loads - handle for thread that loads
 * shops
 * @arg - pointer to loader struct, casted inside
 */
void* handle_loads(void* arg) {
  struct loader* loader = (struct loader*) arg;
  
  /* Load while is loading isn't changed to 0 */
  while (loader->is_loading) {
    int i = generate_rand_ranged(0, loader->shops_amount);
    load_goods(loader, loader->shops[i]); 
  }

  return NULL;
}

/**
 * free_loader - used to free allocated memory
 * for object of loader struct
 * @loader - pointer to an object of loader struct
 */
void free_loader(struct loader* loader) {
  pthread_join(loader->thread, NULL);
  free(loader);
}

