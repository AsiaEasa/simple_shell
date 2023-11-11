#include "hsh.h"

/**
 * check - to check what is the input
 * @arg: array of command
 * Return: exit
 */
int check(char **arg)
{
	if (arg[0] == NULL)
	{
		return (-1);
	}

	if (_strncmp(arg[0], "exit", 4) == 0)
		return (handle_exit(arg));

	if (_strncmp(arg[0], "env", 3) == 0 || _strncmp(arg[0], "printenv", 4) == 0)
		return (envi());

	if (_strncmp(arg[0], "cd", 2) == 0)
		return (cd(arg));

	return (my_fork(arg));
}
