#include "monty.h"

/**
 * prt_c - It Prints Ascii value.
 * @stk: Pointer to another ptr pointing to the top node of the stack.
 * @l_num: An interger represent the line nmber of the opcode.
 */
void prt_c(stack_t **stk, unsigned int l_num)
{
	int as;

	if (stk == NULL || *stk == NULL)
		string_error_(11, l_num);

	as = (*stk)->n;
	if (as < 0 || as > 127)
		string_error_(10, l_num);
	printf("%c\n", as);
}

/**
 * prt_string - It prints a string value.
 * @stk: Pointer to another ptr pointing to top node of the stack.
 * @ln: An interger represent the line nmber of the opcode.
 */
void prt_string(stack_t **stk, __attribute__((unused))unsigned int ln)
{
	int as;
	stack_t *t;

	if (stk == NULL || *stk == NULL)
	{
		printf("\n");
		return;
	}

	t = *stk;
	while (t != NULL)
	{
		as = t->n;
		if (as <= 0 || as > 127)
			break;
		printf("%c", as);
		t = t->next;
	}
	printf("\n");
}

/**
 * rot_f_node - For Rotating the 1st node of the stack to the bottom.
 * @stk: Pointer to another ptr pointing to top node of the stack.
 * @ln: An interger represent the line nmber of of the opcode.
 */
void rot_f_node(stack_t **stk, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;

	t = *stk;
	while (t->next != NULL)
		t = t->next;

	t->next = *stk;
	(*stk)->prev = t;
	*stk = (*stk)->next;
	(*stk)->prev->next = NULL;
	(*stk)->prev = NULL;
}


/**
 * rot_l_node - For Rotating last node of the stack to be the top.
 * @stk: Pointer to a ptr pointing to the top node of the stack.
 * @ln: An interger that represent the line nmber of the opcode.
 */
void rot_l_node(stack_t **stk, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;

	t = *stk;

	while (t->next != NULL)
		t = t->next;

	t->next = *stk;
	t->prev->next = NULL;
	t->prev = NULL;
	(*stk)->prev = t;
	(*stk) = t;
}
