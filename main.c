#include "main.h"
/**
 *main - Entry
 *Return: 0 (Success)
 */
int main(void)
{
	while (1)
	{
		if (isatty(0))
		write(STDOUT_FILENO, "($) ", 4);
		process_input();
	}
	return (0);
}
