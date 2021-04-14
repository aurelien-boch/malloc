/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** my free implementation
*/

#include "malloc.h"

void free(void *ptr)
{
    if (malloc_heap_container == NULL)
        return;
    for (node_t *cur = malloc_heap_container->first;
        cur != NULL; cur = cur->next) {
        if (cur->ptr == ptr) {
            cur->freed = true;
            return;
        }
    }
}
