#include "sort.h"

/**
 * Lomuto partition scheme for Quick Sort.
 * @array: The array to sort.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The total size of the array for printing.
 * Return: The partition index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }
    if (array[high] < array[i + 1])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * Quick Sort algorithm using recursion.
 * @array: The array to be sorted.
 * @low: The starting index of the array.
 * @high: The ending index of the array.
 * @size: The total size of the array for printing.
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);
        quick_sort_recursion(array, low, pi - 1, size);
        quick_sort_recursion(array, pi + 1, high, size);
    }
}

/**
 * Main entry point for Quick Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursion(array, 0, size - 1, size);
}
