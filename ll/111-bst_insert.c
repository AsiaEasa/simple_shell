#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *CC;

    if (!tree)
        return (NULL);

    if (!(*tree))
    {
        new_node = binary_tree_node(NULL, value);
        if (!(new_node))
            return (NULL);
        *tree = new_node;
        return (new_node);
    }

    CC = *tree;

    while (1)
    {
        if (value < CC->n)
        {
            if (!(CC->left))
            {
                new_node = binary_tree_node(CC, value);
                if (!new_node)
                    return (NULL);
                CC->left = new_node;
                return (new_node);
            }
            else
                CC = CC->left;
        }
        else if (value > CC->n)
        {
            if (!(CC->right))
            {
                new_node = binary_tree_node(CC, value);
                if (!(new_node))
                    return (NULL);
                CC->right = new_node;
                return (new_node);
            }
            else
                CC = CC->right;
        }
        else
            return (NULL);
    }

    return (NULL);
}
