#include "hsh.h"

/**
 * check - to check what is the input
 * @arg: array of command
 * Return: exit
 */
int check(char **arg)
{char *_path;
	int ex;
	struct stat stat_in;

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
	ex = stat(arg[0], &stat_in);
	if (ex)
	{ _path = Path(arg[0]);
		if (!_path)
		{ error(arg[0]);
			free(_path);
			return (127); }
		arg[0] = NULL;
		arg[0] = _path;
		my_fork(arg);
		free(_path);
		return (-1); }
	return (my_fork(arg));
}
