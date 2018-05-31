#include <stdlib.h>
#include <string.h>

#include "list.h"

void list_init(list *list, void (*destroy) (void *data))
{
	list->size = 0;
	list->destroy = free;
	list->head = NULL;
	list->tail = NULL;

	return;
}

void list_destroy(list *list)
{
	int  size, ret;
	void *data;
#if 0
	size = list_size(list);

	for (node = list->head; node != NULL; node->next)
	{
		ret = list_del_next(list, node, (void **)&data);
		if (ret == 0 && list->destroy != NULL)
			list->destroy(data);
	}
#else
	while (list_size(list) > 0)
	{
		if (list_del_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL)
			list->destroy(data);
	}
#endif
	memset(list, 0, sizeof(list));

	return ;
}

int list_ins_next(list *list, list_node *node, const void *data)
{
	list_node *new_node;

	new_node = (list_node *)malloc(sizeof(list_node));
	if (new_node == NULL) return -1;

	new_node->data = (void *)data;

	if (node == NULL)
	{
		new_node->next = list->tail;
		list->head = new_node;

		if (list_size(list) == 0)
			list->tail = new_node;
	}
	else 
	{
		new_node->next = node->next;
		node->next = new_node;
		
		if (is_list_tail(node))
			list->tail = new_node;
	}

	list->size++;

	return 0;
}

int list_del_next(list *list, list_node *node, void **data)
{
	list_node *del_node;

	if (list_size(list) == 0) return -1;

	if (node == NULL)
	{
		del_node = list->head;
		*data = del_node->data;
		list->head = list->head->next;

		if (list_size(list) == 0)
			list->tail = NULL;
	}
	else
	{
		if (node->next == NULL) return -1;
		
		del_node = node->next;
		*data = del_node->data;
		node->next = node->next->next;

		if (node->next == NULL)
			list->tail = node;

	}

	free(del_node);

	list->size--;

	return 0;
}
