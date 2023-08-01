typedef enum { WON = 6, DRAW = 3, LOST = 0 } outcome_points ; 
typedef enum {A = 1, B = 2, C = 3, X = A, Y = B, Z = C} shape_points;  
typedef struct round {
  shape_points my_turn;
  shape_points enemy_turn;
} round;

round make_round(shape_points my_turn, shape_points enemy_turn); 
int result_round(round* p_round); 