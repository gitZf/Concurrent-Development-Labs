/* SafeBuffer.h --- 
 * 
 * Filename: SafeBuffer.h
 * Description: 
 * Author: Zoltan Fuzesi 
 * Maintainer: 
 * Created: Tue Oct 31 19:44:16 2017 (+0000)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: 
 *           By: 
 *     Update #: 0
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change Log:
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */


#ifndef SAFEBUFFER_H
#define SAFEBUFFER_H

#include "Semaphore.h"
#include <thread>

class SafeBuffer{
    
    
private:
    int bufferSizeCounter;
    int maxBuffer;
    int consumeCounter;
    int pipe[10000];
    char pipeChars[10000];
    char chars[100] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    std::shared_ptr<Semaphore> producer;
    std::shared_ptr<Semaphore> consumer;
    
    
public:
    
    SafeBuffer(int buffer=0, int max=10, int counter=0) : bufferSizeCounter(buffer), maxBuffer(max),consumeCounter(counter), producer(std::make_shared<Semaphore>(1)), consumer(std::make_shared<Semaphore>(0)){};
    
    void show_pid(pid_t l_pid);
    
    void produce(int num, std::thread::id id);
    
    void consume();
    
};

#endif
/* SafeBuffer.h ends here */
