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

	if (tree->left)
		L = 1 + binary_tree_height(tree->left);

	if (tree->right)
		R = 1 + binary_tree_height(tree->right);

	if (L >= R)
		return (L);
	else
		return (R);
}

/**
 * print_level - prints a level
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * @level: the level to print
 */
void print_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 0)
	{
		func(tree->n);
		return;
	}

	print_level(tree->left, func, level - 1);
	print_level(tree->right, func, level - 1);
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t H, L;

	if (!tree || !func)
		return;

	H = binary_tree_height(tree);

	L = 0;
	while (L <= H)
	{
		print_level(tree, func, L);
		L++;
	}
}
