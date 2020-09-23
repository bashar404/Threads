//Deadlock
//To prevent Deadlock we should not change the order of mutex lock
    
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif>
#include <cstdlib>

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m1,m2;

void thread1()
{
    m1.lock();
        sleep(3);
    m2.lock();
    cout<<"Critical section of thread1"<<endl;
    m1.unlock();
    m2.unlock();
}

void thread2()
{
    m2.lock();   ////To prevent Deadlock we should not change the order of mutex lock
        sleep(3);
    m1.lock();   ////To prevent Deadlock we should not change the order of mutex lock
    cout<<"Critical section of thread2"<<endl;
    m2.unlock();
    m1.unlock();
}

int main()
{
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
}
