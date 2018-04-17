/*!
 * \author Zoltan Fuzesi - C00197361
 * \version 1.0
 * \date 02/10/2017
 *
 * \copyright GNU Public License
 *
 * \mainpage Lab 4
 * \section name_sec Software Engineering
 * Lab 4, ConDev - Joseph Kehoe
 * \subsection info_sec Lab 4 - Description
 * Reusable Barrier Class Create a reusable barrier that employs the Semaphore Class. 
 * The build function generating the Doxyfile. 
 * The make rule include a “clean” rule that deletes all .o files from the project and a debug option 
 * that allows use of the gdb debugger. 
 * The -Wall flag added to the list of compiler flags sued by the Debug rule.
 */


#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>
#include <list>
using namespace std;

static int NUMBER_OF_LOOP = 5;

/*!
 * \brief Description of the void barrier function
 * \param BarrierObj is in the parameter list is type of thread-barrier object
 * \details barrier function.
 *  The function is receiving a shared pointer type of thread-barrier object .
 *  The BarrierObj (threads) are calling the barrierOne after the barrierTwo function, what is a
 *  public method in the barrier class. 
 *  In the function all thread goes trough in the for loop NUMBER_OF_LOOP times.
 */
void barrier(std::shared_ptr<Barrier> BarrierObj){
  
    for(int i=0;i<NUMBER_OF_LOOP;i++){
        BarrierObj->barrierOne();
        cout << "Thread left barrier one " << "\n";
        BarrierObj->barrierTwo();
        cout << "Thread left barrier two " << "\n";
        cout << "Restart loop " << i << "\n";
    }
}

/*!
 * \brief Description of the main method
 * \param numberOfThreadsInTheBarrier is a number of passing to the barrier class
 * represents the threads are going through the barriers
 * \details barrier function.
 * \param shared_ptr<Barrier>barrierObj is a shared pointer of a Barrier object
 * \param vector<std::thread>threadVector is a vector to create threads.
 *  The for loop creates a numberOfThreadsInTheBarrier threads and push into the vector and the
 * threads are calling the barrier function at creation time
 */
int main(void){
    int numberOfThreadsInTheBarrier = 5;
    
    std::shared_ptr<Barrier> barrierObj(new Barrier(numberOfThreadsInTheBarrier));
    std::vector<std::thread> threadVector;

    for (int i = 0; i < numberOfThreadsInTheBarrier; i++) {
      cout << "Loop " << i << "\n";
      threadVector.push_back(std::thread(barrier, barrierObj));
    }
    
    for (auto& th : threadVector) 
    {
        th.join();
    }

    cout << "All threads are finished!!!" << "\n";
    return 0;
}

///* main.cpp ends here */