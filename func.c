
#include "monty.h"
/**
 * _strtok - Tokenizes the line in buffer
 * @gs: General struct of the program
 */
void _strtok(gralStruct *gs)
{
	int counter = 0;
	char *tmp;
/*Tokenizes the buffer*/
	tmp = strtok(gs->buffer, " \n\t");
	while (tmp && counter < 2)
	{
		gs->args[counter] = tmp;
		tmp = strtok(NULL, " \n\t");
		counter++;
	}
	gs->args[counter] = NULL;
}
/**
 * executeOp - Looks for the opcode function and if it's found execute it
 * @gs: General struct of the program
 * Return: When success 1, if fails 0
 */
int executeOp(gralStruct *gs)
{
	int counter = 0;

	if (strcmp(gs->args[0], "stack") == 0)
	{
		gs->modeSQ = 0;
		return (1);
	}
	else if (strcmp(gs->args[0], "queue") == 0)
	{
		gs->modeSQ = 1;
		return (1);
	}
	while (gs->dicciop[counter].opcode)
	{
		if (strcmp(gs->args[0], gs->dicciop[counter].opcode) == 0)
		{
			gs->dicciop[counter].f(&(gs->stack), gs->lineNumber);
			return (1);
		}
		counter++;
	}
	return (0);
}
/**
 * checkNum - Check if the argument passed to push is valid
 * @gs: General struct of the program
 */
void checkNum(gralStruct *gs)
{
	int counter = 0;

	if (!gs->args[1])
	{
		fprintf(stderr, "L%u: usage: push integer\n", gs->lineNumber);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
	while (gs->args[1][counter])
	{
		if (!isdigit(gs->args[1][counter]) && gs->args[1][0] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", gs->lineNumber);
			freeall(gs);
			exit(EXIT_FAILURE);
		}
		counter++;
	}
}
/**
 * freeall - Free all memory allocated in the program
 * @gs: General struct of the program
 */
void freeall(gralStruct *gs)
{
	free(gs->buffer);
	free(gs->args);
	free(gs->dicciop);
	freestack(gs);
	if (gs->montyFile)
		fclose(gs->montyFile);
	free(gs);
}
/**
 * freestack - Frees each node in stack
 * @gs: General struct of the program
 */
void freestack(gralStruct *gs)
{
	if (gs->stack)
	{
		while (gs->stack->next)
		{
			gs->stack = gs->stack->next;
			free(gs->stack->prev);
		}
		free(gs->stack);
	}
}
