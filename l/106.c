#include "sort.h"

void mid(int *array, size_t size)
{
	int x;
	int i, j, h;

	for (i = 0; i < 4; i++)
	{
		if (array[i] > array[i + 4])
		{
			x = array[i];
			array[i] = array[i + 4];
			array[i + 4] = x;
		}
	}

	for (i = 0; i <= 4; i++)
	{
		if (array[i] > array[i + 2])
		{
			x = array[i];
			array[i] = array[i + 2];
			array[i + 2] = x;
		}
		if(i == 1)
			i += 3;
	}

	for (i = 0; i < 8; i+=2)
	{
		if (array[i] > array[i + 1])
		{
			x = array[i];
			array[i] = array[i + 1];
			array[i + 1] = x;
		}
	}
	printf("Result [%lu/%lu] (UP):\n", 8, size);
	print_array(array, (size / 2));
}

void up_d1(int *array, size_t size, int start, int up, int l)
{
	int x;
	int i, j;

	i = start;
	j = start;
	if(l % 2 == 0)
	{
		for (; i < start + 2; i++)
		{
			if (array[i] > array[i + 2])
			{
				x = array[i];
				array[i] = array[i + 2];
				array[i + 2] = x;
			}
		}
		for (; j < start + 2; j+=2)
		{
			if (array[j] > array[j + 1])
			{
				x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;
			}
		}
		printf("Result [%lu/%lu] (UP):\n", 4, size);
		print_array(array, (i + 2));
	}
	else
	{
		for (; i < up; i++)
		{
			if (array[i] < array[i + 2])
			{
				x = array[i];
				array[i] = array[i + 2];
				array[i + 2] = x;

			}
		}
		for (; j < up + start; j+=2)
		{
			if (array[j] < array[j + 1])
			{
				x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;
			}
		}
		printf("Result [%lu/%lu] (DOWN):\n", 4, size);
		print_array(array + start, 4);
	}
}

void up_d(int *array, size_t size, int start, int up, int l)
{
	int x;
	int i;

	i = start;

	for (; i < up - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			x = array[i];
			array[i] = array[i + 1];
			array[i + 1] = x;
		}
	}
	i++;
	printf("Result [%lu/%lu] (UP):\n", 2, size);
	print_array(array + start, 2);

	printf("Merging [%lu/%lu] (DOWN):\n", 2, size);
	print_array(array + i, 2);

	for (; i < up + 1; i++)
	{
		if (array[i] < array[i + 1])
		{
			x = array[i];
			array[i] = array[i + 1];
			array[i + 1] = x;
		}
	}

	printf("Result [%lu/%lu] (DOWN):\n", 2, size);
	print_array(array + (i - 1), 2);
	up_d1(array, size, start, up, l);
}

void bitonic_sort(int *array, size_t size)
{
	size_t step, len;
	int i, l, k, start;
	
	len = size;
	l = 2;
	k = 1;
	start = 0;
	if (!array || !size || size < 2)
		return;

	for (i = 1; len / i != 1; i *= 2)
	{
		printf("Merging [%lu/%lu] (UP):\n", (len / i), size);
		print_array(array, (len / i));
	}

	for (i = 2; i < size / 2; i += 4)
	{
		k++;
		up_d(array, size, start, i, l++);
		if(k % 2 == 0)
		{
			printf("Merging [%lu/%lu] (DOWN):\n", 4, size);
			print_array(array + (start + 4), (start + 4));
			printf("Merging [%lu/%lu] (UP):\n", 2, size);
			print_array(array + 4, 2);
			start += 4;
		}
	}
	mid(array, size);
}
