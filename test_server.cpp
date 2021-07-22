#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <time.h>

// protobuf .h file
#include"proto_file.pb.h"

using namespace std;
#define PORT 8080
#define BUFSIZE 1024

double fakeDataCreator(){
    // create a random double
    return (double)rand() / (RAND_MAX + 1.0)*10;
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
    }else
        cout<<"Socket bind success!\n";
    
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }else
        cout<<"Socket listening...\n";
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }else
        cout<<"Socket accept!\n";
    //valread = read( new_socket , buffer, 1024);
    //printf("%s\n",buffer );
    //send(new_socket , hello , strlen(hello) , 0 );
    //printf("Hello message sent\n");

    // ===========================================
    // protobuf test
    srand(time(NULL));
    cout<<"\n----------------------------\n";
    myPackage::DATA d;
    double fake_x_data=fakeDataCreator(), fake_y_data=fakeDataCreator();

	d.set_x_axis(fake_x_data);
    d.set_y_axis(fake_y_data);

    cout<<"server:\n";
    cout<<"x_axis: "<<fake_x_data<<endl;
    cout<<"y_axis: "<<fake_y_data<<endl;

	// pack, serialize to string
	char buf[BUFSIZE];
	d.SerializeToArray(buf, BUFSIZE);
    send(new_socket, buf, BUFSIZE, 0);
    // ===========================================
    return 0;
}