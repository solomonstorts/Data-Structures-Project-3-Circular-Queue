#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue
{
    int front;  //the array index of the front element
    int rear;   //the array index of the rear element
    int size;   //the number of elements in the queue
    int capacity;  //the capacity of the queue
    int *array;   //the pointer to the circular buffer
} Queue;

//create an empty queue with an array of the desired capacity
Queue *createQueue(int capacity);

//destroy the queue
Queue *destroyQueue(Queue *q);

//return 1 if the queue is empty, 0 otherwise
int isEmpty(Queue *q);

//make the queue empty
void makeEmpty(Queue *q);

//return 1 if the queue is full, 0 otherwise
int isFull(Queue *q);

//add a new element to the rear of the queue
void enqueue(Queue *q, int data);

//remove and return the front element from the queue
int dequeue(Queue *q);

//print the queue elements
void printQueue(Queue *q);

#endif
