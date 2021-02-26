#ifndef NODE_H
#define NODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct node
{
    void* data;
    struct node* next;
} node_t;

node_t* create_node(void* data);

#ifdef __cplusplus
}
#endif

#endif //NODE_H
