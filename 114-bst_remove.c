#include "binary_trees.h"
/**
 * bst_remove -  removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: is the value to remove in the tree
 * Return: a pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL, *temp;

	node = bst_search(root, value);

	if (!node)
		return (root);

	if (node->left && node->right)
	{
		temp = node->right;
		while (temp->left)
			temp = temp->left;
		temp->parent->left = NULL;
		temp->left = node->left;
		temp->right = node->right;
	}
	else
	{
		if (node->left)
			temp = node->left;
		else if (node->right)
			temp = node->right;
		else
			temp = NULL;
	}
	if (temp)
		temp->parent = node->parent;
	if (node->parent && node == node->parent->left)
		node->parent->left = temp;
	else if (node->parent && node == node->parent->right)
		node->parent->right = temp;

	return (root);
}

/**
 * bst_search -  a function that searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: is the value to search in the tree
 * Return: a pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree || tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));

	return (NULL);
}
