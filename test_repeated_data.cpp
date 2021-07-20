#include<iostream>
#include<cstdlib>
using namespace std;

// protobuf .h file
#include"test0715.pb.h"
using namespace myPackage;

#define BUFSIZE 1024
#define FAKE_DATA_COUNT 3
int main()
{
	cout<<"===== Create fake data and pack! =====\n";
	// set dataPack cmd
	DATAPACK dp;
    DATA *d;

    // for creating fake data
    srand(1);   // random seed
    double fake_data;

    dp.set_cmd(12);
    for(int i=0; i<FAKE_DATA_COUNT; i++){
        cout<<"Data "<<i<<": ";
        d = dp.add_data();

        fake_data = (double)rand() / (RAND_MAX + 1.0)*10;   // create a fake x_axis data (random double number)
        d->set_x_axis(fake_data);                           // put it in data
        cout<< fake_data<<',';
        fake_data = (double)rand() / (RAND_MAX + 1.0)*10;   // create a fake x_axis data (random double number)
        d->set_y_axis(fake_data);                           // put it in data
        cout<< fake_data<<endl;
    }
    cout<<"DATAs in DATAPACK: "<<dp.data_size()<<endl;

    // serialize to array
    char buf[BUFSIZE]={0};
	dp.SerializeToArray(buf, BUFSIZE);

	cout<<"\n----- unPack it, and check data -----\n";
	// unpack, deserialize

    DATAPACK dp2;
    DATA d2;
    dp2.ParseFromArray(buf, BUFSIZE);

    for(int i=0; i<FAKE_DATA_COUNT; i++){
        d2 = dp2.data(i);
        cout<<"DATA "<<i<<": ";
        cout<<d2.x_axis()<<',';
        cout<<d2.y_axis()<<endl;
    }
    

    return 0;
}
