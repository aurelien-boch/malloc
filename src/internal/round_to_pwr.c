/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** function that rounds a number to the closest power of 2
*/

#include <stddef.h>

size_t round_to_pwr(size_t x)
{
    --x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return (x + 1);
}
