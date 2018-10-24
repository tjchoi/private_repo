
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct list_node_ {

	void *data;

	struct list_node_ *prev;
	
	struct list_node_ *next;

}list_node_t;

typedef struct list_ {

	int size;

	int (*match) (const void *key1, const void *key2);

	void (*destroy) (void *data);

	list_node_t *head;

	list_node_t *tail;

}list_t;

void list_init(list_t *list, void(*destroy) (void *data));
void list_destroy(list_t *list);
int list_ins_prev(list_t *list, list_node_t *node, const void *data);
int list_ins_next(list_t *list, list_node_t *node, const void *data);
int list_delete(list_t *list, list_node_t *node, void **data);

#define list_size(list)		((list)->size)
#define list_head(list)		((list)->head)
#define list_tail(list)		((list)->tail)

#define is_list_head(list, node)		((node)->prev == NULL ? 1 : 0)
#define is_list_tail(list, node)		((node)->next == NULL ? 1 : 0)

#define list_data(node)		((node)->data)
#define list_prev(node)		((node)->prev)
#define list_next(node)		((node)->next)


#endif /** LIST_H */
