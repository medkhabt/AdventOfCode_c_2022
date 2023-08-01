#include <stdlib.h>
//todo: remove this
#include <stdio.h>
#include "round.h"


round make_round(shape_points my_turn, shape_points enemy_turn) {
  round round; 
  round.my_turn = my_turn; 
  round.enemy_turn = enemy_turn; 
  return round; 
} 

int result_round(round* p_round){ 
  outcome_points outcome; 
  if(p_round == NULL) {
    exit(1); 
  }
  if(p_round->my_turn == p_round->enemy_turn) { 
    outcome = DRAW; 
  }
  else if((p_round->my_turn - p_round->enemy_turn) % 2) { 
    outcome = (((int)p_round->my_turn - (int)p_round->enemy_turn) > 0) ? WON : LOST; 
  }
  else {
    outcome = ((int)p_round->my_turn - (int)p_round->enemy_turn)> 0 ? LOST : WON;
  } 
  return p_round->my_turn * outcome; 
}