#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>

#include "functions.h"


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



int main(){

    struct queue_t queue;
    init_queue(&queue);

    int user_choice = 0;

    while(user_choice != QUIT){
        printf("\nWhat would you like to do?\n1.) Enqueue\n2.) Dequeue\n3.) Dequeue Entirely\n4.) Show Queue\n5.) Quit\n");
        scanf("%d", &user_choice);

        //free the entire queue if the user quits--- same as the #3 command from user
        if(user_choice == QUIT){
            int dq_val;
            while((dq_val = dequeue(&queue)) != QUEUE_IS_EMPTY){
                //printf("Dequeued: %d\n", dq_val);
            }
            printf("Seeya next time!\n");
            //add a freeing function
            break;
        }

        user_choice_controls(user_choice, &queue);
    } 
    
    



    /*
    enqueue(&queue, 2);
    enqueue(&queue, 6);
    enqueue(&queue, 10);
    enqueue(&queue, 14);
    enqueue(&queue, 18);*/

     



    return 0;
}