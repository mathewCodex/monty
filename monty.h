#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct globals - global structure to use in the functions
 * @soq: is stack or queue
 * @cur_l: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO ALX
 */
typedef struct globals
{
	int soq;
	unsigned int cur_l;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_mty;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_mty glob_var;

/* opcode_instructuions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **dhead, unsigned int cur_line);
void pop(stack_t **dhead, unsigned int cur_line);
void swap(stack_t **dhead, unsigned int cur_line);
void queue(stack_t **dhead, unsigned int cur_line);
void stack(stack_t **dhead, unsigned int cur_line);
void add(stack_t **dhead, unsigned int cur_line);
void nop(stack_t **dhead, unsigned int cur_line);
void sub(stack_t **dhead, unsigned int cur_line);
void _div(stack_t **dhead, unsigned int cur_line);
void mul(stack_t **dhead, unsigned int cur_line);
void mod(stack_t **dhead, unsigned int cur_line);
void pchar(stack_t **dhead, unsigned int cur_line);
void pstr(stack_t **dhead, unsigned int cur_line);
void rotl(stack_t **dhead, unsigned int cur_line);
void rotr(stack_t **dhead, unsigned int cur_line);

/*get function*/
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int _ifchrstr(char *s, char c);
char *_strtok(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int num_elem, unsigned int size);
int _strcmp(char *s1, char *s2);

/* doubly linked list functions */
stack_t *add_double_nodeint_end(stack_t **head, const int n);
stack_t *add_double_nodeint(stack_t **head, const int n);
void double_list_free(stack_t *head);

/* main */
void free_glob_var(void);

#endif

