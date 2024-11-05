# Final

# Requirements
For our final we will be writing a solver for battleship!

## Rules
The board is 1000x1000 with 5 ships

you must implement 

``` c++
void UserSolver::solve(Board &board)
{
  //Your Implementation goes here
  this->g->guess(1, 1, board);
}
```

in the `main.cpp` file. An example implementation is above

``` c++
void ExampleSolver::solve(Board &board) {
  for (int i = 0; i < board.getX(); i++) {
    for (int j = 0; j < board.getY(); j++) {
      this->g->guess(i, j, board);
    }
  }
}
```

