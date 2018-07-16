#include <stdio.h>

#define BUF_SIZE	32

int wait_pattern(char *pattern, int pattern_len)
{
	int i = 0;
	char buf[1] = {0};
	printf("Insert characters !\n");
	while (buf[0] = getc(stdin))
	{ /* get new data */
		//printf("buf:%c, pattern:%c(i=%d)\n", buf[0], *(pattern+i), i);
		
		/* when fail the matching compare to first pattern again */
		for ( ; buf[0] != *(pattern + i) && i != 0 ; i = 0 );
		
		/* success pattern maching */
		if (pattern_len == i + 1) break;
		
		/* next pattern */
		if (buf[0] == *(pattern + i)) i++;

	}
	return 0;

}

void test1()
{
	int ret;
	int fd;
	char buf[BUF_SIZE] = {0};


	wait_pattern("ABC", 3);

	printf("wait is over!\n");

	return;
}

int main()
{
	test1();

	return 0;
}
