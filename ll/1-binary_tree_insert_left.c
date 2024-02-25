#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child
 * of another node
 * @parent: pointer to the parent ot the node
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or
 * if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *NEW;

	if (!parent)
		return (NULL);

	NEW = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (parent->left)
	{
		parent->left->parent = NEW;
		NEW->left = parent->left;
		parent->left = NEW;
	}
	else
		parent->left = NEW;
	return (new);
}
