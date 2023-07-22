#include "quick_sort.h" 

int partition(int *arr, size_t arr_size, int low, int high){
  // high is included, this could lead to O(n^2) for the whole sorting algo
  // @todo: pivot should be in the middle to avoid the possibility of having O(n^2) as a worst case.    
  int *pivot_ptr = &arr[high]; 
  int temp; 
  int idx = low - 1; 
  for(size_t i = low; i < high && i < arr_size; i++){
    if(arr[i] <= *pivot_ptr) {
      temp = arr[i];
      arr[i] = arr[++idx];
      arr[idx] = temp;  
    }
  }
  // Swap the placement of the pivot value with where we got in the array (idx)
  temp = *pivot_ptr; 
  *pivot_ptr = arr[++idx]; 
  arr[idx] = temp; 

  return idx;  
} 

void qs(int *arr, size_t arr_size, int low, int high){
  if(low >= high) {
    return ; 
  }
  const int pv_idx = partition(arr, arr_size, low, high); 
  qs(arr, arr_size, low, pv_idx - 1); 
  qs(arr, arr_size, pv_idx + 1, high); 

}
void quick_sort(int *arr, size_t arr_size){
  qs(arr, arr_size, 0, arr_size - 1); 
} 