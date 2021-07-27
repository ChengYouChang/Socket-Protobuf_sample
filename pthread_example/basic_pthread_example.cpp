#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;

void *thread1(void *);
void *thread2(void *);
int main(void)
{
	pthread_t t1, t2;
	pthread_create(&t1,NULL,thread1,NULL);
    pthread_create(&t2,NULL,thread2,NULL);
	pthread_join(t1, 0);
    pthread_join(t2, 0);

	return 0;
}
void *thread1(void *junk)
{
    for(int i=0;i<3;i++){
        cout<<"This is thread 1\n";
        usleep(1*1000000);
    }
    
    pthread_exit((void *)0);
}
void *thread2(void *junk)
{
    for(int i=0;i<10;i++){
        cout<<"This is thread 2\n";
        usleep(0.5*1000000);
    }
    pthread_exit((void *)0);
}