Lab 5 – Producer/Consumer
Create a program that has two parts.  A producer and a consumer.

The producer generates random characters from 097 to 122 ‘a’ to ‘z’ at random intervals (between 0 and 1 second in length). <br>
It adds these to a thread safe buffer that has a finite holding capacity of N characters.<br>
 It generates a preset number of characters (determined at runtime) and when it has finished it add an ‘X’ <br>
character to the buffer and exits.The consumer takes these letters from the buffer at random time intervals <br>
(between 0 and 1 second in length) and records how many of each letter it consumes.<br>
 Once it sees an ‘X’ in the buffer it adds its character count to a central buffer and exits.
Files in this Lab
1. Semaphore.cpp
2. Semaphore.h
3. SafeBuffer.cpp
4. SafeBuffer.h
5. main.cpp
6. Doxyfile
7. README
8. Makefile
The main file should demonstrate your producer consumer implementation in action by creating a  number of consumers <br>
and producers and showing them in action. All files must include suitable documentation. The Makefile must contain a <br>
rule (‘doc’) that runs the Doxygen program and generates the documentation. Edit your emacs settings so that it now <br>
automatically generates headers for your code files.  e.g. see https://www.emacswiki.org/emacs/AutomaticFileHeaders
;x
