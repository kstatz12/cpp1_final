#include <algorithm>
#include <exception>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

// Custom Types
typedef unsigned const int uint32;
typedef unsigned int mut_uint32;

struct Point {
  mut_uint32 x;
  mut_uint32 y;
};

class Board {
private:
  std::vector<std::vector<mut_uint32> *> *grid;
  void random_fill(uint32 ship_count);
  mut_uint32 ship_count;
  mut_uint32 x;
  mut_uint32 y;

public:
  Board(uint32 x, uint32 y, uint32 ship_count);
  std::vector<std::vector<mut_uint32> *> *get_grid();
  void print();
  int getShipCount();
  int getX();
  int getY();
  ~Board();
};

Board::Board(uint32 x, uint32 y, uint32 ship_count) {
  this->ship_count = ship_count;
  this->x = x;
  this->y = y;
  this->grid = new std::vector<std::vector<mut_uint32> *>(x);
  for (mut_uint32 i = 0; i < x; i++) {
    (*this->grid)[i] =
        new std::vector<mut_uint32>(y, 0); // Initialize each cell to 0 directly
  }
  this->random_fill(ship_count);
}

Board::~Board() {
  unsigned long x = this->grid->size();
  for (mut_uint32 i = 0; i < x; i++) {
    delete this->grid->at(i);
  }

  delete this->grid;
}

int Board::getShipCount() { return this->ship_count; }

int Board::getX() { return this->x; }

int Board::getY() { return this->y; }

void Board::print() {
  for (const auto rowPtr : *grid) {
    for (const int cell : *rowPtr) {
      std::cout << cell << " ";
    }
    std::cout << std::endl;
  }
}

void Board::random_fill(const mut_uint32 ship_count) {

  uint32 rows = this->grid->size();
  uint32 cols = this->grid->front()->size();

  std::vector<std::pair<mut_uint32, mut_uint32>> indices;
  indices.reserve(rows * cols);

  for (mut_uint32 i = 0; i < rows; i++) {
    for (mut_uint32 j = 0; j < cols; j++) {
      indices.emplace_back(i, j);
    }
  }

  std::random_device r;

  std::mt19937 gen(r());

  std::shuffle(indices.begin(), indices.end(), gen);

  for (mut_uint32 k = 0; k < ship_count && k < indices.size(); k++) {
    uint row = indices.at(k).first;
    uint col = indices.at(k).second;
    this->grid->at(row)->at(col) = 1;
  }
}

enum ReturnType { hit, miss, near_miss };

struct GuessContext {
  mut_uint32 guess_count;
};

class Guesser {
  GuessContext ctx;
  ReturnType check_coordinates(uint32 x, uint32 y, Board &board);

public:
  ReturnType guess(uint32 x, uint32 y, Board &board);
  int getGuessCount();
};

int Guesser::getGuessCount() { return this->ctx.guess_count; }

ReturnType Guesser::check_coordinates(uint32 x, uint32 y, Board &board) {
  const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  auto grid = board.get_grid();
  int rows = grid->size();
  int cols = grid->at(0)->size();

  if ((*grid)[x]->at(y) == 1) {
    return ReturnType::hit; // The cell itself is 1
  }

  for (const auto &dir : directions) {
    int adjX = x + dir[0];
    int adjY = y + dir[1];

    if (adjX >= 0 && adjX < rows && adjY >= 0 && adjY < cols) {
      if ((*grid)[adjX]->at(adjY) == 1) {
        return ReturnType::miss; // Found an adjacent 1
      }
    }
  }
  return ReturnType::miss;
}

ReturnType Guesser::guess(uint32 x, uint32 y, Board &board) {
  this->ctx.guess_count += 1;
  return this->check_coordinates(x, y, board);
}

class Solver {
protected:
  Guesser *g;

public:
  Solver();
  ~Solver();
  virtual void solve(Board &board) = 0;
  int score();
};

Solver::Solver() { this->g = new Guesser(); }

Solver::~Solver() { delete g; }

int Solver::score() { return this->g->getGuessCount(); }

class ExampleSolver : public Solver {

public:
  void solve(Board &board) override;
};

class UserSolver : public Solver {
public:
  void solve(Board &board) override;
};

void ExampleSolver::solve(Board &board) {
  for (int i = 0; i < board.getX(); i++) {
    for (int j = 0; j < board.getY(); i++) {
      this->g->guess(i, j, board);
    }
  }
}

void UserSolver::solve(Board &board)
{

}

int main() {
  Board b = Board(100, 100, 5);

  ExampleSolver es;
  es.solve(b);

  UserSolver us;
  us.solve(b);

  if (es.score() > us.score()) {
    throw std::runtime_error("Not Efficient Enough");
  }
}
