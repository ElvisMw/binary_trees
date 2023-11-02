#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Represents a pointer to the root node of the binary tree
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree != NULL)
    {
        binary_tree_delete(tree->left);
        binary_tree_delete(tree->right);
        free(tree);
    }
}