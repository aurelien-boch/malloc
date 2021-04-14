/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** function that finds a free block
*/

#include "malloc.h"

node_t *find_block(heap_t *heap, size_t required_size)
{
    node_t *closest = NULL;
    size_t closest_size = -1;

    for (node_t *cur = heap->first; cur != NULL; cur = cur->next) {
        if (
            cur->freed == true &&
            cur->block_size >= required_size &&
            cur->block_size < closest_size
        ) {
            closest = cur;
            closest_size = cur->block_size;
        }
    }
    if (closest != NULL)
        closest->freed = false;
    return (closest);
}
