#include <iostream>
#include <stdexcept>

#include "solver.h"

class ExampleSolver : public Solver {
   public:
    void solve(Board &board) override;
};

// Sample Implemeneation
void ExampleSolver::solve(Board &board) {
    for (int i = 0; i < board.getX(); i++) {
        for (int j = 0; j < board.getY(); j++) {
            guess(i, j, board);
        }
    }
}

class UserSolver : public Solver {
   public:
    void solve(Board &board) override;
};

void UserSolver::solve(Board &board) {
    // Your Implementation goes here
    ReturnType t = guess(1, 1, board);
    std::cout << t << std::endl;
}

int main() {
    Board b = Board(1000, 1000, 5);

    ExampleSolver es;
    es.solve(b);

    UserSolver us;
    us.solve(b);

    if (es.score() > us.score()) {
        throw std::runtime_error("Not Efficient Enough");
    }
}
