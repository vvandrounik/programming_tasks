#include "stack.h"
#include "linked_list.h"

struct stack
{
    linked_list_t* underlying_list;
};


stack_t* stack_create()
{
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));

    if (!stack)
    {
        return NULL;
    }

    linked_list_t* underlying_list = list_create();

    if (!underlying_list)
    {
        free(stack);
        return NULL;
    }

    stack->underlying_list = underlying_list;
    return stack;
}

void stack_destroy(stack_t* stack)
{
    list_destroy(stack->underlying_list);
    free(stack);
}

void stack_destroy_deep(stack_t* stack, void (*deleter)(void*))
{
    list_destroy_deep(stack->underlying_list, deleter);
    free(stack);
}


node_t* stack_push(stack_t* stack, void* data)
{
    return list_push_front(stack->underlying_list, data);
}

void stack_pop(stack_t* stack)
{
    list_pop(stack->underlying_list);
}

node_t* stack_top(stack_t* stack)
{
    return list_front(stack->underlying_list);
}