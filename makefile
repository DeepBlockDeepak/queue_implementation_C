CC = gcc
CFLAGS = -g -Wall
OBJFLAGS = -g -Wall -c
MATHLIB = -lm

#Remove the ./queue executable when cleaned, also run the makefile 'queue' command
targets = queue

all : $(targets)

queue : queue.c
	$(CC) $(CFLAGS) $@.c -o $@

clean :
	rm $(targets)
