#include "binary_trees.h"

/**
 * struct node_s - Custom linked list structure to store binary tree nodes
 * @node: Represents pointer to a binary tree node
 * @next: Represents pointer to the next node in the linked list
 */
typedef struct node_s
{
    const binary_tree_t *node;
    struct node_s *next;
} ll;

/**
 * append - Appends a new node to a linked list
 * @head: Represnts pointer to the head of the linked list
 * @btnode: Represents pointer to a binary tree node to append
 *
 * Return: A pointer to the updated linked list
 */
ll *append(ll *head, const binary_tree_t *btnode);

/**
 * free_list - Frees a linked list
 * @head: Represents pointer to the head of the linked list
 */
void free_list(ll *head);

/**
 * get_children - Gets the children of a binary tree node and
 * appends them to a linked list
 * @head: Represents pointer to the head of the linked list
 * @parent: Reprrsents pointer to the parent node
 *
 * Return: A pointer to the updated linked list
 */
ll *get_children(ll *head, const binary_tree_t *parent);

/**
 * levels_rec - Recursively processes levels of a binary
 * tree via a linked list
 * @head: Represents pointer to the head of the linked list
 * @func: Represents pointer to the function to call on each node
 */
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - Performs a level-order traversal of a binary tree
 * @tree: Represents pointer to the root of the binary tree
 * @func: Represents pointer to the function to call on each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    ll *children = NULL;

    func(tree->n);
    children = get_children(children, tree);
    levels_rec(children, func);

    free_list(children);
}

/**
 * levels_rec - Recursively processes levels of a binary tree
 * via a linked list
 * @head: Represents pointer to the head of the linked list
 * @func: Represents pointer to the function to call on each node
 */
void levels_rec(ll *head, void (*func)(int))
{
    ll *children = NULL, *curr = NULL;

    if (!head)
        return;

    for (curr = head; curr != NULL; curr = curr->next)
    {
        func(curr->node->n);
        children = get_children(children, curr->node);
    }

    levels_rec(children, func);
    free_list(children);
}

/**
 * get_children - Gets the children of a binary tree node
 * and appends them to a linked list
 * @head: Represents pointer to the head of the linked list
 * @parent: Represents pointer to the parent node
 *
 * Return: A pointer to the updated linked list
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
    if (parent->left)
        head = append(head, parent->left);
    if (parent->right)
        head = append(head, parent->right);
    return (head);
}

/**
 * append - Appends a new node to a linked list
 * @head: Represents pointer to the head of the linked list
 * @btnode: Represents pointer to a binary tree node to append
 *
 * Return: A pointer to the updated linked list
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
    ll *new = NULL, *last = NULL;

    new = malloc(sizeof(*new));
    if (new)
    {
        new->node = btnode;
        new->next = NULL;
        if (!head)
            head = new;
        else
        {
            last = head;
            while (last->next)
                last = last->next;
            last->next = new;
        }
    }

    return (head);
}

/**
 * free_list - Frees a linked list
 * @head: Represents pointer to the head of the linked list
 */
void free_list(ll *head)
{
    ll *ptr = NULL;

    while (head)
    {
        ptr = head->next;
        free(head);
        head = ptr;
    }
}