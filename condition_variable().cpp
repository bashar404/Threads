// A condition variable is an object able to block the calling thread until notified to resume.
// It uses a unique_lock (over a mutex) to lock the thread when one of its wait functions is called. The thread remains blocked until woken up by another thread that calls a notification function on the same condition_variable object.
// Member functions: wait, wait_for, wait_until, notify_one, notify_all

/*
TOPIC: Condition Variable In C++ Threading

NOTES:
1. Condition variables allow us to synchronize threads via notifications.
   a. notify_one();
   b. notify_all();
2. You need mutex to use condition variable
3. Condition variable is used to synchronize two or more threads.
4. Best use case of condition variable is Producer/Consumer problem.
5. Condition variables can be used for two purposes:
    a. Notify other threads
    b. Wait for some condition*/
    
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif>
#include <cstdlib>

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

int balance=0;
mutex m;
condition_variable cv;

void addMoney(int amount)
{
    unique_lock<mutex>lock(m);
    balance=balance+amount;
    cout<<"Current amount is "<<balance<<endl;
    cv.notify_one();    
}

void withdraw (int amount)
{
    unique_lock<mutex>lock(m);   //must be same mutex
    cv.wait( lock, [] {return (balance!=0? true : false); } );
    if(balance>amount)
    {
       int updated_amount=balance-amount;
        cout<<"Amount deduct: "<<amount<<","<<"New balance: "<<updated_amount<<endl;
    }
    else
        cout<<"You dont have sufficient amount";
}


int main()
{
    thread t1(withdraw,500);
    sleep(5);
    thread t2(addMoney,600);
    t1.join();
    t2.join();
}
