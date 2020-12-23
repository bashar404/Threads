#include <iostream>
#include<thread>
#include<chrono>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<ctime>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <bits/stdc++.h>
#include <list>
//#include <boost/iterator/counting_iterator.hpp>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;
int size_of_tx=1000000;

set<int> compare(set<int>s0, set<int>s1);
bool comp(int i, int j)
{
	return (i < j);
}

 //set<int>s[0];set<int>s[1];set<int>s[2];set<int>s[3];set<int>s[4]R;set<int>s;
 set<int> s[11];
 std::mutex m1;std::mutex m2;std::mutex m3;std::mutex m4;std::mutex m5;std::mutex m6;
void mempool1(ull start, ull last)
{
    std::srand(std::time(0));
   m1.lock();
    for(ull i=start; i<last; ++i)
    {
        s[0].insert(rand()%last);
    }
    m1.unlock();
 // cout<<"Mempool Transactions of Quorum member 1 : ";
  std::this_thread::sleep_for(chrono::seconds(0));
  cout<<"Q1: ";
    for(auto i:s[0])
        //cout<<"Tx"<<i<<",";
        cout<<"Tx"<<i<<",";
        cout<<"\n--------------------------------------------------------------------------\n";
    
}

void mempool2(ull start, ull last)
{
   // int j=1;
  // std::srand(std::time(0));
   m2.lock();
    for(ull i=start; i<last; ++i)
    {
        s[1].insert(rand()%last);
    }
    m2.unlock();
   // cout<<"Mempool Transactions of Quorum member 2 : ";
  std::this_thread::sleep_for(chrono::seconds(1));
  cout<<"Q2: ";
    for(auto i:s[1])
        //cout<<"Tx"<<i<<",";
        cout<<"Tx"<<i<<",";
        cout<<"\n--------------------------------------------------------------------------\n";
}

void mempool3(ull start, ull last)
{
   // int j=1;
   srand (time(NULL)%10);
    m3.lock();
    for(ull i=start; i<last; ++i)
    {
        s[2].insert(rand()%last);
    }
    m3.unlock();
   // cout<<"Mempool Transactions of Quorum member 3 : ";
  std::this_thread::sleep_for(chrono::seconds(2));
  cout<<"Q3: ";
    for(auto i:s[2])
        //cout<<"Tx"<<i<<",";
        cout<<"Tx"<<i<<",";
        cout<<"\n--------------------------------------------------------------------------\n";
}

void mempool4(ull start, ull last)
{
   // int j=1;
   std::srand(std::time(0)%100);
     m4.lock();
    for(ull i=start; i<last; ++i)
    {
        s[3].insert(rand()%last);
    }
    m4.unlock();
   // cout<<"Mempool Transactions of Quorum member 4 : ";
  std::this_thread::sleep_for(chrono::seconds(3));
    cout<<"Q4: ";
    for(auto i:s[3])
        //cout<<"Tx"<<i<<",";
        cout<<"Tx"<<i<<",";
        cout<<"\n--------------------------------------------------------------------------\n";
}

void mempool5(ull start, ull last)
{
   // int j=1;
   std::srand(std::time(0)%1000);
    m5.lock();
    for(ull i=start; i<last; ++i)
    {
        s[4].insert(rand()%last);
    }
  //  cout<<"Mempool Transactions of Quorum member 5 : ";
  std::this_thread::sleep_for(chrono::seconds(4));
    m5.unlock();
    cout<<"Q5: ";
    for(auto i:s[4])
        //cout<<"Tx"<<i<<",";
        cout<<"Tx"<<i<<",";
        cout<<"\n--------------------------------------------------------------------------\n";
}

void mempool6(ull start, ull last)
{
 std::srand(std::time(0)%10000);
    m6.lock();
    for(ull i=start; i<last; ++i)
    {
        s[5].insert(rand()%last);
    }
   // cout<<"Mempool Transactions of Quorum member 6 : ";
  std::this_thread::sleep_for(chrono::seconds(5));
    m6.unlock();
    cout<<"Q6: ";
    for(auto i:s[5])
        //cout<<"Tx"<<i<<",";
        cout<<"Tx"<<i<<",";
        cout<<"\n--------------------------------------------------------------------------\n";
}



void mempool7(ull start, ull last)
{
 std::srand(std::time(0)%100000);
    m6.lock();
    for(ull i=start; i<last; ++i)
    {
        s[6].insert(rand()%last);
    }
   // cout<<"Mempool Transactions of Quorum member 6 : ";
  std::this_thread::sleep_for(chrono::seconds(6));
    m6.unlock();
    cout<<"Q7: ";
    for(auto i:s[6])
        //cout<<"Tx"<<i<<",";
        cout<<"Tx"<<i<<",";
        cout<<"\n--------------------------------------------------------------------------\n";
}


void mempool8(ull start, ull last)
{
 std::srand(std::time(0)%1000000);
    m6.lock();
    for(ull i=start; i<last; ++i)
    {
        s[7].insert(rand()%last);
    }
   // cout<<"Mempool Transactions of Quorum member 6 : ";
  std::this_thread::sleep_for(chrono::seconds(7));
    m6.unlock();
    cout<<"Q8: ";
    for(auto i:s[7])
        //cout<<"Tx"<<i<<",";
        cout<<"Tx"<<i<<",";
        cout<<"\n--------------------------------------------------------------------------\n";
}


void mempool9(ull start, ull last)
{
 //std::srand(std::time(0)%1000000);
   srand((unsigned) time(0));
    m6.lock();
    for(ull i=start; i<last; ++i)
    {
        s[8].insert(rand()%last);
    }
   // cout<<"Mempool Transactions of Quorum member 6 : ";
  std::this_thread::sleep_for(chrono::seconds(7));
    m6.unlock();
    cout<<"Q9: ";
    for(auto i:s[8])
        //cout<<"Tx"<<i<<",";
        cout<<"Tx"<<i<<",";
        cout<<"\n--------------------------------------------------------------------------\n";
}



void mempool10(ull start, ull last)
{
 std::srand(std::time(0)%101);
    m6.lock();
    for(ull i=start; i<last; ++i)
    {
        s[9].insert(rand()%last);
    }
   // cout<<"Mempool Transactions of Quorum member 6 : ";
  std::this_thread::sleep_for(chrono::seconds(7));
    m6.unlock();
    cout<<"Q10: ";
    for(auto i:s[9])
        //cout<<"Tx"<<i<<",";
        cout<<"Tx"<<i<<",";
        cout<<"\n--------------------------------------------------------------------------\n";
}


void mempool11(ull start, ull last)
{
 std::srand(std::time(0)%10001);
    m6.lock();
    for(ull i=start; i<last; ++i)
    {
        s[10].insert(rand()%last);
    }
   // cout<<"Mempool Transactions of Quorum member 6 : ";
  std::this_thread::sleep_for(chrono::seconds(7));
    m6.unlock();
    cout<<"Q11: ";
    for(auto i:s[10])
        //cout<<"Tx"<<i<<",";
        cout<<"Tx"<<i<<",";
        cout<<"\n--------------------------------------------------------------------------\n";
}

int main()
{
 std::srand(std::time(0));
// srand (time(NULL));

    cout << "\t\tProof of Health!\n" << endl;
    ull start=0, last=100;
    auto startTime=high_resolution_clock::now();
    //mempool(1,100);
    cout<<"Mempool:"<<endl;
    cout<<"-------"<<endl;
        std::thread t1(mempool1,start,last);
        std::thread t2(mempool2,start,last);
        std::thread t3(mempool3,start,last);
        std::thread t4(mempool4,start,last);
        std::thread t5(mempool5,start,last);
        std::thread t6(mempool6,start,last);
        std::thread t7(mempool7,start,last);
        std::thread t8(mempool8,start,last);
        std::thread t9(mempool9,start,last);
        std::thread t10(mempool10,start,last);
        std::thread t11(mempool11,start,last);

    if(t1.joinable())
        t1.join();
    if(t2.joinable())
        t2.join();
    if(t3.joinable())
        t3.join();
    if(t4.joinable())
        t4.join();
    if(t5.joinable())
        t5.join();
    if(t6.joinable())
        t6.join();
    if(t7.joinable())
        t7.join();
    if(t8.joinable())
        t8.join();
    if(t9.joinable())
        t9.join();
    if(t10.joinable())
        t10.join();
    if(t11.joinable())
        t11.join();




    auto stopTime=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stopTime-startTime);
    cout<<"\nsec: "<<duration.count()/1000000<<endl;

  set<int>j1;set<int>j2;set<int>j3;set<int>j4;set<int>j5;set<int>j6;set<int>j7;set<int>j8;set<int>j9;set<int>j10;set<int>j11;


    set<int> newS[11];
    for(int i = 0; i < 11; i++)
        newS[i] = s[i];
    for(int id = 0; id < 11; id++){
        set<int>j[11];
        cout<<"\nMissing Tx's for Q"<<id+1<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~"<<endl;
        for(int index = 1; index < 11; index++){

            j[index] = compare(newS[id], s[(index + id) % 11]);
            for(auto missing : j[index]){
                newS[id].insert(missing);
            }
        }
    }
    for(int id = 0; id < 11; id++){
            cout<<"MB of Q"<<id+1<<"::";
        for(auto i:newS[id])
            cout<<" Tx"<<i<<",";
            cout<<"."<<endl;
    }


    //  //Master Block
    for(int i = 0; i < 11; i++){
        for(int k = 0; k < 11; k++){
            if(newS[i] == newS[k]){
                printf("sets: true\n");
            }else
            {
                printf("sets: false\n");
                std::set<int>::iterator it2 = newS[k].begin();
                for(std::set<int>::iterator it1 = newS[i].begin();it1 != newS[i].end(); it1++){
                    printf("\ns[%d]: %d  s[%d]: %d",k,*it1,i, *it2);
                it2++;
                }
            }
        }
    }



    return 0;
}

set<int> compare(set<int>s0, set<int>s1)
{
        auto it11 = s0.begin();
        auto it12 = s1.begin();
        set<int> j1,j2;
        while( it11 != s0.end() && it12 != s1.end() )
        {
            if( *it11 < *it12 ) {
                j1.insert( *it11++ );
            } else if( *it12 < *it11 ) {
                j2.insert( *it12++ );
            } else {
                it11++;
                it12++;
            }
        }
        while(it12 != s1.end()){
            j2.insert( *it12++ );
        }
 for(auto i:j2)
    cout<<"Tx"<<i<<", ";
    cout<<"."<<endl;
    return j2;
}
