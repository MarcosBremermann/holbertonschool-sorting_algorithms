#include "sort.h"
#include <stddef.h>
/**
 * function that sorts array of integers using the bubble sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp;

				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
		{
			break;
		}
	}
}
