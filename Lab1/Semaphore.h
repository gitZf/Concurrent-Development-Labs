
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
#include <chrono>
/*!
 * \brief Semaphore.h declaration
 * \param m_mutex Mutual exclusion Mutex lock
 * \param m_condition Condition variable
 * \details Seamphore.h declare the member variables and the functions
 */

class Semaphore
{
private:
    unsigned int m_uiCount;
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    /*!
     * \brief Constructor & Deconstructor
     */
    Semaphore(unsigned int uiCount=0)
      : m_uiCount(uiCount) { };
    void Wait();
    void Signal();

};
