
// Prototypes for private functions
ListItem* getListItemPtr (List * list, uint32_t index);


List* newList(uint32_t length)
{
	List* list = malloc(sizeof(List));
	list->length = length;
	list->this = 0;

	// Handle the 0 length case and return early
	if (length == 0) {
		list->first = 0;
		list->last = 0;
		return list;
	}

	// Set first item
	ListItem* thisItem = malloc(sizeof(ListItem));
	list->first = thisItem;
	thisItem->prev = 0;

	// Allocate each subsequent item
	for(int i = 1;i < length;i++) {
		thisItem->next = malloc(sizeof(ListItem));
		thisItem->next->prev = thisItem;
		thisItem = thisItem->next;
	}

	// Set last item
	thisItem->next = 0;
	list->last = thisItem;
	
	return list;
}


int destroyList(List * list)
{
	ListItem * thisItem = list->first;
	ListItem * nextItem;

	// Destroy each item
	for(int i = 0;i < list->length;i++) {
		nextItem = thisItem->next;
		free(thisItem);
		thisItem = nextItem;
	}

	// Destroy list
	free(list);

	return LIST_SUCCESS;
}




ListType getListItem(List* list, uint32_t index)
{
	ListItem* item = getListItemPtr(list, index);
	if (item == 0) {
		return 0;
	}

	list->this = item;

	return item->value;
}



int setListItem(List * list, uint32_t index, ListType value)
{
	ListItem* item = getListItemPtr(list, index);
	if (item == 0) {
		return LIST_ERROR_BOUND;
	}

	list->this = item;

	item->value = value;

	return LIST_SUCCESS;
}


int nextListItem(List* list, ListType* value)
{
	if (list->this) {
		list->this = list->this->next;
		if (list->this) {
			*value = list->this->value;
			return LIST_SUCCESS;
		} 
	}

	return LIST_ERROR_BOUND;
}


int prevListItem(List* list, ListType* value)
{
	if (list->this) {
		list->this = list->this->prev;
		if (list->this) {
			*value = list->this->value;
			return LIST_SUCCESS;
		} 
	}

	return LIST_ERROR_BOUND;
}


int insertListItem(List* list, uint32_t index, ListType item)
{
	if (index > list->length) {
		return LIST_ERROR_BOUND;
	}

	// Create new item
	ListItem* thisItem = malloc(sizeof(ListItem));
	thisItem->value = item;

	// Handle insertion into middle of list
	if ( (index > 0) && (index < list->length) ) {
		ListItem* newNext = getListItemPtr(list, index);
		ListItem* newPrev = newNext->prev;

		newPrev->next = thisItem;
		newNext->prev = thisItem;
		thisItem->prev = newPrev;
		thisItem->next = newNext;
	}

	// Handle insertion into an empty list (first and last simultaneously)
	if (list->length == 0) {
		list->first = thisItem;
		list->last = thisItem;
		thisItem->next = 0;
		thisItem->prev = 0;
	} else {

		// Handle insertion into first position
		if (index == 0) {
			ListItem* newNext = list->first;
			newNext->prev = thisItem;
			list->first = thisItem;
			thisItem->next = newNext;
			thisItem->prev = 0;
		}

		// Handle insertion into last position
		if (index == list->length) {
			ListItem* newPrev = list->last;
			newPrev->next = thisItem;
			list->last = thisItem;
			thisItem->next = 0;
			thisItem->prev = newPrev;
		}
	}

	// Update list length and current item
	list->length += 1;
	list->this = thisItem;

	return LIST_SUCCESS;
}


int removeListItem(List* list, uint32_t index)
{
	if (index > list->length) {
		return LIST_ERROR_BOUND;
	}

	ListItem* delItem = getListItemPtr(list, index);
	ListItem* newThis = delItem->next;
	ListItem* prev = delItem->prev;

	// Handle deletion at front of list
	if (prev == 0) {
		list->first = newThis;
	} else {
		prev->next = newThis;
	}

	// Handle deletion at end of list
	if (newThis == 0) {
		list->last = prev;
	} else {
		newThis->prev = prev;
	}

	// Free the memory
	free(delItem);

	// Update list length and current item
	list->length -= 1;
	list->this = newThis;

	return LIST_SUCCESS;
}



/***** Definitions for private functions *****/

// Get a pointer to the specified list item struct
ListItem* getListItemPtr(List * list, uint32_t index)
{
	// If the item is outside the array, return null
	if (index >= list->length) {
		return 0;
	}

	ListItem* thisItem = list->first;
	for (int i = 0;i < index;i++) {
		thisItem = thisItem->next;
	}

	return thisItem;
}
