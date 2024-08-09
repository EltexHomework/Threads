#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREADS_COUNT 5
#define print_error(msg) do {perror(msg); \
  exit(EXIT_FAILURE);} while(0) 

void* print_index(void* arg);

int main() {
  int indexes[THREADS_COUNT]; 
  pthread_t threads[THREADS_COUNT];
  
  /* Fill indexes and create threads */
  for (int i = 0; i < THREADS_COUNT; i++) {
    indexes[i] = i + 1;
    if (pthread_create(&threads[i], NULL, print_index, (void* ) &indexes[i]) != 0) 
      print_error("pthread_create");
  }
  
  /* Join threads */
  for (int i = 0; i < THREADS_COUNT; i++) {
    if (pthread_join(threads[i], NULL) != 0)
      print_error("pthread_join");
  }

  exit(EXIT_SUCCESS);
}

/**
 * print_index - used as handler for threads
 * to display their index passed by arg.
 * @arg - pointer that is casted to int*
 */
void* print_index(void* arg) {
  int* index = (int *) arg;
  
  printf("Thread with index %d started\n", *index);

  return NULL;
}
