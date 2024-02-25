#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child
 * of another node
 * @parent: pointer to the parent ot the node
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or
 * if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *NEW;

	if (!parent)
		return (NULL);

	NEW = binary_tree_node(parent, value);
	if (!NEW)
		return (NULL);

	if (parent->right)
	{
		parent->right->parent = NEW;
		NEW->right = parent->right;
		parent->right = NEW;
	}
	else
		parent->right = NEW;
	return (NEW);
}
