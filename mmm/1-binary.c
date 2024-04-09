#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: The index where value is located, or -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t L = 0;
	size_t i, M, R;

	R = size - 1;

	if (!array || !size)
		return (-1);

	while (L <= R)
	{
		i = L;
		printf("Searching in array: ");
		while (i <= R)
		{
			if (i == R)
				printf("%d\n", array[i]);
			else
				printf("%d, ", array[i]);
			i++;
		}

		M = L + (R - L) / 2;

		if (array[M] == value)
			return (M);
		else if (array[M] < value)
			L = M + 1;
		else
			R = M - 1;
	}

	return (-1);
}
