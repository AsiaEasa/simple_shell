#include "hsh.h"

/**
 * _read - read a line from the stream
 *
 * Return: pointer that points the the read line
 */
char *_read(void)
{ int j, c, str;
	char *line;

	str = 1024, j = 0;
	line = malloc(sizeof(char) * str);
	while (1)
	{
		c = getchar();
		if (c == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			line[j] = '\0';
			return (line);
		}
		else
		{
			line[j] = c;
		}
		j++;
		if (j >= str)
		{
			str += str;
			line = realloc(line, str);
		}
	}}
