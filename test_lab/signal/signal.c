#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void (*old_func)(int);

void sigint_handler(int sig_num)
{
	printf("Ctrl-C is now inserted. \n");
	signal(SIGINT, old_func);
}

int main(int argc, char **argv)
{
	old_func = signal(SIGINT, sigint_handler);

	while(1)
	{	
		printf("waiting SIGINT signal\n");
		sleep(2);
	}

	return 0;
}
