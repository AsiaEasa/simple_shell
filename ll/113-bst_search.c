#include "binary_trees.h"
/**
 * bst_search - search for a special value in the tree and return the node
 * @tree: tree to go through
 * @value: value to search
 * Return: the node with the value or NULL if the value is not in the tree
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);
	else if (tree->n < value)
		return (bst_search(tree->right, value));
	return (bst_search(tree->left, value));
}
