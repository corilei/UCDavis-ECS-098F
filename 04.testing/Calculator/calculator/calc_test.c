/*
 * Program to test the calculator program
 */
#include <stdio.h>
#include <stdbool.h>

#include "calc.h"

#define NUM_TESTS 18

struct pair{
    char *expression;
    int result;
};

struct pair input_output_pairs[NUM_TESTS] = {
        // +
        {.expression="99+99", .result=198},
        {.expression="28+1", .result=29},
        {.expression="38+1", .result=39},

        {.expression="9+1", .result=10},
        {.expression="16+99", .result=115},
        {.expression="19+1", .result=20},

        {.expression="11+1", .result=12},
        {.expression="10+1", .result=11},
        // -
        {.expression="1-2", .result=-1},
        {.expression="99-1", .result=98},
        // *
        {.expression="999*1", .result=999},
        {.expression="99*100", .result=9900},
        // /
        {.expression="99/9", .result=11},
        {.expression="91/7", .result=13},
        // ()
        {.expression="(0-3)/2", .result=-1},
        {.expression="3/(2-4)", .result=-1},
        // combine
        {.expression="3/(2-4)+2", .result=1},
        {.expression="3+1*2", .result=5}
};

// Given the index of an input-output pair, run the test on the username
// validator. Returns true if the tests passes, false otherwise.
bool run_test(int test_num) {
  char *input = input_output_pairs[test_num].expression;
  int real_output = calc(input);
  int expected_output = input_output_pairs[test_num].result;
  if(real_output != expected_output) {
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
