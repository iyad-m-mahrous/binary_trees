#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to be checked
 * Return: 1 if complete tree otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t leaves_count = 0, total_depth = 0, height = 0;

	if (!tree)
		return (0);

	leaves_count = binary_tree_leaves(tree);
	total_depth =  binary_tree_leaves_depth(tree);
	height =  binary_tree_height(tree);
	printf("Leaves_count = %lu, total_depth = %lu, height = %lu\n", leaves_count,  total_depth, height);
	if ((float)(total_depth / leaves_count) == (float)(height))
		return (1);
	return (0);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the leaves
 * Return: the count of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	count += binary_tree_leaves(tree->left);
	count += binary_tree_leaves(tree->right);
	return (count);
}

/**
 * binary_tree_leaves_depth - sum of depths of the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the leaves
 * Return: the count of leaves
 */
size_t binary_tree_leaves_depth(const binary_tree_t *tree)
{
	size_t depths = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
	{
		printf("tree->n = %d, binary_tree_depth(tree) = %lu\n",tree->n, binary_tree_depth(tree));
		return (binary_tree_depth(tree));
	}

	depths += binary_tree_leaves_depth(tree->left);
	depths += binary_tree_leaves_depth(tree->right);
	return (depths);
}


/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to node to get depth
 * Return: the depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree || !tree->parent)
		return (0);

	depth = binary_tree_depth(tree->parent);
	return (++depth);
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
