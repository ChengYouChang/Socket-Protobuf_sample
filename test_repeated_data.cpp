#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

// protobuf .h file
#include"proto_file.pb.h"
using namespace myPackage;

#define BUFSIZE 1024
#define FAKE_CMD 123
#define FAKE_DATA_COUNT 3
double fakeDataCreate(){
    return (double)rand() / (RAND_MAX + 1.0)*10;
}
int main()
{
	cout<<"\n===== Create fake data and pack! =====\n";
	// set dataPack cmd
	DATAPACK dp;
    DATA *d;

    // for creating fake data
    srand(time(NULL));   // random seed
    double fake_data;

    dp.set_cmd(FAKE_CMD);
    cout<<"cmd: "<<FAKE_CMD<<endl;

    for(int i=0; i<FAKE_DATA_COUNT; i++){
        cout<<"Data "<<i<<" => ";

        d = dp.add_data();      // add a data in dataPack

        // set x
        fake_data = fakeDataCreate();
        d->set_x_axis(fake_data);
        cout<<"x: "<< fake_data<<" | ";

        // set y
        fake_data = fakeDataCreate();
        d->set_y_axis(fake_data);
        cout<<"y: "<< fake_data<<endl;
    }
    cout<<"\nDATAs in DATAPACK: "<<dp.data_size()<<endl;

    // serialize to array
    char buf[BUFSIZE]={0};
	dp.SerializeToArray(buf, BUFSIZE);


	cout<<"\n----- unPack it, and check data -----\n";
	// unpack, deserialize

    DATAPACK dp2;
    DATA d2;
    dp2.ParseFromArray(buf, BUFSIZE);

    cout<<"cmd: "<<dp.cmd()<<endl;
    for(int i=0; i<dp2.data_size(); i++){
        d2 = dp2.data(i);
        cout<<"DATA "<< i <<" => ";
        cout<<"x: "<< d2.x_axis()<<" | ";
        cout<<"y: "<< d2.y_axis()<<"\n";
    }
    
    cout<<endl;
    return 0;
}
