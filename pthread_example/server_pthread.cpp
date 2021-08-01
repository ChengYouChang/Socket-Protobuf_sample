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
//===============================================
// write your code in here!
#include <time.h>
#include <stdlib.h>
#include "fakePB.pb.h"
using namespace std;
using namespace myFakePb;

#define PORT 8080
#define BUFSIZE 100
char flag='2';
pthread_mutex_t mu;
//===============================================

void* server_send_data(void*);
void *server_recv_cmd(void*);

int fake_data_creater(){
    // return a random number between 0~8191
    return rand()%8192;
}
int main(){
    //socket init code
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    //===========================================
    //socket connect 
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }else{cout<<"Socket create success!\n";}

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT , &opt, sizeof(opt))){
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
    //thread
    /*
     t1 is send 3-axis data to client
     t2 is recv cmd from client
     do recv cmd from client and send 3-axis data to client
    */
    pthread_t t1, t2;
    pthread_mutex_init(&mu, 0);
    pthread_create(&t2,NULL,server_recv_cmd, &new_socket);
    pthread_create(&t1,NULL,server_send_data, &new_socket);
    pthread_join(t1, 0);
    pthread_join(t2, 0);
    pthread_mutex_destroy(&mu);
    //================================================
    return 0;
}
/*
 get and send 3-axis data to client
*/
void* server_send_data(void* argv)
{
    //===============================================
    // init code
    srand(time(NULL));      // set random seed
    int xAccl, yAccl, zAccl;
    ACC_DATA s1;
    int c=0;
    char tmp_flag;
    char buf[BUFSIZE];

    int new_socket = *(int *)argv;
    cout<<"===============ready to send=================\n";
    // ===========================================
    // get and send fake data
    while(1){
        pthread_mutex_lock( &mu);
        tmp_flag=flag;      // read flag
        pthread_mutex_unlock( &mu);

        if(tmp_flag == '1'){
        usleep(1*1000000);
	    // get fake XYZ data
	    xAccl = fake_data_creater();
        yAccl = fake_data_creater();
        zAccl = fake_data_creater();
        cout<<"X: "<<xAccl<<"\nY: "<<yAccl<<"\nZ: "<<zAccl<<endl;
        // data pack and send
	    s1.set_x_axis(xAccl);
	    s1.set_y_axis(yAccl);
	    s1.set_z_axis(zAccl);
	    s1.SerializeToArray(buf, BUFSIZE);
	    send(new_socket, buf, BUFSIZE, 0);
	    cout << c << endl;;
	    c++;
	    // ===========================================
        }
        else if(tmp_flag == '2'){
            continue;
        }
        else
            break;
    }
    cout<<endl;
    pthread_exit((void *)0);
}
/*
  recv cmd from client
*/
void *server_recv_cmd(void* argv){
    cout<<"===================================\n";
    int sock = *(int *)argv;
    char tmp_flag;
    while(1){
	recv(sock, &tmp_flag, 1, MSG_WAITALL);
	cout<<"Recv cmd: "<<tmp_flag<<" OK!\n";
	pthread_mutex_lock( &mu);
	flag = tmp_flag;
	pthread_mutex_unlock( &mu);
        if(tmp_flag == '2'){
            continue;
	}
        else if(tmp_flag == '3'){
            break;
	}
    }
    cout<<"Socket close!\n";
    close(sock);
    pthread_exit((void *)0);
}

