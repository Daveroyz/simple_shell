#include "main.h"
/**
 *tokenize_input - function that splits commands into parts
 *@input: string to be entered
 *@cmd: command to execute
 *@args: number of args
 *Description: separates args in parts.
 */
void tokenize_input(char *input, char *cmd, char *args[])
{
	int i = 0;
	char *token = strtok(input, " ");

	if (token != NULL)
	{
		strcpy(cmd, token);
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
	}
	else
	{
		cmd[0] = '\0';
		args[0] = NULL;
	}
}
