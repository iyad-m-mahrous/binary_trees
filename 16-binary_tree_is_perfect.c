#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to be checked
 * Return: i if perfect tree otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, size = 0;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);
	size =  binary_tree_size(tree);

	if ((1 << ((int)height + 1)) - 1 == (int)size)
		return (1);
	return (0);
}

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
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: the size of a binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	tree_size++;
	tree_size += binary_tree_size(tree->left);
	tree_size += binary_tree_size(tree->right);
	return (tree_size);
}
