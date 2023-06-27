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
* partition - Finds and returns the index of the pivot, which
* is the middle index for dividing the array.
* @array: The array of integers.
* @size: The size of the array.
* @left_i: The left-most index of the partition.
* @right_i: The right-most index of the partition.
*
* Return: The pivot index.
*
* Description: This function is used in the Quick Sort algorithm.
*/
size_t partition(
	int *array, size_t size,
	long int left_i, long int right_i)
{
	long int i, j;
	int pivot = array[right_i];

	i = left_i - 1;
	for (j = left_i; j <= right_i; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i == j)
				continue;
			swap_ints(array + j, array + i);
			print_array(array, size);
		}
	}

	return (i);
}

/**
* sort - Sorts the elements on the left and right of the partition.
* @array: The array of integers.
* @size: The size of the array.
* @left_i: The left-most boundary of the array.
* @right_i: The right-most boundary of the array.
*
* Description: This function is a helper function used in the
* Quick Sort algorithm.
*/
void sort(
	int *array, size_t size,
	long int left_i, long int right_i
)
{
	long int p;

	if (left_i >= right_i || left_i < 0)
		return;

	p = partition(array, size, left_i, right_i);

	sort(array, size, left_i, p - 1);
	sort(array, size, p + 1, right_i);
}

/**
* quick_sort - Sorts an array of integers using the Quick Sort
* algorithm with Lomuto partitioning.
* @array: The array of integers.
* @size: The size of the array.
*
* Description: This function implements the Quick Sort algorithm to
* sort the array in ascending order.
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	sort(array, size, 0, (long int) (size - 1));
}
