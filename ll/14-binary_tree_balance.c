#include "binary_trees.h"

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

	L = 1 + binary_tree_height(tree->left);
	R = 1 + binary_tree_height(tree->right);

	if (L >= R)
		return (L);
	else
		return (R);
}

/**
 * binary_tree_balance - measures the balance factor
 * @tree: is a pointer to the root node
 * Return: The balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t L, R;
	L = 0;
	R = 0;

	if (!tree)
		return (0);

	L = binary_tree_height(tree->left);
	R = binary_tree_height(tree->right);

	return (int)(L - R);
}
