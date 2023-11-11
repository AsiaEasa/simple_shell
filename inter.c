#include "hsh.h"

/**
 * interactive - UNIX command line interpreter
 *
 * Return: void
 */
void interactive(void)
{int re;
	char *prompt, **arg, *line;

	re = -1;
	prompt = "$ ";
	while (re == -1)

	{
		write(STDOUT_FILENO, prompt, 2);

		line =  get_line();
		arg = str_tok(line);
		re = check(arg);

		free(arg);
		free(line);
		if (re >= 0)
			exit(re); }}
