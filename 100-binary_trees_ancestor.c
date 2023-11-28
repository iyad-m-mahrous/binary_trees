#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: return a pointer to the lowest common ancestor node otherwise NULL
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first,
		const binary_tree_t *second
		)
{
	const binary_tree_t *p_first, *p_second;

	p_first = first;
	p_second = second;

	while (p_first)
	{
		while (p_second)
		{
			if (p_first == p_second)
				return ((binary_tree_t *) p_first);
			p_second = p_second->parent;
		}
		p_second = second;
		p_first = p_first->parent;
	}
	return (NULL);
}
