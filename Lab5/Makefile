### Makefile.mk Documentation
EXE =Producer
CC = g++ -g 
DOXYGEN = doxygen
PROGRAM = Producer
CFLAGS =-std=c++14 -pthread -o $(EXE) 
CFILES = main.cpp Semaphore.cpp SafeBuffer.cpp
HFILES = Semaphore.h SafeBuffer.h

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
