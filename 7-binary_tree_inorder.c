#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree using inorder traversal
 * @tree: Represents a pointer to the root node of the binary tree to traverse
 * @func: Represents a pointer to a function to apply to each visited node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree && func)
    {
        binary_tree_inorder(tree->left, func);
        func(tree->n);
        binary_tree_inorder(tree->right, func);
    }
}