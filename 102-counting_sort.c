#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, k = 0;
	size_t i;

	if (!array || size < 2)
		return;


	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	count = malloc((k + 1) * sizeof(int));

	if (!count)
		return;

	for (i = 0; i <= (size_t)k; i++)
		count[i] = 0;


	for (i = 0; i < size; i++)
		count[array[i]]++;


	print_array(count, k + 1);


	for (i = 1; i <= (size_t)k; i++)
		count[i] += count[i - 1];


	output = malloc(size * sizeof(int));
	if (!output)
	{
		free(count);
			return;
	}

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
