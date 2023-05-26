#include "main.h"
#include  "shell.h"

/**
 *main - Entry
 *Return: 0 (Success)
 */
int main(void)
{

	while (1)
	{
		if (isatty(0))
		process_input();
		if (is_exit_command("exit"))
			break;
	}
	return (0);
}
