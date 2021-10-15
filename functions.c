/**
 * @file		functions.c
 * 
 * @author		Jordan Medina (jordan.medina@student.nmt.edu)
 * 
 * @brief		Functions used in queue.c
 * 
 * @date		2021-10-15
 * 
 * 
 */

#include "functions.h"


void init_queue(struct queue_t *q){
    q->head = NULL;         // The Queue's head points to the oldest node, which is the head of a linked list... *head => oldest_node---
    q->tail = NULL;         // Queue's tail points to the newest node, which is the tail of the linked list... *head--->*tail->Null
}

bool enqueue(struct queue_t *q, int val){

    //malloc a new arrival to the queue and set its attributes
    struct node_t *new_node = NULL;
    new_node = malloc(sizeof(struct node_t));
    assert(new_node);
    new_node->val = val;
    new_node->next = NULL; //back of the line

    //If the the tail node currently exists, point it to the new node
    if (q->tail){
        q->tail->next = new_node; //(*(q->tail)).next // (*(*q).tail).next
    }
    //Set the new tail node to the queue's tail 
    q->tail = new_node;
    
    //if the queue is empty, the head will equal the new node
    if (!q->head){
        q->head = new_node;
    }

    return true;

}


int dequeue(struct queue_t *q){
    //if the queue is empty
    if (!q->head){
        return QUEUE_IS_EMPTY;
    }

    //temporary pointer to the front of list node
    struct node_t *dq_tmp = q->head;
    int head_val = dq_tmp->val;

    //bypass deleted node, and free
    q->head = q->head->next;
    free(dq_tmp);

    //If head was the last in line, set the tail to NULL too
    if (!q->head){
        q->tail = NULL;
    }

    return head_val;

}



void user_choice_controls(int user_choice, struct queue_t *q){

    int node_val;   // for the user's enqueue command
    struct node_t *head_ptr = NULL; // used for Print_Queue option


    switch (user_choice){
    case ENQUEUE:
        //run an enqueue function
        printf("\nInsert this node's value: ");
        scanf("%d", &node_val);
        enqueue(q, node_val);

        break;

    case DEQUEUE:
        dequeue(q);
        break;

    case DEQUEUE_ENTIRELY:
        printf("\n\nDequeuing...\n");
        //deneque the queue and return values
        int dq_val;
        while((dq_val = dequeue(q)) != QUEUE_IS_EMPTY){
            printf("Dequeued: %d\n", dq_val);
        }

        break;

    case PRINT_QUEUE:
        head_ptr = q->head;

        printf("\nCurrent Queue, Oldest to Newest:\n");
        while(head_ptr){
            printf("\tnode: %d\n", head_ptr->val);
            head_ptr = head_ptr->next;
        }
        break;

    default:
        break;
    
    }

}


