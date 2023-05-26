#include "main.h"
/**
 *get_env - function that prints environment variables
 *@env: retrieve environ variables
 *@env_variable: environ variables to be printed
 *Description: retrieve variables.
 *Return: value of the environ variable or NULL if fails
 */
char *get_env(char *env_variable, char *env[])
{
	int status;
	int i = 0, j;

	/* loop through each element of environ array */
	for (i = 0; env[i] != NULL; i++)
		{
		status = 1;
	/* check each character of current environ untill '=' */
		for (j = 0; env[i][j] != '='; j++)
		{
		/* compare each character of environ variables */
			if (env[i][j] != env_variable[j])
			status = 0;/*if char mismatch set it to 0 */
		}
		if (status == 1)
			break;
		}
		return (&env[i][j] + 1);
}
/**
 *print_env - function that prints environment variables
 *@env: retrieve environ variables
 *Desciription: Print all the environ variables
 */
void print_env(char *env[])
{
	int i = 0;

	/* loop through each element of environ array */
	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
