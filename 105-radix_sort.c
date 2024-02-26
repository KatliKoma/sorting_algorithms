#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void counting_sort_for_radix(int *array, size_t size, int exp);
int max_value(int *array, size_t size);

/**
 * radix_sort - sorts an array of integers in
 * ascending order using the Radix sort algorithm.
 * @array: the array to be sorted.
 * @size: the size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = max_value(array, size);


	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_for_radix(array, size, exp);
		print_array(array, size);
	}
}

/**
 * counting_sort_for_radix - A function to do counting
 * sort of array[] according to
 * the digit represented by exp (10^exp is the current digit place).
 * @array: Array to be sorted.
 * @size: Size of the array.
 * @exp: Exponent representing the current digit to sort by.
 */
void counting_sort_for_radix(int *array, size_t size, int exp)
{
	int output[size];
	int i, count[10] = {0};


	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];


	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}


	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
}

/**
 * max_value - A utility function to get the maximum value in array[].
 * @array: Array to be processed.
 * @size: Size of the array.
 * Return: Maximum integer in the array.
 */
int max_value(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}
