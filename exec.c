#include "main.h"
/**
 *execute_command - exeucte command with args
 *@args: arrays of arguments for commands
 *Description: to execute command
 *Return: 0 success
 */
int execute_command(char *args[])
{
	int status = 0;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Execvp failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pid == -1)
		{
			perror("Wait failed");
			exit(EXIT_FAILURE);
		}
		return (status);
	}
	return (-1);
}
