#include <stdio.h>
#include <pthread.h>
#define len 200000
int g_value = 0;
void *challenge(void *arg)
{
	for(int i=0; i < len; i++)
	{
		g_value++;
		// non atomic command, the: g_value++
			// csw
		///////// move g_value, eax
			// csw
		///////// inc eax
			// csw
		///////// move eax, g_value
	}
	return NULL;
}
void *challenge22(void *arg)
{
	return NULL;
        for(int i=0; i < len; i++)
        {
                g_value++;
                // non atomic command, the: g_value++
                        // csw
                ///////// move g_value, eax
                        // csw
                ///////// inc eax
                        // csw
                ///////// move eax, g_value
        }
        return NULL;
}

int main()
{
	pthread_t threads[2] = {0};
	pthread_create(&threads[0], NULL, challenge, NULL);
	pthread_create(&threads[1], NULL, challenge, NULL);
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

	printf("g_value=%d\n", g_value);

	return 0;
}
