#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max = array[0];
	int i = 1;

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}

	return (max);
}
