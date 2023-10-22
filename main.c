#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point or start
 * @argc: Arguments count
 * @argv: List of arguments
 * Return: Always return 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op_file(argv[1]);
	free_the_node();
	return (0);
}

/**
 * create_node - Creating a node.
 * @n: Numbr to be going inside the node.
 * Return: Upon sucess a ptr to the node. Otherwise return NULL.
 */
stack_t *create_node(int n)
{
	stack_t *nd;

	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		error_(4);
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = n;
	return (nd);
}

/**
 * free_the_node - Frees the nodes in the stack.
 */
void free_the_node(void)
{
	stack_t *t;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		t = head;
		head = head->next;
		free(t);
	}
}


/**
 * add_queue - For adding a node to the queue.
 * @new_nd: Pointer that points to the new node.
 * @ln: line numbr of the opcode.
 */
void add_queue(stack_t **new_nd, __attribute__((unused))unsigned int ln)
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
	while (t->next != NULL)
		t = t->next;

	t->next = *new_nd;
	(*new_nd)->prev = t;

}
