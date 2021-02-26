#include "stack.h"
#include "common.h"

struct stack
{
    node_t* head;
};


void stack_create(stack_t** stack)
{
    CREATE_LIST_BASED(stack_t, stack);
}

void stack_destroy(stack_t* stack)
{
    DESTROY_LIST_BASED(stack);
}

void stack_destroy_deep(stack_t* stack, void (*deleter)(void*))
{
    DESTROY_DEEP_LIST_BASED(stack, deleter);
}


node_t* stack_push(stack_t* stack, void* data)
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

void stack_pop(stack_t* stack)
{
    if (stack->head == NULL)
    {
        return;
    }

    node_t* tmp = stack->head;
    stack->head = tmp->next;
    free(tmp);
}

void* stack_top(stack_t* stack)
{
    return stack->head == NULL
        ? NULL : stack->head->data;
}