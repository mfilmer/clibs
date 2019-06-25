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



int main()
{
	printf("Test Accessing Items...\n");
	TestResults* results = newResults();
	testAccessingItems(results);
	printResults(results);
	deleteResults(results);

	printf("Tests complete\n");

	return 0;
}
