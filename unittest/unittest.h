#ifndef __UNITTEST_H__
#define __UNITTEST_H__

typedef struct {
	uint32_t passed;
	uint32_t failed;
} TestResults;

TestResults* newResults();
void deleteResults(TestResults* results);
int assert(TestResults* results, void* val1, void* val2);

void printResults(TestResults* results);

#endif
