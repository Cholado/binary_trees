#include "binary_trees.h"

int check_bts(const binary_tree_t *node, int min, int max);

/**
 * check_bts - checks if a binary tree is a valid binary search tree
 * @node: pointer node to check
 * @min: min value
 * @max: max value
 *
 * Return: true if the given tree is a BST and its values are >= min and <= max
 */
int check_bts(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);
	if (node->n < min || node->n > max)
		return (0);
	return (
		check_bts(node->left, min, node->n - 1) &&
		check_bts(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (check_bts(tree, INT_MIN, INT_MAX));
}
