#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "array.h"

#define ARRAY_MIN_LENGTH 10

// Private function prototypes
void setAllocationSize(Array* array,  uint32_t alloclength);
void ensureAllocationSize(Array* array, uint32_t alloclength);

// Public function definitions
void* newArray(uint32_t length)
{
	Array* array = malloc(sizeof(Array));

	array->length = length;

	// Allocate some extra space for ease of future expansion
	if (length < ARRAY_MIN_LENGTH) {
		array->alloclength = ARRAY_MIN_LENGTH;
	} else {
		array->alloclength = length + length/2;
	}

	array->data = malloc(array->alloclength * sizeof(void*));

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

void trimArray(Array* array)
{
	int newAllocSize = array->length + array->length/2;
	setAllocationSize(array, newAllocSize);
}

void insertIntoArray(Array* array, void* item, uint32_t index)
{
	// Make sure the data all fits, expand if necessary
	ensureAllocationSize(array, index+1);

	// Shift data back one space to create an opening
	for(int i = array->length-1;i >= index;i--) {
		array->data[i+1] = array->data[i];
	}

	// Set item
	array->data[index] = item;

	// Update length
	if (index <= array->length) {
		array->length += 1;
	} else {
		array->length = index - 1;
	}
}

void removeFromArray(Array* array, uint32_t index)
{
	for(int i = index+1;i < array->length;i++) {
		array->data[i-1] = array->data[i];
	}

	array->length -= 1;
}

void setArrayItem(Array* array, void* item, uint32_t index)
{
	if (index >= array->length) {
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


// Private function definitions
void setAllocationSize(Array* array, uint32_t alloclength)
{
	// Ensure that alloclength is big enough to hold the existing data
	if (alloclength < array->length) {
		alloclength = array->length;
	}

	// Reallocate array to fit new size
	array->alloclength = alloclength;
	array->data = realloc(array->data, array->alloclength * sizeof(void*));
}

// Ensure the allocated array is big enough to hold the specified number of items
// Array is expanded if it does not fit
void ensureAllocationSize(Array* array, uint32_t alloclength)
{
	if (array->alloclength < alloclength) {
		setAllocationSize(array, alloclength + alloclength/2);
	}
}
