#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdint.h>

#include "node.h"

typedef int(*cmp_func_t)(void*, void*);
typedef struct priority_queue priority_queue_t;

void create(priority_queue_t** queue, cmp_func_t cmp_func);
void destroy(priority_queue_t* queue);
void destroy_deep(priority_queue_t* queue, void (*deleter)(void*));

node_t* push(priority_queue_t* queue, void* data);
void pop(priority_queue_t* queue);
void* top(priority_queue_t* stack);

#endif PRIORITYQUEUE_H