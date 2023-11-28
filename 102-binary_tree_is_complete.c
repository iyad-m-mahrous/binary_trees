#include "binary_trees.h"
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height = 0, i = 0, nodes = 0, leaf_end = 0;
	binary_tree_t **queue, **front;

	if (!tree)
		return (0);
	height =  binary_tree_height(tree);
	nodes = (1 << (height + 1)) - 1;
	queue = calloc(nodes, sizeof(binary_tree_t *));
	if (!queue)
		return (0);
	queue[0] = (binary_tree_t *) tree;
	front = queue + 1;
	for (i = 0; i < nodes; i++)
	{
		if (queue[i] && queue[i]->left)
		{
			if (leaf_end)
				break;
			*front = queue[i]->left;
			front++;
		}
		else
			leaf_end = 1;
		if (queue[i] && queue[i]->right)
		{
			if (leaf_end)
				break;
			*front = queue[i]->right;
			front++;
		}
		else
			leaf_end = 1;
		if (leaf_end > 1)
			break;
	}
	free(queue);
	return (i < (nodes - 1) ? 0 : 1);
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
