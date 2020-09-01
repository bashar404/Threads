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
    

    auto lam_fun = [](int x)
    {
    while(x-->0)
        cout<< x  <<endl;
    };

    class Base
    {
    public:
        static void sta_fun(int x)
        {
            while(x-->0)
                cout<< x <<endl;
        }
    };

int main()
{
//1. Function pointer
thread t1(fun, 10); //9876543210  function name fun use as funtion pointer
thread t2(fun, 12); //1110987654321
t1.join();
t2.join();

//2. Lamda
thread t3(lam_fun,5);  //433210
t3.join();

thread t4([](int x)   //LAMDA INSIDE
{
    while(x-->0)
        cout<< x  <<endl;
},3);
t4.join();  //210
    
    
//3. Static member funtion
thread t5(&Base::sta_fun, 10);
t5.join(); //987654321

}
