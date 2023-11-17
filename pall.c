#include "monty.h"

/**
 * print_stack - prints all the values on the stack
 * @head: head of stack
 * @i: total
 * Return: void
*/

void print_stack(stack_t **head, unsigned int i)
{
	stack_t *new_h;
	(void)i;

	new_h = *head;
	if (new_h == NULL)
		return;
	while (new_h)
	{
		printf("%d\n", new_h->n);
		new_h = new_h->next;
	}
}

/**
* stack_free - frees doubly linked list
* @head: head of the stack
*/
void stack_free(stack_t *head)
{
	stack_t *a;

	a = head;
	while (head)
	{
		a = head->next;
		free(head);
		head = a;
	}
}
