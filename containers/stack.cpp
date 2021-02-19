#include "stack.h"
#include "common.h"

struct stack
{
    node_t* head;
};


void create(stack_t** stack)
{
    CREATE_LIST_BASED(stack_t, stack);
}

void destroy(stack_t* stack)
{
    DESTROY_LIST_BASED(stack);
}

void destroy_deep(stack_t* stack, void (*deleter)(void*))
{
    DESTROY_DEEP_LIST_BASED(stack, deleter);
}


node_t* push(stack_t* stack, void* data)
{
    node_t* new_node = create_node(data);

    if (stack->head == NULL)
    {
        stack->head = new_node;
        return new_node;
    }

    new_node->next = stack->head;
    stack->head = new_node;

    return new_node;
}

void pop(stack_t* stack)
{
    if (stack->head == NULL)
    {
        return;
    }

    node_t* tmp = stack->head;
    stack->head = tmp->next;
    free(tmp);
}

void* top(stack_t* stack)
{
    return stack->head == NULL
        ? NULL : stack->head->data;
}