#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line number;
 * Return: no return
 */
void add(stack_t **dhead, unsigned int cur_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *dhead;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cur_line);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	aux = (*dhead)->next;
	aux->n += (*dhead)->n;
	pop(dhead, cur_line);
}


/**
 * nop - doesn't do anythinhg
 *
 * @dhead: head of the linked list
 * @cur_line: line number;
 * Return: no return
 */
void nop(stack_t **dhead, unsigned int cur_line)
{
	(void)dhead;
	(void)cur_line;
}



/**
 * sub - subtracts the top element to the second top element of the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line number;
 * Return: no return
 */
void sub(stack_t **dhead, unsigned int cur_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *dhead;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cur_line);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	aux = (*dhead)->next;
	aux->n -= (*dhead)->n;
	pop(dhead, cur_line);
}
