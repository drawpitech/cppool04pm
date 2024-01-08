/*
** EPITECH PROJECT, 2024
** ppool04pm
** File description:
** ex01
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "int_list.h"

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *node = NULL;

    if (front_ptr == NULL)
        return false;
    node = malloc(sizeof(int_list_t));
    if (node == NULL)
        return false;
    *node = (int_list_t){ elem, *front_ptr };
    *front_ptr = node;
    return true;
}

bool int_list_add_elem_at_position(
    int_list_t **front_ptr,
    int elem,
    unsigned int position
)
{
    if (front_ptr == NULL)
        return false;
    for (; position--;) {
        if (*front_ptr == NULL)
            return false;
        front_ptr = &(*front_ptr)->next;
    }
    return int_list_add_elem_at_front(front_ptr, elem);
}
