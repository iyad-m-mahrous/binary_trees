#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to get rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree)
		return (NULL);

	temp = tree->right;

	tree->right = temp->left;
	temp->parent = tree->parent;
	tree->parent = temp;
	if (temp->left)
		temp->left->parent = tree;
	temp->left = tree;

	return (temp);
}
