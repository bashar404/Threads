//Topic: Mutex in C++ Threading
//Mutex: Mutual Exclusion
//RACE CONDITION:
//0. A race condition occurs when two or more threads can access shared data and they try to <<**CHANGE**>> it at the same time. IF they only access those data means no race condition. To have race condition, must need to update those share or common data.
//1. If there is a race condition we have to protect it and protection section is called critical section/region

//When we have critical section we will have Mutex to avoid race condition
//We use lock() and unlock() on mutex to avoid race condition
#include <iostream>
#include<thread>
#include <mutex>
using namespace std;

int addAmount=0;  //global that's why its common, if it's local and put inside the addMoney() no race condition
mutex m;
void addMoney()
{
  m.lock();
  ++addAmount;  //race condition is only this line <<critical section/region>>
  m.unlock();
}

int main() 
{
 thread t1(addMoney);  //no parameter is passing as addMoney() doesn't have any
 thread t2(addMoney);

 t1.join();
 t2.join();

 cout<<addAmount;
}
