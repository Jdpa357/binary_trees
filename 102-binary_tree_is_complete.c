#include "binary_trees.h"
#include <stdio.h>
/**
 *  add_queue - add a value to the queue
 *  @node: is the value to be added
 *  @last: is the last node of the queue
 *  @size: is the size of the queue
 *  Return: the queue node added or NULL
 */
queue *add_queue(const binary_tree_t *node, queue **last, size_t *size)
{
	queue *new_node = NULL;

	new_node = malloc(sizeof(queue));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->node = (binary_tree_t *) node;
	if (*last)
	{
		(*last)->next = new_node;
	}
	*last = new_node;
	*size = *size + 1;
	return (new_node);
}

/**
 * pop_queue - free the queue meanwhile print its values
 *
 * @head: is the head of the queue
 * @size: is the size of the queue
 * Return: Nothing
 */
void pop_queue(queue **head, size_t *size)
{
	queue *free_n = NULL;

	if (*head)
	{
		free_n = *head;
		*head = (*head)->next;
		free(free_n);
		*size = *size - 1;
	}
}

/**
 * binary_tree_is_complete - evaluates if a tree is complete
 * @tree: is the root of the tree
 * Return: 1 if it is complete, 0 in otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int answer = 0;
	size_t q_size = 0;
	queue *head = NULL, *tail = NULL;
	binary_tree_t *node;

	head = add_queue(tree, &tail, &q_size);

	while (head && head->node)
	{
		node = head->node;
		if (node->left || node->right)
		{
			add_queue(node->left, &tail, &q_size);
			add_queue(node->right, &tail, &q_size);
		}
		else
			add_queue(NULL, &tail, &q_size);
		pop_queue(&head, &q_size);
	}

	while (head)
	{
		if (!head->node)
			pop_queue(&head, &q_size);
		else
			head = head->next;
	}
	answer = (q_size == 0) ? 1 : 0;
	while (head)
		pop_queue(&head, &q_size);


	return (answer);
}
