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
#include <ctype.h>

#include "translator_tools.h"


void TestSplitSentenceIntoWords()
{
  const char *input = " the fox jumps ";
  char *except_output[] = {"the", "fox", "jumps", NULL};

  char **real_output = malloc(sizeof(char*) * strlen(input));
  real_output = SplitSentenceIntoWords(input);

	CU_ASSERT(except_output == except_output);
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
  char word2convert[] = "sIlLy";
  ToLowerCase(word2convert);
  CU_ASSERT(strcmp(word2convert, "silly")==0);
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
  CU_ASSERT(GetConsonantCluster("") == NULL);
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
