/******************************************************************************
DESCRIPTION :
 async is a good way to do some job in the background just one or multiple times while main thread keeps doing its stuff.
The function template async runs the function f asynchronously (potentially in a separate thread 
async means function findOdd also run and main() also run simultaneously in a new thread

 *******************************************************************************/
#include<thread>
#include<future>
#include<iostream>

using namespace std;

double findOdd( double start, double end)
{
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "thread id on findOdd " << this_id << "\n";
    
    double oddSum=0;
    for(int i=start; i<end; i++)
    {
        if(i&1==1)
            oddSum=oddSum+i;
    }
    return oddSum;
}

int main()
{
    double start=0, end=1900000000;
    cout<<"Thread created if policy is async"<<endl;
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "thread id on main() " << this_id << "\n";
 //deferred will not create a thread
 //cpu decide if we write launch::async | launch::deferred
    future<double> f = async (launch::async, findOdd, start,end);  //deferred
    cout<<"Calculating"<<endl;
    cout<<"Result: "<<f.get();
    
    return 0;
}

// Thread created if policy is async                                                    
// thread id on main() 140530747238272                                                  
// Calculating                                                                          
// thread id on findOdd 140530730292992                                                 
// Result: 9.025e+17 

//deferred gave the op
/*thread id on main() 140270518450048                                                  
Calculating                                                                          
thread id on findOdd 140270518450048                                                 
Result: 9.025e+17   */
