#include "guesser.h"

#include <cstdint>

int Guesser::getGuessCount() { return this->ctx.guess_count; }

constexpr bool safe_less_than(int a, unsigned int b) {
    if (a < 0) {
        return true;
    }
    return static_cast<int64_t>(a) < static_cast<int64_t>(b);
}

constexpr bool safe_greater_than(int a, unsigned int b) {
    if (a < 0) {
        return false;
    }
    return static_cast<int64_t>(a) < static_cast<int64_t>(b);
}

constexpr bool safe_eq(int a, unsigned int b) {
    if (a < 0) {
        return false;
    }
    return static_cast<int64_t>(a) == static_cast<int64_t>(b);
}

ReturnType Guesser::check_coordinates(uint32 x, uint32 y, Board &board) {
    const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    auto grid = board.get_grid();
    unsigned int rows = grid->size();
    unsigned int cols = grid->at(0)->size();

  if(x >= rows || y >= cols)
  {
      return ReturnType::bad_guess;
  }

  if (grid->at(x)->at(y) == 1) {
    return ReturnType::hit; // The cell itself is 1
  }

  for (const auto &dir : directions) {
    int adjX = x + dir[0];
    int adjY = y + dir[1];

    if (safe_greater_than(adjX, 0) && safe_less_than(adjX, rows) && safe_greater_than(adjY, 0) && safe_less_than(adjY, cols)) {
      if ((*grid)[adjX]->at(adjY) == 1) {
        return ReturnType::miss; // Found an adjacent 1
      }
    }

    if (grid->at(x)->at(y) == 1) {
        return ReturnType::hit;  // The cell itself is 1
    }

    for (const auto &dir : directions) {
        int adjX = x + dir[0];
        int adjY = y + dir[1];

        if (safe_greater_than(adjX, 0) && safe_less_than(adjX, rows) &&
            safe_greater_than(adjY, 0) && safe_less_than(adjY, cols)) {
            if ((*grid)[adjX]->at(adjY) == 1) {
                return ReturnType::miss;  // Found an adjacent 1
            }
        }
    }
    return ReturnType::miss;
}

ReturnType Guesser::guess(uint32 x, uint32 y, Board &board) {
    this->ctx.guess_count += 1;
    return this->check_coordinates(x, y, board);
}
