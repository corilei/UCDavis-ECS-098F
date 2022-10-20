/*
 * Unit tests for the pig latin translator using the CUnit framework.
 * Command Line:
 * $ gcc --coverage -g -O0 translator_unittests.c translator_tools.c -lcunit -o translator_unittests
 * $ ./translator_unittests
 * $ gcovr --html -o report.html
 */
#include <CUnit/Basic.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "translator_tools.h"

//bool isWordsEqual(char **arr1, char **arr2)
//{
////  int arr1Count = sizeof(arr1) / sizeof(arr1[0]);
////  int arr2Count = sizeof(arr2) / sizeof(arr2[0]);
////  int arr1Count = strlen(arr1);
////  int arr2Count = strlen(arr2);
//  int arr1Count = 0;
//  while(arr1[arr1Count] != NULL)
//  {
//    arr1Count ++;
//  }
//  int arr2Count = 0;
//  while(arr2[arr1Count] != NULL)
//  {
//    arr2Count ++;
//  }
//
//  printf("%d %d", arr1Count, arr2Count);
//
//  if (arr1Count != arr2Count)
//  {
//    return false;
//  }
//  int i;
//  for(i = 0; i < arr1Count; i++)
//  {
//    if (strcmp(arr1[i], arr2[i]) != 0)
//    {
//      return false;
//    }
//    i++;
//  }
//  return true;
//}

void TestSplitSentenceIntoWords()
{
  const char *input = "the fox jumps";
  char *except_output[] = {"the", "fox", "jumps", NULL};

  char **real_output = malloc(sizeof(char*) * strlen(input));
  real_output = SplitSentenceIntoWords(input);

  printf("asdf: %s\n", real_output[3]);
  printf("asdf: %s\n", except_output[3]);
//  if (strcmp(real_output[3], except_output[3]) != 0){
//    printf("asdfasdfasdfa");
//  }
//  printf("%d", strcmp(real_output[3], except_output[3]) != 0);

//	CU_ASSERT(isWordsEqual(except_output, real_output));
}

void TestWordHasOnlyLetters()
{
	// Positive examples
  CU_ASSERT(WordHasOnlyLetters("the"));
  CU_ASSERT(WordHasOnlyLetters("fox"));
  CU_ASSERT(WordHasOnlyLetters("jumps"));
  // Negative examples
  CU_ASSERT(!WordHasOnlyLetters("jumps "));
  CU_ASSERT(!WordHasOnlyLetters("$jumps"));
}

void TestToLowerCase()
{
  // Positive examples
  char *word2convert = "sIlLy";
//  char *word2convert_copy = word2convert;
//  ToLowerCase(word2convert);
//  printf("%s", word2convert);
//  CU_ASSERT((strcmp("silly", "silly") == 0));
//  CU_ASSERT((strcmp("the", "the") == 0));
//  CU_ASSERT(WordHasOnlyLetters("fox"));
//  CU_ASSERT(WordHasOnlyLetters("jumps"));s
//  // Negative examples
//  CU_ASSERT(!WordHasOnlyLetters("jumps "));
//  CU_ASSERT(!WordHasOnlyLetters("$jumps"));
}

void TestIsVowel()
{
  // Positive examples
  CU_ASSERT(IsVowel('a'));
  CU_ASSERT(IsVowel('e'));
  CU_ASSERT(IsVowel('i'));
  CU_ASSERT(IsVowel('o'));
  CU_ASSERT(IsVowel('u'));
  // Negative examples
  CU_ASSERT(!IsVowel('b'));
  CU_ASSERT(!IsVowel('c'));
  CU_ASSERT(!IsVowel('d'));
  CU_ASSERT(!IsVowel('f'));
  CU_ASSERT(!IsVowel('g'));

}

void TestGetConsonantCluster()
{
  CU_ASSERT(strcmp(GetConsonantCluster("string"), "str")==0);
  CU_ASSERT(strcmp(GetConsonantCluster("apple"), "")==0);
  CU_ASSERT(strcmp(GetConsonantCluster("ps"), "ps")==0);
}

void TestStripString()
{
  CU_ASSERT(strcmp(StripString("foobarbaz", 3), "barbaz")==0);
  CU_ASSERT(strcmp(StripString("foobarbaz", 0), "foobarbaz")==0);
}

void TestStringConcat()
{
  CU_ASSERT(strcmp(StringConcat("asd", "123"), "asd123")==0);
  CU_ASSERT(strcmp(StringConcat("fly", "ing"), "flying")==0);
}

int main(void)
{
	// Initialize CUnit
	CU_initialize_registry();
	CU_pSuite pSuite = CU_add_suite("TranslatorToolsTests", NULL, NULL);

	// Register unit tests
	CU_add_test(pSuite, "SplitSentenceIntoWords", TestSplitSentenceIntoWords);
	CU_add_test(pSuite, "WordHasOnlyLetters", TestWordHasOnlyLetters);
	CU_add_test(pSuite, "ToLowerCase", TestToLowerCase);
	CU_add_test(pSuite, "IsVowel", TestIsVowel);
	CU_add_test(pSuite, "GetConsonantCluster", TestGetConsonantCluster);
	CU_add_test(pSuite, "StripString", TestStripString);
	CU_add_test(pSuite, "StringConcat", TestStringConcat);

	// Run all tests
	CU_basic_run_tests();

	// Clean up & exit
	CU_cleanup_registry();
	return 0;
}
