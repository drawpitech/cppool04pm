/*
** EPITECH PROJECT, 2024
** ppool04pm
** File description:
** ex07_part1
*/

#include <stdbool.h>

#include "list.h"
#include "map.h"

unsigned int map_get_size(map_t *map)
{
    return list_get_size(map);
}

bool map_is_empty(map_t *map)
{
    return list_is_empty(map);
}
