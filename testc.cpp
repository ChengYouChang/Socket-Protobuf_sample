#include<iostream>
using namespace std;

// protobuf .h file
#include"test0715.pb.h"

int main()
{
	cout<<"===== cpp test protobuf start! =====\n";
	// set data
	myPackage::student s1;
	s1.set_name("Jack");
	s1.set_number(12345);
	s1.set_id(999);

	// pack, serialize to char array
	char buf[1024];
	s1.SerializeToArray(buf, 1024);
	cout<<"-----------------------\n";

	// unpack, deserialize
	myPackage::student s2;
	s2.ParseFromArray(buf, 1024);
	cout<<"name: "<<s2.name()<<endl;
	cout<<"number: "<<s2.number()<<endl;
	cout<<"id: "<<s2.id()<<endl;
	return 0;
}
