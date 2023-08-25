#include "monty.h"


/**
 * _div - divides the second element by the top element of the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line number;
 * Return: no return
 */
void _div(stack_t **dhead, unsigned int cur_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *dhead;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't divide, stack too short\n", cur_line);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	if ((*dhead)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cur_line);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	aux = (*dhead)->next;
	aux->n /= (*dhead)->n;
	pop(dhead, cur_line);
}

/**
 * mul - multiplies the top element to the second top element of the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line number;
 * Return: no return
 */
void mul(stack_t **dhead, unsigned int cur_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *dhead;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cur_line);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	aux = (*dhead)->next;
	aux->n *= (*dhead)->n;
	pop(dhead, cur_line);
}


/**
 * mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line number;
 * Return: no return
 */
void mod(stack_t **dhead, unsigned int cur_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *dhead;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cur_line);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	if ((*dhead)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cur_line);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	aux = (*dhead)->next;
	aux->n %= (*dhead)->n;
	pop(dhead, cur_line);
}


