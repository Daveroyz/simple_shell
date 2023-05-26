#include "main.h"
/**
 *is_exit_command - exit the shell
 *@command: command to exit shell
 *Description: exit the shell with newline
 */
bool is_exit_command(const char *command)
{
	return (strcmp(command, "exit") == 0);
}
