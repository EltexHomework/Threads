#include "../headers/common.h"

/**
 * generate_rand_ranged - used to generate random
 * int number in specific range excluding end.
 * @start - start of range
 * @end - end of range
 *
 * Return: random generate number 
 */
int generate_rand_ranged(int start, int end) {
  return rand() % (end - start) + start;
}
