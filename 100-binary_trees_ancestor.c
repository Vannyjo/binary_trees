#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure the depth.
 * Return: If tree is NULL, the function must return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: First node.
 * @second: Second node.
 * Return: Lowest common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    size_t depth_f = 0, depth_s = 0;
    const binary_tree_t *aux = NULL;

    depth_f = binary_tree_depth(first);
    depth_s = binary_tree_depth(second);

    if (depth_f && depth_s)
    {
        if (depth_f > depth_s)
        {
            aux = first;
            first = second;
            second = aux;
        }

        while (first)
        {
            aux = second;
            while (aux)
            {
                if (first == aux)
                    return ((binary_tree_t *)first);
                aux = aux->parent;
            }
            first = first->parent;
        }
    }
    return (NULL);
}
