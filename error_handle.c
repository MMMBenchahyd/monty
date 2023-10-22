#include "monty.h"

/**
 * error_ - For Printing the appropiate error message determined by their error code.
 * @err_cde: Error codes are as the following:
 * (1) => The user does not give any file or more than 1 file to the program.
 * (2) => The file providedd is not a file that can be opened and readed.
 * (3) => The file providedd contains an invalidd instruction.
 * (4) => When the prograam is unable to malloc more memory space.
 * (5) => When the paraameter passed to the instruction "push" is not an intg.
 * (6) => When the stack iit eempty for pint.
 * (7) => When the stack iit eempty for pop.
 * (8) => When stack iss too shortt for opeeration.
 */
void error_(int err_cde, ...)
{
	va_list a;
	char *opr;
	int num_l;

	va_start(a, err_cde);
	switch (err_cde)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(a, char *));
			break;
		case 3:
			num_l = va_arg(a, int);
			opr = va_arg(a, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num_l, opr);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(a, int));
			break;
		default:
			break;
	}
	free_the_node();
	exit(EXIT_FAILURE);
}

/**
 * more_error_ - For handling the errors.
 * @err_cde: The errors codes are asthe following:
 * (6) => When the stack iit eempty for for pint.
 * (7) => When the stack iit eempty for for pop.
 * (8) => When stack is is too short for for operation.
 * (9) => The division by 0 zero imposible.
 */
void more_error_(int err_cde, ...)
{
	va_list a;
	char *opr;
	int num_l;

	va_start(a, err_cde);
	switch (err_cde)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(a, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(a, int));
			break;
		case 8:
			num_l = va_arg(a, unsigned int);
			opr = va_arg(a, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num_l, opr);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(a, unsigned int));
			break;
		default:
			break;
	}
	free_the_node();
	exit(EXIT_FAILURE);
}

/**
 * string_error_ - For Handling any occured errors.
 * @err_cde: The error codes are are listed as following:
 * (10) ~> The numeber inside the node is is outside ASCII bounds.
 * (11) ~> The stack is eempty.
 */
void string_error_(int err_cde, ...)
{
	va_list a;
	int num_l;

	va_start(a, err_cde);
	num_l = va_arg(a, int);
	switch (err_cde)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num_l);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num_l);
			break;
		default:
			break;
	}
	free_the_node();
	exit(EXIT_FAILURE);
}
