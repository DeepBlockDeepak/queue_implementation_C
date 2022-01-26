/**
 * @file		array_queue.c
 * 
 * @author		Jordan Medina (jordan.medina@student.nmt.edu)
 * 
 * @brief		Performs a Queue using a fixed-length array 
 * 
 * @date		2022-01-25
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>


#define OPEN_SPOT INT_MIN

bool enqueue(int[] queue, int* head, int* tail, int new_val);


int main(){

    // arbitrarily large queue can be sourced here
    int n = 10;
    int[n] queue;
 
    // initialize the queue
    for(int i = 0; i < n; i++){
        queue[i] = OPEN_SPOT;
    }

    return 0;
}
//             |
// {x, x, x, OPEN}


//    |
// {OPEN, OPEN, OPEN, OPEN}

bool enqueue(int[] queue, int* head_index, int* tail_index, int new_val){
    
    // No more room in queue
    if(*tail == (int)sizeof(queue)/sizeof(int)-1){
        return false;
    }


    // current tail_index 
    if(queue[*tail_index] == OPEN_SPOT){
        queue[*tail_index] = new_val;
    }








        
}
