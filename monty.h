#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: a value
 * @fi: pointer to monty file
 * @store: line content
 * @lifi: flag for indicating change between
 * stack and queue mode
 * Description: carries values through program
 */
typedef struct bus_s
{
	char *arg;
	FILE *fi;
	char *store;
	int lifi;
}  bus_t;

extern bus_t bus;

void push_file(stack_t **head, unsigned int i);
void print_stack(stack_t **head, unsigned int i);
void q_add(stack_t **head, int n);
void n_add(stack_t **head, int n);
int run_op(char *store, stack_t **stack, unsigned int i, FILE *fi);
void stack_free(stack_t *head);

#endif
