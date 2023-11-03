#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL;

    if (parent == NULL)
        return (NULL);

    node = binary_tree_node(parent, value);
    if (node == NULL)
        return (NULL);

    if (parent->left != NULL)
    {
        node->left = parent->left;
        parent->left->parent = node;
    }

    parent->left = node;

    return (node);
}
