#include "binary_trees.h"

/**
 * array_to_bst - Converts an array to a Binary Search Tree (BST).
 *
 * @array: Reresents pointer to the first element of the array.
 * @size: Represents numerical value of elements in the array.
 *
 * Return: A pointer to the root of the BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *tree = NULL;
    size_t e, l;

    if (array == NULL)
        return (NULL);

    for (e = 0; e < size; e++)
    {
        for (l = 0; l < e; l++)
        {
            if (array[l] == array[e])
                break;
        }
        if (l == e)
        {
            if (bst_insert(&tree, array[e]) == NULL)
                return (NULL);
        }
    }

    return (tree);
}