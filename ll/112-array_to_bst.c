#include "binary_trees.h"
/**
 * array_to_bst - change an array to a BST tree
 * @array: array
 * @size: size of array
 * Return: BST tree from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	int i;
	bst_t *root;

	root = NULL;
	if (size == 0)
		return (NULL);

	i = 0;
	while (i < (int)size)
	{
		if (i == 0)
		{
			if(!bst_insert(&root, array[i]))
			return (NULL);
		}
		else
		{
			if(!bst_insert(&root, array[i]))
			return (NULL);
		}
		i++;
	}
	return (root);
}
