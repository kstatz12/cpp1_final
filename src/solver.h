#ifndef SOLVER_H_
#define SOLVER_H_

#include "board.h"
#include "guesser.h"

class Solver {
   protected:
    Guesser *guesser;

    ReturnType guess(size_t x, size_t y, Board &board);

   public:
    Solver();
    ~Solver();
    virtual void solve(Board &board) = 0;
    int score();
};

#endif  // SOLVER_H_
