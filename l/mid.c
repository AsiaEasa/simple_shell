void midf(int *array, size_t size)
{
	int x;
	int i;
	
		
	for (i = 0; i < 8; i++)
	{
		if (array[i] > array[i + 8])
		{
			x = array[i];
			array[i] = array[i + 8];
			array[i + 8] = x;
		}
	}
	
	for (i = 0; i < 12; i++)
	{
		if (array[i] > array[i + 4])
		{
			x = array[i];
			array[i] = array[i + 4];
			array[i + 4] = x;
		}
		if(i == 3)
		   i = 7;
	}
	
	for (i = 0; i <= 8; i++)
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

	for (i = 0; i < 16; i+=2)
	{
		if (array[i] > array[i + 1])
		{
			x = array[i];
			array[i] = array[i + 1];
			array[i + 1] = x;
		}
	}
	printf("Result [%u/%lu] (UP):\n", 16, size);
	print_array(array, size);
}
void midD(int *array, size_t size)
{
	int x;
	int i;

	for (i = 0; i < 4; i++)
	{
		if (array[i] < array[i + 4])
		{
			x = array[i];
			array[i] = array[i + 4];
			array[i + 4] = x;
		}
	}

	for (i = 0; i <= 4; i++)
	{
		if (array[i] < array[i + 2])
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
		if (array[i] < array[i + 1])
		{
			x = array[i];
			array[i] = array[i + 1];
			array[i + 1] = x;
		}
	}
	printf("Result [%u/%lu] (DOWN):\n", 8, size);
	print_array(array, (size / 2));
}
void mid(int *array, size_t size)
{
	int x;
	int i;

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
	printf("Result [%u/%lu] (UP):\n", 8, size);
	print_array(array, (size / 2));
}
