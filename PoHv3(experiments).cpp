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
#include <random>
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

void mempool(int id, int start, int last, int seed, set<int>* s)
{
    //Random rand = new Random(seed);
    default_random_engine gen;
    gen.seed(seed);
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for(int i=start; i<last; ++i)
    {
//        if(dist(gen) < 0.8)
//            s -> insert(i);

        s -> insert(int(dist(gen)*last));
    }

}


int main()
{
    cout << "\t\tProof of Health!\n" << endl;
    auto startTime=high_resolution_clock::now();

    int sizes[] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,1000};
    double txMultiplier[] = {1.5};
    for(auto mult : txMultiplier){
        for(auto networkSize : sizes){

            int debug = 0;
            int q_size= ceil(log2(networkSize)) + 1;

            set<int> s[q_size];
            cout << q_size << endl;
            std::srand(std::time(0));
        // srand (time(NULL));

            int start = 0, last = networkSize * mult;
            //mempool(1,100);
    //        cout<<"Mempool:"<<endl;
    //        cout<<"-------"<<endl;
            thread* t[q_size];

            //Random r[q_size]
            srand(time(0));
            for(int i = 0; i < q_size; i++){
                t[i] = new thread(mempool, i, start, last, rand(), &(s[i]));
            }

            for(int i = 0; i < q_size; i++){
                t[i] -> join();
                delete t[i];
            }
            cout << networkSize << ",";
            for(int i = 0; i < q_size; i++){
                cout << i+1 << ", ";
            }
            cout << endl << "skeleton block, ";
            for(int i = 0; i < q_size; i++){
                cout << ull(s[i].size())* (q_size-1) << ", ";
            }
            if(debug == 1){
                cout<<"Mempool Transactions of Quorum member 1 : ";
                cout<<"Q1: ";
                for(auto i:s[0])
                    cout<<"Tx"<<i<<",";
               // cout<<"Tx"<<i<<",";
                cout<<"\nTotal no of Transactions (SB): "<< s[0].size()* (q_size-1) <<endl;
                cout<<"\n--------------------------------------------------------------------------\n";
            }

            ull requests[q_size];
            ull tx[q_size];
            ull receipt[q_size];
            ull sigs[q_size];

            for(int i = 0; i < q_size; i++){
                requests[i] = tx[i] = 0;
                receipt[i] = q_size - 1;
                sigs[i] = 2*(q_size - 1);
            }


        //    cout<<"\nsec: "<<duration.count()/1000000<<endl;


            set<int> newS[q_size];
            for(int i = 0; i < q_size; i++)
                newS[i] = s[i];
            for(int id = 0; id < q_size; id++){
                set<int>j[q_size];
                if(debug == 1){
                    cout<<"\nMissing Tx's for Q"<<id+1<<endl;
                    cout<<"~~~~~~~~~~~~~~~~~~~"<<endl;
                }
                for(int index = 1; index < q_size; index++){
                    bool messagesNeeded = false;
                    j[index] = compare(newS[id], s[(index + id) % q_size]);
                    for(auto missing : j[index]){
                        newS[id].insert(missing);
                        requests[id]++;
                        tx[(index + id) % q_size]++;
                        messagesNeeded = true;
                    }
                    if(messagesNeeded){
                        sigs[id] += 2;
                        receipt[id]++;
                        sigs[(index + id) % q_size]++;
                    }
                    else{
                        sigs[id]++;
                    }
                }



                if(debug == 1) cout<<"\nRequest Transmission: " << requests[id] <<endl;
            }
            if(debug == 1){
                for(int id = 0; id < q_size; id++){
                        cout<<"MB of Q"<<id+1<<"::";
                    for(auto i:newS[id])
                        cout<<" Tx"<<i<<",";
                    cout<<"."<<endl;
                }
            }

            cout << endl << "requests, ";

            for(int i = 0; i < q_size; i++){
                cout << requests[i] << ", ";
            }
            cout << endl << "transactions, ";

            for(int i = 0; i < q_size; i++){
                cout << tx[i] << ", ";
            }
            cout << endl << "receipts, ";

            for(int i = 0; i < q_size; i++){
                cout << receipt[i] << ", ";
            }
            cout << endl << "sigs, ";

            for(int i = 0; i < q_size; i++){
                cout << sigs[i] << ", ";
            }
            cout << endl;
            //  //Master Block
            for(int i = 0; i < q_size; i++){
                for(int k = 0; k < q_size; k++){
                    if(newS[i] == newS[k]){
                        if(debug == 1)
                            printf("sets: true\n");
                    }
                    else{
                        printf("sets: false\n");
                        std::set<int>::iterator it2 = newS[k].begin();
                        for(std::set<int>::iterator it1 = newS[i].begin();it1 != newS[i].end(); it1++){
                            printf("\ns[%d]: %d  s[%d]: %d",k,*it1,i, *it2);
                        it2++;
                        }
                    }
                }
            }
        }
    }
    auto stopTime=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stopTime-startTime);

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
    return j2;
}
