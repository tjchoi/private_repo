
#include <stdio.h>

int temp(void)
{
	printf("This is %s %s %s\n", __func__, __FILE__, __BASE_FILE__ );
	return 0;
}
