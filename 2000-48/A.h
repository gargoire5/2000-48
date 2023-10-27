#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "A.h"

class Game2048 {
public:
    
    void PrintGrid();

    void Move(char direction);

    void MoveUp(bool& IsAction);

    void MoveDown(bool& IsAction);

    void MoveLeft(bool& IsAction);

    void MoveRight(bool& IsAction);

    int IsGameOver();

    int IsGameWin();

private:
    std::vector<std::vector<int>> grid;
    int score;

    void AddRandomTile();
};