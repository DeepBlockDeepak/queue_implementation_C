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

#ifndef QUEUE_H
#define QUEUE_H


void init_queue(struct queue_t *q);

bool enqueue(struct queue_t *q, int val);

int dequeue(struct queue_t *q);

void user_choice_controls(int user_choice, struct queue_t *q);


#endif