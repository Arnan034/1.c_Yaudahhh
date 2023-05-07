#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 15

bool isEmpty_stack(Stack *stack)
{
	if(stack->top == -1 && stack->data[0] == false) {
		return false;
	}
	return true;
}

Stack* make_stack()
{
	Stack *tmp = (Stack*)calloc(sizeof(Stack), 1);
	if(!tmp) {
		puts("memory is full-using.");
		exit(1);
	}
	for(int i = 0; i < MAX_STACK_SIZE; i++){
		tmp->data[i] = false;
	}
	tmp->top = -1;
	return tmp;
}

void push(Stack *stack)
{
	stack->top += 1;
	stack->data[stack->top] = true;
}

void pop(Stack *stack)
{
	stack->top -= 1;
	stack->data[stack->top] = false;
}
