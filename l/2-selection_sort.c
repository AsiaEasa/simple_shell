#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
    size_t i, j, min_i;
    int p;

	if (!array || !size || size < 2)
		return;

    for (i = 0; i < size - 1; i++)
    {
        min_i = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_i])
                min_i = j;
        }

        if (min_i != i)
        {
            p = array[i];
            array[i] = array[min_i];
            array[min_i] = p;

            print_array(array, size);
        }
    }
}
