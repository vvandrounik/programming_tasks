#include <stdlib.h>

#include "node.h"

node_t* create_node(void* data)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    if (!new_node)
        return NULL;

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}