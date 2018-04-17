/*!
 * \author Zoltan Fuzesi - C00197361
 * \version 1.0
 * \date 02/10/2017
 *
 * \copyright GNU Public License
 *
 * \mainpage Lab 3
 * \section name_sec Software Engineering
 * Lab 3, ConDev - Joseph Kehoe
 * \subsection info_sec Lab 3 - Description
 * The main method creates fived threads and four of them will call the mutexOne and the mutexTwo functions.#
 * In those two functions each thread will goes through in the loop ten times and increase the shared variable
 * value by one. The last thread only will call the printShared Variable function, which is displaying the
 * shared variable value changed by the threads. The size of the loop can be changed in the mutex functions
 * and that will increase of decrease the shared variable value.
 * Debug function added to the makefile. to use debugger:
 * 1. open terminal
 * 2. navigate to the folder where mutex lab is created
 * 3. Type in : gdb mutex  - to start the debugger function.
 * The Makefile runs the Doxygen to generate the documentation when the project build
 *
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>



/*!
 * \brief Description of the void mutexOne function
 * \param theSemaphore is in the parameter list type of thread
 * \details MutexOne function.
 *  The function is receiving a shared pointer type of thread and the pointer to the shared variable.
 *  In the function the thread goes trough in the for loop ten times and increasing the shared variable by one.
 */
void mutexOne(std::shared_ptr<Semaphore> theSemaphore, int *x)
{
  for (int i = 0; i < 10; i++)
  {
    std::cout << "Mutex one loop " << i << '\n';
    theSemaphore->Wait();
    *x = *x + 1;
    std::cout << "Mutex count " << *x << '\n';
    theSemaphore->Signal();
  }
}


/*!
 * \brief Description of the void mutexTwo function
 * \param theSemaphore is in the parameter list type of thread
 * \details MutexTwo function.
 *  The function is receiving a shared pointer type of thread and the pointer to the shared variable.
 *  In the function the thread goes trough in the for loop ten times and increasing the shared variable by one.
 */
void mutexTwo(std::shared_ptr<Semaphore> theSemaphore, int *x)
{

  for (int i = 0; i < 10; i++)
  {
     std::cout << "Mutex two loop " << i << '\n';

    theSemaphore->Wait();
    *x = *x + 1;
    std::cout << "Mutex count " << *x << '\n';
    theSemaphore->Signal();
  }
}




/*!
 * \brief Description of the main function
 * \param thread threadOne is the first thread
 * \param thread threadTwo is the second thread
 * \param thread threadThree is the third thread
 * \param thread threadFour is the fourth thread
 * \param thread threadFive is the fifth thread
 * \details Main function of mutex
 *  The main method creates two threads and call the mutexOne & mutexTwo functions and passing the threads and the
 *  shared int (count) variable addres to the functions.
 */
int main(void){

  int count = 0;
  std::thread threadOne, threadTwo;

   std::shared_ptr<Semaphore> a( new Semaphore);
   std::shared_ptr<Semaphore> b( new Semaphore);
   std::cout << "Threads are created" << '\n';
   threadTwo=std::thread(mutexOne,a,&count);
   threadOne=std::thread(mutexTwo,b,&count);




  threadOne.join();
  threadTwo.join();

  std::cout << "All threads joined" << '\n';
  std::cout << "Count value is : " << count <<'\n';

  return 0;

}
