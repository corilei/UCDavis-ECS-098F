  {.expression="28+1", .result=29},
  {.expression="38+1", .result=39},

  {.expression="17+1", .result=18},
  {.expression="16+1", .result=17},
  {.expression="15+1", .result=16},
  {.expression="14+1", .result=15},
  {.expression="13+1", .result=14},
  {.expression="12+1", .result=13},
  {.expression="11+1", .result=12},
  {.expression="10+1", .result=11},
  // -
  {.expression="1-2", .result=-1},
  // *
  {.expression="0*1", .result=0},
  {.expression="99*100", .result=9900},
  // /
  {.expression="3/2", .result=1},
  {.expression="9/3", .result=3},
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
                                                                                                                           82,1          Bot