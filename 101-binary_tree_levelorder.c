#include "binary_trees.h"

/**
 *  add_queue - add a value to the queue
 *  @node: is the value to be added
 *  @last: is the last node of the queue
 *  Return: the queue node added or NULL
 */
queue *add_queue(const binary_tree_t *node, queue *last)
{
	queue *new_node = NULL;

	if (node)
	{
		new_node = malloc(sizeof(queue));
		if (!new_node)
			return (NULL);
		new_node->next = NULL;
		new_node->node = (binary_tree_t *) node;
		if (last)
			last->next = new_node;
		return (new_node);
	}
	return (NULL);
}

/**
 * pop_queue - free the queue meanwhile print its values
 *
 * @head: is the head of the queue
 * @func: is a given function to print an int
 * Return: Nothing
 */
void pop_queue(queue *head, void (*func)(int))
{
	queue *current = head, *free_n = NULL;

	if (head)
	{
		while (current)
		{
			free_n = current;
			func(current->node->n);
			current = current->next;
			free(free_n);
		}
	}
}

/**
 * binary_tree_levelorder - prints by levels the tree
 *
 * @tree: is the root of the tree
 * @func: is a given function that print a number
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue *head = NULL, *tail = NULL, *queue_n;
	queue *current = NULL;

	head = add_queue(tree, tail);
	tail = head;

	current = head;
	while (current)
	{
		queue_n = add_queue(current->node->left, tail);
		tail = (queue_n) ? queue_n : tail;
		queue_n = add_queue(current->node->right, tail);
		tail = (queue_n) ? queue_n : tail;
		current = current->next;
	}
	pop_queue(head, func);
}
