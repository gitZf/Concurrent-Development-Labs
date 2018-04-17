///* Semaphore.cpp --- 
// * 
// * Filename: Barrier.h
// * Description: 
// * Author: Zoltan Fuzesi 
// * Maintainer: 
//// LICENSE :  GPLv3
// * Created: Mon Nov  6 09:05:06 2017 (+0000)
// * Version: 
// * Package-Requires: ()
// * Last-Updated: 
// *           By: 
// *     Update #: 0
// * URL: 
// * Doc URL: 
// * Keywords: 
// * Compatibility: 
// * 
// */
//
///* Commentary: 
// * 
// * 
// * 
// */
//
///* Change Log:
// * 
// * 
// */
//
///* This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or (at
// * your option) any later version.
// * 
// * This program is distributed in the hope that it will be useful, but
// * WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// * General Public License for more details.
// * 
// * You should have received a copy of the GNU General Public License
// * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// */
//
///* Code: */
#include "Semaphore.h"


/*!
 * \brief Description of the void Wait function
 * \param m_uiCount Counter to the lock
 * \details Decrease the m_uiCount if more than Zero
 */
void Semaphore::Wait()
{
  std::unique_lock< std::mutex > lock(m_mutex);
  m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount;
}



/*!
 * \brief Description of the void Signal function
 * \param m_uiCount Counter to the lock
 * \details Increase the m_uiCount if more than Zero
 */
void Semaphore::Signal()
{
  std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}

///* Semaphore.cpp ends here */