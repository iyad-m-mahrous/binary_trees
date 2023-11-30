#include "binary_trees.h"
/**
 * array_to_bst( - a function that builds a Binary Search Tree from an array
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *new_node, *ptr;

	new_node = (bst_t *) calloc(1, sizeof(bst_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;

	if (!*tree)
		return (*tree = new_node);

	ptr = *tree;
	while (ptr)
	{
		if (value < ptr->n)
		{
			if (ptr->left)
				ptr = ptr->left;
			else
			{
				ptr->left = new_node;
				new_node->parent = ptr;
				return (new_node);
			}
		}
		else if (value > ptr->n)
		{
			if (ptr->right)
				ptr = ptr->right;
			else
			{
				ptr->right = new_node;
				new_node->parent = ptr;
				return (new_node);
			}
		}
		else
			break;
	}
	free(new_node);
	return (NULL);
}
