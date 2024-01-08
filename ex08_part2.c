/*
** EPITECH PROJECT, 2024
** ppool04pm
** File description:
** ex8_part2
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "tree.h"

bool init_tree(tree_t **tree_ptr, void *data)
{
    if (tree_ptr)
        return false;
    *tree_ptr = malloc(sizeof(tree_t));
    if (*tree_ptr)
        return false;
    **tree_ptr = (tree_t){
        .parent = NULL,
        .data = data,
        .children = NULL,
    };
    return true;
}

tree_t *tree_add_child(tree_t *node, void *data)
{
    tree_t *new;

    if (node == NULL)
        return NULL;
    if (init_tree(&new, data))
        return NULL;
    new->parent = node;
    if (list_add_elem_at_back(&(new->children), new))
        free(new);
    return new;
}

bool tree_destroy(tree_t **tree_ptr)
{
    list_t *children;

    if (tree_ptr == NULL && *tree_ptr == NULL)
        return false;
    children = (*tree_ptr)->children;
    while (children != NULL) {
        tree_destroy(children->value);
        list_del_elem_at_front(&children);
    }
    free(*tree_ptr);
    return true;
}
