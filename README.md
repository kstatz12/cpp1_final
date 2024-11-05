# Final

# Requirements
For our final we will be writing a solver for battleship!

## Compiling/Runing
### Windows

### Mac/Linux


## Rules
The board is 1000x1000 with 5 ships

you must implement 

``` c++
void UserSolver::solve(Board &board)
{
  //Your Implementation goes here
  ReturnType t = guess(1, 1, board);
}
```

in the `main.cpp` file. An example implementation is above

``` c++
void ExampleSolver::solve(Board &board) {
  for (int i = 0; i < board.getX(); i++) {
    for (int j = 0; j < board.getY(); j++) {
        guess(i, j, board);
    }
  }
}
```

The `Solver` class exposes a function called `guess` that takes in 3 arguments. an `X` coordinate, a `Y` coordinate and the board to look up the coordinates. It returns a `ResultType`. There are 4 possible values for the `ResultType` enum: `Hit`, `Miss`, `Near Miss`, and `Bad Guess`. They signify
- Miss is returned when the cell at x,y is empty and no adjacent cell has a value
- Near Miss is returned when the cell at x,y is empty but an adjacent cell has a value
- Hit is returned when the cell at x,y has a value
- Bad Guess is returned when the x,y coordinates are out of range

using these return values you must devise an algorithm to find the 5 ships in fewer moves than the computer (see example)

## Rubric
| Criteria                          | Points |
|-----------------------------------|--------|
| Code Completes without Errors     | 50     |
| Code Uses Correct C++ Conventions | 30     |
| Code is legible and followable    | 10     |
| Code Compiles                     | 10     |
