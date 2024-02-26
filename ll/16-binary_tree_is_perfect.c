#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to find a leaf in.
 * Return: A pointer to the first leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (binary_tree_is_leaf(tree) == 1)
		return (tree);
	if (tree->left)
		return get_leaf(tree->left);
	else
		return get_leaf(tree->right);
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to check.
 * @D: The depth of one leaf.
 * @L: Level of current node.
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect(const binary_tree_t *tree,
		size_t D, size_t L)
{
	int per_L, per_R;
	if (binary_tree_is_leaf(tree))
		return (L == D);
	if (!(tree->left) || !(tree->right))
		return (0);
	per_L = is_perfect(tree->left, D, L + 1);
	per_R = is_perfect(tree->right, D, L + 1);
	return (per_L && per_R);
}

/**
 * binary_tree_depth - measures the depth
 * @tree: a pointer to the node
 * Return: the depth of a node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *P;
	size_t D = 0;
	P = tree;

	if (!tree || !(P->parent))
		return (0);

	while (P->parent)
	{
		D++;
		P = P->parent;
	}

	return (D);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to check.
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t D = 0, B = 0;
	const binary_tree_t *F;

	if (!tree)
		return (0);
	F = get_leaf(tree);
	D = binary_tree_depth(F);
	B = is_perfect(tree, D, 0);
	return (B);
}
