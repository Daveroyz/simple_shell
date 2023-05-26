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
=======
#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}


