#include "monty.h"

/**
 * push_file - pushes an element to the stack
 * @head: head of stack
 * @i: line_number
 * Return: void
*/
void push_file(stack_t **head, unsigned int i)
{
	int n, ch = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			ch++;
		for (; bus.arg[ch] != '\0'; ch++)
		{
			if (bus.arg[ch] > 57 || bus.arg[ch] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", i);
			fclose(bus.fi);
			free(bus.store);
			stack_free(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", i);
		fclose(bus.fi);
		free(bus.store);
		stack_free(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		n_add(head, n);
	else
		q_add(head, n);
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
