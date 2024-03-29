#include "sort.h"

/**
 * recursive_quick_sort - Recursively sorts the array
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: Number of elements in array
 */
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = lomuto_partition(array, low, high, size);

		recursive_quick_sort(array, low, partition_index - 1, size);
		recursive_quick_sort(array, partition_index + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using Quick Sort
* @array: The array to be sorted
* @size: Number of elements in the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: The array to be sorted
 * @low: The low index of the partition
 * @high: The high index of the partition
 * @size: Number of elements in array
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if ((i + 1) != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
