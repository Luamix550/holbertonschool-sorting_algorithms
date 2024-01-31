#include "sort.h"
/**
 *swap - Swaps two element in an array
 *@a: pointer to first element
 *@b: pointer to second element
 */
void swap(int *a, int *b)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

/**
 * lomuto - Lomuto partition scheme for Quick Sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Partition index
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;


	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}
/**
 * quick_sort_ - Recursive function to perform Quick Sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_(int *array, int low, int high,  size_t size)
{
	if (low < high)
	{
		int pi = lomuto(array, low, high, size);

		quick_sort_(array, low, pi - 1, size);
		quick_sort_(array, pi + 1, high, size);
	}
}
/**
 * quick_sort -array of integers in ascending order using Quick Sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{

if (array == NULL || size < 2)
	return;

quick_sort_(array, 0, size - 1, size);

}
