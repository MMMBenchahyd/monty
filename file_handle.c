#include "monty.h"

/**
 * op_file - For opening a file
 * @fname: The namepath of the file
 * Return: Return nothing in this case
 */

void op_file(char *fname)
{
	FILE *fptr = fopen(fname, "r");

	if (fname == NULL || fptr == NULL)
		error_(2, fname);

	r_file(fptr);
	fclose(fptr);
}


/**
 * r_file - For reading a file
 * @fptr: A pointer to the descriptor of the file
 * Return: Return nothing
 */

void r_file(FILE *fptr)
{
	int l_num, fmt = 0;
	char *buff = NULL;
	size_t lenght = 0;

	for (l_num = 1; getline(&buff, &lenght, fptr) != -1; l_num++)
	{
		fmt = par_line(buff, l_num, fmt);
	}
	free(buff);
}


/**
 * par_line - For Separating each line into tokens for determining
 * which function to call exactly
 * @buff: Line from the file file
 * @l_num: The line numbr
 * @fmt:  The storage format. If zero Nodes will be entered
 * as a stack. if 1 nodes will bbe entered as a a queue.
 * Return: Return 0 if the code is stack. and 1 if queue.
 */

int par_line(char *buff, int l_num, int fmt)
{
	char *code, *val;
	const char *delimiter = "\n ";

	if (buff == NULL)
		error_(4);

	code = strtok(buff, delimiter);
	if (code == NULL)
		return (fmt);
	val = strtok(NULL, delimiter);

	if (strcmp(code, "stack") == 0)
		return (0);
	if (strcmp(code, "queue") == 0)
		return (1);

	find_function(code, val, l_num, fmt);
	return (fmt);
}

/**
 * find_function - Finding the appropriate function for the entred code
 * @code: The code
 * @val: The argument of code
 * @fmt:  the storage format. If zero Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * @ln: The line number
 * Return: void nothing
 */
void find_function(char *code, char *val, int ln, int fmt)
{
	int i, fl;

	instruction_t func_list[] = {
		{"push", add_stack},
		{"pall", pall_stack},
		{"pint", print_tp},
		{"pop", _pop_t},
		{"nop", n_tg},
		{"swap", swap_func_node},
		{"add", add_op_node},
		{"sub", sub_op_node},
		{"div", div_op_node},
		{"mul", mul_op_node},
		{"mod", mod_op_node},
		{"pchar", prt_c},
		{"pstr", prt_string},
		{"rotl", rot_f_node},
		{"rotr", rot_l_node},
		{NULL, NULL}
	};

	if (code[0] == '#')
		return;

	for (fl = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(code, func_list[i].opcode) == 0)
		{
			func_call(func_list[i].f, code, val, ln, fmt);
			fl = 0;
		}
	}
	if (fl == 1)
		error_(3, ln, code);
}


/**
 * func_call - Calling the required funct.
 * @func: Pointer to the funct that will be called.
 * @op: A String representes the code.
 * @val: String representes a numeric value.
 * @ln: Line numebr for the instructions.
 * @fmt: The format specifier. If 0 Nodes will be entered aas a stack.
 * if 1 nodes will be entered as a a queue.
 */
void func_call(op_func func, char *op, char *val, int ln, int fmt)
{
	stack_t *nd;
	int fl, i;

	fl = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			fl = -1;
		}
		if (val == NULL)
			error_(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error_(5, ln);
		}
		nd = create_node(atoi(val) * fl);
		if (fmt == 0)
			func(&nd, ln);
		if (fmt == 1)
			add_queue(&nd, ln);
	}
	else
		func(&head, ln);
}
