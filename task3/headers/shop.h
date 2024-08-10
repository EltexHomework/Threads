#ifndef SHOP_H
#define SHOP_H

#include "common.h"
#include <pthread.h>
#include <stdlib.h>

/*
 * shop that has goods. Receives goods and sells them.
 * Mutex should be locked and unlock in when using fill_goods
 * and sell_goods.
 */
struct shop {
  /* Shop mutex */
  pthread_mutex_t mutex; 
  /* Shop name */
  char* name;
  /* Goods available */
  int goods;
};

struct shop* create_shop(int goods, char* name);

void fill_goods(struct shop* shop, int amount);

int sell_goods(struct shop* shop, int amount);

void free_shop(struct shop* shop);

#endif // !SHOP_H
