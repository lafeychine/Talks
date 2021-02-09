#include "list.h"
#include "utils.h"

#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE (10 Mo)

void *get_top(size_t);

list_t list = { get_top, NULL, NULL, 0 };
byte memory[MEMORY_SIZE];

void *malloc(size_t size)
{
    node_t *node = create_node(&(list), size);

    if (node == NULL) {
        return (NULL);
    }

    return (node->payload);
}

void free(void *ptr)
{
    ptr = ptr;
    return;
}

void *calloc(size_t nmemb, size_t size)
{
    node_t *node = malloc(nmemb * size);

    if (node == NULL) {
        return (NULL);
    }

    memset(node->payload, 0, node->size_payload);
    return (node);
}

void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return (malloc(size));
    }

    node_t *new = create_node(&(list), size);
    if (new == NULL) {
        return (NULL);
    }

    node_t *node = (node_t *)((byte *)ptr - sizeof(node_t));
    memcpy(new->payload, ptr, node->size_payload);
    return (&(node->payload));
}

void *get_top(size_t size)
{
    if (list.length + size > MEMORY_SIZE) {
        return (NULL);
    }
    return (memory + list.length);
}
