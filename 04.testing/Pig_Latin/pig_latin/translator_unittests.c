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

#include "translator_tools.h"

void TestSplitSentenceIntoWords()
{
  // TODO
//  const char *sentence = "the fox jumps";
//  char *words[] = {"the", "fox", "jumps", NULL};
//	CU_ASSERT_EQUAL(SplitSentenceIntoWords(sentence), words);
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
//  ToLowerCase(word2convert);
//  printf("%s", word2convert);
//  CU_ASSERT((strcmp(word2convert, "the") == 0));
//  CU_ASSERT((strcmp("the", "the") == 0));
//  CU_ASSERT(WordHasOnlyLetters("fox"));
//  CU_ASSERT(WordHasOnlyLetters("jumps"));s
//  // Negative examples
//  CU_ASSERT(!WordHasOnlyLetters("jumps "));
//  CU_ASSERT(!WordHasOnlyLetters("$jumps"));
}

void TestIsVowel()
{
	// TODO
}

void TestGetConsonantCluster()
{
	// TODO
}

void TestStripString()
{
	// TODO
}

void TestStringConcat()
{
	// TODO
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
