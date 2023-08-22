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
//TODO: need to check this.
#define __NUMBER_LINES__ 2700 
size_t readFile_v1(const char* fileName, round* storage){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    size_t storage_size = 0; 

    fp = fopen(fileName, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        shape_points myTurn = convertCharToShapePoints(line[2]); 
        shape_points enemyTurn = convertCharToShapePoints(line[0]); 
        storage[storage_size++] = make_round(myTurn, enemyTurn);
    }
    fclose(fp);
    if (line)
        free(line);
    return storage_size; 
}
size_t readFile_v2(const char* fileName, round* storage){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    size_t storage_size = 0; 

    fp = fopen(fileName, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        outcome_points expectedOutcome = convertCharToOutcomePoints(line[2]); 
        shape_points enemyTurn = convertCharToShapePoints(line[0]); 
        storage[storage_size++] = make_round_from_expected_outcome(expectedOutcome, enemyTurn);
    }
    fclose(fp);
    if (line)
        free(line);
    return storage_size; 
}
int main() {
  // Reading and converting the file to an array of rounds. 
  round rounds[__NUMBER_LINES__];

  // const size_t __FILE_SIZE1__ = readFile_v1("inputs/input.txt", rounds);
  // unsigned int sum_pts1 = 0; 
  // // Summing up all the rounds. 
  // for(size_t i = 0; i < __FILE_SIZE1__; i++) {
  //   sum_pts1 += result_round(&rounds[i]);
  // }
  // printf("PART 1: \n"); 
  // printf("result: %d\n" , sum_pts1);

  const size_t __FILE_SIZE__ = readFile_v2("inputs/input.txt", rounds);
  unsigned int sum_pts2 = 0;  

 for(size_t i = 0; i < __FILE_SIZE__; i++) {
    sum_pts2 += result_round(&rounds[i]);
  } 
  printf("PART 2: \n"); 
  printf("result: %d\n" , sum_pts2);

  return 0;
}