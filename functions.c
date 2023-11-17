#include "monty.h"

/**
 * n_add - add node to stack head
 * @head: stack head
 * @n: new value
 * Return: void
*/
void n_add(stack_t **head, int n)
{
	stack_t *node_n, *a;

	a = *head;
	node_n = malloc(sizeof(stack_t));
	if (node_n == NULL)
	{ printf("Error\n");
		exit(0); }
	if (a)
		a->prev = node_n;
	node_n->n = n;
	node_n->next = *head;
	node_n->prev = NULL;
	*head = node_n;
}

/**
 * q_add - add node to end of stack
 * @n: new item
 * @head: the head
 * Return: void
*/
void q_add(stack_t **head, int n)
{
	stack_t *node_n, *a;

	a = *head;
	node_n = malloc(sizeof(stack_t));
	if (node_n == NULL)
	{
		printf("Error\n");
	}
	node_n->n = n;
	node_n->next = NULL;
	if (a)
	{
		while (a->next)
			a = a->next;
	}
	if (!a)
	{
		*head = node_n;
		node_n->prev = NULL;
	}
	else
	{
		a->next = node_n;
		node_n->prev = a;
	}
}
