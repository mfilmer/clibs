#include <stdint.h>
#include <stdio.h>

#include "array.h"
#include "../unittest/unittest.h"

void testAccessingItems(TestResults* results)
{
	char* str1 = "string 1";
	char* str2 = "string 2";
	char* str3 = "string 3";
	char* str4 = "string 4";
	char* str5 = "string 5";

	Array* array = newArray(5);

	setArrayItem(array, str1, 0);
	setArrayItem(array, str2, 1);
	setArrayItem(array, str3, 2);
	setArrayItem(array, str4, 3);
	setArrayItem(array, str5, 4);

	assert(results, getArrayItem(array, 0), str1);
	assert(results, getArrayItem(array, 1), str2);
	assert(results, getArrayItem(array, 2), str3);
	assert(results, getArrayItem(array, 3), str4);
	assert(results, getArrayItem(array, 4), str5);
}

void testInsertingItems(TestResults* results)
{
	char* str1 = "string 1";
	char* str2 = "string 2";
	char* str3 = "string 3";
	char* str4 = "string 4";
	char* str5 = "string 5";

	Array* array = newArray(1);

	setArrayItem(array, str1, 0);

	insertIntoArray(array, str2, 1);
	insertIntoArray(array, str3, 2);
	insertIntoArray(array, str4, 3);
	insertIntoArray(array, str5, 4);
	insertIntoArray(array, str2, 5);
	insertIntoArray(array, str3, 6);
	insertIntoArray(array, str4, 7);
	insertIntoArray(array, str5, 8);
	insertIntoArray(array, str2, 9);
	insertIntoArray(array, str3, 10);
	insertIntoArray(array, str4, 11);
	insertIntoArray(array, str5, 6);


	assert(results, getArrayItem(array, 0), str1);
	assert(results, getArrayItem(array, 1), str2);
	assert(results, getArrayItem(array, 2), str3);
	assert(results, getArrayItem(array, 3), str4);
	assert(results, getArrayItem(array, 4), str5);
	assert(results, getArrayItem(array, 5), str2);
	assert(results, getArrayItem(array, 7), str3);
	assert(results, getArrayItem(array, 8), str4);
	assert(results, getArrayItem(array, 9), str5);
	assert(results, getArrayItem(array, 10), str2);
	assert(results, getArrayItem(array, 11), str3);
	assert(results, getArrayItem(array, 12), str4);
	assert(results, getArrayItem(array, 6), str5);

}

int main()
{
	TestResults* results;

	printf("Test Accessing Items...\n");
	results = newResults();
	testAccessingItems(results);
	printResults(results);
	deleteResults(results);

	printf("Test Inserting Items...\n");
	results = newResults();
	testInsertingItems(results);
	printResults(results);
	deleteResults(results);
	

	printf("Tests complete\n");

	return 0;
}
