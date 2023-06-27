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
* bubble_sort - Sorts an array of integers using the bubble sort algorithm.
* @array: The array of integers to be sorted.
* @size: The size of the array.
*
* Description: This function implements the bubble sort algorithm
* to sort the array in ascending order.
*/
void bubble_sort(int *array, size_t size)
{
	int swapped = 0;
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
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
