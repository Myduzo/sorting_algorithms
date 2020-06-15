#include "sort.h"
/**
 * partition - partition in an ascending order
 * @array : array of integers
 * @left : left of the array
 * @right : right of the array
 * @size : size of the array
 * Return: partitioned array
 */
int partition(int *array, int left, int right, size_t size)
{
    int x = left, y = left, pivot = array[right], tmp;

	while (y < right)
	{
		if (array[y] <= pivot)
		{
            tmp = array[x];
            array[x] = array[y];
            array[y] = tmp;
			if (x != y)
				print_array(array, size);
			x++;
		}
        y++;
	}
	if (x != y)
	{
		tmp = array[x];
        array[x] = array[y];
        array[y] = tmp;
		print_array(array, size);
	}
	return (x);
}


/**
 * before_quicksort - Lomuto partition schema
 * @array : array of integers
 * @left : left of the array
 * @right : right of the array
 * @size : size of the array
 */
void before_quicksort(int *array, int left, int right, size_t size)
{
    int location;

    if (left < right)
    {
        location = partition(array, left, right, size);
        before_quicksort(array, left, location - 1, size);
        before_quicksort(array, location + 1, right, size);
    }
}


/**
 * quick_sort - quick sort fucntion
 * @array : array of integers
 * @size : size of array
 */
void quick_sort(int *array, size_t size)
{
    before_quicksort(array, 0, (int)size - 1, size);
}
