#include <stdio.h>
#include <stdlib.h>
#include "round.h"
/*
A X 
B Y 
C Y 
=> 
temp = "A X" => trim : "A", "X"

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
      // we don't actually need this read check in this solution i think. no empty lines. 
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
  // Reading and converting the file to an array of rounds. 
  round *rounds; 
  unsigned int sum_pts = 0; 
  // Summing up all the rounds. 
  for(size_t i = 0; i < 10; i++) {
    sum_pts += result_round(&rounds[i]); 
  }
  printf("result: %u" , sum_pts); 
  return 0;
}