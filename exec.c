#include "main.h"
/**
 *execute_command - exeucte command with args
 *@cmd: command to be executed
 *@args: arrays of arguments for commands
 */
void execute_command(char *cmd, char *args[])
{
	pid_t pid = fork();

	if (pid < 0)
	{
	/* Error message is executed if fork fails */
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
	/* execute command with args given */
		execvp(cmd, args);
		perror("Command execution failed");
		exit(1);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
