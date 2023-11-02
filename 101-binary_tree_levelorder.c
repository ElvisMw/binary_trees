#include "binary_trees.h"

/**
 * struct levelorder_queue_s - Custom queue structure for
 * level-order traversal
 * @node: Represents pointer to a binary tree node
 * @next: Represents pointer to the next node in the queue
 */
typedef struct levelorder_queue_s
{
    binary_tree_t *node;
    struct levelorder_queue_s *next;
} levelorder_queue_t;

/**
 * create_node - Creates a new node for the queue
 * @node: Represents pointer to a binary tree node
 *
 * Return: Represents pointer to the new node, or
 * NULL if allocation fails
 */
levelorder_queue_t *create_node(binary_tree_t *node);

/**
 * free_queue - Allows Freeing the queue
 * @head: Represents pointer to the head of the queue
 */
void free_queue(levelorder_queue_t *head);

/**
 * pint_push - Pushes a binary tree node into the queue and applies a function
 * @node: Represents pointer to a binary tree node
 * @head: Represents pointer to the head of the queue
 * @tail: Represents pointer to the tail of the queue
 * @func: Represents pointer to the function to apply to the node's value
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
              levelorder_queue_t **tail, void (*func)(int));

/**
 * pop - Removes the head of the queue
 * @head: Represents pointer to the head of the queue
 */
void pop(levelorder_queue_t **head);

/**
 * binary_tree_levelorder - Performs a level-order traversal of a binary tree
 * @tree: Represents pointer to the root of the binary tree
 * @func: Represents pointer to the function to call on each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates a new node for the queue
 * @node: Represents pointer to a binary tree node
 *
 * Return: Represents pointer to the new node, or
 * NULL if allocation fails
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
    levelorder_queue_t *new;

    new = malloc(sizeof(levelorder_queue_t));
    if (new == NULL)
        return (NULL);

    new->node = node;
    new->next = NULL;

    return (new);
}

/**
 * free_queue - Frees the queue
 * @head: Represents pointer to the head of the queue
 */
void free_queue(levelorder_queue_t *head)
{
    levelorder_queue_t *tmp;

    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

/**
 * pint_push - Pushes a binary tree node into the queue and applies a function
 * @node: Represents binary tree node's pointer
 * @head: Represents head of the queue's pointer
 * @tail: Represents tail of the queue's pointer
 * @func: Represents pointer to the function to apply to the node's value
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
              levelorder_queue_t **tail, void (*func)(int))
{
    levelorder_queue_t *new;

    func(node->n);

    if (node->left != NULL)
    {
        new = create_node(node->left);
        if (new == NULL)
        {
            free_queue(head);
            exit(1);
        }

        (*tail)->next = new;
        *tail = new;
    }

    if (node->right != NULL)
    {
        new = create_node(node->right);
        if (new == NULL)
        {
            free_queue(head);
            exit(1);
        }

        (*tail)->next = new;
        *tail = new;
    }
}

/**
 * pop - Removes the head of the queue
 * @head: Represents pointer to the head of the queue
 */
void pop(levelorder_queue_t **head)
{
    levelorder_queue_t *tmp;

    tmp = (*head)->next;
    free(*head);
    *head = tmp;
}

/**
 * binary_tree_levelorder - Performs a level-order traversal of
 * a binary tree
 * @tree: Represents pointer to the root of the binary tree
 * @func: Represents pointer to the function to call on each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    levelorder_queue_t *head, *tail;

    if (tree == NULL || func == NULL)
        return;

    head = tail = create_node((binary_tree_t *)tree);
    if (head == NULL)
        return;

    while (head != NULL)
    {
        pint_push(head->node, head, &tail, func);
        pop(&head);
    }
}