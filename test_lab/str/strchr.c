/**
 *	Get specific entry value link "entry_name=value" in the input strings
 *
 */

#include <stdio.h>
#include <string.h>

#define DATA_STR_SIZE	30


void show_data(char *data, int len)
{
	int i;

	printf("data[#]=[integer|string|hex]\n");
	printf("data size : %d\n", len);
	for (i = 0 ; i < len ; i++)
	{
		printf("data[%d]=[%d|%c|0x%x]\n", i, data[i], data[i], data[i]);
	}
}

char *get_entry_value(char *buf, char *tag)
{
	char *tag_p = NULL;
	char *val_start = NULL;
	char *val_end = NULL;
	static char value[DATA_STR_SIZE] = {0}; //"static" is for global variable
	int val_len;

	tag_p = strstr(buf, tag);
	if (!tag_p) {
		printf("Can't find string \"%s\" !", tag);
		return 0;
	}

	val_start = strchr(tag_p, '=') + 1;
	val_end = strchr(tag_p, '&');
	if (val_end == NULL) val_end = strchr(tag_p, '\0');  //in case of last chr

	val_len = val_end - val_start;
	if (val_len >= DATA_STR_SIZE) return 0; //'=' is for \0

	memcpy(value, val_start, val_len);

	return value;
}

void test1()
{
	char *input = "input=123&page=test&port1=1&port2=2";
	char *val = NULL;

	val = get_entry_value(input, "port2");
	//show_data(val, strlen(val) + 1);
	printf("val:%s\n", val);
}


int main()
{
	test1();

	return 0;
}
