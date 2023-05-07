#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define MAX_STACK_SIZE 15
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct StackNode
{
	bool data[MAX_STACK_SIZE];
	int top;
}Stack;

bool isEmpty_stack(Stack *stack);
Stack* make_stack();
void push(Stack *stack);
void pop(Stack *stack);

#endif // STACK_H_INCLUDED
