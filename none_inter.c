#include "hsh.h"

/**
 * none_interactive - UNIX command line none interpreter
 *
 * Return: void
 */
void none_interactive(void)
{int re;
	char **arg, *line;

	re = -1;
	while (re == -1)

	{
		line = _read();
		arg = str_tok(line);
		re = check(arg);
		free(arg);
		free(line);
		if (re >= 0)
		{
			exit(re); }}}
