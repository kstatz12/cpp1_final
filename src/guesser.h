#ifndef GUESSER_H_
#define GUESSER_H_

#include "board.h"
#include "types.h"

enum ReturnType { bad_guess, hit, miss, near_miss };

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

#endif  // GUESSER_H_
