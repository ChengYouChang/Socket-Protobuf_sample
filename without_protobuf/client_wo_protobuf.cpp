#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;
#define PORT 8080
#define BUFSIZE 10

union fake_data{
    int i;
    float f;
    char c[4];
};
void showBuf(char buf[BUFSIZE], int bufLen, string label){
    cout<<label;
    for(int i=0;i<bufLen;i++){
        if(i%10==0){
            cout<<endl<<setw(2)<<i<<": ";
        }
        cout<<int(buf[i])<<"|";   
    }
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    //char *hello = "Hello from client";
    //char buffer[1024] = {0};

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
    union fake_data x, y;
    char buf[BUFSIZE]={0};
    read( sock , buf, BUFSIZE);

    showBuf(buf, BUFSIZE, "buf: ");
    for(int i=0;i<4;i++){
        x.c[i]=buf[i];
        y.c[i]=buf[i+4];
    }

    cout<<"x: "<<x.i<<endl;
    cout<<"y: "<<y.f<<endl;
    
    // ===========================================
    return 0;
}