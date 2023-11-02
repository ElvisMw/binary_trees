#include "binary_trees.h"

/**
 * binary_tree_nodes - This counts the number of non-leaf nodes in a binary tree
 * @tree: Represents a pointer to the root node of the binary tree
 *
 * Return: The numerical value of non-leaf nodes in
 * the binary tree, or 0 if the tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t nodes = 0;

    if (tree)
    {
        nodes += (tree->left || tree->right) ? 1 : 0;
        nodes += binary_tree_nodes(tree->left);
        nodes += binary_tree_nodes(tree->right);
    }
    return (nodes);
}