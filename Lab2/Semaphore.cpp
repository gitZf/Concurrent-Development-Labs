/*! \class Semaphore.cpp
    \brief A Semaphore Implementation
    \author Zoltan Fuzesi - C00197361
    \version 1.0
    \date 02/10/2017
    \copyright GNU Public License
   Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

#include "Semaphore.h"



/*!
 * \brief Description of the void aWait function
 * \param m_uiCountA Counter to the lock
 * \param m_mutexA Mutex to the m_uiCountA
 * \details Decrease the m_uiCount if more than Zero
 */
void Semaphore::aWait()
{
  std::unique_lock< std::mutex > lock(m_mutexA);
  m_condition.wait(lock,[&]()->bool{ return m_uiCountA>0; });
      --m_uiCountA;
}




/*!
 * \brief Description of the void aSignal function
 * \param m_uiCountA Counter to the lock
 * \param m_mutexA Mutex to the m_uiCountA
 * \details Increase the m_uiCount if more than Zero
 */
void Semaphore::aSignal()
{
  std::unique_lock< std::mutex > lock(m_mutexA);
      ++m_uiCountA;
      m_condition.notify_one();
}

/*!
 * \brief Description of the void bWait function
 * \param m_uiCountB Counter to the lock
 * \param m_mutexB Mutex to the m_uiCountB
 * \details Decrease the m_uiCount if more than Zero
 */
void Semaphore::bWait()
{
  std::unique_lock< std::mutex > lock(m_mutexB);
  m_condition.wait(lock,[&]()->bool{ return m_uiCountB>0; });
      --m_uiCountB;
}




/*!
 * \brief Description of the void Signal function
 * \param m_uiCountB Counter to the lock
 * \param m_mutexB Mutex to the m_uiCountB
 * \details Increase the m_uiCount if more than Zero
 */
void Semaphore::bSignal()
{
  std::unique_lock< std::mutex > lock(m_mutexB);
      ++m_uiCountB;
      m_condition.notify_one();
}
