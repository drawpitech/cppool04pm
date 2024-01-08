/*
** EPITECH PROJECT, 2024
** ppool04pm
** File description:
** int_list
*/

#include <stdio.h>
#include <stdlib.h>

#include "int_list.h"

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t **end = front_ptr;

    if (front_ptr == NULL)
        return false;
    while (*end != NULL)
        end = &(*end)->next;
    *end = malloc(sizeof(int_list_t));
    **end = (int_list_t) {elem, NULL};
    return true;
}

void int_list_dump(int_list_t *list)
{
    while (list != NULL) {
        printf("%d\n", list->value);
        list = list->next;
    }
}

unsigned int int_list_get_size(int_list_t *list)
{
    size_t size = 0;

    while (list != NULL) {
        size += 1;
        list = list->next;
    }
    return size;
}

bool int_list_is_empty(int_list_t *list)
{
    return (list == NULL);
}

static
int_list_t **get_last(int_list_t **front_ptr)
{
    int_list_t **end = front_ptr;

    while (*end != NULL && (*end)->next != NULL)
        end = &(*end)->next;
    return end;
}

void int_list_clear(int_list_t **front_ptr)
{
    int_list_t **end;

    while (*front_ptr != NULL) {
        end = get_last(front_ptr);
        free(*end);
        *end = NULL;
    }
}
