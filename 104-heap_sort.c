#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index start
 * @array: The array to sort
 * @start: The root of the heap to repair
 * @end: The end of the heap section
 * @size: The size of the array
 */
static void sift_down(int *array, int start, int end, size_t size)
{
	int root = start;

	while (root * 2 + 1 <= end)
	{
		int child = root * 2 + 1;
		int swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			int temp = array[root];

			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heapify - Build a heap
 * @array: The array to heapify
 * @size: The size of the array
 */
static void heapify(int *array, size_t size)
{
	int start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - Perform the heap sort algorithm on an array of integers
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	int end = size - 1;

	if (!array || size < 2)
		return;

	heapify(array, size);

	while (end > 0)
	{
		int temp = array[end];

		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
