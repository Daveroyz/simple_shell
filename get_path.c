#include "main.h"
/**
 *get_path - Retrives the value of PATH environment variable
 *Decsription: it uses the getenv() to retrives the values.
 *Return:returns a poiter to duplicated srting, on failure exit the program.
 */
char *get_path()
{
	char *path = getenv("PATH");
	char err[] = "Failed to retrieved PATH environment variables";

	if (path == NULL)
	{
		write(STDOUT_FILENO, err, strlen(err));
		exit(EXIT_FAILURE);
	}
	return (strdup(path));
}
