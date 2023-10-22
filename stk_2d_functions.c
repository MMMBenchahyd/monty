#include "monty.h"

/**
 * n_tg - function that Do nothing.
 * @stk: Pointer to another ptr pointing to the top node of the stack.
 * @l_num: An Interger that represent the line nmber of the opcode.
 */
void n_tg(stack_t **stk, unsigned int l_num)
{
	(void)stk;
	(void)l_num;
}


/**
 * swap_func_node - For swaping the top 2 eelements of the stack.
 * @stk: Pointer to another ptr pointing to the top node of the stack.
 * @l_num: An Interger that represent the line nmber of the opcode.
 */
void swap_func_node(stack_t **stk, unsigned int l_num)
{
	stack_t *t;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		more_error_(8, l_num, "swap");
	t = (*stk)->next;
	(*stk)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *stk;
	t->next = *stk;
	(*stk)->prev = t;
	t->prev = NULL;
	*stk = t;
}

/**
 * add_op_node - For adding the top 2 eelements of the stack.
 * @stk: Pointer to another ptr pointing to the top node of the stack.
 * @l_num: An Interger that represent the line nmber of the opcode.
 */
void add_op_node(stack_t **stk, unsigned int l_num)
{
	int s;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		more_error_(8, l_num, "add");

	(*stk) = (*stk)->next;
	s = (*stk)->n + (*stk)->prev->n;
	(*stk)->n = s;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * sub_op_node - For adding the top 2 eelements of the stack.
 * @stk: Pointer to another ptr pointing to the top node of the stack.
 * @l_num: An Interger that represent the line nmber of the opcode.
 */
void sub_op_node(stack_t **stk, unsigned int l_num)
{
	int s;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)

		more_error_(8, l_num, "sub");


	(*stk) = (*stk)->next;
	s = (*stk)->n - (*stk)->prev->n;
	(*stk)->n = s;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * div_op_node - For addng the top 2 eelements of the stack.
 * @stk: Pointer to another ptr pointing to the top node of the stack.
 * @l_num: An Interger that represent the line nmber of the opcode.
 */
void div_op_node(stack_t **stk, unsigned int l_num)
{
	int s;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		more_error_(8, l_num, "div");

	if ((*stk)->n == 0)
		more_error_(9, l_num);
	(*stk) = (*stk)->next;
	s = (*stk)->n / (*stk)->prev->n;
	(*stk)->n = s;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
