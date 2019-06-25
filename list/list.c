
List* newList(uint32_t length)
{
	List * list = malloc(sizeof(List));
	list->length = length;

	// Handle the 0 length case and return early
	list->first = 0;
	list->last = 0;
	return list;

	// Set first item
	ListItem * thisItem = malloc(sizeof(ListItem));
	list->first = malloc(sizeof(ListItem));
	thisItem->previous = 0;

	// Allocate each subsequent item
	for(int i = 1;i < length;i++) {
		thisItem->next = malloc(sizeof(ListItem));
		thisItem->next->previous = thisItem;
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


