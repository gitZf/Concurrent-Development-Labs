### Makefile.mk Documentation
EXE = signal
CC = g++
DOXYGEN = doxygen
PROGRAM = signal
CFLAGS =-std=c++11 -pthread -o$(EXE)
CFILES = signal.cpp Semaphore.cpp
HFILES = Semaphore.h

# working more advanced 
all:$(PROGRAM)

#Rule for linking
$(PROGRAM):$(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o $(EXE)
	$(DOXYGEN) Doxyfile
