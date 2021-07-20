#include<iostream>
using namespace std;

// protobuf .h file
#include"test0715.pb.h"

#define BUFSIZE 20
int main()
{
	cout<<"===== cpp test protobuf start! =====\n";
	// set data
	myPackage::student s1;
	s1.set_name("Jack");
	s1.set_number(123);
	s1.set_id(999);

	// pack, serialize to char array
	char buf[BUFSIZE]={0};
	s1.SerializeToArray(buf, BUFSIZE);

	int count=0;
	for(int i=0;i<BUFSIZE;i++){
		cout<<(int)buf[i]<<" | ";
	}
	
	cout<<"-----------------------\n";

	// unpack, deserialize
	myPackage::student s2;
	s2.ParseFromArray(buf, BUFSIZE);
	cout<<"name: "<<s2.name()<<endl;
	cout<<"number: "<<s2.number()<<endl;
	cout<<"id: "<<s2.id()<<endl;
	return 0;
}
