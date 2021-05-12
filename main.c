#include "monty.h"

gralStruct *gs;

/**
 * dic_op - Creates an array of paires opcode-function
 * Return: A pointer to the array crated
 */
instruction_t *dic_op()
{
	instruction_t *arrayOp = malloc(sizeof(instruction_t) * 16);

	if (arrayOp)
	{
		arrayOp[0].opcode = "push";
		arrayOp[0].f = push;
		arrayOp[1].opcode = "pall";
		arrayOp[1].f = pall;
		arrayOp[2].opcode = "pint";
		arrayOp[2].f = pint;
		arrayOp[3].opcode = "pop";
		arrayOp[3].f = pop;
		arrayOp[4].opcode = "swap";
		arrayOp[4].f = swap;
		arrayOp[5].opcode = "add";
		arrayOp[5].f = add;
		arrayOp[6].opcode = "nop";
		arrayOp[15].opcode = NULL;
		arrayOp[15].f = NULL;
		return (arrayOp);
	}
	return (NULL);
}

/**
 * initialize - Asign initial values to the elements of the general struct
 * @argv: Double pointer to arguments passed to the program
 * Return: a pointer to the initial gral Struct
 */
gralStruct *initialize(char **argv)
{
	gs = malloc(sizeof(gralStruct));
	if (!gs)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	gs->bufferSize = 0;
	gs->buffer = NULL;
	gs->args = malloc(sizeof(char *) * 3);
	if (!gs->args)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(gs), exit(EXIT_FAILURE);
	}
	gs->argv = argv;
	gs->dicciop = dic_op();
	if (!gs->dicciop)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(gs->args), free(gs), exit(EXIT_FAILURE);
	}
	gs->stack = NULL;
	gs->lineNumber = 1;
	gs->montyFile = NULL;
	gs->modeSQ = 0;
	return (gs);
}
/**
 * main - Main process of the program
 * @argc: Quantity of arguments passed to the program
 * @argv: Array of pointer to arguments passed to the program
 * Return: Ever 1.
 */
int main(int argc, char **argv)
{
	int res = 0;
/*Checks if user has passed 1 argument to the program*/
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
/*Initializes general struct of the program*/
	gs = initialize(argv);
/*Opens file passed to the program*/
	gs->montyFile = fopen(argv[1], "r");
	if (!gs->montyFile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		freeall(gs);
		exit(EXIT_FAILURE);
	}
/*Gets and deals with each line of the file*/
	while (getline(&gs->buffer, &gs->bufferSize, gs->montyFile) != EOF)
	{
		_strtok(gs);
		if (!gs->args[0])
		{
			gs->lineNumber++;
			continue;
		}
		res = executeOp(gs);
		if (gs->args[0][0] == '#')
		{
			gs->lineNumber++;
			continue;
		}
		if (res == 0)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
				gs->lineNumber, gs->args[0]);
			freeall(gs), exit(EXIT_FAILURE);
		}
		gs->lineNumber++;
	}
	freeall(gs);
	exit(EXIT_SUCCESS);
}
