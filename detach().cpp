//Topic: detach() and joinable() in therad in C++ (C++ 11)
//detach
//1. detach newly created thread from parent thread (without thread main() is the only thread exist in a program-->called parent thread)
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>


#include<iostream>
#include<thread>
using namespace std;
void fun(int x)
{
    while(x-->0)
        cout<< x << "Golam D Bashar" << endl;
    // cout<<"going to sleep"<<endl;
    // sleep(3);  
    cout<<"Thread finished"<<endl;
}

int main()
{
    thread t1(fun,5);
    cout<<"prog start"<<endl;
    t1.detach(); //detach() is mainly useful when you have a task that has to be done in background, but you don't care about its
    cout<<"going to sleep"<<endl;
    sleep(3);  
    cout<<"Wake up"<<endl;

}
