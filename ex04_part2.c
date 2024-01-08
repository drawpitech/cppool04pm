/*
** EPITECH PROJECT, 2024
** ppool04pm
** File description:
** ex04_part2
*/

#include <stdlib.h>

#include "list.h"

void *list_get_elem_at_front(list_t *list)
{
    return (list == NULL) ? NULL : list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    if (list == NULL)
        return NULL;
    while (list->next != NULL)
        list = list->next;
    return list_get_elem_at_front(list);
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    if (list == NULL)
        return NULL;
    for (; list != NULL && position; position--)
        list = list->next;
    return list_get_elem_at_front(list);
}

void list_dump(list_t *list, value_displayer_t val_disp)
{
    for (; list != NULL; list = list->next)
        val_disp(list->value);
}
