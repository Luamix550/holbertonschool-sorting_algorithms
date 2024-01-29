#include "sort.h"
/**
 * selection_sort - selects the smallest element from an unsorted list in each iteration 
 *  and places that element at the beginning of the unsorted list.
 * @array: 
 * @size:
*/
void selection_sort(int *array, size_t size)
{

    size_t i, j, min_idx; 

    for (i = 0; i < size - 1; i++) 
    { 
        min_idx = i; 
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx]) 
            {
                min_idx = j;
            } 
            swap(&array[min_idx], &array[i]);
            print_array(array, size);
        } 
    } 
} 

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}