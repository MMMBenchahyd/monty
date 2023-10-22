#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void op_file(char *fname);
int par_line(char *buff, int l_num, int fmt);
void r_file(FILE *);
int len_chars(FILE *);
void find_function(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_the_node(void);
void pall_stack(stack_t **, unsigned int);
void add_stack(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void func_call(op_func, char *, char *, int, int);

void print_tp(stack_t **, unsigned int);
void _pop_t(stack_t **, unsigned int);
void n_tg(stack_t **, unsigned int);
void swap_func_node(stack_t **, unsigned int);

/*Math operations with nodes*/
void add_op_node(stack_t **, unsigned int);
void sub_op_node(stack_t **, unsigned int);
void div_op_node(stack_t **, unsigned int);
void mul_op_node(stack_t **, unsigned int);
void mod_op_node(stack_t **, unsigned int);

/*String operations*/
void prt_c(stack_t **, unsigned int);
void prt_string(stack_t **, unsigned int);
void rot_f_node(stack_t **, unsigned int);

/*Error hanlding*/
void error_(int err_cde, ...);
void more_error_(int err_cde, ...);
void string_error_(int err_cde, ...);
void rot_l_node(stack_t **, unsigned int);

#endif
