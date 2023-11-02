#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the node's depth in a binary tree
 * @tree: Reresents the pointer to the node for which the depth will be measured
 *
 * Return: The depth of the node, or 0 if the node is NULL or the root
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}