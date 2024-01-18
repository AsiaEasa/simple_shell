#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array.
 * @size: The size of the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, l = size;
	int p, x;

	x = 0;
	if (!array || !size || size < 2)
		return;

	while (x == 0)
	{
		x = 1;
		for (i = 0; i < l - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				p = array[i];
				array[i] = array[i + 1];
				array[i + 1] = p;
				print_array(array, size);
				x = 0;
			}
		}
		l--;
	}
}
