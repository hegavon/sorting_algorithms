#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * bitonic_compare_swap - Compare and swap two integers based on the direction.
 * @array: An array of integers.
 * @i: Index of the first element.
 * @j: Index of the second element.
 * @dir: Sorting direction (UP or DOWN).
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
 * bitonic_merge - Merge a bitonic sequence.
 * @array: An array of integers.
 * @low: Starting index of the sequence.
 * @cnt: Size of the sequence.
 * @dir: Sorting direction (UP or DOWN).
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
 * bitonic_recursive_sort - Recursive Bitonic Sort.
 * @array: An array of integers.
 * @low: Starting index of the sequence.
 * @cnt: Size of the sequence.
 * @dir: Sorting direction (UP or DOWN).
 */
void bitonic_recursive_sort(int *array, size_t low, size_t cnt, int dir)
{
    if (cnt > 1)
    {
        size_t k = cnt / 2;

        printf("Merging [%lu/%lu] (%s):\n", k, cnt, (dir == UP) ? "UP" : "DOWN");
        print_array(array + low, cnt);

        bitonic_recursive_sort(array, low, k, UP);
        bitonic_recursive_sort(array, low + k, k, DOWN);

        bitonic_merge(array, low, cnt, dir);

        printf("Result [%lu/%lu] (%s):\n", cnt, cnt, (dir == UP) ? "UP" : "DOWN");
        print_array(array + low, cnt);
    }
}

/**
 * bitonic_sort - Sort an array of integers using Bitonic Sort.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_recursive_sort(array, 0, size, UP);
}
