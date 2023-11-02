#include "binary_trees.h"

/**
 * binary_tree_postorder - This traverses a binary tree via postorder traversal
 * @tree: Represents pointer the to binary tree's root's node to traverse
 * @func: Represents the pointer to a function to apply to each visited node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree && func)
    {
        binary_tree_postorder(tree->left, func);
        binary_tree_postorder(tree->right, func);
        func(tree->n);
    }
}
