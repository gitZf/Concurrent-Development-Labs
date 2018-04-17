### Makefile.mk Documentation
EXE =Barrier
CC = g++
DOXYGEN = doxygen
PROGRAM = Barrier
CFLAGS =-std=c++11 -Wall -pthread -o$(EXE)
CFILES = main.cpp Semaphore.cpp Barrier.cpp
HFILES = Semaphore.h Barrier.h

# working more advanced
ALL:$(PROGRAM)

#Rule for linking
$(PROGRAM):$(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o $(EXE) $(DEBUGFLAGS)
	$(DOXYGEN) Doxyfile

DEBUG: DEBUGFLAGS = -g -O0 -Wall
DEBUG: ALL

CLEAN:
	rm *.o
