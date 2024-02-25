#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: height or 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t L, R;
	L = 0;
	R = 0;

	if (!tree)
		return (0);

	if (tree->left)
		L = 1 + binary_tree_height(tree->left);

	if (tree->right)
		R = 1 + binary_tree_height(tree->right);

	if (L >= R)
		return (L);
	else
		return (R);
}
