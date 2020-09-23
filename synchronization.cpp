 /*TOPIC: Thread OR Process Synchronization
NOTE: we will use only thread examples to explain this topic.

POINTS:
1.0 Thread Or Process synchronize to access critical section.
2.0 Critical section is one or collection of program statements which should be executed by only one thread or process at a time.
Critical section only happen to shared (common) resorce between more than 2 threads.
if reading only cout<<shared (common) resorce that is not the critical section, it arise when we try to write on shared (common) resorce
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
