/*!
 * \author Zoltan Fuzesi - C00197361
 * \version 1.0
 * \date 02/10/2017
 *
 * \copyright GNU Public License
 *
 * \mainpage Lab 5
 * \section name_sec Software Engineering
 * Lab 5, ConDev - Joseph Kehoe
 * \subsection info_sec Lab 5 - Description
 * A producer and a consumer.
 * The producer generates random characters from 097 to 122 ‘a’ to ‘z’ at random intervals (between 0 and 1 second in length). <br>
 * It adds these to a thread safe buffer that has a finite holding capacity of N characters.<br>
 * It generates a preset number of characters (determined at runtime) and when it has finished it add an ‘X’ <br>
 * character to the buffer and exits.The consumer takes these letters from the buffer at random time intervals <br>
 * (between 0 and 1 second in length) and records how many of each letter it consumes.<br>
 * Once it sees an ‘X’ in the buffer it adds its character count to a central buffer and exits.
 *
 */

#include "SafeBuffer.h"
#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <unistd.h>




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
void produce(std::shared_ptr<SafeBuffer> Buffer){
  
    //int num = rand()%21+10;
    int num = rand()%26;
    //std::cout << "The number is " << std::to_string(num) << "\n";

    
    Buffer->produce(num, std::this_thread::get_id());
}

void consume(std::shared_ptr<SafeBuffer> Buffer){
  
 
    Buffer->consume();
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
    pid_t ppid;
    
    SafeBuffer sb;
    
    
    
    ppid = getppid();
    sb.show_pid(ppid);
    cout << "The pid is " << ppid <<"\n";
    
    int bufferSize = 0;
    int numberOfThreadsInThebuffer = 39;
    
    std::shared_ptr<SafeBuffer> bufferObj(new SafeBuffer(bufferSize,numberOfThreadsInThebuffer));
    std::vector<std::thread> threadVector;

    for (int i = 0; i < numberOfThreadsInThebuffer; i++) {

      threadVector.push_back(std::thread(produce, bufferObj));
    }
    

    for (int i = 0; i < numberOfThreadsInThebuffer; i++) {

      threadVector.push_back(std::thread(consume, bufferObj));
    }
    
    for (auto& th : threadVector) 
    {
        th.join();
    }
    
    

    cout << "All threads are finished!!!" << "\n";
    return 0;
}

///* main.cpp ends here */
