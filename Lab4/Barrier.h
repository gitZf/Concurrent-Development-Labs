///* Barrier.h --- 
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

#include <iostream>
#include "Semaphore.h"

/*!
 * \brief Description of the void barrier.h class
 * \param numOfThreads is in the number of threads goest through the barriers
 * \param count is in the counter to the threads are going through the mutex
 * \param Semaphoremutex is an shared pointer, object of the Semaphore class
 * \param barrier1 is an shared pointer, object of the Semaphore class
 * \param barrier2 is an shared pointer, object of the Semaphore class
 * \details Barrier.h declare the member variables and the functions
 */

class Barrier{

private:
    int numOfThreads;
    int count;
    std::shared_ptr<Semaphore> Semaphoremutex;
    std::shared_ptr<Semaphore> barrier1;
    std::shared_ptr<Semaphore> barrier2;

public:
    /*!
     * \brief Constructor
     */
    Barrier(int numOfThreads) : numOfThreads(numOfThreads), Semaphoremutex(std::make_shared<Semaphore>(1)), barrier1(std::make_shared<Semaphore>(0)), barrier2(std::make_shared<Semaphore>(1)) { };
    /*!
     * \brief barrierOne method declaration
     */
    void barrierOne();
    /*!
     * \brief barrierTwo method declaration
     */
    void barrierTwo();
};


///* Barrier.h ends here */



