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
* selection_sort - using selection sort algorithm to
* sort an array of integers
* @array: array of integers
* @size: length of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min_index] > array[j])
				min_index = j;
		}

		if (min_index != i)
		{
			swap_ints(array + i, array + min_index);
			print_array(array, size);
		}
	}
}
