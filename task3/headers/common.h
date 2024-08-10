#ifndef COMMON_H
#define COMMON_H

#define SLEEP_TIME 2
#define LOAD_PERIOD 1
#define MAX_DEMAND 100000
#define MAX_SHOP_CAPACITY 10000
#define SHOPS_AMOUT 5
#define CUSTOMERS_AMOUNT 3
#define LOAD_AMOUNT 5000
#define print_error(msg) do {perror(msg); \
  exit(EXIT_FAILURE);} while(0)

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int generate_rand_ranged(int start, int end);

#endif // !COMMON_H
