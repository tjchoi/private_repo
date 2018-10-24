
#include <string.h>

#include "list.h"

void list_init(list_t *list, void(*destroy) (void *data))
{
	list->size = 0;
	list->destroy = free;
	list->head = NULL;
	list->tail = NULL;

	return;
}

void list_destroy(list_t *list)
{
	void *data;

	while (list_size(list) > 0)
	{
		if (list_delete(list, NULL, &data) == 0 && list->destroy != NULL)
			list->destroy(data);
	}
	memset(list, 0, sizeof(list_t));

	return ;
}

int list_ins_prev(list_t *list, list_node_t *node, const void *data)
{
	list_node_t *new_node;

	if (node == NULL && list_size(list) != 0)
		return -1;
	
	new_node = (list_node_t *)malloc(sizeof(list_node_t));
	if (new_node == NULL) return -1;

	new_node->data = (void *)data;

	if (list_size(list) == 0)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		list->tail = new_node;
		list->head = new_node;
	}
	else 
	{
		new_node->prev = node->prev;
		new_node->next = node;

		if (is_list_head(list, node))
			list->head = new_node;
		else
			node->prev->next = new_node;

		node->prev = new_node;
	}
	list->size++;

	return 0;
}

int list_ins_next(list_t *list, list_node_t *node, const void *data)
{
	list_node_t *new_node;
	
	if (node == NULL && list_size(list) != 0)
		return -1;

	new_node = (list_node_t *)malloc(sizeof(list_node_t));
	if (new_node == NULL) return -1;

	new_node->data = (void *)data;

	if (list_size(list) == 0)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		list->head = new_node;
		list->tail = new_node;
	}
	else
	{
		new_node->prev = node;
		new_node->next = node->next;

		if (is_list_tail(list, node))
			list->tail = new_node;
		else
			node->next->prev = new_node;

		node->next = new_node;
	}
	list->size++;

	return 0;
}

/*
 *	Delete the node of list
 *	\param	*list	list structure ptr
 *	\param	*node	node ptr to be deleted
 *	\param	**data	ptr to store dataa
 *	\return	0 on sucess or -1 on fail	
 */
int list_delete(list_t *list, list_node_t *node, void **data)
{
	if (list_size(list) == 0 && node == NULL)
		return -1;

	if (data != NULL)
		*data = node->data;
#if 0
	if (list_size(list) == 1) {
		list->head = NULL;
		list->tail = NULL;
	}
	else if (is_list_head(list, node)) {
		list->head = node->next;
		node->next->prev = NULL;
	}
	else if (is_list_tail(list, node)) {
		list->tail = node->prev;
		node->prev->next = NULL;
	}
	else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
#else
	if (is_list_head(list, node)) {
		list->head = node->next;
		
		/** list size is 1 */
		if (list->head  == NULL)
			list->tail = NULL;
		else
			node->next->prev = NULL;
	} 
	else {
		node->prev->next = node->next;

		if (node->prev->next == NULL)
			list->tail = node->prev;
		else
			node->next->prev = node->prev;
	}
#endif
	free(node);

	list->size--;

	return 0;
}

