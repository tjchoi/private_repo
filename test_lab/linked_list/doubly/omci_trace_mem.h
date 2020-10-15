
#ifndef __OMCI_TRACE_MEM_H__
#define __OMCI_TRACE_MEM_H__

#include "omci_core.h"
#include "list.h"

#define _MALLOC(ptr)		realloc(NULL, ptr)
#define _FREE(ptr)			realloc(ptr, 0)

#define malloc(size)		dbg_malloc(size, __FILE__, __func__, __LINE__)
#define free(ptr)			dbg_free(ptr)

typedef struct mem_info_
{
	char *file;
	char *func;
	int line;
	void *ptr;
	unsigned int size;

}mem_info_t;

void *dbg_malloc(int size, char *file, char *func, int line);
void dbg_free(void *ptr);
void trace_mem_create();
void trace_mem_delete();
int trace_mem_add(list_t *list, mem_info_t *item);
int trace_mem_remove(list_t *list, void *ptr);
extern void trace_mem_print(list_t *list);

extern list_t *trace_mem_list;

#endif //__OMCI_TRACE_MEM_H__
