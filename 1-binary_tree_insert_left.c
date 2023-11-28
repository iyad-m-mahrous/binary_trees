#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent:  a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = (binary_tree_t *) calloc(1, sizeof(*new_node));

	if (!new_node)
		return (NULL);

	if (parent->left)
		parent->left->parent = new_node;
	new_node->left = parent->left;
	new_node->n = value;
	new_node->parent = parent;
	parent->left = new_node;

	return (new_node);
}
