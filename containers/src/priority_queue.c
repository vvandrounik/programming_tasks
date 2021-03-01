#include "priority_queue.h"
#include "linked_list.h"

struct priority_queue
{
    linked_list_t* underlying_list;
    cmp_func_t cmp_func;
};


priority_queue_t* pqueue_create(cmp_func_t cmp_func)
{
    priority_queue_t* pqueue = 
        (priority_queue_t*)malloc(sizeof(priority_queue_t));

    if (!pqueue)
    {
        return NULL;
    }

    linked_list_t* underlying_list = list_create();

    if (!underlying_list)
    {
        free(underlying_list);
        return NULL;
    }

    pqueue->underlying_list = underlying_list;
    pqueue->cmp_func = cmp_func;

    return pqueue;
}

void pqueue_destroy(priority_queue_t*pqueue)
{
    list_destroy(pqueue->underlying_list);
    free(pqueue);
}

void pqueue_destroy_deep(priority_queue_t* pqueue, void (*deleter)(void*))
{
    list_destroy_deep(pqueue->underlying_list, deleter);
    free(pqueue);
}


node_t* pqueue_push(priority_queue_t* pqueue, void* data)
{
    node_t* curr = list_front(pqueue->underlying_list);

    if (curr == NULL || pqueue->cmp_func(curr->data, data) < 0)
    {
        return list_push_front(pqueue->underlying_list, data);
    }

    while (curr->next != NULL && pqueue->cmp_func(curr->next->data, data) > 0)
    {
        curr = curr->next;
    }

    return list_insert_after(pqueue->underlying_list, curr, data);
}

void pqueue_pop(priority_queue_t* pqueue)
{
    list_pop(pqueue->underlying_list);
}

node_t* pqueue_top(priority_queue_t* pqueue)
{
    return list_front(pqueue->underlying_list);
}
