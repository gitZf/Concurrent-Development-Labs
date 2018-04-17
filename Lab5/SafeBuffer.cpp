// SafeBuffer.cpp --- 
// 
// Filename: SafeBuffer.cpp
// Description: 
// Author: Zoltan Fuzesi 
// Maintainer: 
// Created: Tue Oct 31 19:43:59 2017 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: 
//           By: 
//     Update #: 0
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// 
// 

// Code:


#include "SafeBuffer.h"
#include <unistd.h>

void SafeBuffer::show_pid(pid_t l_pid){
    std::cout<< l_pid << "\n";
}

 void SafeBuffer::produce(int num,std::thread::id id) {
/*
 * Solution 1
 */
//             producer->Wait();
//             pipe[bufferSizeCounter] = num;
//             std::cout << "Producer produce : " << std::to_string(num) << "\n";
//             consumer->Signal();
     /*
      *Solution 2
      */
               producer->Wait();
               std::cout << "the thread id is " << id << "\n";
               int sleep = rand()%2 * 1000;
               usleep(sleep * 1000);
               if(bufferSizeCounter<maxBuffer-1){
                   pipeChars[bufferSizeCounter] = chars[num];
                   std::cout << "Producer produce : " << pipeChars[bufferSizeCounter] << "\n";
                   ++bufferSizeCounter;
                   producer->Signal();
               }
               else{
                   pipeChars[bufferSizeCounter] = 'X';
                   std::cout << "Producer produce last : " << pipeChars[bufferSizeCounter] << "\n";
                   bufferSizeCounter = 0;
                   consumer->Signal();
               }
                
               
               
    }
 

  void SafeBuffer::consume() {
/*
 * Solution 1
 */
//                consumer->Wait();
//                int num = pipe[bufferSizeCounter];
//                
//                std::cout << "Consumer consumed : " << std::to_string(num) << "\n";
//                ++bufferSizeCounter;
//                
//                if(bufferSizeCounter>=maxBuffer-1){
//                    bufferSizeCounter=0;
//                }
//                producer->Signal();
      /*
       * Solution 2
       */
                consumer->Wait();
                int sleep = rand()%2 * 1000;
                usleep(sleep * 1000);
                if(pipeChars[bufferSizeCounter]!='X'){//bufferSizeCounter<maxBuffer-1){//change for not equals to character X
                   std::cout << "Consumer consume : " << pipeChars[bufferSizeCounter] << "\n";
                   ++bufferSizeCounter;
                   ++consumeCounter;
                   consumer->Signal();
                }else{
                   std::cout << "Consumer consume : " << pipeChars[bufferSizeCounter] << "\n";
                   bufferSizeCounter = 0;
                   ++consumeCounter;
                   std::cout << "Consumer counter : " << std::to_string(consumeCounter) << "\n";
                }
       
    }
// 
// SafeBuffer.cpp ends here
