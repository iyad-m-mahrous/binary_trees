#include "binary_trees.h"
#include <limits.h>
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bst_check(tree, INT_MIN, INT_MAX));
}

/**
 * bst_check - Checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * @min: min value in the BST
 * @max: mx value in the BST
 * Return:  1 if BST otherwise 0
 */
int bst_check(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	return (
			bst_check(tree->left, min, tree->n - 1) &&
			bst_check(tree->right, tree->n + 1, max)
	       );
}
