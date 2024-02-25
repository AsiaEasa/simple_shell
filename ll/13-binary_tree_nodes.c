#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in
 * @tree: pointer to the root node
 * Return: num of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node_L = 0;
	size_t node_R = 0;
	size_t nodes = 0;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
		nodes = 1;

	node_L += binary_tree_nodes(tree->left);
	node_R += binary_tree_nodes(tree->right);

	return (node_R + node_L + nodes);
}
