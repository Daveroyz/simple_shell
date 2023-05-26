#include "main.h"
/**
 *process_input - function that process input
 *Description: process command entered
 *Return: print out is success
 */
void process_input(void)
{
	char input[100];
	char *args[20];
	char *cmd;
	bool execute;
	int i;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		fgets(input, sizeof(input), stdin);
		/* replaces the newline char with a null charater */
		input[strcspn(input, "\n")] = '\0';
		cmd = strtok(input, " ");
		if (cmd == NULL)
			continue;
		if (strcmp(cmd, "exit") == 0)
		{
			break;
		}
		/*stores first command/token into args array at ind 0 */
		args[0] = cmd;
		for (i = 1; i < 19; i++)
		{
		/*extracts subsequent token */
			args[i] = strtok(NULL, " ");
			if (args[i] == NULL)
				break;
		}
		execute = false;
		/* checks if command is allowed one*/
		if (strcmp(cmd, "ls") == 0 || strcmp(cmd, "/bin/ls") == 0 ||
		strcmp(cmd, "-l") == 0 || strcmp(cmd, "/tmp") == 0 ||
		strcmp(cmd, "env") == 0)
		{
			execute = true;
			execute_command(cmd, args);
		}
		if (!execute)
		{
			print_error_message("Command does not exist");
		}
	}

}

/**
 *print_error_message - function that prints error message
 *@message: message to be printed
 *Description: display error messgae
 *Return: prints error meg to the screen
 */
void print_error_message(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
	write(STDOUT_FILENO, "\n", 1);
}

