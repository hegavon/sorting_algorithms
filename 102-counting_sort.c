#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	unsigned int i;
	int max;

	int *count_array;
	int *sorted_array;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count_array = malloc((max + 1) * sizeof(int));
	if (count_array == NULL)
		return;

	for (i = 0; i <= (size_t)max; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max + 1);

	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}

	for (i = 0; i < size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(count_array);
	free(sorted_array);
}
