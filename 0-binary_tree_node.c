#include "binary_trees.h"

/**
 * binary_tree_node - This creates a new binary tree node
 * @parent: Represents a pointer to the parent node of the new node
 * @value: Represents the integer value to be stored in the new node
 *
 * Return: A pointer to the newly created binary_tree_t node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new;

    new = malloc(sizeof(binary_tree_t));
    if (new == NULL)
        return (NULL);

    new->n = value;
    new->parent = parent;
    new->left = NULL;
    new->right = NULL;

    return (new);
}