#include <stdlib.h>
//todo: remove this
#include <stdio.h>
#include "round.h"


round make_round(shape_points my_turn, shape_points enemy_turn) {
  round round; 
  round.my_turn = my_turn; 
  round.enemy_turn = enemy_turn; 
  round.expectedOutcome = -1;
  return round; 
} 

int result_round(round* p_round){ 
  outcome_points outcome; 
  if(p_round == NULL) {
    exit(1); 
  }
  if((int)(p_round->expectedOutcome) == -1) { 
    if(p_round->my_turn == p_round->enemy_turn) { 
        outcome = DRAW; 
      }
      else if((p_round->my_turn - p_round->enemy_turn) % 2) { 
        outcome = (((int)p_round->my_turn - (int)p_round->enemy_turn) > 0) ? WON : LOST; 
      }
      else {
        outcome = ((int)p_round->my_turn - (int)p_round->enemy_turn)> 0 ? LOST : WON;
      } 
  }
  else {
    outcome = (int)p_round->expectedOutcome; 
  }
  return p_round->my_turn + outcome; 
}
round make_round_from_expected_outcome(outcome_points outcome, shape_points enemy_turn) { 
    round round; 
    round.expectedOutcome = outcome; 
    round.enemy_turn = enemy_turn; 
    if(outcome == DRAW) { 
      round.my_turn = enemy_turn; 
    }
    else { 
      round.my_turn = (((int)outcome) ? ((int)enemy_turn + 1) : ((int)enemy_turn - 1));
      if(round.my_turn==0){
        round.my_turn = 3; 
      }
      else if(round.my_turn == 4) {
        round.my_turn = 1; 
      }
    }
    return round; 
}
shape_points convertCharToShapePoints(char c) { 
  switch (c)
  {
  case 'A': 
    return A; 
  case 'B':
    return B; 
  case 'C': 
    return C; 

  default:
    return -1;
  }
}

outcome_points convertCharToOutcomePoints(char c){
  switch (c)
    {
    case 'X': 
      return X; 
    case 'Y': 
      return Y; 
    case 'Z': 
      return Z; 
    default:
      return -1;
  } 
}