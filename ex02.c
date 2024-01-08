/*
** EPITECH PROJECT, 2024
** ppool04pm
** File description:
** ex02
*/

#include <stdlib.h>

#include "int_list.h"

int int_list_get_elem_at_front(int_list_t *list)
{
    return (list == NULL) ? 0 : list->value;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    if (list == NULL)
        return 0;
    while (list->next != NULL)
        list = list->next;
    return list->value;
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    if (list == NULL)
        return 0;
    while (position > 0 && list != NULL)
        list = list->next;
    return (list == NULL) ? 0 : list->value;
}
