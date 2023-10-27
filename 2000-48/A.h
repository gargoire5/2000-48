
#include <vector>

class Game2048 {
public:
    
    Game2048();

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