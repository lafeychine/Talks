#include "list.h"

#include <stdlib.h>

#define ALLOC_ALIGNMENT (sizeof(size_t))

#define ALIGN(_size, _align) ((_size + (_align - 1)) & ~(_align - 1))

bool is_empty(list_t *list)
{
    return (list->head == NULL);
}

node_t *create_node(list_t *list, size_t size)
{
    size = ALIGN(size, ALLOC_ALIGNMENT);
    node_t *node = list->alloc_fptr(sizeof(node_t) + size);

    if (node == NULL) {
        return (NULL);
    }

    node->next = list->head;
    node->prev = NULL;
    list->head = node;

    if (node->next != NULL) {
        node->next->prev = node;
    }

    node->size_payload = size;
    list->length += (node->size_payload + sizeof(node_t));
    return (node);
}

void delete_node(list_t *list, node_t *node)
{
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    list->length -= (node->size_payload + sizeof(node_t));
    list->dealloc_fptr(node);
}

void delete_list(list_t *list)
{
    while (!(is_empty(list))) {
        delete_node(list, list->head);
    }
}
