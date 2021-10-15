CC = gcc
CFLAGS = -g -Wall
OBJFLAGS = -g -Wall -c
MATHLIB = -lm

#Remove the ./queue executable when cleaned, also run the makefile 'queue' command
targets = queue
clean_targets = queue

all : $(targets)

#	creates the functions.o object file, needed for the queue.c functions
#	libraries are within the functions.h file
functions : queue.c functions.c functions.h
	$(CC) $(OBJFLAGS) $@.c

#	compile with the object file
queue : queue.c
	$(CC) $(CFLAGS) functions.o $@.c -o $@

clean :
	rm *.o $(targets)
