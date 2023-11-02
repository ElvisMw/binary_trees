#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the number of leaf nodes in a binary tree
 * @tree: Represents a pointer to the binary tree's root node
 *
 * Return: The number of leaf nodes in the binary tree, or 0 if the tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t leaves = 0;

    if (tree)
    {
        leaves += (!tree->left && !tree->right) ? 1 : 0;
        leaves += binary_tree_leaves(tree->left);
        leaves += binary_tree_leaves(tree->right);
    }
    return (leaves);
}