### Makefile.mk Documentation

EXE = randezvous
CC = g++
DOXYGEN = doxygen
PROGRAM = randezvous
CFLAGS =-std=c++11 -pthread -o $(EXE)
CFILES = randezvous.cpp Semaphore.cpp
HFILES = Semaphore.h

# working simple
#all:$(CFILES) $(HFILES)
#	$(CC) $(CFLAGS) *.cpp -o $(EXE)
#	$(DOXYGEN) Doxyfile

# working more advanced 
ALL:$(PROGRAM)

#Rule for linking
$(PROGRAM):$(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o $(EXE)
	$(DOXYGEN) Doxyfile

CLEAN:
	rm *.o
