#include "priority_queue.h"
#include "common.h"

struct priority_queue
{
    node_t* head;
    cmp_func_t cmp_func;
};


void create(priority_queue_t** queue, cmp_func_t cmp_func)
{
    CREATE_LIST_BASED(priority_queue_t, queue);

    if (*queue)
    {
        (*queue)->cmp_func = cmp_func;
    }
}

void destroy(priority_queue_t* queue)
{
    DESTROY_LIST_BASED(queue);
}

void destroy_deep(priority_queue_t* queue, void (*deleter)(void*))
{
    DESTROY_DEEP_LIST_BASED(queue, deleter);
}


node_t* push(priority_queue_t* queue, void* data)
{
    node_t* new_node = create_node(data);

    if (queue->head == NULL)
    {
        queue->head = new_node;
        return new_node;
    }

    if (queue->cmp_func(queue->head->data, data) < 0)
    {
        new_node->next = queue->head;
        queue->head = new_node;
        return new_node;
    }

    node_t* curr = queue->head;
    while (curr->next != NULL && queue->cmp_func(curr->next->data, data) > 0)
    {
        curr = curr->next;
    }
      
    new_node->next = curr->next;
    curr->next = new_node;

    return new_node;
}

void pop(priority_queue_t* queue)
{
    if (queue->head == NULL)
    {
        return;
    }

    node_t* tmp = queue->head;
    queue->head = tmp->next;
    free(tmp);
}

void* top(priority_queue_t* queue)
{
    return queue->head == NULL
        ? NULL : queue->head->data;
}
