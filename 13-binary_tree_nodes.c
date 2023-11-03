#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: Pointer to the root node of the tree to count the number of nodes.
 * Return: If tree is NULL, the function must return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t count = 0;
	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
		count += 1;

	return (count);
}