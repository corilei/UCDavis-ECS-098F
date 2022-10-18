/*
 * Unit tests for the pig latin translator using the CUnit framework.
 */
#include <CUnit/Basic.h>

#include "translator_tools.h"

void TestSplitSentenceIntoWords()
{
  const char *sentence = "the fox jumps";
  char *words[] = {"the", "fox", "jumps", NULL};
	CU_ASSERT_EQUAL(SplitSentenceIntoWords(sentence) == words);
}

void TestWordHasOnlyLetters()
{
	// TODO
}

void TestToLowerCase()
{
	// TODO
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
