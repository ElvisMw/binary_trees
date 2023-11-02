#include "binary_trees.h"

/**
 * binary_tree_size - Measures the binary tree's size
 * @tree: Reresents pointer to the root node of the binary tree
 *
 * Return: Binary tree's size, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    size_t size = 0;

    if (tree)
    {
        size += 1;
        size += binary_tree_size(tree->left);
        size += binary_tree_size(tree->right);
    }
    return (size);
}