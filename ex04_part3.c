/*
** EPITECH PROJECT, 2024
** ppool04pm
** File description:
** ex04_part3
*/

#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *node = NULL;

    if (front_ptr == NULL || *front_ptr == NULL)
        return false;
    node = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(node);
    return true;
}

bool list_del_elem_at_back(list_t **front_ptr)
{
    if (front_ptr == NULL || *front_ptr == NULL)
        return false;
    while ((*front_ptr)->next != NULL)
        front_ptr = &(*front_ptr)->next;
    free(*front_ptr);
    *front_ptr = NULL;
    return true;
}

bool list_del_elem_at_position(
    list_t **front_ptr,
    unsigned int position)
{
    if (front_ptr == NULL || *front_ptr == NULL)
        return false;
    for (; position--;) {
        if (*front_ptr == NULL)
            return false;
        front_ptr = &(*front_ptr)->next;
    }
    return list_del_elem_at_front(front_ptr);
}

void list_clear(list_t **front)
{
    if (front == NULL)
        return;
    while (*front != NULL)
        list_del_elem_at_front(front);
}
