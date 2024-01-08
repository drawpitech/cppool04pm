/*
** EPITECH PROJECT, 2024
** ppool04pm
** File description:
** ex03
*/

#include <stdbool.h>
#include <stdlib.h>

#include "int_list.h"

bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *node = NULL;

    if (front_ptr == NULL || *front_ptr == NULL)
        return false;
    node = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    free(node);
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    if (front_ptr == NULL || *front_ptr == NULL)
        return false;
    while ((*front_ptr)->next != NULL)
        front_ptr = &(*front_ptr)->next;
    free((*front_ptr)->next);
    *front_ptr = NULL;
    return true;
}

bool int_list_del_elem_at_position(
    int_list_t **front_ptr,
    unsigned int position)
{
    if (front_ptr == NULL || *front_ptr == NULL)
        return false;
    for (; position--;) {
        if (*front_ptr == NULL)
            return false;
        front_ptr = &(*front_ptr)->next;
    }
    return int_list_del_elem_at_front(front_ptr);
}
