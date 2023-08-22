#include <stdio.h>
#include "../round.h" 

int main() { 
  round round_draw_test = make_round(Y, A);
  round round_lost_test = make_round(X, B);
  round round_won_test = make_round(Z, C);

  printf("%d, %d, %d", result_round(&round_draw_test),result_round(&round_lost_test), result_round(&round_won_test)); 
  return 0; 
}







//  [ ROCK , PAPER, SCISSORS] .    1 1 -> 3, 1 2 -> 0 , 1 3 -> 6 , 2 1 -> 6, 2 2 -> 3, 2 3 -> 0 , 3 -> 1 0, 3 -> 2 6, 3 3 ->3.  