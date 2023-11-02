#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node as the right child of a parent node
 * @parent: Represents a pointer to the parent node to which the new node will be inserted
 * @value: Represents the integer value to be stored in the new node
 *
 * Return: A pointer to the newly inserted binary_tree_t node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new;

    if (parent == NULL)
        return (NULL);

    new = binary_tree_node(parent, value);
    if (new == NULL)
        return (NULL);

    if (parent->right != NULL)
    {
        new->right = parent->right;
        parent->right->parent = new;
    }
    parent->right = new;

    return (new);
}