### Makefile.mk Documentation
EXE = mutex
CC = g++
DOXYGEN = doxygen
PROGRAM = Mutex
CFLAGS =-std=c++11 -pthread -o$(EXE)
CFILES = mutex.cpp Semaphore.cpp
HFILES = Semaphore.h

# working more advanced 
ALL:$(PROGRAM)

#Rule for linking
$(PROGRAM):$(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o $(EXE) $(DEBUGFLAGS)
	$(DOXYGEN) Doxyfile

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

CLEAN:
	rm *.o
