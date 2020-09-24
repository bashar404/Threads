#include<thread>
#include<mutex>
#include<condition_variable>
#include<deque>
#include <iostream>
#define MAX_BUFFER_SIZE 50
using namespace std;
mutex m;
condition_variable cv;
deque<int> buffer;

//double buffer_size=0;

void producer (int value)
{
    while(value)
    {
        unique_lock<mutex>lock(m);
        cv.wait(lock, [] () { return (buffer.size()<MAX_BUFFER_SIZE );} );
        buffer.push_back(value);
        cout<<"Produced: "<<value<<endl;
        value--;
        lock.unlock();
        cv.notify_one();      
    }
}

void consumer()
{
    while(true)
    {
        unique_lock<mutex>lock(m);
        cv.wait(lock, [] () { return (buffer.size()>0);} );
        buffer.pop_back();
        int value=buffer.back();
        cout<<"Consumed: "<<value<<endl;
        lock.unlock();
        cv.notify_one();
    }
}


int main() 
{
  thread t1(producer,100);
  thread t2(consumer);
  t1.join();
  t2.join();
  return 0;
}
