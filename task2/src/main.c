#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREADS_COUNT 5
#define INCREMENT_COUNT 10000
#define print_error(msg) do {perror(msg); \
  exit(EXIT_FAILURE);} while(0)
#define run() do { if (MUTEXES) {test_increment_mutex();} \
  else {test_increment();}} while(0)

int counter = 0;

pthread_mutex_t counter_mutex;

void* increment_counter(void* arg);

void* increment_counter_mutex(void* arg);

void test_increment();

void test_increment_mutex();

int main(void) {
  run();   
  exit(EXIT_SUCCESS);
}

/**
 * increment_counter - handler for thread used to increment
 * global counter without mutexes
 * @arg - pointer to argument, should be NULL
 */
void* increment_counter(void* arg) {
  for (int i = 0; i < INCREMENT_COUNT; i++)
    counter++;
  return NULL;
}

/**
 * increment_counter_mutex - handler for thread used to increment
 * global counter with mutexes
 * @arg - pointer to argument, should be NULL
 */
void* increment_counter_mutex(void* arg) {
  for (int i = 0; i < INCREMENT_COUNT; i++) {
    /* Enter critical section */
    if (pthread_mutex_lock(&counter_mutex) != 0)
      print_error("pthread_mutex_lock");

    counter++;
    
    /* Leave critical section */
    if (pthread_mutex_unlock(&counter_mutex) != 0)
      print_error("pthread_mutex_unlock");
  }
  
  return NULL;
}

/**
 * test_increment - used in macro definition to 
 * start program without mutexes
 */
void test_increment() {
  pthread_t threads[THREADS_COUNT];
  
  /* Create and start threads */
  for (int i = 0; i < THREADS_COUNT; i++) {
    if (pthread_create(&threads[i], NULL, increment_counter, NULL) != 0)
      print_error("pthread_create");
  }

  /* Join threads */
  for (int i = 0; i < THREADS_COUNT; i++) {
    if (pthread_join(threads[i], NULL) != 0)
      print_error("pthread_join");
  }

  printf("Result of incrementation without mutexes: %d \n", counter);
}

/**
 * test_increment_mutex - used in macro definition to 
 * start program with mutexes
 */
void test_increment_mutex() {
  pthread_t threads[THREADS_COUNT];
  
  /* Init global mutex */
  if (pthread_mutex_init(&counter_mutex, NULL) != 0)
    print_error("pthread_mutex_init");
  
  /* Create and start threads */
  for (int i = 0; i < THREADS_COUNT; i++) {
    if (pthread_create(&threads[i], NULL, increment_counter_mutex, NULL) != 0)
      print_error("pthread_create");
  }
  
  /* Join threads */
  for (int i = 0; i < THREADS_COUNT; i++) {
    if (pthread_join(threads[i], NULL) != 0)
      print_error("pthread_join");
  }

  printf("Result of incrementation with mutexes: %d \n", counter);
}

