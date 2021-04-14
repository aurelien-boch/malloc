/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** main header
*/

#ifndef MALLOC_H
#define MALLOC_H

#include <stddef.h>
#include "malloc_types.h"

extern heap_t *malloc_heap_container;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
size_t round_to_pwr(size_t x);
void *get_block(heap_t *heap, size_t size);
node_t *find_block(heap_t *heap, size_t required_size);
inline size_t align(size_t n)
{
    return ((n % 2 == 1) ? n + 1 : n);
}

#endif //MALLOC_H
