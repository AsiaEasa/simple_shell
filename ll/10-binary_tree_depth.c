#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth
 * @tree: a pointer to the node
 * Return: the depth of a node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *P;
	size_t D = 0;
	P = tree;

	if (!tree || !(P->parent))
		return (0);

	while (P->parent)
	{
		D++;
		P = P->parent;
	}

	return (D);
}
