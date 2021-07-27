#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <pthread.h>
#include <unistd.h>

using namespace std;

//===============================================
// write your code in here!
#define PORT 8080
#define BUFSIZE 10
//===============================================

void *socket_connect(void*);
void *thread2(void*);
int main(){
    pthread_t t1, t2;
	pthread_create(&t1,NULL,socket_connect,NULL);
    pthread_create(&t2,NULL,thread2,NULL);
	pthread_join(t1, 0);
    pthread_join(t2, 0);

	return 0;
}
void *socket_connect(void* junk)
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }else
        cout<<"Socket create success!\n";
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }else
        cout<<"Socket binding success!\n";
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }else
        cout<<"Socket listening...\n";
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }else
        cout<<"Socket accept!\n";
    
    // ===========================================
    // write your code in here!

    cout<<"===================================\n";
    
    char buf[BUFSIZE] = "hello";
    if(send(new_socket, buf, BUFSIZE, 0 )!=0){
        cout<<"Send: "<<buf<<" OK!\n";
    }else{
        cout<<"Send error!\n";
    }
    
    // ===========================================
    cout<<endl;
    return 0;
}

void *thread2(void* junk){
    for(int i=0;i<3;i++){
        cout<<"This is thread 2\n";
        usleep(1*1000000);
    }
    pthread_exit((void *)0);
}