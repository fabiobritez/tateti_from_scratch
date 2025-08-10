#include <stdio.h>




#define MAX_MOVEMENTS 9
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


/* 
 * set all cells to EMPTY, current player to X, state to IN_PROGRESS and moves counter to '0'
 * */
void init(Game* game)
{
  for(int i = 0; i<3; i++)
    for (int j = 0; j<3; j++)
      game->board[i][j] = EMPTY;

  game->current_player = X;
  game->state = IN_PROGRESS;
  game->moves_counter = 0;
}


/*
 * print the board on standar output, with the status of the game parameter*/
void print_board(const Game *game)
{
  printf("\n %4d %4d %4d \n",0,1,2);
  printf("----------------");

  for(short i = 0; i<3; i++)
  {
    printf("%d |",i);
    for(short j = 0; j<3; j++)
    {
      char cell_value = ' ';
      if(game->board[i][j]==X) cell_value = 'X';
      else if (game->board[i][j]==O) cell_value = 'O';

      printf("%4c |",cell_value);
    }
    printf("\n");
  }
   printf("----------------\n");
}


/*
 * checks if row and column is valid (between 0 and 2).
 * checks if cell is empty 
 * return 0 if is an invalid movement, 1 if sucess
 * increase moves counter, place mark and switch player
 * */
short place(Game *game, short row, short column)
{
  if(row>=0 && column>=0 && row<3 && column<3) // if out of bounds
  {
    if(game->board[row][column] == EMPTY) // if cell is already taken
    {
      game->board[row][column] = game->current_player;
      game->moves_counter+=1;
      game->current_player = game->current_player == X ? O : X; // change de current player  
      return 1;
    }
  }

  return 0;
}

/*
* evaluate if three cells are all same mark (no-empty),
* return 1 if is a triplet winning
*/
short is_triplet(Cell a, Cell b, Cell c){
  if (a != EMPTY){
    if (a == b == c) return 1;
  }
  return 0;
}

// function that evaluate all posibilites, use the previuos function

/* its a combinatory problem. first we check al columns, then all rows and finally two diagonals.
 * if there is no triplet and moves_counter is MAX, return DRAW
 * */

State evaluate_and_get_state(const Game *game)
{
  // check all columns1
  for (short column = 0; column<3; column++)
  {
    if (is_triplet(game->board[0][column], game->board[1][column], game->board[2][column])){
      return (game->board[0][column] == X ? X_WON : O_WON);
    }
  }

  // check all rows
  for (short row = 0; row < 3; row++)
  {
    if(is_triplet(game->board[row][0], game->board[row][1], game->board[row][2])){
      return (game->board[row][0] == X_WON ? X_WON : 0);
    }
  }
  
  // check diagonals
  if(is_triplet(game->board[0][0], game->board[1][1], game->board[2][2] )) {
    return (game->board[0][0] == X ? X_WON : O_WON);
  }
  if(is_triplet(game->board[0][2], game->board[1][1], game->board[2][0]))
    return (game->board[0][2] == X ? X_WON : O_WON);
  
  // case draw
  if(game->moves_counter == MAX_MOVEMENTS)
  {
    return DRAW;
  }
  return IN_PROGRESS;
}



int main()
{
  // TODO: loop of the game
  return 0;
}
