#include <stdio.h>
#include <pthread.h>
#define len 200000
int turn = 0;
int g_value = 0;
void *challenge(void *arg)
{
//	for(int i=0; i < len; i++)
//	{	
		while(turn != 0) ; 
		//for(int i=0; i < len; i++)
		for(int i=0; i < len; i++)
		{
			g_value++;
		}
		turn = 1;				
//	}
	return NULL;
}
void *challenge22(void *arg)
{
//	for(int i=0; i < len; i++)
//	{	
		while(turn != 1) ;
		//for(int i=0; i < len; i++)
		for(int i=0; i < len; i++)
		{
			g_value++;
		}
		turn = 0;				
//	}
	return NULL;
}

int main()
{
        pthread_t threads[2] = {0};
        pthread_create(&threads[0], NULL, challenge, NULL);
        pthread_create(&threads[1], NULL, challenge22, NULL);
        pthread_join(threads[0], NULL);
        pthread_join(threads[1], NULL);

        printf("g_value=%d\n", g_value);

        return 0;
}
