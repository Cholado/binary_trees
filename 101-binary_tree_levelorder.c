#include "binary_trees.h"

/**
 * f_on_level - perform a function on a specific level of a binary tree
 * @tree: tree to perform in
 * @level: level to perform in
 * @func: function to perform
 *
 * Return: 1 if things were done, 0 otherwise
 */
size_t f_on_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return (0);
	if (level != 0)
		return (do_at_level(tree->left, level - 1, func) +
			do_at_level(tree->right, level - 1, func));
	func(tree->n);
	return (1);
}

/**
 * binary_tree_levelorder - traverse tree in level order traversal
 * @tree: tree to traverse
 * @func: function to perform
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t depth, ret;

	if (tree == NULL)
		return;
	for (depth = 0, ret = 1; ret; depth++)
		ret = f_on_level(tree, depth, func);
}
