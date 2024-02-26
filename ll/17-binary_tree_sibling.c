#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling
 * @node: is a pointer to the node
 * Return: the sibling node or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !(node->parent))
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
