#include "binary_trees.h"

/**
 * struct levelorder_queue_s - Custom queue structure for level-order traversal
 * @node: A pointer to a binary tree node
 * @next: A pointer to the next node in the queue
 */
typedef struct levelorder_queue_s
{
    binary_tree_t *node;
    struct levelorder_queue_s *next;
} levelorder_queue_t;

/**
 * create_node - Creates a new node for the queue
 * @node: A pointer to a binary tree node
 *
 * Return: A pointer to the new node, or NULL if allocation fails
 */
levelorder_queue_t *create_node(binary_tree_t *node);

/**
 * free_queue - Frees the queue
 * @head: A pointer to the head of the queue
 */
void free_queue(levelorder_queue_t *head);

/**
 * push - Pushes a binary tree node into the queue
 * @node: A pointer to a binary tree node
 * @head: A pointer to the head of the queue
 * @tail: A pointer to the tail of the queue
 */
void push(binary_tree_t *node, levelorder_queue_t *head, levelorder_queue_t **tail);

/**
 * pop - Removes the head of the queue
 * @head: A pointer to the head of the queue
 */
void pop(levelorder_queue_t **head);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root of the binary tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new node for the queue
 * @node: A pointer to a binary tree node
 *
 * Return: A pointer to the new node, or NULL if allocation fails
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
    levelorder_queue_t *new_node;

    new_node = malloc(sizeof(levelorder_queue_t));
    if (new_node == NULL)
        return (NULL);

    new_node->node = node;
    new_node->next = NULL;

    return (new_node);
}

/**
 * free_queue - Frees the queue
 * @head: A pointer to the head of the queue
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
 * push - Pushes a binary tree node into the queue
 * @node: A pointer to a binary tree node
 * @head: A pointer to the head of the queue
 * @tail: A pointer to the tail of the queue
 */
void push(binary_tree_t *node, levelorder_queue_t *head, levelorder_queue_t **tail)
{
    levelorder_queue_t *new_node;

    new_node = create_node(node);
    if (new_node == NULL)
    {
        free_queue(head);
        exit(1);
    }
    (*tail)->next = new_node;
    *tail = new_node;
}

/**
 * pop - Removes the head of the queue
 * @head: A pointer to the head of the queue
 */
void pop(levelorder_queue_t **head)
{
    levelorder_queue_t *tmp;

    tmp = (*head)->next;
    free(*head);
    *head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root of the binary tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    levelorder_queue_t *head, *tail;
    unsigned char flag = 0;

    if (tree == NULL)
        return (0);

    head = tail = create_node((binary_tree_t *)tree);
    if (head == NULL)
        exit(1);

    while (head != NULL)
    {
        if (head->node->left != NULL)
        {
            if (flag == 1)
            {
                free_queue(head);
                return (0);
            }
            push(head->node->left, head, &tail);
        }
        else
            flag = 1;
        if (head->node->right != NULL)
        {
            if (flag == 1)
            {
                free_queue(head);
                return (0);
            }
            push(head->node->right, head, &tail);
        }
        else
            flag = 1;
        pop(&head);
    }
    return (1);
}