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
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <thread>
#include <memory.h>
#include "pen.pb.h"

#define IP_ADDR "10.21.11.19"
#define PORT 8080
#define BUFSIZE 100
char flag='2';
pthread_mutex_t mu;
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
pthread_mutex_init(&mu, 0);
pthread_create(&t1,NULL,client_recv_data, &sock);
pthread_create(&t2,NULL,client_send_cmd, &sock);
pthread_join(t1, 0);
pthread_join(t2, 0);
pthread_mutex_destroy(&mu);
return 0;
}

void *client_recv_data(void *argv)
{
int sock = *(int *)argv;

char buf[BUFSIZE]={0};
code::file s2;
char old_flag;
old_flag=flag;
cout<<"============ready to recv=============\n";
while(1){
if(old_flag != flag){
cout<< "===========";
cout << old_flag << "->" << flag << endl;
}
if(flag == '1'){
//recv_data
recv( sock , buf, BUFSIZE, MSG_WAITALL);
s2.ParseFromArray(buf, BUFSIZE);
cout << "recv OK\n";
/*cout << endl;
cout<<"X: "<<s2.x()<<endl;
cout<<"Y: "<<s2.y()<<endl;
cout<<"Z: "<<s2.z()<<endl;
cout << endl;*/
}
else if(flag == '2'){
continue;
}
else
break;
old_flag=flag;
}
pthread_exit((void *)0);
}

void *client_send_cmd(void* argv){
int new_socket = *(int *)argv;
char tmp_flag;
cout<<"Cmd: ";
cin>> tmp_flag;
pthread_mutex_lock( &mu);
flag = tmp_flag;
pthread_mutex_unlock( &mu);
while(1){
if(flag == '1'){
usleep(1*1000000);
}
send_cmd(new_socket, flag);
if(flag == '3'){
break;
}
cout<<"Cmd: ";
cin>>tmp_flag;
pthread_mutex_lock( &mu);
flag = tmp_flag;
pthread_mutex_unlock( &mu);
}
send(new_socket, (void*)&flag, 1, 0);
close(new_socket);
cout<<"Socket close!\n";

pthread_exit((void *)0);
}

void send_cmd(int fd, char cmd){
if(send(fd, &cmd, 1, 0 )!=0){
cout<<"Send cmd: "<<cmd<<" OK!\n";
}else{
cout<<"Send error!\n";
}
}