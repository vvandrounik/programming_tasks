#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

#include "node.h"

typedef struct linked_list linked_list_t;

void create(linked_list_t** list);
void destroy(linked_list_t* list);
void destroy_deep(linked_list_t* list, void (*deleter)(void*));

node_t* push_back(linked_list_t* list, void* data);
node_t* insert(linked_list_t* list, size_t pos, void* data);

node_t* get_middle(const linked_list_t* list);
bool has_loop(const linked_list_t* list);

#endif LINKEDLIST_H