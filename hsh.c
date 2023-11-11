#include "hsh.h"

/**
 * main - Entry point for the custom shell program.
 * Return: Exit status.
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive();
	}
	else
	{
		none_interactive();
	}
	return (0);
}
