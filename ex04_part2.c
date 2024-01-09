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
    return (list == NULL) ? 0 : list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    if (list == NULL)
        return 0;
    while (list->next != NULL)
        list = list->next;
    return list->value;
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    if (list == NULL)
        return 0;
    for (; position && list != NULL; position--)
        list = list->next;
    return (list == NULL) ? 0 : list->value;
}

void list_dump(list_t *list, value_displayer_t val_disp)
{
    for (; list != NULL; list = list->next)
        val_disp(list->value);
}
