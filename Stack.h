#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "sll.h"

//Stack LIFO /LCFS - > ali -> veli -> can
typedef struct Stack{
    SLL sll;
}Stack;

string pop(Stack* stk){
    return removeRear(&stk->sll);
}

void push(Stack* stk, string data){
    insertRear(&stk->sll, data);
}
string top(Stack* stk){
    return bottom(&stk->sll);
}
int sizeStack(Stack* stk){
    return stk->sll.size;
}
void print(Stack* stk){
    printReverse(&stk->sll);
}

bool isEmpty(Stack* stk){
    return isEmpty(&stk->sll);
}

void printNL(Stack* stk){
    printNL(&stk->sll);
}
void freeStack(Stack* stk) {
    freeSLL(&stk->sll);
}

#endif // STACK_H_INCLUDED
