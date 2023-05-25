#include "main.h"
/**
 *get_line - Read a line of input form stdin.
 *Description: Prompt user with text "($)".
 *Return: 0 on success.
 */
char *get_line(void)
{
	size_t n = 0;
	char *lineptr = NULL;
	ssize_t read;

	read = getline(&lineptr, &n, stdin);
	if (read > 0 && lineptr[read - 1] == '\n')
	lineptr[read - 1] = '\0';
	return (lineptr);
}
