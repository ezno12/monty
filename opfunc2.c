#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void add(stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	int result;
	stack_t *tmp;

	if (!*stack || !gs->stack->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	result = tmp->n + tmp->next->n;
	tmp->next->n = result;
	pop(&gs->stack, gs->lineNumber);
}
/**
 * nop - doesn’t do anything.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file
 */
void nop(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
}
/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: Double pointer to double linked list of elements stack'ed
 * @line_number: Number of line read from input file*
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !gs->stack->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp->next->n = tmp->next->n - tmp->n;
	pop(&gs->stack, gs->lineNumber);
}
