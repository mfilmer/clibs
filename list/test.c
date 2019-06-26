#include <stdint.h>
#include <stdio.h>

#include "doubleList.h"
#include "../unittest/unittest.h"

void printList(DoubleList* list)
{
	DoubleListItem* item = list->first;
	printf("0: %f\n", item->value);
	for(int i = 1;i < list->length;i++) {
		item = item->next;
		printf("%d: %f\n", i, item->value);
	}
}

void testAccessingItems(TestResults* results)
{
	DoubleList* list = newDoubleList(5);

	setDoubleListItem(list, 0, 1);
	setDoubleListItem(list, 1, 2);
	setDoubleListItem(list, 2, 3);
	setDoubleListItem(list, 3, 4);
	setDoubleListItem(list, 4, 5);

	assertDouble(results, getDoubleListItem(list, 0), 1);
	assertDouble(results, getDoubleListItem(list, 1), 2);
	assertDouble(results, getDoubleListItem(list, 2), 3);
	assertDouble(results, getDoubleListItem(list, 3), 4);
	assertDouble(results, getDoubleListItem(list, 4), 5);
}

void testInsertingItems(TestResults* results)
{
	DoubleList* list = newDoubleList(0);
	insertDoubleListItem(list, 0, 3);		// 3
	insertDoubleListItem(list, 0, 1);		// 1 3
	insertDoubleListItem(list, 1, 2);		// 1 2 3
	insertDoubleListItem(list, 3, 5);		// 1 2 3 5
	insertDoubleListItem(list, 3, 4);		// 1 2 3 4 5

	assertDouble(results, getDoubleListItem(list, 0), 1);
	assertDouble(results, getDoubleListItem(list, 1), 2);
	assertDouble(results, getDoubleListItem(list, 2), 3);
	assertDouble(results, getDoubleListItem(list, 3), 4);
	assertDouble(results, getDoubleListItem(list, 4), 5);
}

void testDeletingItems(TestResults* results)
{
	DoubleList* list = newDoubleList(5);

	setDoubleListItem(list, 0, 1);
	setDoubleListItem(list, 1, 2);
	setDoubleListItem(list, 2, 3);
	setDoubleListItem(list, 3, 4);
	setDoubleListItem(list, 4, 5);

	assertDouble(results, getDoubleListItem(list, 0), 1);
	assertDouble(results, getDoubleListItem(list, 1), 2);
	assertDouble(results, getDoubleListItem(list, 2), 3);
	assertDouble(results, getDoubleListItem(list, 3), 4);
	assertDouble(results, getDoubleListItem(list, 4), 5);

	removeDoubleListItem(list, 3);
	assertDouble(results, getDoubleListItem(list, 0), 1);
	assertDouble(results, getDoubleListItem(list, 1), 2);
	assertDouble(results, getDoubleListItem(list, 2), 3);
	assertDouble(results, getDoubleListItem(list, 3), 5);

	removeDoubleListItem(list, 0);
	assertDouble(results, getDoubleListItem(list, 0), 2);
	assertDouble(results, getDoubleListItem(list, 1), 3);
	assertDouble(results, getDoubleListItem(list, 2), 5);
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
	
	printf("Test Inserting Items...\n");
	results = newResults();
	testDeletingItems(results);
	printResults(results);
	deleteResults(results);

	printf("Tests complete\n");

	return 0;
}
