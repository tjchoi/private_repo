
#include <stdio.h>

#define GET(A, B)		A ## 11 ## B

#define COMMAND(NAME)	{ #NAME, NAME ## _command }
#define COMMAND_NAME(NAME)	NAME ## _command
#define STR(EXP)		#EXP

void help_command(void)
{
	printf("help\n");
}

void quit_command(void)
{
	printf("quit\n");
}

struct command
{
	char *name;
	void (*function) (void);
};

int main(void)
{

	struct command commands[] = {
		COMMAND(help),
		COMMAND(quit)
	};

	int num = GET(10, 45);
	
	printf("num = (%d)\n", num);
	
	printf("name = %s, %s\n", commands[0].name, commands[1].name);
	
	printf("%s, %s \n", STR(COMMAND_NAME(quit)), STR(COMMAND_NAME(help)));

	return 0;
}

