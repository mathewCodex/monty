#include "monty.h"



/**
 * stack - sets the format fo the data to a stack (LIFO)
 *
 * @dhead: head of the linked list
 * @cur_line: line number;
 * Return: no return
 */
void stack(stack_t **dhead, unsigned int cur_line)
{
	(void)dhead;
	(void)cur_line;

	 glob_var.soq = 1;
}


/**
 * queue - sets the format of the data to a queue (FIFO)
 *
 * @dhead: head of the linked list
 * @cur_line: line number;
 * Return: no return
 */
void queue(stack_t **dhead, unsigned int cur_line)
{
	(void)dhead;
	(void)cur_line;

	glob_var.soq = 0;
}
