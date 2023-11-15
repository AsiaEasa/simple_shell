#include "hsh.h"
/**
 *_strcat - concatenates two string
 * @dest: input value
 * @src: input value
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * str_concat - concatenates three strings
 * @word1: input value
 * @word2: input value
 * @word3: input value
 * Return: void
 */

char *str_concat(char *word1, char *word2, char *word3)
{
	int total_length = _strlen(word1) + _strlen(word2) + _strlen(word3) + 1;
	char *result = malloc(total_length * sizeof(char));

	if (result == NULL)
	{
		return (NULL); }
	_strcpy(result, word1);
	_strcat(result, word2);
	_strcat(result, word3);
	return (result); }

