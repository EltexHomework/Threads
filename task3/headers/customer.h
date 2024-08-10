#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "common.h"
#include "shop.h"
#include <pthread.h>

/*
 * Used to describe customer. Buys goods in thread
 * with sleep_time period. Opens thread when run_customer
 * is called. Should be freed when deman is fulfilled. 
 */
struct customer {
  /* Thread where handle_shopping runs */
  pthread_t thread;
  /* Array of shops objects */
  struct shop** shops;
  /* Name of customer */
  char* name;
  /* Amount of shop object in shops */  
  int shops_amount;
  /* Amount of goods to buy */
  int demand;
  /* Breaktime in seconds between shopping */
  int sleep_time;
};

struct customer* create_customer(struct shop** shops, char* name, int shops_amount, int demand, int sleep_time);

void run_customer(struct customer* customer);

void* handle_shopping(void* arg);

int buy_goods(struct customer* customer, struct shop* shop);

void free_customer(struct customer* customer);

#endif // !CUSTOMER_H
