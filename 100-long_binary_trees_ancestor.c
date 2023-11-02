#include "binary_trees.h"

/**
 * depth - Calculates the depth of a node in the tree
 * @tree: Represents pointer to the node
 *
 * Return: The node's depth
 */
size_t depth(const binary_tree_t *tree)
{
    return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Represents1st node's
 * @second: Represents 2nd node's pointer
 *
 * Return: A pointer to the lowest common ancestor, or NULL if no ancestor is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    size_t first_depth, second_depth;

    if (first == NULL || second == NULL)
        return (NULL);

    if (first == second)
        return ((binary_tree_t *)first);

    if (first->parent == second->parent)
        return ((binary_tree_t *)first->parent);

    if (first == second->parent)
        return ((binary_tree_t *)first);

    if (first->parent == second)
        return ((binary_tree_t *)second);

    for (first_depth = depth(first); first_depth > 1; first_depth--)
        first = first->parent;

    for (second_depth = depth(second); second_depth > 1; second_depth--)
        second = second->parent;

    if (first == second)
        return ((binary_tree_t *)first);

    if (first->parent == second->parent)
        return ((binary_tree_t *)first->parent);

    if (first == second->parent)
        return ((binary_tree_t *)first);

    if (first->parent == second)
        return ((binary_tree_t *)second);

    return (NULL);
}