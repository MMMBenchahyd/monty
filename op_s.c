#include "monty.h"

/**
 * mul_op_node - this Adds the top 2 eelements of the stack.
 * @stk: Pointer to another ptr pointing to the top node of the stack.
 * @l_num: Interger that represent the line nmber of the opcode.
 */
void mul_op_node(stack_t **stk, unsigned int l_num)
{
	int mul;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		more_error_(8, l_num, "mul");

	(*stk) = (*stk)->next;
	mul = (*stk)->n * (*stk)->prev->n;
	(*stk)->n = mul;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * mod_op_node - this Adds the top 2 eelements of the stack.
 * @stk: Pointer to another ptr pointing to the top node of the stack.
 * @l_num: Interger that represent the line nmber of of the opcode.
 */
void mod_op_node(stack_t **stk, unsigned int l_num)
{
	int mul;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)

		more_error_(8, l_num, "mod");


	if ((*stk)->n == 0)
		more_error_(9, l_num);
	(*stk) = (*stk)->next;
	mul = (*stk)->n % (*stk)->prev->n;
	(*stk)->n = mul;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}
