#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int is_bst = 1;

	if (!tree)
		return (0);

	binary_tree_is_bst(tree->left);
	if (tree->parent->n <= tree->n)
		is_bst = 0;
	binary_tree_is_bst(tree->right);

	return (is_bst);
}
