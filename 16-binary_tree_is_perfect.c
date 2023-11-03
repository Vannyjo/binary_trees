#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, the function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = 0, right_height = 0;

	if (tree->left)
		left_height = binary_tree_height(tree->left) + 1;
	if (tree->right)
		right_height = binary_tree_height(tree->right) + 1;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 * Return: If tree is NULL, must return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_size = binary_tree_size(tree->left);
	size_t right_size = binary_tree_size(tree->right);

	return (1 + left_size + right_size);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * Return: If tree is NULL, the function must return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t height = binary_tree_height(tree);
	size_t perfect_size = (1 << (height + 1)) - 1;

	return (perfect_size == binary_tree_size(tree));
}
