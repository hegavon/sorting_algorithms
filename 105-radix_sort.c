#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
    int max, i;

    for (max = array[0], i = 1; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return (max);
}

/**
 * counting_sort_radix - Sort an array of integers using counting sort
 * based on the value at a specific significant place (exp).
 * @array: An array of integers.
 * @size: The size of the array.
 * @exp: The current significant place (exponential value).
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, *count, i;
	size_t index;

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * 10);

	if (output == NULL || count == NULL)
		return;

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		index = count[(array[i] / exp) % 10] - 1;
		output[index] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
	free(count);
}

/**
 * radix_sort - Sort an array of integers in ascending order using
 * the LSD Radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_radix(array, size, exp);
}
