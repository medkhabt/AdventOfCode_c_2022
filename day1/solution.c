#include <stdio.h> 
#include <stdlib.h>

#define __NUMBER_LINES__ 2300
/*
  Input : 
  - v1: array of strings? 
  - v2: txt file 

  Output: total Calories carried by the elf with carrying the most calories. 


  Solutions : 
  - v1: go through the array, and update max 


  
  
  // 1 
*/
size_t readFile(const char* fileName, char** storage){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    size_t storage_size = 0; 

    fp = fopen(fileName, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        storage[storage_size] = malloc((read > 0) ? read : 1); 
        for(size_t i = 0; i < read ; i++) {
          if(i == read - 1  && line[i] - '0' == -38 ) { 
            storage[storage_size][read - 1] = '\0';  
            break;  
          }
          storage[storage_size][i] = line[i];
        }
        storage[storage_size++][read] = '\0'; 
       
        
    }
    fclose(fp);
    if (line)
        free(line);
    return storage_size; 
}
int main() { 
  // Declare consts and variables; 
  char* listOfCalories[__NUMBER_LINES__]; 
  unsigned maxCalories = 0, numberSize = 0, foodCaloriesOneElf  = 0, stringNumberToInt = 0 ;   
 
  const size_t __FILE_SIZE__ = readFile("inputs/input.txt", listOfCalories); 

  for(int i = 0; i < __FILE_SIZE__ ; i++) {
    // if the string is empty than we should reset the foodCaloriesOneElf. 
    if(*(listOfCalories[i]) == '\0'){
      maxCalories = (maxCalories > foodCaloriesOneElf) ? maxCalories : foodCaloriesOneElf; 
      foodCaloriesOneElf = 0; 
    }

    while(*(listOfCalories[i]++) != '\0') {
      // If the character in not a number than we just put 0. and continue to the next iteration .
      if((*(listOfCalories[i] - 1) - '0') < 0 || (*(listOfCalories[i] - 1) - '0') > 9) {
        stringNumberToInt = 0; 
        break; 
      } 
      stringNumberToInt = stringNumberToInt * 10 + (*(listOfCalories[i] - 1) - '0'); 
    }
    foodCaloriesOneElf += stringNumberToInt; 
    stringNumberToInt = 0; 
  }
  printf("The max calories are : %d .\n", maxCalories); 

  return 0; 
}
