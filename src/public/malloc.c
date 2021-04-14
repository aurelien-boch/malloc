/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** my malloc implementation
*/

#include <stddef.h>
#include <unistd.h>
#include <math.h>
#include "malloc.h"

heap_t *malloc_heap_container = NULL;

static void init_global(size_t size)
{
    const size_t page_size = getpagesize() * 2;
    const size_t number_of_pages = ceil(
        (double)(size + sizeof(heap_t)) / (double)page_size
    );
    const size_t mem = number_of_pages * page_size;

    malloc_heap_container = sbrk(mem);
    malloc_heap_container->first = NULL;
    malloc_heap_container->used_size = sizeof(heap_t);
    malloc_heap_container->total_size = page_size;
}

void *malloc(size_t size)
{
    node_t *block;

    if (malloc_heap_container == NULL)
        init_global(size);
    if (size == 0)
        return (NULL);
    block = find_block(malloc_heap_container, size);
    if (block != NULL)
        return (block->ptr);
    return (get_block(malloc_heap_container, size));
}