/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** my realloc implementation
*/

#include <stddef.h>
#include "malloc.h"

static node_t *get_node(void *ptr)
{
    for (node_t *cur = malloc_heap_container->first;
        cur != NULL; cur = cur->next)
        if (cur->ptr == ptr)
            return cur;
    return (NULL);
}

static void
copy_mem(void *new_ptr, void *old_ptr, size_t new_size, size_t old_size)
{
    const size_t smallest = (new_size > old_size) ? old_size : new_size;

    for (size_t i = 0; i < smallest; i++)
        ((char *)new_ptr)[i] = ((char *)old_ptr)[i];
}

void *realloc(void *ptr, size_t size)
{
    node_t *old;

    if (ptr == NULL)
        return malloc(size);
    old = get_node(ptr);
    free(ptr);
    ptr = malloc(size);
    copy_mem(ptr, old->ptr, size, old->block_size);
    return (ptr);
}
