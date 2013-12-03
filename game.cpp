#include "game.h"

Game::Game() : turn(0)
{

}

void Game::Run()
{
    turn = 1;
    RandomPopulate();
    board.Print();

    char again;
    cout<<":";
    cin>>again;

    while(again=='\'')
    {
        Advance();
        board.Print();

        cout<<":";
        cin>>again;
    }
}

// Need to change so predators move first, and then prey
void Game::Advance()
{
    // Predators move
    for(int xx=0; xx<board.Width(); xx++)
    {
        for(int yy=0; yy<board.Height(); yy++)
        {
            if(board.Get(xx,yy)!=NULL && board.Get(xx,yy)->GetCode()=='X')
                board.Get(xx,yy)->Move(board, turn);
        }
    }

    // Every creature that has not already moved will move (decision if move already happened takes place in creatures move function)
    for(int xx=0; xx<board.Width(); xx++)
    {
        for(int yy=0; yy<board.Height(); yy++)
        {
            if(board.Get(xx,yy)!=NULL)
                board.Get(xx,yy)->Move(board, turn);
        }
    }

    // Predators starve or live
    for(int xx=0; xx<board.Width(); xx++)
    {
        for(int yy=0; yy<board.Height(); yy++)
        {
            if(board.Get(xx,yy)!=NULL && board.Get(xx,yy)->GetCode()=='X')
                board.Get(xx,yy)->DieOrLive(board, turn);
        }
    }

    // Every creature reproduce (if it's time), according to their rules
    for(int xx=0; xx<board.Width(); xx++)
    {
        for(int yy=0; yy<board.Height(); yy++)
        {
            if(board.Get(xx,yy)!=NULL)
                board.Get(xx,yy)->Reproduce(board, turn);
        }
    }

    ++turn;
}

void Game::RandomPopulate()
{
    int numSpaces = board.Height() * board.Width();
    int numCreatures = numSpaces * 2 / 5;
    int numPredators = numCreatures / 5;
    int numPrey = numCreatures - numPredators;

    int randX;
    int randY;

    for(int i=0; i<numPredators; i++)
    {
        bool unplaced = true;

        while(unplaced)
        {
            randX = rand()%board.Width();
            randY = rand()%board.Height();
            if(!board.IsOccupied(randX, randY))
            {
                board.Get(randX, randY) = new Predator(randX, randY, turn);
                unplaced = false;
            }
        }
    }

    for(int i=0; i<numPrey; i++)
    {
        bool unplaced = true;

        while(unplaced)
        {
            randX = rand()%board.Width();
            randY = rand()%board.Height();
            if(!board.IsOccupied(randX, randY))
            {
                board.Get(randX, randY) = new Prey(randX, randY, turn);
                unplaced = false;
            }
        }
    }
}

int Game::GetTurn()
{
    return turn;
}

void Game::SetTurn(int newTurn)
{
    turn = newTurn;
}
