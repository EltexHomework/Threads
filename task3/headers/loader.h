#ifndef LOADER_H
#define LOADER_H

#include "common.h"
#include "shop.h"
#include <pthread.h>

/*
 * Loads goods in shops with load_period in seconds.
 * To stop loading is_loading should be 0. Runs in thread
 * with handle_loads handler. Should be freed after stopped
 * loading.
 */
struct loader {
  /* Loading thread */
  pthread_t thread;
  /* Array of shops */
  struct shop** shops;
  /* Amount of shops in array */
  int shops_amount;
  /* Amount of goods loaded per time */
  int load_amount;
  /* Time in seconds between loads */
  int load_period;
  /* Status of loading */
  int is_loading;
};

struct loader* create_loader(struct shop** shops, int shops_amount, int load_amount, int load_period);

int load_goods(struct loader* loader, struct shop* shop);

void run_loader(struct loader* loader);

void* handle_loads(void* arg);

void free_loader(struct loader* loader);

#endif // !LOADER_H
