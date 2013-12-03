#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include "board.h"
#include "predator.h"
#include "prey.h"
#include <iostream>
using namespace std;

class Game
{
public:
    Game();
    void Run();
    void Advance();
    void RandomPopulate();
    int GetTurn();
    void SetTurn(int newTurn);
private:
    Board board;
    int turn;
};

#endif // GAME_H
