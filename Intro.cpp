//Every C++ program has at least one thread, which is started by the C++ runtime: int main(). 
//Bydefault c++ program is a single thread program. If we want to create another thread we need to create inside the main()
//What is concurrency? concurrency is about two or more separate activities happening at the same time.
//Ex: The browser has multiple tabs & this can be consider as different threads as 
//Ex: MS word (while typing it format our text and do spell checking)
//Ex: Auto suggestion #include<..>
//So what is a thread? A thread is a working unit of a particular process.
//Multithreading support was introduced in C+11.
//Compilers Required:  Windows: Visual Studio 2012 and MingW


/*WAYS TO CREATE THREADS IN C++11
1. Function Pointers
2. Lambda Functions
3. Functors
4. Member Functions
5. Static Member functions */
#include <iostream>
#include <thread>
#include <chrono>
//Chrono library is used to deal with date and time. This library was designed to deal with the fact that timers and clocks might be different on 
//different systems and thus to improve over time in terms of precision.
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef long long int  ull;
 
void findEven(ull start, ull end, ull* EvenSum) {
	for (ull i = start; i <= end; ++i){
		if (!(i & 1)){
			*(EvenSum) += i;
		}
	}
}
 
void findOdd(ull start, ull end, ull* OddSum) {
	for (ull i = start; i <= end; ++i){
		if (i & 1){
			(*OddSum) += i;
		}
	}
}
int main() {
 
	ull start = 0, end = 1900000000;
 
	ull OddSum = 0;
	ull EvenSum = 0;
 
   auto startTime = high_resolution_clock::now(); // To measure time
 
	// WITH THREAD
    thread t1(findEven, start, end, &(EvenSum));  //thread creater er somoy fun er nam er sathe parameter o pass korte hobe
    thread t2(findOdd, start, end, &(OddSum));
 
	t1.join();
	t2.join();
 
	// // WITHOUT THREAD
//  findEven(start,end, &EvenSum);
//  findOdd(start, end, &OddSum);
 auto stopTime = high_resolution_clock::now(); // To measure time 
auto duration = duration_cast<microseconds>(stopTime - startTime);
 
	cout << "OddSum : " << OddSum << endl;
	cout << "EvenSum : " << EvenSum << endl;
 
cout << "Sec: " << duration.count()/1000000 << endl;  //converting to sec
	
	/*
    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
			//code    
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	*/
 
	return 0;
}
