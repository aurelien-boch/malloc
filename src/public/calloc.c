/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** my calloc implementation
*/

#include <stddef.h>
#include <string.h>
#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    char *res;
    size_t total = nmemb * size;

    if (nmemb * size > __INT_MAX__ || total == 0)
        return (NULL);
    res = malloc(total);
    if (res == NULL)
        return (NULL);
    memset(res, 0, total);
    return (res);
}