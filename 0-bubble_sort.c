#include "sort.h"
/**
 * bubble_sort - sort array elements from min to max value
 * @array: array
 * @size: array size
 */

void bubble_sort(int *array, size_t size)
{
	size_t currentIndex, nextIndex, newLimit = size;
	int swapTemp, swapOccurred = 0;

	if (array == NULL || size < 2)
		return;

	for (currentIndex = 0; currentIndex < size; currentIndex++)
	{
		for (nextIndex = 1; nextIndex < newLimit; nextIndex++)
		{
			if (array[nextIndex - 1] > array[nextIndex])
			{
				swapOccurred = 1;
				swapTemp = array[nextIndex];
				array[nextIndex] = array[nextIndex - 1];
				array[nextIndex - 1] = swapTemp;
				print_array(array, size);
			}
		}

		if (swapOccurred == 0)
			break;

		swapOccurred = 0;
		newLimit--;
	}
}
