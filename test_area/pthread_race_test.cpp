#include <stdio.h>
#include <pthread.h>

int x= 0;
//Create mutex
pthread_mutex_t test_mutex;

void* fun(void* in)
{
    int i;
    for ( i = 0; i < 10000000; i++ )
    {
        //Lock mutex before going to change variable
        pthread_mutex_lock(&test_mutex);
        x++;
        //Unlock mutex after changing the variable
        pthread_mutex_unlock(&test_mutex);
    }
}

int main()
{
    pthread_t t1, t2;
    printf("Point 1 >> X is: %d\n", x);

    //Initlize mutex
    pthread_mutex_init(&test_mutex, NULL);

    pthread_create(&t1, NULL, fun, NULL);
    pthread_create(&t2, NULL, fun, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    //Destroy mutex after use
    pthread_mutex_destroy(&test_mutex);
    printf("Point 2 >> X is: %d\n", x);
    return 0;
}