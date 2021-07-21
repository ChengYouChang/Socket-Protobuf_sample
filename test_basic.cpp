#include<iostream>
using namespace std;

// protobuf .h file
#include"proto_file.pb.h"

#define BUFSIZE 20
int main()
{
	cout<<"===== cpp test protobuf start! =====\n";
	// set data
	myPackage::DATA d;
	d.set_x_axis(1.23);		// fake x_axis data
	d.set_y_axis(4.56);		// fake y_axis data

	// pack, serialize to char array
	char buf[BUFSIZE]={0};
	d.SerializeToArray(buf, BUFSIZE);

	cout<<"-----------------------\n";

	// unpack, deserialize
	myPackage::DATA d2;
	d2.ParseFromArray(buf, BUFSIZE);

	cout<<"x_axis: "<<d2.x_axis()<<endl;
	cout<<"y_axis: "<<d2.y_axis()<<endl;
	return 0;
}
