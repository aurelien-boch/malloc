/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** types header
*/

#ifndef MALLOC_TYPES_H
#define MALLOC_TYPES_H

#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct node_s {
    size_t block_size;
    bool freed;
    void *ptr;
    struct node_s *next;
} node_t;

typedef struct {
    size_t total_size;
    size_t used_size;
    node_t *first;
} heap_t;

#endif //MALLOC_TYPES_H
