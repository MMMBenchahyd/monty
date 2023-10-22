#include "monty.h"


/**
 * add_stack - For adding a node to the stack.
 * @new_nd: Pointr pionting to the new node.
 * @ln: An Interger that represent the line nmber of the opcode.
 */
void add_stack(stack_t **new_nd, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (new_nd == NULL || *new_nd == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_nd;
		return;
	}
	t = head;
	head = *new_nd;
	head->next = t;
	t->prev = head;
}


/**
 * pall_stack - For adding a node to the stack.
 * @stk: Pointer to another ptr pointing to the top node of the stack.
 * @l_num: Its the line numbr of  the opcode.
 */
void pall_stack(stack_t **stk, unsigned int l_num)
{
	stack_t *t;

	(void) l_num;
	if (stk == NULL)
		exit(EXIT_FAILURE);
	t = *stk;
	while (t != NULL)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}

/**
 * _pop_t - For adding a node to the stack.
 * @stk: Pointer to another ptr pointing to the top node of the stack.
 * @l_num: An Interger that represent the line nmber of the opcode.
 */
void _pop_t(stack_t **stk, unsigned int l_num)
{
	stack_t *t;

	if (stk == NULL || *stk == NULL)
		more_error_(7, l_num);

	t = *stk;
	*stk = t->next;
	if (*stk != NULL)
		(*stk)->prev = NULL;
	free(t);
}

/**
 * print_tp - For printing the top node of tthe stack.
 * @stk: Pointer to another ptr pointing to the top node of the stack.
 * @l_num: An Interger that represent the line nmber of the opcode.
 */
void print_tp(stack_t **stk, unsigned int l_num)
{
	if (stk == NULL || *stk == NULL)
		more_error_(6, l_num);
	printf("%d\n", (*stk)->n);
}
