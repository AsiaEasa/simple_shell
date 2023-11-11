#include "hsh.h"
/**
 * str_tok - a function that spilt the string
 * @line: command input
 * Return: string
 */

char **str_tok(char *line)
{
	int j;
	char **str;
	char *token;

	j = 0;
	str = malloc(BUFFER_SIZE * sizeof(char *));

	if (!str)
	{
		write(1, "error in malloc\n", 16);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " ");
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
	str[j] = token;
		j++;
		token = strtok(NULL, " ");
	}
	str[j] = NULL;
	return (str);
}
/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
