#ifndef LIST_H_
#define LIST_H_

#include "utils.h"

#include <stdbool.h>
#include <stddef.h>

/* === TYPEDEF STRUCT DECLARATION === */

typedef struct list_s list_t;
typedef struct node_s node_t;

typedef void *(alloc)(size_t);
typedef void(dealloc)(void *);

/* === STRUCT DEFINITION === */

struct node_s {
    node_t *next;
    node_t *prev;
    size_t size_payload;
    byte payload[];
};

struct list_s {
    alloc *alloc_fptr;
    dealloc *dealloc_fptr;

    node_t *head;
    size_t length;
};

/* === FUNCTION DECLARATION === */

node_t *create_node(list_t *list, size_t size);
void delete_node(list_t *list, node_t *node);

bool is_empty(list_t *list);
void delete_list(list_t *list);

#endif /* LIST_H_ */
