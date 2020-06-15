#include "sort.h"
/**
 * partition - partition in an ascending order
 * @array : 
 * 
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
 * 
 * 
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
 * 
 * 
 */
void quick_sort(int *array, size_t size)
{
    before_quicksort(array, 0, (int)size - 1, size);
}
