
/*! \class Semaphore.h
    \brief Semaphore declaration
    \author Zoltan Fuzesi - C00197361
    \version 1.0
    \date 02/10/2017
    \copyright GNU Public License
   Uses C++11 features such as mutex and condition variables to implement Semaphore

*/

#include <mutex>
#include <condition_variable>
#include <iostream>
/*!
 * \brief Semaphore.h declaration
 * \param m_mutexA Mutual exclusion Mutex lock
 * \param m_mutexB Mutual exclusion Mutex lock
 * \param m_uiCountA is a counter for aWait and aSignal functions
 * \param m_uiCountB is a counter for bWait and bSignal functions
 * \param m_condition Condition variable
 * \details Seamphore.h declare the member variables and the functions
 */

class Semaphore
{
private:
    unsigned int m_uiCountA;
    unsigned int m_uiCountB;
    std::mutex m_mutexA;
    std::mutex m_mutexB;
    std::condition_variable m_condition;

public:
    /*!
     * \brief Constructor & Deconstructor
     * The constructor initialise the two member variable (m_uiCountA & m_uiCountB)to Zero;
     */
    Semaphore(unsigned int uiCountA=0, unsigned int uiCountB=0 ) : m_uiCountA(uiCountA), m_uiCountB(uiCountB) { };
    void aWait();
    void aSignal();

    void bWait();
    void bSignal();


};
