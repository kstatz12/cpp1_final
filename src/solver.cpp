#include "solver.h"

Solver::Solver() { this->g = new Guesser(); }

Solver::~Solver() { delete g; }

int Solver::score() { return this->g->getGuessCount(); }
