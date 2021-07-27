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

// ===========================================

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }else
        cout<<"Socket create!\n";
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, IP_ADDR, &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }else
        cout<<"Socket connect!\n";

    // ===========================================
    // write your code in here!
    cout<<"===================================\n";
    char buf[BUFSIZE]={0};
    if(recv(sock, buf, BUFSIZE, 0)!=0){
        cout<<"Recv: "<<buf<<" OK!\n";
    }
    else{
        cout<<"Recv error!\n";
    }
    // ===========================================
    return 0;
}