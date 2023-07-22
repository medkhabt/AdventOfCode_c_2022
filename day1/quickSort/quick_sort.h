#include <stdlib.h>
void quick_sort(int *arr, size_t arr_size); 
// the return type is the pivot index. 
int partition(int *arr, size_t arr_size, int low, int high); 
void qs(int *arr, size_t arr_size, int low, int high);