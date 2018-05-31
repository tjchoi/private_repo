
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct list_node_ {
	
	void *data;
	
	struct list_node_ *next;

}list_node;

typedef struct list_ {

	int	size;
	
	int	(*match) (const void *key1, const void *key2);
	
	void (*destroy) (void *data);

	list_node	*head;
	
	list_node	*tail;

}list;

void list_init(list *list, void (*destroy) (void *data));
void list_destroy(list *list);
int list_ins_next(list *list, list_node *node, const void *data);
int list_del_next(list *list, list_node *node, void **data);

#define list_size(list)		((list)->size)
#define list_head(list)		((list)->head)
#define list_tail(list)		((list)->tail)

#define is_list_head(list, node)		((node) == (list)->head ? 1 : 0)
#define is_list_tail(node)				((node)->next == NULL ? 1 : 0)
//#define is_list_tail(list, node)		((list)->tail == node ? 1 : 0)

#define list_data(node)		((node)->data)
#define list_next(node)		((node)->next)




#endif /* LIST_H */
