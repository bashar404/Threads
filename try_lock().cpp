//mutex::try_lock() in C++ threading
//m.lock() is kind of blocking call and m.try_lock() is non blocking call

//if don't able to lock the mutex m.try_lock() return false

/*


0. try_lock() Tries to lock the mutex (not actually lock the mutex). Returns immediately. On successful lock acquisition returns true otherwise returns false.
1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
2. If try_lock is called again by the same thread which owns the mutex, the behavior is undefined.
   It is a dead lock situation with undefined behavior. (if you want to be able to lock the same mutex by same thread more than one time the go for recursive_mutex)

There are so many try_lock function
1. std::try_lock
2. std::mutex::try_lock
3. std::shared_lock::try_lock
4. std::timed_mutex::try_lock
5. std::unique_lock::try_lock
6. std::shared_mutex::try_lock
7. std::recursive_mutex::try_lock
8. std::shared_timed_mutex::try_lock
9. std::recursive_timed_mutex::try_lock
*/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int counter=0; //global variable thus access by each thread
mutex m;

    void increaseTheCounterFor1000times()
    {
        for(int i=0; i<1000; i++)
        {
            if(m.try_lock())
            {
                ++counter;
                m.unlock();
            }
        }
    }
int main()
{
    thread t1(increaseTheCounterFor1000times);
    thread t2(increaseTheCounterFor1000times);
    
    t1.join();
    t2.join();
    
    cout<<"Value of counter is "<<counter;  // sometimes 632, 708, 1910, 2000 etc 
    
    //If we want 2000 all the time then
    /*
    void increaseTheCounterFor1000times()
    {
        for(int i=0; i<1000; i++)
        {
                m.try_lock();
                ++counter;
                m.unlock();
        }
    }
    */
}









