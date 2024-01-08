/*
** EPITECH PROJECT, 2024
** ppool04pm
** File description:
** ex08_part1
*/

#include <stdbool.h>
#include <stdlib.h>

#include "tree.h"

bool tree_is_empty(tree_t *tree)
{
    return (tree == NULL);
}

void tree_node_dump(tree_t *node, dump_func_t dump_func)
{
    list_t *ptr;

    if (node == NULL)
        return;
    dump_func(node->data);
    ptr = node->children;
    while (ptr != NULL)
        tree_node_dump(ptr->value, dump_func);
}
