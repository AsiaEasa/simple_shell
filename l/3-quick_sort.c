#include "sort.h"

/**
 * lomuto_Par - sorts pivot
 * @ar: The array to sort
 * @begin:  start of the index
 * @end: the end of index
 * @len:  array  of size
 * Return: The index of the pivot
 */

size_t lomuto_Par(int *ar, ssize_t begin, ssize_t end, size_t len)
{
	int pivot = ar[end], p;
	int i, j;

	i = begin;
	j = begin;
	while (j < end)
	{
		if (pivot > ar[j])
		{

			if (ar[i] != ar[j])
			{
				/* swap */
				p = ar[j];
				ar[j] = ar[i];
				ar[i] = p;
				print_array(ar, len);
			}
			i += 1;
		}
		j++;
	}
	if (ar[i] != ar[j])
	{
		/* swap */
		p = ar[i];
		ar[i] = ar[end];
		ar[end] = p;
		print_array(ar, len);
	}
	return (i);
}

/**
 * quick_rec - sorts an array using the quick sort algorithm
 * @ar: array to sort
 * @begin: start  of index
 * @end: end of index
 * @len: array  of size
 */
void quick_rec(int *ar, int begin, int end, size_t len)
{
	size_t i_part;

	if (end > begin)
	{
		i_part = lomuto_Par(ar, begin, end, len);

		quick_rec(ar, begin, i_part - 1, len);
		quick_rec(ar, i_part + 1, end, len);
	}
}

/**
 * quick_sort - sorts a list using the quick sort algotithm
 * @array: The array to  sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;

	quick_rec(array, 0, size - 1, size);
}
