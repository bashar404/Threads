//Topic: Use of join() double join and joinable() in therad in C++ (C++ 11)
//join
//1.Once a thread is started we wait until this finish
//2.Double join will result into program termination.
//3.We should check wheather it is joinable or not
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
        cout<< "Golam D Bashar" << endl;
        cout<<"going to sleep"<<endl;
        sleep(3); //Sleep (): C++ language does not provide a sleep function of its own. However, the os specific files like unistd.h for Linux and Windows.h for Windows provide this functionality
}

int main()
{
    thread t1(fun,5);
    cout<<"prog start"<<endl;
    t1.join();
   // t1.join();  /*double join o/p fail to run*/
    cout<<"Wake up"<<endl;

    if(t1.joinable()) //not running this section but help to not fail
       t1.join();
}
