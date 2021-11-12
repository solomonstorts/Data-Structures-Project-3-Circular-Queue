//
//  queue.c
//  
//
//  Solomon Storts
//  Data Structures Project 3
//  Student ID: 7625
//
//  Contains definitions for the required functions listed in queue.h
//
//  Note: throughout this program I use "% q->capacity."
//  This due to the circular manner of the queue.
//  For example, if capacity is 4 and rear index is 3, and we want to add an element, we need to add it to index 0.
//  So we use (q->rear + 1) % q->capacity, because (3 + 1) % 4 = 0
//

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

//create an empty queue with an array of the desired capacity
Queue *createQueue(int capacity) {
    Queue *q = calloc(1, sizeof(Queue));
    q->array = malloc(sizeof(int) * capacity);
    q->capacity = capacity;
    q->front = -1; //empty queue has front index of -1
    q->rear = -1; //empty queue has rear index of -1
    q->size = 0; //empty queue has size of 0
    return q;
}

//destroy the queue
Queue *destroyQueue(Queue *q) {
    free(q->array);
    free(q);
    return NULL;
}

//return 1 if the queue is empty, 0 otherwise
int isEmpty(Queue *q) {
    //empty queue has front index of -1, rear index of -1, or size of 0
    if(q->front == -1 || q->rear == -1 || q->size == 0) {
        return 1;
    }
    return 0;
}

//make the queue empty
void makeEmpty(Queue *q) {
    //empty queue has front index of -1, rear index of -1, and size of 0
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

//return 1 if the queue is full, 0 otherwise
int isFull(Queue *q) {
    //check if rear index + 1 = front index
    if(((q->rear + 1) % q->capacity) == q->front) {
        return 1;
    }
    return 0;
}

//add a new element to the rear of the queue
void enqueue(Queue *q, int data) {
    //if the queue is full, we cannot add elements
    if(isFull(q)) {
        return;
    }
    //If the queue is empty, we now need to set the front to 0.
    //Otherwise, the front stays the same.
    if(isEmpty(q)) {
        q->front = 0;
    }
    int index = (q->rear + 1) % q->capacity; //destination index
    q->array[index] = data; //add element to array
    q->rear = index; //update rear index
    q->size++; //increment size
}

//remove and return the front element from the queue
int dequeue(Queue *q) {
    //if the queue is empty, we cannot remove elements
    if(isEmpty(q)) {
        return -1;
    }
    int frontElement = q->array[q->front]; //store front element
    q->front = (q->front + 1) % q->capacity; //increment front index
    q->size--; //decrement size
    return frontElement; //return removed element
}

//print the queue elements
void printQueue(Queue *q) {
    //if the queue is empty, print a blank line
    if(isEmpty(q)) {
        printf("");
        return;
    }
    int i = q->front; //set counter to front index
    int end = (q->rear + 1) % q->capacity; //set end to rear index + 1
    //use a do-while loop in case of full queue, where i = end
    do {
        printf("%d ", q->array[i % q->capacity]); //print element
        i = (i + 1) % q->capacity; //increment i
    } while(i != end);
}
