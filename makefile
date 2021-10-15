CC = gcc
CFLAGS = -g -Wall
OBJFLAGS = -g -Wall -c
MATHLIB = -lm

targets = functions queue
clean_targets = queue # Remove the ./queue executable when cleaned


all : $(targets)

#	creates the functions.o object file, needed for the queue.c functions
#	libraries are within the functions.h file
functions : queue.c functions.c functions.h
	$(CC) $(OBJFLAGS) $@.c

#	compile with the object file
queue : queue.c
	$(CC) $(CFLAGS) functions.o $@.c -o $@

clean :
	rm *.o $(clean_targets)
