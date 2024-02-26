#include "binary_trees.h"

/**
 * binary_trees_ancestor - lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{

	const binary_tree_t *temp_first = first;
	const binary_tree_t *temp_second = second;

	if (!first || !second)
		return NULL;

	if (first == second)
		return (binary_tree_t *)first;

	while (temp_first != temp_second)
	{
		temp_first = temp_first->parent ? temp_first->parent : second;
		temp_second = temp_second->parent ? temp_second->parent : first;
	}

	return (binary_tree_t *)temp_first;
}
