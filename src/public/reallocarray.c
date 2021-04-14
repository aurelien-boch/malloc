/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** my reallocarray implementation
*/

#include <stddef.h>
#include "malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    if ((long) nmemb * size > __INT_MAX__)
        return (NULL);
    return (realloc(ptr, nmemb * size));
}
