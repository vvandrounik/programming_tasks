#include <stdlib.h>

#include "linked_list.h"
#include "common.h"

struct linked_list
{
    node_t* head;
};


void list_create(linked_list_t** list)
{
    CREATE_LIST_BASED(linked_list_t, list);
}

void list_destroy(linked_list_t* list)
{
    DESTROY_LIST_BASED(list);
}

void list_destroy_deep(linked_list_t* list, void (*deleter)(void*))
{
    DESTROY_DEEP_LIST_BASED(list, deleter);
}


node_t* list_push_back(linked_list_t* list, void* data)
{
    node_t* new_node = create_node(data);

    if (list->head == NULL)
    {
        list->head = new_node;
        return new_node;
    }

    node_t* curr = list->head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new_node;
    return new_node;
}

node_t* list_insert(linked_list_t* list, size_t pos, void* data)
{
    node_t* new_node = create_node(data);

    if (list->head == NULL)
    {
        list->head = new_node;
        return new_node;
    }

    if (pos == 0)
    {
        new_node->next = list->head;
        return new_node;
    }

    node_t* curr = list->head;
    while (curr->next != NULL && pos - 1 > 0)
    {
        curr = curr->next;
        --pos;
    }

    new_node->next = curr->next;
    curr->next = new_node;

    return new_node;
}


node_t* list_get_middle(const linked_list_t* list)
{
    if (!list->head)
        return NULL;

    node_t* slow_ptr = list->head;
    node_t* fast_ptr = list->head;

    while (fast_ptr->next != NULL && fast_ptr->next->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    return slow_ptr;
}

bool list_has_loop(const linked_list_t* list)
{
    if (!list->head)
        return false;

    node_t* slow_ptr = list->head;
    node_t* fast_ptr = list->head;

    while (slow_ptr != NULL &&
        fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if (slow_ptr == fast_ptr)
            return true;
    }

    return false;
}