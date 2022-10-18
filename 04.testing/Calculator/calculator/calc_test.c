/*
 * Program to test the calculator program 
 */
#include <stdio.h>
#include <stdbool.h>

#include "calc.h"

#define NUM_TESTS 1

struct pair{
  char *expression;
  int result;
};

struct pair input_output_pairs[NUM_TESTS] = {
  // correct calculation
  {.expression="1+1", .result=1}
  // incorrect calculation
};

// Given the index of an input-output pair, run the test on the username
// validator. Returns true if the tests passes, false otherwise.
bool run_test(int test_num) {
  char *input = input_output_pairs[test_num].expression;
  int real_output = calc(input);
  int expected_output = input_output_pairs[test_num].result;
    if(real_output != expected_output) {
      printf("Test %i failed! Expected %s to %sbe a valid username\n", test_num + 1,
            input, expected_output ? "" : "not ");
      printf("Test %i failed! Expected %s = %i , not %i\n", test_num + 1,
            input, expected_output, real_output);
      return false;
  }
  return true;

}

int main(int argc, char **argv) {
  int num_passed = 0;
  for(int i = 0; i < NUM_TESTS; i++) {
    if(run_test(i))
      num_passed++;
  }
  printf("%i out of %i tests passed.\n", num_passed, NUM_TESTS);
}
