#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define len 10
void *thread_infinity1(void *arg)
{
	while(1)
		printf("1");
}

void *thread_infinity2(void *arg)
{
	while(1)
		printf("2");
}



void *thread_func1(void *arg)
{
	for(int i=0; i < len; i++)
	{
		usleep(100000);
		printf("1\n");


	}
	return NULL;


}
void *thread_func2(void *arg)
{

	for(int i=0; i < len; i++)
	{
		usleep(100000);

		printf("2\n");


	}
	return NULL;

}

int main()
{
	int retval = 0;
	pthread_t t1;
	pthread_t t2;
	retval = pthread_create(&t1, NULL, thread_func1, NULL);
	retval = pthread_create(&t2, NULL, thread_func2, NULL);
	//retval = pthread_create(&t1, NULL, thread_infinity1, NULL);
	//retval = pthread_create(&t2, NULL, thread_infinity2, NULL);
	
	usleep(500000);
	printf("shalom\n");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	

	return 0;
}


