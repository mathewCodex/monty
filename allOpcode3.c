#include "monty.h"



/**
 * pchar - print the char value of the first element
 *
 * @dhead: head of the linked list
 * @cur_line: line number;
 * Return: no return
 */
void pchar(stack_t **dhead, unsigned int cur_line)
{
	if (dhead == NULL || *dhead == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cur_line);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	if ((*dhead)->n < 0 || (*dhead)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cur_line);
		free_glob_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*dhead)->n);
}

/**
 * pstr - prints the string of the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line number;
 * Return: no return
 */
void pstr(stack_t **dhead, unsigned int cur_line)
{
	stack_t *aux;
	(void)cur_line;

	aux = *dhead;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}



/**
 * rotl - rotates the first element to the bottom and  the second to the top
 *
 * @dhead: head of the linked list
 * @cur_line: line number;
 * Return: no return
 */
void rotl(stack_t **dhead, unsigned int cur_line)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)cur_line;

	if (*dhead == NULL)
		return;

	if ((*dhead)->next == NULL)
		return;

	aux1 = (*dhead)->next;
	aux2 = *dhead;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *dhead;
	(*dhead)->next = NULL;
	(*dhead)->prev = aux2;
	*dhead = aux1;
}




/**
 * rotr - reverse the stack
 *
 * @dhead: head of the linked list
 * @cur_line: line number
 * Return: no return
 */
void rotr(stack_t **dhead, unsigned int cur_line)
{
	stack_t *aux = NULL;
	(void)cur_line;

	if (*dhead == NULL)
		return;

	if ((*dhead)->next == NULL)
		return;

	aux = *dhead;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *dhead;
	aux->prev = NULL;
	(*dhead)->prev = aux;
	*dhead = aux;
}
