#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct stack stack_t;

void create(stack_t** stack);
void destroy(stack_t* stack);
void destroy_deep(stack_t* stack, void (*deleter)(void*));

node_t* push(stack_t* stack, void* data);
void pop(stack_t* stack);
void* top(stack_t* stack);

#endif STACK_H
