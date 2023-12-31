#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    bst_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_bst(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);

    tree = bst_remove(tree, 84);
    printf("Removed 84...\n");
    binary_tree_print(tree);

    tree = bst_remove(tree, 79);
    printf("Removed 79...\n");
    binary_tree_print(tree);


    tree = bst_remove(tree, 2);
    printf("Removed 2...\n");
    binary_tree_print(tree);

    tree = bst_remove(tree, 47);
    printf("Removed 47...\n");
    binary_tree_print(tree);

    tree = bst_remove(tree, 1);
    printf("Removed 1...\n");
    binary_tree_print(tree);

    tree = bst_remove(tree, 680);
    printf("Removed 680...\n");
    binary_tree_print(tree);
    binary_tree_delete(tree);
    return (0);
}
