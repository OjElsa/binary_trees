#include "binary_trees.h"
/**
 * binary_tree_height - Measure the height of a binary tree
 * @tree: A pointer to the root node of the tree
 * Return: The height of the tree, 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_size = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_size = 1 + binary_tree_height(tree->right);

	return ((left_size > right_size) ? left_size : right_size);
}

/**
 * binary_tree_is_full - Check if a binary tree is full
 * @tree: A pointer to the root node of the tree
 * Return: 1 if the tree is full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full
				(tree->right));
	return (0);
}


/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is NULL or not perfect, return 0, ortherwise return 1
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);

	return (binary_tree_is_full(tree) && binary_tree_height
			(tree->left) == height - 1);
}
