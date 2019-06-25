
// Error codes returned by list manipulation functions
#ifndef __LIST_ERROR_H__
#define __LIST_ERROR_H__
#define LIST_SUCCESS 0			// No error to report
#define LIST_ERROR_BOUND 1		// Index out of bounds
#endif

typedef struct ListItem ListItem;

struct ListItem {
	ListType value;
	ListItem * next;
	ListItem * previous;
};

typedef struct List List;

struct List {
	ListItem* first;
	ListItem* last;
	uint32_t length;
};

List * newList (uint32_t length);
int destroyList (List * list);

ListType getItem (List * list, int32_t item);
int setItem (List * list, uint32_t index, ListType item);

