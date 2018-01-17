#include <stdio.h>
#include <string.h>

int main()
{
	char *src  = "0000\0aa";
	char dst_1[7], dst_2[7];
	memset(dst_1, 0, 7);
	memset(dst_2, 0, 7);

	strncpy(dst_1, src, 6);
	memcpy(dst_2, src, 6);
	
	int i;
	for(i = 0 ; i < sizeof(dst_1) ; i++)
	{
		printf("%x:%s ", dst_1[i], dst_1+i);
	}
	printf("\n");

	int j;
	for(j = 0 ; j < sizeof(dst_2) ; j++)
	{
		printf("%x:%s ", dst_2[j], dst_2+j);
	}
	printf("\n");


	return 0;

}
