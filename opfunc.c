#include "monty.h"
/**
 * push - pushes an element to the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node, *tmp;

	checkNum(gs);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(gs->args[1]);
	if (gs->modeSQ == 0 || !*stack)
	{
		new_node->next = *stack;
		if (*stack)
			new_node->next->prev = new_node;
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new_node->next = NULL;
		new_node->prev = tmp;
		tmp->next = new_node;
	}
}
/**
 * pall - prints all the values on the stack, starting
 * from the top of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp;

	if (*stack)
	{
		tmp = *stack;
		while (tmp)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%i\n", gs->stack->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop - removes the top element of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack)
	{
		tmp = *stack;
		if (tmp->next)
			tmp->next->prev = NULL;
		*stack = tmp->next;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}

}
/**
 * swap - swaps the top two elements of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	if (!*stack || !gs->stack->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp2 = tmp->next;
	tmp2->prev = NULL;
	if (tmp2->next)
		tmp2->next->prev = tmp;
	tmp->next = tmp2->next;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	*stack = tmp2;
}
