/**
 * @file		functions.h
 * 
 * @author		Jordan Medina (jordan.medina@student.nmt.edu)
 * 
 * @brief		Header file for importing the functions.c functions into the queue.c driver 
 * 
 * @date		2021-10-15
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>


#ifndef QUEUE_H
#define QUEUE_H


#define QUEUE_IS_EMPTY INT_MIN

enum user_choices{
    ENQUEUE = 1, DEQUEUE, DEQUEUE_ENTIRELY, PRINT_QUEUE, QUIT
};

struct node_t{
    int val;
    struct node_t *next;
};


struct queue_t{
    struct node_t *head;    // The linked list is represented like q.head----->q.tail->Null .... 
    struct node_t *tail;    //  Where nodes enter the queue at the tail, and the oldest node is at head
};



void init_queue(struct queue_t *q);

bool enqueue(struct queue_t *q, int val);

int dequeue(struct queue_t *q);

void user_choice_controls(int user_choice, struct queue_t *q);


#endif