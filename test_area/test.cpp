#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <unistd.h>
using namespace std;
using namespace std::chrono;
int main()
{
    cout<<"===================\ntest start!\n";
    // set random seed
    auto start = high_resolution_clock::now();
    usleep(1000000);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"duration: "<<(double)duration.count()/1000000<<endl;


    srand(time(NULL));
    cout<<rand()%8192<<endl;
    return 0;
}