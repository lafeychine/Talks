#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node_t *add_node_value(list_t *list, int value)
{
    node_t *tmp = create_node(list, sizeof(int));

    memcpy(tmp->payload, &(value), sizeof(int));
    return (tmp);
}

int main()
{
    list_t list = { malloc, free, NULL, 0 };
    node_t *node;

    add_node_value(&(list), 4);
    node = add_node_value(&(list), 3);
    add_node_value(&(list), 2);
    add_node_value(&(list), 1);

    delete_node(&(list), node);

    node = list.head;
    while (node) {
        printf("%d\n", *(int *)node->payload);
        node = node->next;
    }
    delete_list(&(list));
}
