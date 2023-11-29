#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to get rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree)
		return (NULL);

	temp = tree->left;

	tree->left = temp->right;
	temp->parent = tree->parent;
	tree->parent = temp;
	if (temp->right)
		temp->right->parent = tree;
	temp->right = tree;

	return (temp);
}
