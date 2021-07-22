#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;
#define PORT 8080
#define BUFSIZE 10

union fake_data{
    int i;
    float f;
    char c[4];
};
double fakeDataCreator(){
    // create a random double
    return (double)rand() / (RAND_MAX + 1.0)*10;
}
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
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    //char buffer[1024] = {0};
    //char *hello = "Hello from server";
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
       
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
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    //valread = read( new_socket , buffer, 1024);
    //printf("%s\n",buffer );
    //send(new_socket , hello , strlen(hello) , 0 );
    //printf("Hello message sent\n");

    
    // ===========================================
    srand(time(NULL));
    cout<<"\n----------------------------\n";
    union fake_data fake_x, fake_y, fake_z;
    fake_x.i=123;
    fake_y.f=4.56;

    char buf[BUFSIZE]={0};

    showBuf(fake_x.c, 4, "fake_x: ");
    showBuf(fake_y.c, 4, "fake_y: ");

    for(int i=0;i<4;i++){
        buf[i]=fake_x.c[i];
        buf[i+4]=fake_y.c[i];
    }
    showBuf(buf, BUFSIZE, "buf: ");
    send(new_socket , buf , BUFSIZE, 0 );
    // ===========================================
    cout<<endl;
    return 0;
}