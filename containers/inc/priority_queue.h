#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdint.h>

#include "node.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int(*cmp_func_t)(void*, void*);
typedef struct priority_queue priority_queue_t;

priority_queue_t* pqueue_create(cmp_func_t cmp_func);
void pqueue_destroy(priority_queue_t* queue);
void pqueue_destroy_deep(priority_queue_t* queue, void (*deleter)(void*));

node_t* pqueue_push(priority_queue_t* queue, void* data);
void pqueue_pop(priority_queue_t* queue);
node_t* pqueue_top(priority_queue_t* stack);

#ifdef __cplusplus
}
#endif

#endif //PRIORITYQUEUE_H