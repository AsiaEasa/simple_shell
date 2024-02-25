#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node
 * @value: value to put in the new node
 * Return: A pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *NEW;

	NEW = malloc(sizeof(binary_tree_t));
	if (!NEW)
		return (NULL);

	NEW->n = value;
	NEW->parent = parent;
	NEW->left = NULL;
	NEW->right = NULL;

	return (NEW);
}
