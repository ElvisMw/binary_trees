#include "binary_trees.h"

/**
 * binary_tree_uncle - This finds the binary tree node's uncle
 * @node: Represents pointer to the node for which to find the uncle
 *
 * Return: A pointer to the uncle node, or NULL if no uncle is found
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return (NULL);

    if (node->parent->parent->left == node->parent)
        return (node->parent->parent->right);
    return (node->parent->parent->left);
}