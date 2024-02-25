#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: the size or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t L, R;

	if (!tree)
		return (0);

        L = binary_tree_size(tree->left);
        R = binary_tree_size(tree->right);
	return (L + R + 1);
}
