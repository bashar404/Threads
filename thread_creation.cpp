//Types of threads creation in c++ 11 (5 types we can create threads in C++ 11 using callable Object)
//**NOTE: If we create multiple threads at the same time it doesn't guarntee which one will start first
#include<iostream>
#include<thread>
using namespace std;
    void fun(int x)
    {
    while(x-->0)   //9876543210  --> is not an operator. It is in fact two separate operators, -- and >
        cout<<x<<endl;  //while( (x--) > 0 )
    }
    

int main()
{
//1. Function pointer
thread t1(fun, 10); //9876543210  function name fun use as funtion pointer
thread t2(fun, 12); //1110987654321
t1.join();
t2.join();


}
