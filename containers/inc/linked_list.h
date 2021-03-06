#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

#include "node.h"
#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct linked_list linked_list_t;

linked_list_t* list_create();
void list_destroy(linked_list_t* list);
void list_destroy_deep(linked_list_t* list, void (*deleter)(void*));

node_t* list_push_front(linked_list_t* list, void* data);
node_t* list_push_back(linked_list_t* list, void* data);
node_t* list_insert_at(linked_list_t* list, size_t pos, void* data);
node_t* list_insert_after(linked_list_t* list, node_t* node, void* data);
node_t* list_front(linked_list_t* list);
void list_pop(linked_list_t* list);

node_t* list_get_middle(const linked_list_t* list);
bool list_has_loop(const linked_list_t* list);

#ifdef __cplusplus
}
#endif

#endif //LINKEDLIST_H