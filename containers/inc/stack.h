#ifndef STACK_H
#define STACK_H

#include "node.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct stack stack_t;

stack_t* stack_create();
void stack_destroy(stack_t* stack);
void stack_destroy_deep(stack_t* stack, void (*deleter)(void*));

node_t* stack_push(stack_t* stack, void* data);
void stack_pop(stack_t* stack);
node_t* stack_top(stack_t* stack);

#ifdef __cplusplus
}
#endif

#endif //STACK_H
