#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct node_t{
    int val;
    struct node_t *next;
};


struct queue_t{
    struct node_t *head;
    struct node_t *tail;
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






int main(){

    struct queue_t *queue = NULL;

    enqueue(queue, 2);


    struct node_t *head_ptr = NULL;
    head_ptr = &node;

    while(head_ptr){
        printf("node: %d\n", head_ptr->val);
        head_ptr = head_ptr->next;
    }

    return 0;
}