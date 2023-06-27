#include "sort.h"

/**
* swap_ints - Swaps the values of two integer pointers.
* @a: Pointer to the first integer.
* @b: Pointer to the second integer.
*
* Description: This function swaps the values of the integers
* pointed to by 'a' and 'b'.
*/
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
* selection_sort - Sorts an array of integers using the selection
* sort algorithm.
* @array: The array of integers to be sorted.
* @size: The size of the array.
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
