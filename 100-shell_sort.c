#include "sort.h"

/**
 * shell_sort - sorts an array of integers
 * in ascending order using the Shell sort
 * algorithm, leveraging the Knuth sequence for interval determination.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}


	for (; gap > 0; gap /= 3)
	{

		for (i = gap; i < size; i += 1)
		{

			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}

		print_array(array, size);
	}
}
