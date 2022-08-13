/*g++ -o client client.cpp pen.pb.cc -lprotobuf*/
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

using namespace std;
// ===========================================
// write your code in here!

#define IP_ADDR "10.21.11.19"
#define PORT 8080
#define BUFSIZE 100
#define DATA_COUNT 100
// ===========================================

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    //========================
    code::file s2;
    char buf[BUFSIZE];
    char begin[BUFSIZE];
    struct timespec ts1, ts2;
	unsigned long long ms1, ms2, diff;
	double d;
	double feq;
    int m;
	//timespec_get(&ts1, TIME_UTC);
    //========================
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, IP_ADDR, &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("\nConnection Failed \n");
        return -1;
    }
    cout<<"Socket ready!\n";

    // ===========================================
    // write your code in here
    cout<<"===================================\n";
    cout << "code: ";
    cin  >> m ;
    while(m==1)
    {
        cout<<"ready to recv\n";
        begin[0]='A';
        timespec_get(&ts1, TIME_UTC);
        send(sock, begin, 1, MSG_WAITALL);
        // do recv
        for(int i=0; i<DATA_COUNT; i++){
            recv( sock , buf, BUFSIZE, MSG_WAITALL);
            s2.ParseFromArray(buf, BUFSIZE);
            /*cout << "i: " << i <<endl;
            cout<<"X: "<<s2.x()<<endl;
            cout<<"Y: "<<s2.y()<<endl;
            cout<<"Z: "<<s2.z()<<endl;
            cout << endl;*/
        }
        timespec_get(&ts2, TIME_UTC);
        ms1 = ts1.tv_nsec;
		ms2 = ts2.tv_nsec;
		diff = ms2-ms1;
		d= diff/1000000000.0;
        feq= 1/d*DATA_COUNT;
        std::cout << "sec(s):" << d << std::endl;
        std::cout << "freq(Hz): " << feq << std::endl;
        cout << "code: ";
        cin  >> m ;
    }
    begin[0]='B';
    send(sock, begin, 1, MSG_WAITALL);
    close(sock);
    
    // ===========================================
    return 0;
}
