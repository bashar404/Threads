/*TOPIC: unique_lock In C++

NOTES:
1. The class unique_lock is a mutex ownership wrapper.
2. It Allows:
    a. Can Have Different Locking Strategies
    b. time-constrained attempts at locking (try_lock_for, try_lock_until)
    c. recursive locking
    d. transfer of lock ownership (move not copy)
    e. condition variables. (See this in coming videos)

Locking Strategies
   TYPE           EFFECTS(S)
1. defer_lock  do not acquire ownership of the mutex.
2. try_to_lock  try to acquire ownership of the mutex without blocking.
3. adopt_lock  assume the calling thread already has ownership of the mutex.
*/
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int addAmount=0, buffer=0;
mutex m,m1;

void addMoney()
{
    //m.lock();
    unique_lock<mutex> lock(m); //A unique lock is an object that manages a mutex object with unique ownership in both states: locked and unlocked.
    ++addAmount;
    //m.unlock();  //lock kore unlock na korle t2 kokonoi code run korte parto na
                  
}

void increment(const char* threadNumber, int loop_for)
{
    unique_lock<mutex> lock(m1);
    for(int i=0; i<loop_for; i++)
    {
        ++buffer;
        cout<<threadNumber<<": "<<buffer<<endl;   //T3:1,2,..10   T4:11,..20
    }
}


void increment_with_deffer_lock(const char* threadNumber, int loop_for)
{
    unique_lock<mutex> lock(m1,defer_lock);
    //..lines of code..//
    //..lines of code..//
    //..lines of code..//
    lock.lock();
    for(int i=0; i<loop_for; i++)
    {
        ++buffer;
        cout<<threadNumber<<": "<<buffer<<endl;   //T3:1,2,..10   T4:11,..20
    }
}


int main()
{
    thread t1(addMoney);
    thread t2(addMoney);
    t1.join();
    t2.join();
    cout<<addAmount;     //2
    
    thread t3(increment, "T3", 10);
    thread t4(increment, "T4", 10);
    t3.join();
    t4.join();
    
    thread t5(increment_with_deffer_lock, "T5", 10);
    thread t6(increment_with_deffer_lock, "T6", 10);
    t5.join();
    t6.join();
}













