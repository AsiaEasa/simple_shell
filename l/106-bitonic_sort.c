#include "sort.h"

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
		printf("Result [%u/%lu] (UP):\n", 4, size);
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
		for (; j <= up; j+=2)
		{
			if (array[j] < array[j + 1])
			{
				x = array[j];
				array[j] = array[j + 1];
				array[j + 1] = x;
			}
		}
		printf("Result [%u/%lu] (DOWN):\n", 4, size);
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
	printf("Result [%u/%lu] (UP):\n", 2, size);
	print_array(array + start, 2);

	printf("Merging [%u/%lu] (DOWN):\n", 2, size);
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

	printf("Result [%u/%lu] (DOWN):\n", 2, size);
	print_array(array + (i - 1), 2);
	up_d1(array, size, start, up, l);
}
void bitonic_sort(int *array, size_t size)
{
	size_t len;
	int i, l, k, start;
	int arr[size / 2];

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

	for (i = 2; i < (int)size / 2; i += 4)
	{
		k++;
		up_d(array, size, start, i, l++);
		if(k % 2 == 0)
		{
			printf("Merging [%u/%lu] (DOWN):\n", 4, size);
			print_array(array + (start + 4), (start + 4));
			printf("Merging [%u/%lu] (UP):\n", 2, size);
			print_array(array + 4, 2);
			start += 4;
		}
	}
	mid(array, size);
	for (i = 0; i < (int)size; i++)
	{
		arr[i] = array[i + size / 2];
	}
	printf("Merging [%u/%lu] (DOWN):\n", 8, len);
	print_array(arr, 8);

	for (i = 4; i >= 2; i /= 2)
	{
		printf("Merging [%lu/%lu] (UP):\n", i, len);
		print_array(arr, i);
	}

	l = 2;
	k = 1;
	start = 0;

	up_d(arr, len, start, 2, l++);
	printf("Merging [%u/%lu] (DOWN):\n", 4, len);
	print_array(arr + 4, 4);
	printf("Merging [%u/%lu] (UP):\n", 2, len);
	print_array(arr + 4, 2);
	start += 4;
	up_d(arr, len, start, 6, l++);
	midD(arr, 16);
	for (i = 0; i < 8; i++)
	{
		array[i + 8] = arr[i];
	}
	midf(array, len);
}
