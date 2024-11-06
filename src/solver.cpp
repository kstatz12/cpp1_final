#include "solver.h"

Solver::Solver() { this->guesser = new Guesser(); }

Solver::~Solver() { delete guesser; }

int Solver::score() { return this->guesser->getGuessCount(); }

ReturnType Solver::guess(unsigned int x, unsigned int y, Board &board) {
    return this->guesser->guess(x, y, board);
}
