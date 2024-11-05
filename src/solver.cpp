#include "solver.h"

Solver::Solver() { this->guesser = new Guesser(); }

Solver::~Solver() { delete guesser; }

int Solver::score() { return this->guesser->getGuessCount(); }
