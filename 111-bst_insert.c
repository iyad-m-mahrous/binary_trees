#include "binary_trees.h"
/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *ptr;

	ptr = *tree;

	if (!ptr)
		return ((*tree) =  binary_tree_node(ptr, value));

	while (ptr)
	{
		if (value < ptr->n)
		{
			if (ptr->left)
				ptr = ptr->left;
			else
			{
				ptr->left = binary_tree_node(ptr, value);
				return (ptr->left);
			}
		}
		else if (value > ptr->n)
		{
			if (ptr->right)
				ptr = ptr->right;
			else
			{
				ptr->right = binary_tree_node(ptr, value);
				return (ptr->right);
			}
		}
		else
			break;
	}
	return (NULL);
}
