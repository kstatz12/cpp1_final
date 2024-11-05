#ifndef SOLVER_H_
#define SOLVER_H_

#include "board.h"
#include "guesser.h"

class Solver {
protected:
  Guesser *g;

public:
  Solver();
  ~Solver();
  virtual void solve(Board &board) = 0;
  int score();
};


#endif // SOLVER_H_
