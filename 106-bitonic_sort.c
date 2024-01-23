#include "sort.h"

void swap_ints(int *a_bio, int *b_bio);
void bitonic_merge(int *arr, size_t size, size_t start, size_t seqs, char flow);
void bitonic_seq(int *arr, size_t size, size_t start, size_t seqs, char flow);
void bitonic_sort(int *arr, size_t size);

/**
 * swap_ints - The swap function for integers.
 * @a_bio: This is the first integer to swap.
 * @b_bio: This is the second integer to swap.
 */
void swap_ints(int *a_bio, int *b_bio)
{
	int temp;

	temp = *a_bio;
	*a_bio = *b_bio;
	*b_bio = temp;
}

/**
 * bitonic_merge - Merges two bitonic sequences.
 * @arr: This is an array of integers.
 * @size: This is the size of the array.
 * @start: This is the start index of the sequence to sort.
 * @seqs: This is the number of elements in the sequence to sort.
 * @flow: This is the direction of the sequence to sort.
 */
void bitonic_merge(int *arr, size_t size, size_t start, size_t seqs,
		char flow)
{
	size_t i, jump = seqs / 2;

	if (seqs > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && arr[i] > arr[i + jump]) ||
					(flow == DOWN && arr[i] < arr[i + jump]))
			{
				swap_ints(arr + i, arr + i + jump);
				printf("Merging [%lu/%lu] (%s):\n", seqs, size, (flow == UP) ? "UP" : "DOWN");
				print_array(arr + start, seqs);
			}
		}
		bitonic_merge(arr, size, start, jump, flow);
		bitonic_merge(arr, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @arr: This is an array of integers.
 * @size: This is the size of the array in the sequence.
 * @start: This is the start index of the sequence to sort.
 * @seqs:  This is the number of elements in the sequence to sort.
 * @flow: This is the direction of the sequence to sort.
 */
void bitonic_seq(int *arr, size_t size, size_t start, size_t seqs, char flow)
{
	size_t cut = seqs / 2;

	if (seqs > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seqs, size, (flow == UP) ? "UP" : "DOWN");
		print_array(arr + start, seqs);

		bitonic_seq(arr, size, start, cut, UP);
		bitonic_seq(arr, size, start + cut, cut, DOWN);
		bitonic_merge(arr, size, start, seqs, flow);

		printf("Result [%lu/%lu] (%s):\n", seqs, size, (flow == UP) ? "UP" : "DOWN");
		print_array(arr + start, seqs);
	}
}

/**
 * bitonic_sort - This function sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @arr: This is an array of integers.
 * @size: This is the size of the array.
 *
 * Description: The function prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *arr, size_t size)
{
	if (arr == NULL || size < 2)
		return;

	bitonic_seq(arr, size, 0, size, UP);
}
