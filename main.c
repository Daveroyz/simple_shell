#include "main.h"
/**
 *main - Entryi
 *Return: 0 (Success)
 */
int main(void)
{
	char *str = "No such file or directory";
	char *lineptr = NULL;
	char *args[2];

	while (1)
	{
		if (isatty(0))
		write(STDOUT_FILENO, "(S) ", 4);
		lineptr = get_line();
		/* Split the input line into arguments*/
		args[0] = "/bin/ls";
		args[1] = NULL;
		/*Execute the command*/
	if (strcmp(lineptr, "/bin/ls") == 0)
	{
		execute_command(args);
	}
	else
	{
		write(STDOUT_FILENO, str, strlen(str));
		write(STDOUT_FILENO, "\n", 1);
	}
	free(lineptr);
	}
	return (0);
}
