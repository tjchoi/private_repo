#include <stdio.h>
#include <string.h>
#include <stdint.h>


enum state
{
	IN,
	OUT
};

const char *get_words(const char *buf, int num)
{
	int nw;
	const char *c = buf;
	int state = IN;
	nw = 0;

	while (*c != '\n')
	{
		if (*c == '\t' || *c == ' ') {
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			nw++;
		}
		
		if (nw == num) break;
		
		c++;
	}

	return c;
}

int get_newline_num(char *buf, int size) 
{
	int  nw = 0, i;
	char *c = buf;

	for (i = 0 ; i < size ; i++)
	{
		if (*c == '\n')
			nw++;
		c++;
	}

	return nw;
}

void get_client_list()
{
	int i, line_num;
	FILE *fp;
	char cmd[20];
	char buf[1024];
	char device[10];
	uint8_t ip[4];
	uint8_t mac[6];

	const char *start_line, *target_words;
	int ret;
	snprintf(cmd, 20, "cat /proc/net/arp");

	fp = popen(cmd, "r");
	if (fp == NULL) {
		printf("Error: popen fail ! \n");
		return;
	}
	
	ret = fread(buf, 1, sizeof(buf), fp);
	if (ret < 0) {
		printf("Error: fread fail ! \n");
		return;
	}

	start_line = strpbrk(buf, "\n") + 1;
	printf("%s\n\n", start_line);

	line_num = get_newline_num(buf, sizeof(buf));
	printf("line:%d\n", line_num);

	for (i = 0 ; i < line_num ; i++)
	{
		target_words = get_words(start_line, 5);
		sscanf(target_words, "%s ", device);
		if (!strncmp(device, "eth0", 5))
		{
			target_words = get_words(start_line, 0);
			sscanf(target_words, "%d.%d.%d.%d ", (int *)&ip[0], (int *)&ip[1], 
												(int *)&ip[2], (int *)&ip[3]);
			printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);

			target_words = get_words(start_line, 3);
			sscanf(target_words, "%02X:%02X:%02X:%02X:%02X:%02X ",
					(unsigned int *)&mac[0], (unsigned int *)&mac[1], 
					(unsigned int *)&mac[2], (unsigned int *)&mac[3], 
					(unsigned int *)&mac[4], (unsigned int *)&mac[5]);
			printf("%02X:%02X:%02X:%02X:%X:%X\n", 
					mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

		}


		start_line = strpbrk(start_line, "\n") + 1;
		//printf("%s\n", start_line);
	
	}

	return;
}

void test1()
{
	get_client_list();

	return;
}

int main()
{
	test1();

	return 0;
}
