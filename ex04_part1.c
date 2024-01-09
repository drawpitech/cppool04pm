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

    while (list != NULL) {
        size += 1;
        list = list->next;
    }
    return size;
}

bool list_is_empty(list_t *list)
{
    return (list == NULL);
}

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *node = NULL;

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
    list_t **end = front_ptr;

    if (front_ptr == NULL)
        return false;
    while (*end != NULL)
        end = &(*end)->next;
    *end = malloc(sizeof(list_t));
    **end = (list_t) {
        .value = elem,
        .next = NULL,
    };
    return true;
}

bool list_add_elem_at_position(
    list_t **front_ptr,
    void *elem,
    unsigned int pos)
{
    if (front_ptr == NULL)
        return false;
    for (; pos; pos--) {
        if (*front_ptr == NULL)
            return false;
        front_ptr = &(*front_ptr)->next;
    }
    return list_add_elem_at_front(front_ptr, elem);
}
