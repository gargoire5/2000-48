#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "A.h"

int main() {
    Game2048 game;

    while (true) {
        game.PrintGrid();
        char move;
        bool IsAction = false;
        std::cout << "Entrez une direction (z, q, s, d) ou 'a' pour quitter : ";
        std::cin >> move;
        

        if (move != 'z' && move != 'd' && move != 's' && move != 'q' && move != 'a')
        {
            std::cout << "non" << std::endl;
        }
        else
        {            
            if (move == 'a')
            {
                // L'utilisateur peut appuyer sur 'a' pour quitter le jeu
                break;
            }
            game.Move(move);
        }          

        if (game.IsGameOver() == 0) {
            std::cout << "Game Over!" << std::endl;
            break;
        }
        if (game.IsGameWin() == 1) {
            game.PrintGrid();
            std::cout << "Win!" << std::endl;
            break;
        }
    }

    return 0;
}