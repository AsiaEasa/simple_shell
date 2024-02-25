#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves
 * @tree: pointer to the root node
 * Return: The number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_L = 0;
	size_t leaves_R = 0;

	if (!tree)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);

	leaves_L += binary_tree_leaves(tree->left);
	leaves_R += binary_tree_leaves(tree->right);

	return (leaves_R + leaves_L);
}
