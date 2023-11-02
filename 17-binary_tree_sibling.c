#include "binary_trees.h"

/**
 * binary_tree_sibling - This finds the binary tree node's sibling
 * @node: Represents pointer to the node for which to find the sibling
 *
 * Return: A pointer to the sibling node, or NULL if no sibling is found
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return (NULL);

    if (node->parent->left == node)
        return (node->parent->right);
    return (node->parent->left);
}