#include "monty.h"

global_mty glob_var;

/**
 * free_glob_var - frees the global variables
 *
 * Return: no return
 */
void free_glob_var(void)
{
	double_list_free(glob_var.head);
	free(glob_var.buffer);
	fclose(glob_var.fd);
}

/**
 * start_glob_var - initializes the global variables
 *
 * @fd: file descriptor
 * Return: no return
 */
void start_glob_var(FILE *fd)
{
	glob_var.soq = 1;
	glob_var.cur_l = 1;
	glob_var.arg = NULL;
	glob_var.head = NULL;
	glob_var.fd = fd;
	glob_var.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_glob_var(fd);
	nlines = getline(&glob_var.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtok(glob_var.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", glob_var.cur_l);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_glob_var();
				exit(EXIT_FAILURE);
			}
			glob_var.arg = _strtok(NULL, " \t\n");
			f(&glob_var.head, glob_var.cur_l);
		}
		nlines = getline(&glob_var.buffer, &size, fd);
		glob_var.cur_l++;
	}

	free_glob_var();

	return (0);
}

