/*
 * fibonacci.c
 *
 * Find the numbers of fibonacci's sequence.
 * This is limited by the capacity of a c int.
 *
 * author: Ryan Morehouse
 * license: MIT
 */

#include <stdio.h>
#include <stdlib.h>
#define MIN 1
#define MAX 46

void error_msg()
{
  printf("Usage: fibonacci.o [n]\n");
  printf("[n] is a positive integer less than 47\n");
}

int main(int argc, char* argv[])
{
  // check for arg
  if(argc < 2)
  {
    error_msg();
    return 1;
  }

  // verify arg is within limits
  int n = atoi(argv[1]);
  if(n < MIN || n > MAX)
  {
    error_msg();
    return 1;
  }

  // simply print simple cases
  if(n == 1)
    printf("[ 1 ]\n");
  else if(n == 2)
    printf("[ 1, 1 ]\n");
  else
  {
    long int fib[n];
    fib[0] = 1;
    fib[1] = 1;

    // calculate sequence
    for(int i = 2; i < n; i++)
      fib[i] = fib[i-1] + fib[i-2];

    // print sequence
    printf("[ ");
    for(int i=0; i < n-1; i++)
      printf("%d, ", fib[i]);
    printf("%d ]\n", fib[n-1]);
  }

  return 0;
}

