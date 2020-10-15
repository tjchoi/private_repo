
#include <stdio.h>
#include <stdlib.h>

#include "omci_trace_mem.h"

list_t *trace_mem_list = NULL;

void *dbg_malloc(int size, char *file, char *func, int line)
{
	int ret;
	//fprintf(stdout, "[IN] : %s\n", __func__);
	mem_info_t *mem_item = realloc(NULL, sizeof(mem_info_t));
	void *ptr = _MALLOC(size);
	if (ptr == NULL) {
		fprintf(stdout, "can't dbg_malloc\n");
		return ptr;
	}

	mem_item->file = file;
	mem_item->func = func;
	mem_item->line = line;
	mem_item->ptr = ptr;
	mem_item->size = size;

	ret = trace_mem_add(trace_mem_list, mem_item);
	if (ret != 0)
		fprintf(stderr, "trace_mem_add fail\n");
	
	//fprintf(stdout, "[OUT] : %s\n", __func__);
	return ptr;
}

void dbg_free(void *ptr)
{
	int ret;
	//fprintf(stdout, "[IN] : %s\n", __func__);
	ret = trace_mem_remove(trace_mem_list, ptr);
	if (ret != 0)
		fprintf(stderr, "trace_mem_remove fail\n");
	
	_FREE(ptr);
	ptr = NULL;

	//fprintf(stdout, "[OUT] : %s\n", __func__);
	return;
}
void trace_mem_create()
{
	//fprintf(stdout, "[IN] : %s\n", __func__);
	trace_mem_list = realloc(NULL, sizeof(list_t));
	if (trace_mem_list == NULL) {
		fprintf(stderr, "trace mem list allocation failed\n");
		return;
	}

	omci_list_init(trace_mem_list, NULL); //destroy func

	//fprintf(stdout, "[OUT] : %s\n", __func__);
	return;
}

void trace_mem_delete()
{
	omci_list_destroy(trace_mem_list);
	if (trace_mem_list)
		realloc(trace_mem_list, 0);
	return;
}

list_node_t *trace_mem_find_ptr(list_t *list, void *ptr)
{
	list_node_t *node;
	mem_info_t *item;
	
	//fprintf(stdout, "[IN] : %s\n", __func__);

	for (node = omci_list_head(list)
			; node != NULL
			; node = omci_list_next(node))
	{
		item = (mem_info_t *)omci_list_data(node);
		if (item->ptr == ptr) {
			fprintf(stdout, "[OUT] : %s\n", __func__);
			return node;
		}
	}

	//fprintf(stdout, "[OUT] NULL : %s\n", __func__);
	return NULL;
}

int trace_mem_add(list_t *list, mem_info_t *item)
{
	int ret;

	ret = omci_list_ins_next(list, omci_list_head(list), 
						(const void *)item);
	if (ret != 0) {
		fprintf(stderr, "insert mem list is failed\n");
		return ret;
	}
	return ret;
}

int trace_mem_remove(list_t *list, void *ptr)
{
	int ret = 0;
	list_node_t *node;
	//fprintf(stdout, "[IN] : %s\n", __func__);

	node = trace_mem_find_ptr(list, ptr);
	if (node != NULL) {
		omci_list_delete(list, node, NULL);
	}
	else {
		fprintf(stderr, "remove mem list is failed\n");
		trace_mem_print(list);	
		ret = -1;
	}

	//fprintf(stdout, "[OUT] : %s\n", __func__);
	return ret;
}

void trace_mem_item_print(list_node_t *node)
{
	mem_info_t *item = (mem_info_t *)omci_list_data(node);
	fprintf(stdout, "@file:%s    @func:%s    @line:%d    @ptr:(%p)\n", 
			item->file, item->func, item->line, item->ptr);

	return;
}

void trace_mem_print(list_t *list)
{
	list_node_t *node;

	fprintf(stdout, "\n +++++ Trace Mem Print\n");
	fprintf(stdout, "list_size = %u\n", list->size);
	if (list->size == 0) {
		fprintf(stdout, "There is no list about Trace MEM\n");
		return;
	}

	for (node = list->head ; node != NULL ; node = omci_list_next(node))
	{
		trace_mem_item_print(node);
	}
	fprintf(stdout, "\n +++++ End Trace Mem Print\n");
	return;
}
