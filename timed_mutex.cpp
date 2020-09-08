/*

TOPIC: Timed Mutex In C++ Threading (std::timed_mutex)
We have learned Mutex, Race Condition, Critical Section in previous videos.

NOTES:
0. std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if success 
   otherwise false.
1. Member Function:
   a. lock 
   b. try_lock
   c. try_lock_for    ---\ These two functions makes it different from mutex.
   d. try_lock_until  ---/ 
   e. unlock

EXAMPLE: try_lock_for();
Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
On successful lock acquisition returns true, otherwise returns false.

*/

#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;


#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>

int counter=0; //global variable thus access by each thread
timed_mutex m; //important timed_mutex

    void timeLock(int i)
    {
        if(m.try_lock_for( chrono::seconds(1) ) )   //sleep(1) is not working //if any thread gets the access others mudt need to wait
        {
            cout<<"Thread "<< i <<" has entered"<<endl;
            sleep(2);
            ++counter;
            m.unlock();
        }
        
        else
            cout<<"Thread "<< i <<" couldn't entered"<<endl;
    }

/*Thread 1 has entered
  Thread 2 couldn't entered*/


    void increment(int i)
    {
        if(m.try_lock_for( chrono::seconds(2) ) )   //sleep(1) is not working //if any thread gets the access others mudt need to wait
        {
            cout<<"Thread "<< i <<" has entered"<<endl;
            sleep(1);
            ++counter;
            m.unlock();
        }
        
        else
            cout<<"Thread "<< i <<" couldn't entered"<<endl;
    }
    
    /*Thread 2 has entered
      Thread 1 has entered*/

int main()
{
    thread t1(timeLock,1);
    thread t2(timeLock,2);
    
    t1.join();
    t2.join();
    
    cout<<counter<<endl;   //1
    
    thread t3(increment,1);
    thread t4(increment,2);
    
    t3.join();
    t4.join();
    
    
    cout<<counter<<endl;   //3
}


