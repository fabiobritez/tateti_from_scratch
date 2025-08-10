#include <stdio.h>

// enum for cells
typedef enum {
  EMPTY = 0,
  X = 1,
  O = 2
} Cell;

// enum for states
typedef enum {
  IN_PROGRESS,
  X_WON,
  O_WON,
  DRAW
} State;


// struct for each game
typedef struct{
  Cell board[3][3];
  Cell current_player; //X or O
  State state;
  short moves_counter; // number of moves
} Game;

void init(Game* game)
{
  // TODO: set all cells to EMPTY, current to X, state to IN_PROGRESS, n_moves to 0
}

void print_board(const Game *game)
{
  // TODO: print board on screen, with the current state of the game. 
}


short place(Game *game, short row, short column)
{
  // TODO: try to place current player mark at (row, column)
  // return 1 if success, 0 if its a illegal movement
  // increase moves counter if sucess
  // change current player if sucess
}

// we need a function to evaluate if three cells are all same mark (no-empty)
short is_triplet(Cell a, Cell b, Cell c){
  // TODO: return 1, if three cells are a (non-empty triplet)
}

// we need other function that evaluate all posibilites, use the previuos function
State evaluate_and_get_state(const Game *game)
{
  // TODO: evaluate all posibilities of triplets.
  // if there are no triplets and moves_counter is MAX, return draw.
  // if not, IN_PROGRESS, X_WON or O_WON
}



int main()
{
  // TODO: loop of the game
  return 0;
}
