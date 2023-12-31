#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "A.h"

Game2048::Game2048()
{
    score = 0;
    grid = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
    Game2048::AddRandomTile();
    Game2048::AddRandomTile();
}
    void Game2048::PrintGrid() {
        system("cls");  // actualise l'ecran
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                std::cout << grid[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << "Score : " << score << std::endl;
    }

    void Game2048::Move(char direction) {
        bool IsAction = false;
        switch (direction) {
        case 'z': // Haut
            MoveUp(IsAction);
            break;
        case 's': // Bas
            MoveDown(IsAction);
            break;
        case 'q': // Gauche
            MoveLeft(IsAction);
            break;
        case 'd': // Droite
            MoveRight(IsAction);
            break;
        }
        if (IsAction = true) {
            AddRandomTile(); // Apr�s chaque mouvement, ajouter une case
        }
        else
        {
            std::cout << "mouvement impossible" << std::endl;
        }
    }

    // mouvements
    void Game2048::MoveUp(bool& IsAction) {
        for (int col = 0; col < 4; col++) {
            for (int row = 1; row < 4; row++) {
                if (grid[row][col] != 0) {
                    int newRow = row;
                    while (newRow > 0 && grid[newRow - 1][col] == 0) {
                        std::swap(grid[newRow][col], grid[newRow - 1][col]);
                        newRow--;
                    }
                    if (newRow > 0 && grid[newRow - 1][col] == grid[newRow][col]) {
                        grid[newRow - 1][col] *= 2;
                        grid[newRow][col] = 0;
                        IsAction = true;
                        score += grid[newRow - 1][col];
                    }
                }
            }
        }
    }

    void Game2048::MoveDown(bool& IsAction) {
        for (int col = 0; col < 4; col++) {
            for (int row = 2; row >= 0; row--) {
                if (grid[row][col] != 0) {
                    int newRow = row;
                    while (newRow < 3 && grid[newRow + 1][col] == 0) {
                        std::swap(grid[newRow][col], grid[newRow + 1][col]);
                        newRow++;
                    }
                    if (newRow < 3 && grid[newRow + 1][col] == grid[newRow][col]) {
                        grid[newRow + 1][col] *= 2;
                        grid[newRow][col] = 0;
                        IsAction = true;
                        score += grid[newRow + 1][col];
                    }
                }
            }
        }
    }

    void Game2048::MoveLeft(bool& IsAction) {
        for (int row = 0; row < 4; row++) {
            for (int col = 1; col < 4; col++) {
                if (grid[row][col] != 0) {
                    int newCol = col;
                    while (newCol > 0 && grid[row][newCol - 1] == 0) {
                        std::swap(grid[row][newCol], grid[row][newCol - 1]);
                        newCol--;
                    }
                    if (newCol > 0 && grid[row][newCol - 1] == grid[row][newCol]) {
                        grid[row][newCol - 1] *= 2;
                        grid[row][newCol] = 0;
                        IsAction = true;
                        score += grid[row][newCol - 1];
                    }
                }
            }
        }
    }

    void Game2048::MoveRight(bool& IsAction) {
        for (int row = 0; row < 4; row++) {
            for (int col = 2; col >= 0; col--) {
                if (grid[row][col] != 0) {
                    int newCol = col;
                    while (newCol < 3 && grid[row][newCol + 1] == 0) {
                        std::swap(grid[row][newCol], grid[row][newCol + 1]);
                        newCol++;
                    }
                    if (newCol < 3 && grid[row][newCol + 1] == grid[row][newCol]) {
                        grid[row][newCol + 1] *= 2;
                        grid[row][newCol] = 0;
                        IsAction = true;
                        score += grid[row][newCol + 1];
                    }
                }
            }
        }
    }

    int Game2048::IsGameOver() {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                if (grid[row][col] == 0) {
                    return 2; // Le jeu n'est pas termin� car il y a une case vide.
                }
            }
        }

        // V�rification horizontale
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                if (grid[row][col] == grid[row][col + 1]) {
                    return 2; // Le jeu n'est pas termin� car il existe une fusion possible.
                }
            }
        }

        // V�rification vertical
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 4; col++) {
                if (grid[row][col] == grid[row + 1][col]) {
                    return 2; // Le jeu n'est pas termin� car il existe une fusion possible.
                }
            }
        }


        // Si aucune des conditions pr�c�dentes n'est v�rifi�e, le jeu est termin�.
        return 0;
    }

    int Game2048::IsGameWin() {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                if (grid[row][col] == 2048) {
                    return 1; // Le jeu est termin� car il y a un 2048.
                }
            }
        }
    }


    void Game2048::AddRandomTile() {
        // Recherchez toutes les positions vides dans la grille
        std::vector<std::pair<int, int>> emptyCells;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] == 0) {
                    emptyCells.push_back(std::make_pair(i, j));
                }
            }
        }

        // Si aucune case vide n'est trouv�e, ne fais rien
        if (emptyCells.empty()) {
            return;
        }

        // Choisissez une position vide al�atoire
        srand(static_cast<unsigned int>(time(nullptr)));
        int randomIndex = rand() % emptyCells.size();
        int value;
        int valeur = (rand() % 100 + 1);
        if (valeur < 80)  // G�n�re 2 (80%) ou 4 (20%)
        {
            value = 2;

        }
        else
        {
            value = 4;
        }

        int row = emptyCells[randomIndex].first;
        int col = emptyCells[randomIndex].second;
        grid[row][col] = value;
    }
