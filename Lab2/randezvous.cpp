/*!
 * \author Zoltan Fuzesi - C00197361
 * \version 1.0
 * \date 02/10/2017
 *
 * \copyright GNU Public License
 *
 * \mainpage Lab 2
 * \section name_sec Software Engineering
 * Lab 2, ConDev - Joseph Kehoe
 * \subsection info_sec Lab 1 - Description
 * Randezvous implementation. Whatever first thread arrives to the function that increasing the counter variable by one
 * and after must wait until the other thread in the other function calling the xWait funtion which is decreasing the counter and
 * let the thread to executing ahead because the signal from that point will be Zero.
 *
 * The Makefile runs the Doxygen to generate the documentation when the project has built  
 *
 */
#include "Semaphore.h"
#include <iostream>
#include <thread>

/*!
 * \brief Description of the void randezvousA function
 * \param theSemaphore is in the parameter list is a shared_ptr type of Semaphore
 * \details This function called by the first thread 
 */
void randezvousA(std::shared_ptr<Semaphore> aThread)
{
  std::cout << "Randezvous A1" << '\n';
  aThread->aSignal();
  aThread->bWait();
  std::cout << "Randezvous A2" << '\n';
}

/*!
 * \brief Description of the void randezvousB function
 * \param bThread is in the parameter list is a  shared_ptr type of Semaphore
 * \details This function called by the second thread
 */
void randezvousB(std::shared_ptr<Semaphore>bThread)
{
  std::cout << "Randezvous B1" << '\n';
  //bThread->aWait();
  bThread->bSignal();
  bThread->aWait();
  std::cout << "Randezvous B2" << '\n';
}


/*!
 * \brief Description of the main function
 * \param thread threadOne is the first thread
 * \param thread threadTwo is the second thread
 * \details Main function creates two threads and call the taskOne & taskTwo functions 
 */
int main(void){

  std::thread threadOne, threadTwo;

  std::shared_ptr<Semaphore> sem( new Semaphore);

  threadTwo=std::thread(randezvousA,sem);
  threadOne=std::thread(randezvousB,sem);

  threadOne.join();
  threadTwo.join();
  std::cout << "All threads joined" << '\n';
  
  return 0;
  
}
