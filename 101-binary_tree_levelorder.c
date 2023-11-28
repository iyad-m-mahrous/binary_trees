#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through a binary tree
 * using levelorder traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 *  The value in the node must be passed as a parameter to this function.
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = 0, i = 0, nodes = 0;
	binary_tree_t **queue, **front, **pointer;

	if (!tree || !func)
		return;

	height =  binary_tree_height(tree);
	nodes = (1 << (height + 1)) - 1;
	queue = calloc(nodes, sizeof(binary_tree_t *));
	if (!queue)
		return;
	queue[0] = (binary_tree_t *) tree;
	pointer = queue;
	front = queue + 1;
	func(pointer[0]->n);

	for (i = 0; i < nodes; i++)
	{
		if (queue[i]->left)
		{
			*front = queue[i]->left;
			func((*front)->n);
			front++;
		}
		if (queue[i]->right)
		{
			*front = queue[i]->right;
			func((*front)->n);
			front++;
		}
	}
	free(queue);
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
