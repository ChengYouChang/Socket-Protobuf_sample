#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include<iostream>

// protobuf .h file
#include"test0715.pb.h"

using namespace std;
#define PORT 8080
   
int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    //send(sock , hello , strlen(hello) , 0 );
    //printf("Hello message sent\n");
    //valread = read( sock , buffer, 1024);
    //printf("%s\n",buffer );
    
    // ===========================================
    // protobuf test
    cout<<"----------------------------\n";
    myPackage::student s2;
    char buf[1024];

    read( sock , buf, 1024);
	s2.ParseFromArray(buf, 1024);
	cout<<"name: "<<s2.name()<<endl;
	cout<<"number: "<<s2.number()<<endl;
	cout<<"id: "<<s2.id()<<endl;

    // ===========================================
    return 0;
}