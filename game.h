#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include "board.h"

class Game
{
public:
    Game();
    void Run();
    void Advance();
    void RandomPopulate();
private:
    Board board;
};

#endif // GAME_H
