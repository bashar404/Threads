 /*TOPIC: Thread OR Process Synchronization
NOTE: we will use only thread examples to explain this topic.

POINTS:
1.0 Thread Or Process synchronize to access critical section.
2.0 Critical section is one or collection of program statements which should be executed by only one thread or process at a time.
Critical section only happen to shared (common) resorce between more than 2 threads.
if reading only cout<<shared (common) resorce that is not the critical section, it arise when we try to write on shared (common) resorce

TOPIC: std::lock() In C++11

It is used to lock **MULTIPLE** mutex at the same time.

IMPORTANT:
styntax: std::lock(m1, m2, m3, m4);
1. All arguments are locked via a sequence of calls to lock(),  try_lock(), or unlock() on each argument.
2. Order of locking is not defined (it will try to lock provided mutex in any order and ensure that
    there is no dead lock).
3. It is a blocking call.


[Example:0] -- No deadlock.
    Thread 1                    Thread 2
    std::lock(m1,m2);           std::lock(m1,m2);

[Example:1] -- No deadlock. 

    Thread 1                    Thread 2
    std::lock(m1, m2);          std::lock(m2, m1);

[Example:2] -- No deadlock. 

    Thread 1                    Thread 2
    std::lock(m1, m2, m3, m4);  std::lock(m3, m4);
                                std::lock(m1, m2);

[Example:3] -- Yes, the below can deadlock. 

    Thread 1                    Thread 2
    std::lock(m1,m2);           std::lock(m3,m4);
    std::lock(m3,m4);           std::lock(m1,m2);
*/

#include<thread>
#include<mutex>
#include<iostream>
using namespace std;

int balance=0;
mutex m;

void update_balance (long amount)
{
m.lock();
balance=balance+amount;
m.unlock();
}

int main()
{
    thread t1(update_balance,100);
    thread t2(update_balance,200);
    t1.join();
    t2.join();
    cout<<"Final balance: "<<balance;
}
