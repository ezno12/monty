#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct generalStruct - General struct of the program
 * @buffer: Stores the line read by fgets
 * @args: Array of pointers to arguments of the line read
 * @argv: Array of pointer to the arguments passed to the program
 * @dicciop: Array of paired opcode-function list
 * @stack: Pointer to double linked list of stack'ed elements
 * @lineNumber: Number of the line read from the input file
 * @bufferSize: Fixed sixe to be read per line of file
 * @modeSQ: Mode of storing elements in stack, 0 = stack-mode, 1 = queue-mode
 * @montyFile: Input file opened
 */
typedef struct generalStruct
{
	char *buffer;
	char **args;
	char **argv;
	instruction_t *dicciop;
	stack_t *stack;
	unsigned int lineNumber;
	size_t bufferSize;
	int modeSQ;
	FILE *montyFile;
} gralStruct;

extern gralStruct *gs;

/*Auxiliar functions*/
gralStruct *initialize(char **argv);
void _strtok(gralStruct *gs);
int executeOp(gralStruct *gs);
instruction_t *dic_op();
void checkNum(gralStruct *gs);
void freeall(gralStruct *gs);
void freestack(gralStruct *gs);
int isComment(gralStruct *gs);

/*opcode functions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_s(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

#endif
