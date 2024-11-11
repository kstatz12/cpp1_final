#ifndef BOARD_H_
#define BOARD_H_

#include <cstddef>
#include <vector>

#include "types.h"

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
    size_t getShipCount();
    size_t getX();
    size_t getY();
    ~Board();
};

#endif  // BOARD_H_
