#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>


int create_timer(timer_t *timer_id, void (*func) (int, siginfo_t *, void *), 
					int sec, int msec)
{
	struct sigevent		te;
	struct itimerspec	its;
	struct sigaction	sa;

	int	sig_no = SIGRTMIN;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = (void *)func;
	sigemptyset(&sa.sa_mask);

	if (sigaction(sig_no, &sa, NULL) == -1) {
		printf("sigaction error\n");
		return -1;
	}

	te.sigev_notify = SIGEV_SIGNAL;
	te.sigev_signo = sig_no;
	te.sigev_value.sival_ptr = timer_id;
	timer_create(CLOCK_REALTIME, &te, timer_id);

	/* period time */
	its.it_interval.tv_sec = sec;
	its.it_interval.tv_nsec = msec * 1000000;
	/* initial time at first */
	its.it_value.tv_sec = sec;
	its.it_value.tv_nsec = msec * 1000000;
	timer_settime(*timer_id, 0, &its, NULL);

	return 0;
}

void sigaction_handler(int sig_no, siginfo_t *info, void *arg)
{
	printf("siginfo: pid=%d, uid=%d\n", info->si_pid, info->si_uid);
	static int num = 0;
	printf("timer(%d)\n", num++);

}


void test1()
{
	timer_t timer_id;
	
	create_timer(&timer_id, sigaction_handler, 2, 0);

	while(1);

}

int main()
{
	test1();

	return 0;
}
