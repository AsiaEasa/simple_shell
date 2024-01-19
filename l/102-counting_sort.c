#include "sort.h"

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *places, max, x;
	size_t k, i;

	if (array == NULL || !size || size < 2)
		return;

	places = malloc(sizeof(int) * size);
	if (places == NULL)
		return;

	max = array[0];
	k = 1;
	while (k < size)
	{
		if (array[k] > max)
			max = array[k];
		k += 1;
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(places);
		return;
	}

	for (x = 0; x < (max + 1); x++)
		count[x] = 0;
	i = 0;
	while (i < size)
	{
		count[array[i]] += 1;
		i += 1;
	}
	for (x = 1; x < (max + 1); x++)
		count[x] += count[x - 1];
	print_array(count, max + 1);

	i = 0;
	while (i < size)
	{
		places[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	i += 1;
	}

	k = 0;
	for (; k < size; k++)
		array[k] = places[k];

	free(places);
	free(count);
}
