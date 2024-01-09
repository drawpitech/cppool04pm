/*
** EPITECH PROJECT, 2024
** ppool04pm
** File description:
** ex07_part2
*/

#include <stdbool.h>
#include <stdlib.h>

#include "map.h"

bool map_add_elem(
    map_t **map_ptr,
    void *key,
    void *value,
    key_comparator_t key_cmp)
{
    map_t **ptr = map_ptr;
    pair_t *pair;
    int cmp = 0;

    if (map_ptr == NULL || key == NULL || key_cmp == NULL)
        return false;
    for (; *ptr != NULL && cmp <= 0; ptr = &(*ptr)->next) {
        pair = (*ptr)->value;
        if (pair == NULL)
            return false;
        cmp = key_cmp(pair->key, key);
        if (cmp == 0) {
            pair->value = value;
            return true;
        }
    }
    pair = malloc(sizeof(pair_t));
    *pair = (pair_t){key, value};
    list_add_elem_at_front(ptr, pair);
    return true;
}

void *map_get_elem(map_t *map, void *key, key_comparator_t key_cmp)
{
    pair_t *pair;

    while (map != NULL) {
        pair = map->value;
        if (key_cmp(pair->key, key) == 0)
            return pair->value;
        map = map->next;
    }
    return NULL;
}

bool map_del_elem(map_t **map_ptr, void *key, key_comparator_t key_cmp)
{
    pair_t *pair;

    while (*map_ptr != NULL) {
        pair = (*map_ptr)->value;
        if (pair != NULL && key_cmp(pair->key, key) == 0) {
            free(pair);
            return list_del_elem_at_front(map_ptr);
        }
        map_ptr = &(*map_ptr)->next;
    }
    return false;
}

void map_clear(map_t **map_ptr)
{
    while (*map_ptr != NULL) {
        if ((*map_ptr)->value != NULL)
            free((*map_ptr)->value);
        list_del_elem_at_front(map_ptr);
    }
}
