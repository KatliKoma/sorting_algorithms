#include "sort.h"

/**
 * merge-Merge two subarrays of array[].
 * @array: First subarray is arr[begin..mid]
 * @copy:Second subarray is arr[mid+1..end]
 * @array: The array to be sorted, which will contain the merged output.
 * @copy: A copy of the array used to hold the original values during the merge process.
 *        The first subarray is `copy[begin..mid]`, and the second subarray is `copy[mid+1..end]`.
 * @begin: The starting index of the first subarray.
 * @mid: The ending index of the first subarray, which also separates the two subarrays.
 *       The second subarray starts at `mid + 1`.
 * @end: The ending index of the second subarray.
 */
void merge(int *array, int *copy, size_t begin, size_t mid, size_t end)
{
	size_t i = begin, j = mid, k = begin;

	while (i <= mid - 1 && j <= end)
	{
		if (copy[i] <= copy[j])
			array[k++] = copy[i++];
		else
			array[k++] = copy[j++];
	}
	while (i <= mid - 1)
		array[k++] = copy[i++];

	while (j <= end)
		array[k++] = copy[j++];
}

/**
 * topDownSplitMerge-Main function that sorts arr[begin..end] using merge()
 * @copy: A copy of the original array, used here as a working array to hold elements during
 *        the merge process. The sorted elements are merged back into the original array (@array).
 *        This parameter allows the function to work on a copy of the array segments for merging,
 *        ensuring that the original array is updated with the sorted order.
 * @begin: The starting index of the segment of the array to be sorted. Initially, this would
 *         be 0, representing the start of the array.
 * @end: The ending index of the segment of the array to be sorted. Initially, this would be
 *       the index of the last element in the array.
 * @array: The original array that needs to be sorted. As the algorithm progresses, this array
 *         is updated with the sorted elements as they are merged from the @copy array.
 *
 */
void topDownSplitMerge(int *copy, size_t begin, size_t end, int *array)
{
	if (end - begin < 1)
	return;

	size_t mid = (end + begin) / 2;

	topDownSplitMerge(array, begin, mid, copy);
	topDownSplitMerge(array, mid + 1, end, copy);
	merge(array, copy, begin, mid + 1, end);
}

/**
 * merge_sort-Merge sort function
 * @array: Pointer to the first element of the array to be sorted. The array contains
 *         the elements that will be sorted in place, meaning that the contents of
 *         this array will be modified to present the sorted order upon completion.
 * @size: The number of elements in the array. This size determines the range of
 *        elements to be sorted and is used to allocate memory for the temporary array
 *        used during the sorting process.
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	int *copy = malloc(size * sizeof(int));

	if (!copy)
		return;

	for (size_t i = 0; i < size; i++)
		copy[i] = array[i];

	topDownSplitMerge(copy, 0, size - 1, array);
	free(copy);
}
