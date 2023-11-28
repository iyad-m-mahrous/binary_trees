#include "binary_trees.h"
/**
 * binary_tree_height - goes through a binary tree using
 * @tree: pointer to the root node of the tree to get height
 * Return: the height of a binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return (1 + ((left_height > right_height) ? left_height : right_height));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to get balance factor
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = (int) binary_tree_height(tree->left) + 1;
	if (tree->right)
		r_height = (int) binary_tree_height(tree->right) + 1;

	return (l_height - r_height);
}
