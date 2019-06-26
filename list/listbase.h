
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
	ListItem * prev;
};

typedef struct List List;

struct List {
	ListItem* first;		// First item in the list
	ListItem* last;			// List item in the list
	ListItem* this;			// Most recently accessed item
	uint32_t length;
};

List* newList(uint32_t length);
int destroyList(List* list);

ListType getListItem(List* list, uint32_t index);
int setListItem(List* list, uint32_t index, ListType item);
int nextListItem(List* list, ListType* value);
int prevListItem(List* list, ListType* value);

int insertListItem(List* list, uint32_t index, ListType item);
int removeListItem(List* list, uint32_t index);

