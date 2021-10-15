/**
 * @file		queue.c
 * 
 * @author		Jordan Medina (jordan.medina@student.nmt.edu)
 * 
 * @brief		Performs a Queue. Users can chooes to enqueue, dequeue, and print the queue.
 *              Memory should be cleared 
 * 
 * @date		2021-10-15
 * 
 * 
 */


#include "functions.h"


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
            }
            printf("Seeya next time!\n");

            break;
        }

        user_choice_controls(user_choice, &queue);
    } 
    
    

    return 0;
}