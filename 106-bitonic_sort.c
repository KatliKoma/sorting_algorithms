#include "sort.h"

/**
 * bitonic_merge- Merge and sort a bitonic sequence.
 * @array: Pointer to the array to sort.
 * @size: Size of the `array`.
 * @low: Starting index of the sequence in `array`.
 * @count: Number of elements to sort.
 * @dir: Direction to sort (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, int low, int count, int dir)
{
	int i, temp;

	if (count > 1)
	{
		int k = count / 2;

		for (i = low; i < low + k; i++)
		{

			if ((array[i] > array[i + k]) == dir)
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
				print_array(array, size);
			}
		}

		bitonic_merge(array, size, low, k, dir);
		bitonic_merge(array, size, low + k, k, dir);
	}
}

/**
 * bitonic_sort_rec- Recursively sorts a bitonic sequence in
 * ascending or descending order, depending on `dir`.
 * @array: Pointer to the array to sort.
 * @size: Size of the `array`.
 * @low: Starting index of the sequence in `array`.
 * @count: Number of elements to sort.
 * @dir: Direction to sort (1 for ascending, 0 for descending).
 */
void bitonic_sort_rec(int *array, size_t size, int low, int count, int dir)
{
	if (count > 1)
	{
		int k = count / 2;

		bitonic_sort_rec(array, size, low, k, 1);
		bitonic_sort_rec(array, size, low + k, k, 0);
		bitonic_merge(array, size, low, count, dir);
	}
}

/**
 * Main function to call the recursive bitonic sort.
 * @array: Pointer to the array to sort.
 * @size: Size of the `array`.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_rec(array, size, 0, size, 1);
}
