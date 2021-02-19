#ifndef NODE_H
#define NODE_H

typedef struct node
{
    void* data;
    node* next;
} node_t;

node_t* create_node(void* data);

#endif NODE_H
