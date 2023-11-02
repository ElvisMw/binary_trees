#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using preorder traversal
 * @tree: Represents pointer to the root node of the binary tree to traverse
 * @func: Reresents a pointer to a function to apply to each visited node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree && func)
    {
        func(tree->n);
        binary_tree_preorder(tree->left, func);
        binary_tree_preorder(tree->right, func);
    }
}