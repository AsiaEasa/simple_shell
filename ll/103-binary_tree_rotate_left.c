#include "binary_trees.h"

/**
 *binary_tree_rotate_left - rotate to the left
 *@tree: pointer to the tree
 *Return: the new root
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *NEW;
    if (!tree || !(tree->right))
        return NULL;

    NEW = tree->right;
    tree->right = NEW->left;

    if (NEW->left)
    {
        NEW->left->parent = tree;
    }

    NEW->left = tree;
    NEW->parent = tree->parent;

    if (tree->parent)
    {
        if (tree == tree->parent->left)
        {
            tree->parent->left = NEW;
        }
        else
        {
            tree->parent->right = NEW;
        }
    }

    tree->parent = NEW;

    return NEW;
}
