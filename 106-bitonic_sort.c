#include <stdio.h>
#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * bitonic_compare_swap - Compares and swaps two elements in an array.
 * @array: The array containing elements to swap.
 * @i: The index of the first element.
 * @j: The index of the second element.
 * @dir: The sorting direction (UP or DOWN).
 */
void bitonic_compare_swap(int *array, size_t i, size_t j, int dir)
{
    if ((dir == UP && array[i] > array[j]) || (dir == DOWN && array[i] < array[j]))
    {
        swap_ints(&array[i], &array[j]);
        printf("Merging [%lu/%lu] (%s):\n", j - i + 1, j + 1, (dir == UP) ? "UP" : "DOWN");
        print_array(array + i, j - i + 1);
    }
}

/**
 * bitonic_merge - Merges two subarrays in bitonic order.
 * @array: The array containing subarrays to merge.
 * @low: The starting index of the subarray.
 * @cnt: The size of the subarray.
 * @dir: The sorting direction (UP or DOWN).
 */
void bitonic_merge(int *array, size_t low, size_t cnt, int dir)
{
    if (cnt > 1)
    {
        size_t k = cnt / 2;
        size_t i;

        for (i = low; i < low + k; ++i)
            bitonic_compare_swap(array, i, i + k, dir);

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_recursive_sort - Recursively sorts an array using bitonic sort.
 * @array: The array to sort.
 * @low: The starting index of the array.
 * @cnt: The size of the array.
 * @dir: The sorting direction (UP or DOWN).
 */
void bitonic_recursive_sort(int *array, size_t low, size_t cnt, int dir)
{
    if (cnt > 1)
    {
        size_t k = cnt / 2;

        bitonic_recursive_sort(array, low, k, UP);
        bitonic_recursive_sort(array, low + k, k, DOWN);

        printf("Merging [%lu/%lu] (%s):\n", cnt, cnt, (dir == UP) ? "UP" : "DOWN");
        print_array(array + low, cnt);

        bitonic_merge(array, low, cnt, dir);

        printf("Result [%lu/%lu] (%s):\n", cnt, cnt, (dir == UP) ? "UP" : "DOWN");
        print_array(array + low, cnt);
    }
}

/**
 * bitonic_sort - Sorts an array using the bitonic sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_recursive_sort(array, 0, size, UP);
}
