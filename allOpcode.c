#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line number
 * Return: no return
 */
void push(stack_t **dhead, unsigned int cur_line)
{
	int n, j;

	if (!glob_var.arg)
	{
		dprintf(2, "L%u: ", cur_line);
		dprintf(2, "usage: push integer\n");
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glob_var.arg[j] != '\0'; j++)
	{
		if (!isdigit(glob_var.arg[j]) && glob_var.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cur_line);
			dprintf(2, "usage: push integer\n");
			free_glob_var();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glob_var.arg);

	if (glob_var.soq == 1)
		add_double_nodeint(dhead, n);
	else
		add_double_nodeint_end(dhead, n);
}

/**
 * pall - prints all values on the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line numbers
 * Return: no return
 */
void pall(stack_t **dhead, unsigned int cur_line)
{
	stack_t *aux;
	(void)cur_line;

	aux = *dhead;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}



/**
 * pint - prints the value at the top of the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line number
 * Return: no return
 */
void pint(stack_t **dhead, unsigned int cur_line)
{
	(void)cur_line;

	if (*dhead == NULL)
	{
		dprintf(2, "L%u: ", cur_line);
		dprintf(2, "can't pint, stack empty\n");
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*dhead)->n);
}


/**
 * pop - removes the top element of the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line number
 * Return: no return
 */
void pop(stack_t **dhead, unsigned int cur_line)
{
	stack_t *aux;

	if (dhead == NULL || *dhead == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cur_line);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	aux = *dhead;
	*dhead = (*dhead)->next;
	free(aux);
}




/**
 * swap - swaps the top two elements of the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line number
 * Return: no return
 */
void swap(stack_t **dhead, unsigned int cur_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *dhead;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cur_line);
		free_glob_var();
		exit(EXIT_FAILURE);
	}

	aux = *dhead;
	*dhead = (*dhead)->next;
	aux->next = (*dhead)->next;
	aux->prev = *dhead;
	(*dhead)->next = aux;
	(*dhead)->prev = NULL;
}




