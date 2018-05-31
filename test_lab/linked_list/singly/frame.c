#include <stdlib.h>

#include "list.h"


int alloc_frame(list *frame)
{
	int frame_number;
	int *data;

	if (list_size(frame) == 0) return -1;

	if (list_del_next(frame, NULL, (void **)&data) == 0)
		return -1;
	else 
	{
		frame_number = *data;
		free(data);
	}

	return frame_number;
}

int free_frame(list *frame, int frame_number)
{

	int *data;

	if ((data = (int *)malloc(sizeof(int))) == NULL)
		return -1;
	
	*data = frame_number;
	if (list_ins_next(frame, NULL, (const void *)data) != 0)
		return -1;

	return 0;
}
