#include "sort.h"

/**
 * merge - Merge two sub-arrays of array[].
 * @array: The array containing the sub-arrays.
 * @temp: Temporary array to store merged result.
 * @left: Index of the start of the first sub-array.
 * @mid: Index of the end of the first sub-array.
 * @right: Index of the end of the second sub-array.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid, k = 0;

    printf("[Merging...]\n");
    printf("[left]: ");
    print_array(array + left, mid - left);
    printf("[right]: ");
    print_array(array + mid, right - mid);

    while (i < mid && j < right)
    {
        if (array[i] <= array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            temp[k++] = array[j++];
        }
    }

    while (i < mid)
        temp[k++] = array[i++];
    while (j < right)
        temp[k++] = array[j++];

    for (i = 0; i < k; i++)
        array[left + i] = temp[i];

    printf("[Done]: ");
    print_array(temp, k);
}

/**
 * merge_sort_recursive - Recursively divides the array into sub-arrays.
 * @array: The array to be sorted.
 * @temp: Temporary array to store merged result.
 * @left: Index of the start of the sub-array.
 * @right: Index of the end of the sub-array.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    if (right - left > 1)
    {
        size_t mid = left + (right - left) / 2;

        merge_sort_recursive(array, temp, left, mid);
        merge_sort_recursive(array, temp, mid, right);
        merge(array, temp, left, mid, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(size * sizeof(int));
    if (temp == NULL)
        return;

    merge_sort_recursive(array, temp, 0, size);

    free(temp);
}
