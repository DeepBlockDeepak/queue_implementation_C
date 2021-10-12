#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

#define QUEUE_IS_EMPTY INT_MIN


struct node_t{
    int val;
    struct node_t *next;
};


struct queue_t{
    struct node_t *head;    // The linked list is represented like tail----->head
    struct node_t *tail;    //  Where nodes enter the queue at the tail, and the oldest node is at head
};

void init_queue(struct queue_t *q){
    q->head = NULL;
    q->tail = NULL;
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
        q->tail->next = new_node; //*(q->tail).next
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

int main(){

    struct queue_t queue;
    init_queue(&queue);

    enqueue(&queue, 2);
    enqueue(&queue, 6);
    enqueue(&queue, 10);
    enqueue(&queue, 14);
    enqueue(&queue, 18);



    struct node_t *head_ptr = NULL;
    head_ptr = queue.head;

    printf("Current Queue, Oldest to Newest:\n");
    while(head_ptr){
        printf("node: %d\n", head_ptr->val);
        head_ptr = head_ptr->next;
    }

    printf("\n\nDequeuing...\n");
    //deneque the queue and return values
    int dq_val;
    while((dq_val = dequeue(&queue)) != QUEUE_IS_EMPTY){
        printf("Dequeued: %d\n", dq_val);
    }

    return 0;
}