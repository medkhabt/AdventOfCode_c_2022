typedef enum { WON = 6, DRAW = 3, LOST = 0 , X = LOST, Y = DRAW, Z = WON} outcome_points ; 
typedef enum {A = 1, B = 2, C = 3} shape_points;  
typedef struct round {
  shape_points my_turn;
  shape_points enemy_turn;
  outcome_points expectedOutcome; 
} round;

round make_round(shape_points my_turn, shape_points enemy_turn); 
round make_round_from_expected_outcome(outcome_points outcome, shape_points enemy_turn);
int result_round(round* p_round);
shape_points convertCharToShapePoints(char c);  
outcome_points convertCharToOutcomePoints(char c);