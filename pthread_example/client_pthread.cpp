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
#include <fstream>
#include <chrono>
#include <thread>
#include <memory.h>
#include "fakePB.pb.h"

using namespace myFakePb;
#define IP_ADDR "127.0.0.1"
#define PORT 8080
#define BUFSIZE 100
char flag='2';
pthread_mutex_t mu;
// ===========================================

void *client_recv_data(void*);
void *client_send_cmd(void*);

int main(int argc, char const *argv[])
{
    //===========================================
    //socket  connect
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
    
    //===============================================
    //thread
    /*
     t1 is recv 3-axis data from server
     t2 is send cmd to server
     do send cmd to server and recv 3-axis data from server
    */
    pthread_t t1, t2;
    pthread_mutex_init(&mu, 0);
    pthread_create(&t2,NULL,client_send_cmd, &sock);
	pthread_create(&t1,NULL,client_recv_data, &sock);
	pthread_join(t1, 0);
    pthread_join(t2, 0);
    pthread_mutex_destroy(&mu);
    return 0;
}

void *client_recv_data(void *argv)
{
    int sock = *(int *)argv;
    char buf[BUFSIZE]={0};
    
    char old_flag;
    char tmp_flag;
    ACC_DATA s2;

    // ---------------------------------------
    // test area
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    auto t1 = high_resolution_clock::now();
    // ---------------------------------------

    pthread_mutex_lock( &mu);
    old_flag=flag;
    pthread_mutex_unlock( &mu);
    cout<<"============ready to recv=============\n";
    while(1){
        pthread_mutex_lock( &mu);
        tmp_flag=flag;      // get flag state
        pthread_mutex_unlock( &mu);

        if(old_flag != tmp_flag){   // flag state changes
            cout<< "===========";
            cout << old_flag << "->" << tmp_flag << endl;
        }
        if(tmp_flag == '1'){
            //recv and unpack data
            recv( sock , buf, BUFSIZE, MSG_WAITALL);
            s2.ParseFromArray(buf, BUFSIZE);
            
            auto t2 = high_resolution_clock::now();
            duration<double, std::milli> ms_double = t2 - t1;
            t1 = t2;
            
            cout << "\n\n";
            cout<<"X: "<<s2.x_axis()<<endl;
            cout<<"Y: "<<s2.y_axis()<<endl;
            cout<<"Z: "<<s2.z_axis()<<endl;
            cout <<"============: Time: "<< ms_double.count() << "ms, "<< 1/ms_double.count()*1000<<"Hz\n";
        }
        else if(tmp_flag == '2'){
            old_flag=tmp_flag;
            continue;
        }
        else
            break;
        old_flag=tmp_flag;
    }
    pthread_exit((void *)0);
}
/*
  send cmd to server
*/
void *client_send_cmd(void* argv){
    int new_socket = *(int *)argv;
    char tmp_flag;
    cout<<"Cmd: ";
    cin>> tmp_flag;
    pthread_mutex_lock( &mu);
    flag = tmp_flag;
    pthread_mutex_unlock( &mu);
    while(1){
        if(tmp_flag == '1'){
            usleep(1*1000000);
        }
        send(new_socket, &tmp_flag, 1, 0 );
        cout<<"Send cmd: "<<tmp_flag<<" OK!\n";
        if(tmp_flag == '3'){
            break;
        }
        cout<<"Cmd: ";
        cin>>tmp_flag;
        pthread_mutex_lock( &mu);
        flag = tmp_flag;
        pthread_mutex_unlock( &mu);
    }
    send(new_socket, (void*)&tmp_flag, 1, 0);
    close(new_socket);
    cout<<"Socket close!\n";

    pthread_exit((void *)0);
}

