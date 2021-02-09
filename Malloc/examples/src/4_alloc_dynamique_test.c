#include "list.h"
#include "utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    list_t list = { malloc, free, NULL, 0 };

    wait_user();

    {
        node_t *node;
        size_t counter = 0;
        do {
            counter = counter + 1;
            node = create_node(&(list), 1 Go);

            printf("%p\n", (void *)node);
        } while (node != NULL);

        printf("Nombre d'appels malloc(): %zu\n", counter - 1);
    }

    wait_user();

    {
        node_t *node = list.head;
        size_t counter = 0;
        do {
            memset(node->payload, 0, node->size_payload);

            counter = counter + 1;
            printf("=== Nombre d'appels memset(): %zu\n", counter);

            wait_user();

            node = node->next;
        } while (node != NULL);
    }

    delete_list(&(list));
}
