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
