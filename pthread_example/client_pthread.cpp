#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

// ===========================================
// write your code in here!
#define IP_ADDR "127.0.0.1"
#define PORT 8080
#define BUFSIZE 10
char flag='2';
// ===========================================
void *client_recv_data(void*);
void *client_send_cmd(void*);
int recv_data(int);
void send_cmd(int, char);
int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation error \n");
        return -1;
    }else{cout<<"Socket create!\n";}
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, IP_ADDR, &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }else{cout<<"inet pton OK!\n";}
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("\nConnection Failed \n");
        return -1;
    }else{cout<<"Socket connect!\n";}

    pthread_t t1, t2;
	pthread_create(&t1,NULL,client_recv_data, &sock);
    pthread_create(&t2,NULL,client_send_cmd, &sock);
	pthread_join(t1, 0);
    pthread_join(t2, 0);
    return 0;
}

void *client_recv_data(void *argv)
{
    // ===========================================
    // write your code in here!
    cout<<"===================================\n";
    int sock = *(int *)argv;

    while(1){
        if(flag == '1'){
            recv_data(sock);
        }
        else if(flag == '2'){
            continue;
        }
        else
            break;
    }
    // ===========================================
    pthread_exit((void *)0);
}

void *client_send_cmd(void* argv){
    usleep(1*1000000);
    // ===========================================
    // write your code in here!
    cout<<"===================================\n";
    int new_socket = *(int *)argv;

    cout<<"Cmd: ";
    cin>>flag;
    while(1){
        send_cmd(new_socket, flag);
        if(flag == '3')
            break;

        cout<<"Cmd: ";
        cin>>flag;
    }
    flag = 0;
    send(new_socket, &flag, 1, 0 );
    close(new_socket);
    cout<<"Socket close!\n";
    // ===========================================
    pthread_exit((void *)0);
}

int recv_data(int fd){
    char buf[BUFSIZE]={0};
    int retval;
    retval = recv(fd, buf, BUFSIZE, 0);
    cout<<"Recv data: "<<buf<<endl;
    return retval;
}
void send_cmd(int fd, char cmd){
    if(send(fd, &cmd, 1, 0 )!=0){
        cout<<"Send cmd: "<<cmd<<" OK!\n";
    }else{
        cout<<"Send error!\n";
    }
}