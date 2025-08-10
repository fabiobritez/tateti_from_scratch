# tateti_from_zero
this is an implementation of ta-te-ti (tic-tac-toe) inc, made from scratch just for fun

## game rules (ta-te-ti)

* we have a board with a 3x3 grid.
* there are two players, one uses `X` and the other uses `O`
* on each turn, a player choose an empty cell and place his mark.
* the first player to get three in a row (horizontally, vertically or diagonally) wins.
* if all 9 cells are filled and nobody has a line of three points, the game is a draw.
* palyers cannot overwrite an occupied cell.
* the game ends when someone wins or when the board is full.

## modeling the game in c

### board
3x3 array of cells. each cell is `EMPTY`, `X` or `O`.

```c
typedef enum {EMPTY=0, X=1, O=2} Cell;
```

### players
current player is either `X` or `O`.

### game status
can be IN_PROGRESS, X_WON, Y_WON or DRAW.
```c
typedef enum {IN_PROGRESS, X_WON, O_WON, DRAW} State;
```

### game
all info of the game it's contained on a struct:

```c
typedef struct {
    Cell board [3][3]; // bi-dimensional array of 3x3 cells
    Cell current;      // X or O
    State state;
} Game;

```

### movements 
place a X or O in a pair (row, column) that can be 0, 1 or 3.
```c
short move(Game* game, short row, short column); // return 0 if success, 1 if its a illegal movement
```
after of each movement, the state is evaluated and updated.

### game loop

```c
init a game

while (state == IN_PROGRESS)
    update_board();
    
    do
    ask current player for a next movement (row, column)
    while (movement = invalid)
    
    place mark
    evaluate and update state
    
update_board();

print results (based on current state)
```


## how to run

compile
```sh
gcc -o tateti main.c
```

run
```sh
./tateti
```


## notes
* input format: row, column or row column (int)
* invalid inputs are handled by asking again
* next improvements
    - input by a single number (1-9) mapped to coordinates
    - single-player mode with "ai"
    - better board display
