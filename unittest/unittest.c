#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "unittest.h"

TestResults* newResults()
{
	TestResults* results = malloc(sizeof(TestResults));
	results->passed = 0;
	results->failed = 0;

	return results;
}

void deleteResults(TestResults* results)
{
	free(results);
}

// Returns 1 if passed, -1 if failed
int assert(TestResults* results, void* val1, void* val2)
{
	if (val1 == val2) {
		results->passed += 1;
		return 1;
	} else {
		results->failed += 1;
		return -1;
	}
}

// Returns 1 if passed, -1 if failed
int assertDouble(TestResults* results, double val1, double val2)
{
	if (val1 == val2) {
		results->passed += 1;
		return 1;
	} else {
		results->failed += 1;
		return -1;
	}
}

void printResults(TestResults* results)
{
	printf("Passed: %d\t\tFailed: %d\n", results->passed, results->failed);
}
