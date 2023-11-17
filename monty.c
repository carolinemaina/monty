#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - interprets monty code
* @argc: number of command-line arguments
* @argv: array of strings containing
* command-line arguments
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char store[LINE_LENGTH];
	FILE *fi;
	stack_t *stack = NULL;
	unsigned int i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fi = fopen(argv[1], "r");
	if (!fi)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(store, sizeof(store), fi) != NULL)
	{
		i++;
		run_op(store, &stack, i, fi);
		printf("Line %d: %s", i, store);
	}

	stack_free(stack);
	fclose(fi);
	return 0;
}

/**
* run_op - executes opcode
* @stack: stack head linked list
* @i: line counter
* @fi: poiner to monty file
* @store: line content
* Return: void
*/
int run_op(char *store, stack_t **stack, unsigned int i, FILE *fi)
{
	instruction_t opst[] = {
				{"push", push_file}, {"pall", print_stack},
				{NULL, NULL}
				};

	unsigned int k = 0;
	char *opc;

	opc = strtok(store, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[k].opcode && opc)
	{
		if (strcmp(opc, opst[k].opcode) == 0)
		{	opst[k].f(stack, i);
			return (0);
		}
		k++;
	}
	if (opc && opst[k].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", i, opc);
		fclose(fi);
		free(store);
		stack_free(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
