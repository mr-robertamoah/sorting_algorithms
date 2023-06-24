#include "sort.h"

/**
* swap_ints - swap the int values of two addresses
* @a: pointer to an int
* @b: pointer to an int
*/
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
* bubble_sort - bubble sort algorithm for sorting an
* array of integers
* @array: array of integers
* @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	int swapped = 0;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				swapped = 1;
			}
		}

		if (!swapped)
			break;
	}
}
