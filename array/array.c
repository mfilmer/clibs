#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "array.h"

// Function definitions
void* newArray(uint32_t length)
{
	Array* array = malloc(sizeof(Array));
	array->data = malloc(length * sizeof(void*));
	array->length = length;
	array->maxlength = length;

	return array;
}

void deleteArray(Array* array)
{
	free(array->data);
	array->data = 0;
}

void deleteArrayAndContents(Array* array)
{
	for(int i = 0;i < array->length;i++) {
		free(array->data[i]);
		array->data[i] = 0;
	}

	deleteArray(array);
}

void insertIntoArray(Array* array, void* item, uint32_t index)
{

}

void removeFromArray(Array* array, uint32_t index)
{

}

void setArrayItem(Array* array, void* item, uint32_t index)
{
	if (index >= array->length) {
		printf("returning early\n");
		return;
	}

	array->data[index] = item;
}

void* getArrayItem(Array* array, uint32_t index)
{
	if (index >= array->length) {
		return 0;
	}

	return array->data[index];
}


