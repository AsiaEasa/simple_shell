#include "hsh.h"

/**
 * Path - checks if a file exists in PATH
 * @command: command input
 * Return: The full path of the file or NULL if not found.
 */
char *Path(char *command)
{
	char *path = in_env("PATH");
	char *pathCopy = _strdup(path);
	char *token = pathCopy;
	char *fullPath = NULL;

	while (token != NULL && *token != '\0')
	{ char *delimiter = _strchr(token, ':');
		if (delimiter != NULL)

			*delimiter = '\0';

		fullPath = str_concat(token, "/", command);
		if (fullPath != NULL)
		{
			if (access(fullPath, X_OK) == 0)
			{ free(pathCopy);
				return (fullPath); }

			free(fullPath);
			token = delimiter != NULL ? delimiter + 1 : NULL;
		} else
		{perror("memory");
			free(pathCopy);
			free(fullPath);
			return (NULL); }
	}
	free(pathCopy);
	free(fullPath);
	return (NULL); }
/**
 *_strchr - Entry point
 * @s: input
 * @c: input
 * Return: Always 0 (Success)
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}

/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: 0
 */
char *_strdup(char *str)
{
	char *aaa;
	int i, r = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	aaa = malloc(sizeof(char) * (i + 1));

	if (aaa == NULL)
		return (NULL);

	for (r = 0; str[r]; r++)
		aaa[r] = str[r];
	return (aaa);
}
