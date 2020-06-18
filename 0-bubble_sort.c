#include "sort.h"
/**
 * bubble_sort - Bubble sort algorithm
 * @array: array of integers
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t pass = 0, idx = 0;
	int temp, flag;

	if (!array)
		return;
	while (pass < size - 1)
	{
		flag = 0;
		while (idx < size - 1)
		{
			if (array[idx] > array[idx + 1])
			{
				temp = array[idx + 1];
				array[idx + 1] = array[idx];
				array[idx] = temp;
				flag = 1;
				print_array(array, size);
			}
			idx++;
		}
		if (flag == 0)
			break;
		pass++;
		idx = 0;
	}
}
