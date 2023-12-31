#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: is a pointer to the node to find the uncle
 * Return: a pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandpa, *pa;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	grandpa = node->parent->parent;
	pa = node->parent;

	if (pa == grandpa->left)
	{
		if (grandpa->right)
			return (grandpa->right);
	}
	else
	{
		if (grandpa->left)
			return (grandpa->left);
	}
	return (NULL);
}
