/*g++ -o server server.cpp pen.pb.cc -lprotobuf*/
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include "pen.pb.h"

using namespace std;
// ===========================================
// write your code in here!
#define PORT 8080
#define BUFSIZE 100
#define DATA_COUNT 100

// ===========================================
int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    //===========================
    // i2c init
    int file;
	char *bus = "/dev/i2c-1";
	if ((file = open(bus, O_RDWR)) < 0) {
		printf("Failed to open the bus.");
		exit(1);
	}
	ioctl(file, I2C_SLAVE, 0x53);
	char config[2]={0};
	config[0] = 0x2C;
	config[1] = 0x0F;
	write(file, config, 2);
	config[0] = 0x2D;
	config[1] = 0x08;
	write(file, config, 2);
	config[0] = 0x31;
	config[1] = 0x0B;
	write(file, config, 2);
	sleep(1);

	char reg[1] = {0x32};
	char data[6] ={0};
	uint16_t xAccl, yAccl, zAccl ;
	struct timespec ts1, ts2;
	unsigned long long ms1, ms2, diff;
	double d, feq;
	char buf[BUFSIZE];
	code::file s2, s1;
    //==========================

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }else
        cout<<"socket create OK\n";
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }else
        cout<<"set socke opt OK\n";
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }else
        cout<<"bind OK\n";
        

    if (listen(server_fd, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }else
        cout<<"listen OK\n";

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
        perror("accept");
        exit(EXIT_FAILURE);
    }else
        cout<<"accept OK\n";
    cout<<"Socket ready!\n";

    // ===========================================
    // write your code in here!
    cout<<"===================================\n";
    cout << "before recv\n";
    recv(new_socket , buf, 1, MSG_WAITALL); 
    cout << "after recv\n";  
    while(buf[0]=='A'){
        cout<<"ready to send\n";
        // send 10 data
        for(int i=0; i<DATA_COUNT; i++){
            write(file, reg, 1);
            if(read(file, data, 6) != 6)
            {
                std::cout << "Erorr : Input/output Erorr " << std::endl;
                exit(1);
            }
            else
            {
                xAccl = ((data[1] & 31) * 256 + (data[0] & 0xFF));
                yAccl = ((data[3] & 0x1F) * 256 + (data[2] & 0xFF));
                zAccl = ((data[5] & 0x1F) * 256 + (data[4] & 0xFF));
            }
            cout<<"i: "<<i<<endl;
            cout << "Acceleration in X-Axis : " << xAccl << std::endl;
            cout << "Acceleration in Y-Axis : " << yAccl << std::endl;
            cout << "Acceleration in Z-Axis : " << zAccl << std::endl;
            s1.set_x(xAccl);
            s1.set_y(yAccl);
            s1.set_z(zAccl);
            s1.set_freq(feq);
            s1.SerializeToArray(buf, BUFSIZE);
            send(new_socket, buf, BUFSIZE, MSG_WAITALL);
        }
        recv(new_socket , buf, 1, MSG_WAITALL);   
    }
    close(new_socket);
    // ===========================================
    cout<<endl;
    return 0;
}
