#ifndef __ARRAY_H__
#define __ARRAY_H__

typedef struct {
	void** data;
	uint32_t length;		// Number of items exposed to the user
	uint32_t maxlength;		// Length of allocated array
} Array;

// Function prototypes
void* newArray(uint32_t length);
void deleteArray(Array* array);
void deleteArrayAndContents(Array* array);

void insertIntoArray(Array* array, void* item, uint32_t index);
void removeFromArray(Array* array, uint32_t index);

void setArrayItem(Array* array, void* item, uint32_t index);
void* getArrayItem(Array* array, uint32_t index);

#endif
