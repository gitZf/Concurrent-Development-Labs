//// Barrier.cpp --- 
//// 
//// Filename: Barrier.cpp
//// Description: 
//// Author: Zoltan Fuzesi 
//// Maintainer: 
//// LICENSE :  GPLv3
//// Created: Mon Nov  6 09:05:24 2017 (+0000)
//// Version: 
//// Package-Requires: ()
//// Last-Updated: 
////           By: 
////     Update #: 0
//// URL: 
//// Doc URL: 
//// Keywords: 
//// Compatibility: 
//// 
//// 
//
//// Commentary: 
//// 
//// 
//// 
//// 
//
//// Change Log:
//// 
//// 
//// 
//// 
//// This program is free software: you can redistribute it and/or modify
//// it under the terms of the GNU General Public License as published by
//// the Free Software Foundation, either version 3 of the License, or (at
//// your option) any later version.
//// 
//// This program is distributed in the hope that it will be useful, but
//// WITHOUT ANY WARRANTY; without even the implied warranty of
//// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//// General Public License for more details.
//// 
//// You should have received a copy of the GNU General Public License
//// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
//// 
//// 
//
//// Code:

#include "Barrier.h"
#include <iostream>
using namespace std;

/*!
 * \brief Description of the barrierOne() function
 * \param counter is counting the threads
 * \param Semaphoremutex is pointer of Semaphore object
 * \param barrier1 Counter is pointer of Semaphore object
 * \param barrier2 Counter is pointer of Semaphore object
 * \details From the main class all the threads are calling this method
 * and the threads are controlled by the Semaphore objects
 */


void Barrier::barrierOne(){
    cout << "barrier 1 mutex wait" << '\n';
    Semaphoremutex->Wait();
    count++;
    if(count == numOfThreads){
        cout << "count == numOfThreads" << '\n';
        cout << "barrier 2 wait" << '\n';
        barrier2->Wait();
        cout << "barrier 1 signal" << '\n';
        barrier1->Signal();
    }
    cout << "barrier 1 mutex signal" << '\n';
    Semaphoremutex->Signal();
    cout << "barrier 1 wait (1)" << '\n';
    barrier1->Wait();
    cout << "barrier 2 signal" << '\n';
    barrier1->Signal();
}

/*!
 * \brief Description of the barrierTwo() function
 * \param counter is counting the threads
 * \param Semaphoremutex is pointer of Semaphore object
 * \param barrier1 Counter is pointer of Semaphore object
 * \param barrier2 Counter is pointer of Semaphore object
 * \details From the main class all the threads are calling this method
 * and the threads are controlled by the Semaphore objects
 */
void Barrier::barrierTwo(){
    cout << "barrier 2 mutex wait" << '\n';
    Semaphoremutex->Wait();
    count--;
    if(count == 0){
        cout << "count == 0" << '\n';
        cout << "barrier 1 wait (2)" << '\n';
        barrier1->Wait();
        cout << "barrier 2 signal" << '\n';
        barrier2->Signal();
    }
    cout << "barrier 2 mutex signal" << '\n';
    Semaphoremutex->Signal();
    cout << "barrier 2 wait" << '\n';
    barrier2->Wait();
    cout << "barrier 2 signal" << '\n';
    barrier2->Signal();
}

//// Barrier.cpp ends here


