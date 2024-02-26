#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate the binary tree to the right
 * @tree: pointer to the root of the tree
 * Return: pointer to the new root after rotation
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *NEW;

    if (!tree || !(tree->left))
        return NULL;

    NEW = tree->left;
    tree->left = NEW->right;

    if (NEW->right)
    {
        NEW->right->parent = tree;
    }

    NEW->right = tree;
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
