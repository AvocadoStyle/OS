#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

int get_current_tid()
{
	return syscall(__NR_gettid);
}


void *thread_funct1(void *arg)
{
	//for(int i=0; i<100; i++)
	//{
	// 	printf("1\n");
	//	usleep(100000);
	//}
	printf("my tid(need to be diffrent) %d and my pid %d\n", get_current_tid(), getpid());
	return NULL;

}

void *thread_funct2(void *arg)
{
	//for(int i=0; i<100; i++)
	//{
	//	printf("2\n");
	//	usleep(100000);
	//}
	printf("my tid(need to be diffrent) %d and my pid %d\n", get_current_tid(), getpid());
	return NULL;
}



int main()
{
	int retval = 0;
	pthread_t t1, t2;
	retval = pthread_create(&t1, NULL, thread_funct1, NULL);
	if(retval != 0)
	{
		printf("Error");
		exit(1);
	}
	retval = pthread_create(&t2, NULL, thread_funct2, NULL);
	if(retval != 0)
	{
		printf("Error");
		exit(1);
	}
	printf("my tid %d and my pid %d\n", get_current_tid(), getpid());
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("my tid %d and my pid %d\n", get_current_tid(), getpid());
	return 0;
}

