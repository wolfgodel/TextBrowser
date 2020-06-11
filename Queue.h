#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "sll.h"


//Queue : FIFO/FCFS  örn. -> Ali -> Veli -> Can -> NULL

typedef struct Queue {
    SLL sll;
} Queue;
//kuyuruğa eleman ekler , sonuna
void enqueue(Queue *q, string data){
    insertRear(&q->sll, data);
}

//kuyruğun başından eleman siler
string dequeue(Queue* q){
    return removeFront(&q->sll);
}

string top(Queue *q){
    return top(&q->sll);
}

int sizeQueue(Queue *q){
    return q->sll.size;
}

bool isEmpty(Queue *q){
    return isEmpty(&q->sll);
}

void print(Queue *q){
    print(&q->sll);
}

void printNL(Queue *q){
    printNL(&q->sll);
}
void freeQueue(Queue *q) {
    freeSLL(&q->sll);
}

#endif // QUEUE_H_INCLUDED
