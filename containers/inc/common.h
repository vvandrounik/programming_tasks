#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include "node.h"

#define CREATE_LIST_BASED(type, container_ptr) {\
    (*(container_ptr)) = (type*)malloc(sizeof(type));\
    if (*(container_ptr)) (*(container_ptr))->head = NULL;\
}

#define DESTROY_LIST_BASED(container_ptr) {\
    node_t* curr = (container_ptr)->head;\
    node_t* next = NULL;\
    (container_ptr)->head = NULL;\
    while (curr != NULL)\
    {\
        next = curr->next;\
        free(curr);\
        curr = next;\
    }\
    free((container_ptr));\
}

#define DESTROY_DEEP_LIST_BASED(container_ptr, deleter_ptr) {\
    node_t* curr = (container_ptr)->head;\
    node_t* next = NULL;\
    (container_ptr)->head = NULL;\
    while (curr != NULL)\
    {\
        next = curr->next;\
        (*(deleter_ptr))(curr->data);\
        free(curr);\
        curr = next;\
    }\
    free((container_ptr));\
}

#endif //COMMON_H