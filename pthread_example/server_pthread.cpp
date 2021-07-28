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
char flag='2';
//===============================================

void* server_send_data(void*);
void *server_recv_cmd(void*);
int send_data(int);
char recv_cmd(int);


int main(){
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }else{cout<<"Socket create success!\n";}

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }else{cout<<"set socker opt OK!\n";}

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }else{cout<<"Socket binding success!\n";}

    if (listen(server_fd, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }else{cout<<"Socket listening...\n";}

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
        perror("accept");
        exit(EXIT_FAILURE);
    }else{cout<<"Socket accept!\n";}
    
    //===============================================
    // 3-axis init code
    //===============================================

    pthread_t t1, t2;
	pthread_create(&t1,NULL,server_send_data,&new_socket);
    pthread_create(&t2,NULL,server_recv_cmd, &new_socket);
	pthread_join(t1, 0);
    pthread_join(t2, 0);
    
	return 0;
}
void* server_send_data(void* argv)
{
    cout<<"===================================\n";
    int new_socket = *(int *)argv;
    while(1){
        usleep(1*1000000);
        if(flag == '1'){
            send_data(new_socket);
            cout<<"Send data OK\n";
        }
        else if(flag == '2'){
            continue;
        }
        else
            break;
    }
    cout<<endl;
    pthread_exit((void *)0);
}

void *server_recv_cmd(void* argv){
    usleep(1*1000000);
    cout<<"===================================\n";
    int sock = *(int *)argv;

    while(1){
        flag = recv_cmd(sock);
        if(flag != '3')
            continue;
        else
            break;
    }
    cout<<"Socket close!\n";
    close(sock);
    pthread_exit((void *)0);
}

int send_data(int fd){
    char buf[BUFSIZE] = "hello";
    int retval;
    retval = send(fd, buf, BUFSIZE, 0);
    // ===========================================
    // 3-axis get XYZ data
    // 3-axis data pack
    // ===========================================
    return retval;
}
char recv_cmd(int fd){
    char cmd = '1';
    if(recv(fd, &cmd, 1, 0)!=0){
        cout<<"Recv cmd: "<<cmd<<" OK!\n";
    }
    else{
        cout<<"Recv error!\n";
    }
    return cmd;
}