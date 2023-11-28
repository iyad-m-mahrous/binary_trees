#include "binary_trees.h"
#include "stdio.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to traverse
 * Return: 1 if tree is full otherwisw 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l = 1, r = 1;

	if (
			!tree ||
			!(
				(tree->left == NULL && tree->right == NULL) ||
				(tree->left != NULL && tree->right != NULL)
			 )
	   )
		return (0);

	l *= binary_tree_is_full(tree->left);
	r *= binary_tree_is_full(tree->right);

	return ((l == r) ? 1 : 0);
}
