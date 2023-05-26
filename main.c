#include "main.h"
#include  "shell.h"

/**
 *main - Entry
 *Return: 0 (Success)
 */
int head(void)
{
	while (1)
	{
		if (isatty(0))
		write(STDOUT_FILENO, "($) ", 4);
		process_input();
	}
	return (0);
}
