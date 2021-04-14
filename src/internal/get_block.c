/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** function that creates a memory block
*/

#include <math.h>
#include "malloc.h"
#include "malloc_types.h"

static node_t *get_last_node(heap_t *heap)
{
    node_t *res = heap->first;

    if (res == NULL)
        return (node_t *) (((char *)heap) + sizeof(heap_t));
    for (; res->next != NULL; res = res->next);
    return (res);
}

static void *create_block(heap_t *heap, size_t size)
{
    node_t *node = get_last_node(heap);

    heap->used_size += size + sizeof(node_t);
    if (heap->first == NULL)
        heap->first = (node_t *)(((char *)heap) + sizeof(heap_t));
    else {
        node->next =
            (node_t *) (((char *) node) + (node->block_size + sizeof(node_t)));
        node = node->next;
    }
    node->next = NULL;
    node->block_size = size;
    node->freed = false;

    node->ptr = (void *)(((char *)node) + sizeof(node_t));
    return (node->ptr);
}

static void *alloc_block(heap_t *heap, size_t size)
{
    const int page_size = getpagesize();
    const int number_of_pages = ceil(
        (double)(sizeof(node_t) + size) / (double)page_size
    );
    const size_t memory = round_to_pwr(page_size * number_of_pages);

    sbrk(memory);
    heap->total_size += memory;
    return create_block(heap, size);
}

void *get_block(heap_t *heap, size_t size)
{
    if (heap == NULL)
        return (NULL);
    if (size % 2 == 1)
        size++;
    if (size + sizeof(node_t) > heap->total_size - heap->used_size)
        return (alloc_block(heap, size));
    return (create_block(heap, size));
}
