///* Semaphore.h --- 
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
#include <mutex>
#include <condition_variable>
#include <iostream>
/*!
 * \brief Semaphore.h declaration
 * \param m_mutex Mutual exlusion
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
    Semaphore(unsigned int uiCount=1) : m_uiCount(uiCount) { };

   /*!
     * \brief Wait() function declaration
     */
    void Wait();
      /*!
     * \brief Signal() function declaration
     */
    void Signal();

};

///* Semaphore.h ends here */