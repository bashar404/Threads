#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m;
int buffer=0;
int buffer1=0;

void task(char t, int no_for_loop)
{
  m.lock();
  for(int i=0; i<no_for_loop; i++)
  {
    buffer++;
    cout<<"thead " <<t  <<" buffer "<<buffer  <<endl;
  }
  m.unlock();
}



void task2(char t, int no_for_loop)
{

lock_guard<mutex>lock(m);  //removing lock() and unlock()
 // m.lock();
  for(int i=0; i<no_for_loop; i++)
  {
    buffer1++;
    cout<<"thead " <<t  <<" buffer1 "<<buffer1  <<endl;
  }
 // m.unlock();
}

int main()
{
  thread t1(task, 't1', 10);
  thread t2(task, 't2', 10);

  t1.join();
  t2.join();



  thread t3(task2, 't3', 10);
  thread t4(task2, 't4', 10);

  t3.join();
  t4.join();
}
