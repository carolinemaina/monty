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
