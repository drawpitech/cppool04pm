/*
** EPITECH PROJECT, 2024
** ppool04pm
** File description:
** ex04_part1
*/

#include <stdlib.h>

#include "list.h"

unsigned int list_get_size(list_t *list)
{
    size_t size = 0;

    for (; list != NULL; size++)
        list = list->next;
    return size;
}

bool list_is_empty(list_t *list)
{
    return (list == NULL);
}

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *node;

    if (front_ptr == NULL)
        return false;
    node = malloc(sizeof(list_t));
    if (node == NULL)
        return false;
    *node = (list_t){
        .value = elem,
        .next = *front_ptr,
    };
    *front_ptr = node;
    return true;
}

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    if (front_ptr == NULL)
        return false;
    while (*front_ptr != NULL)
        front_ptr = &(*front_ptr)->next;
    return list_add_elem_at_front(front_ptr, elem);
}

bool list_add_elem_at_position(
    list_t **front_ptr,
    void *elem,
    unsigned int pos)
{
    if (front_ptr == NULL)
        return false;
    for (; *front_ptr != NULL && pos; pos--)
        front_ptr = &(*front_ptr)->next;
    return list_add_elem_at_front(front_ptr, elem);
}
