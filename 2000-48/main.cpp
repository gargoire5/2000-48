#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>

class Game2048 {
public:
    Game2048() : score(0) {
        grid = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
        AddRandomTile();
        AddRandomTile();
    }

    void PrintGrid() {
        system("cls");  // actualise l'ecran
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                std::cout << grid[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << "Score : " << score << std::endl;
    }

    void Move(char direction) {
        switch (direction) {
        case 'z': // Haut
            MoveUp();
            break;
        case 's': // Bas
            MoveDown();
            break;
        case 'q': // Gauche
            MoveLeft();
            break;
        case 'd': // Droite
            MoveRight();
            break;
        }
        AddRandomTile(); // Après chaque mouvement, moov
    }

    // mouvements
    void MoveUp() {
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
                        score += grid[newRow - 1][col];
                    }
                }
            }
        }
    }

    void MoveDown() {
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
                        score += grid[newRow + 1][col];
                    }
                }
            }
        }
    }

    void MoveLeft() {
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
                        score += grid[row][newCol - 1];
                    }
                }
            }
        }
    }

    void MoveRight() {
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
                        score += grid[row][newCol + 1];
                    }
                }
            }
        }
    }

    bool IsGameOver() {
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                if (grid[row][col] == 0) {
                    return false; // Le jeu n'est pas terminé car il y a une case vide.
                }
            }
        }

        // Vérification horizontale
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 3; col++) {
                if (grid[row][col] == grid[row][col + 1]) {
                    return false; // Le jeu n'est pas terminé car il existe une fusion possible.
                }
            }
        }

        // Vérifiecation vertical
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 4; col++) {
                if (grid[row][col] == grid[row + 1][col]) {
                    return false; // Le jeu n'est pas terminé car il existe une fusion possible.
                }
            }
        }

        // Si aucune des conditions précédentes n'est vérifiée, le jeu est terminé.
        return true;
    }

private:
    std::vector<std::vector<int>> grid;
    int score;

    void AddRandomTile() {
        // Recherchez toutes les positions vides dans la grille
        std::vector<std::pair<int, int>> emptyCells;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] == 0) {
                    emptyCells.push_back(std::make_pair(i, j));
                }
            }
        }

        // Si aucune case vide n'est trouvée, ne faites rien
        if (emptyCells.empty()) {
            return;
        }

        // Choisissez une position vide aléatoire
        srand(static_cast<unsigned int>(time(nullptr)));
        int randomIndex = rand() % emptyCells.size();
        int value = (rand() % 2 + 1) * 2;  // Génère 2 (90%) ou 4 (10%)

        int row = emptyCells[randomIndex].first;
        int col = emptyCells[randomIndex].second;
        grid[row][col] = value;
    }
};

int main() {
    Game2048 game;

    while (true) {
        game.PrintGrid();
        char move;
        std::cout << "Entrez une direction (z, q, s, d) ou 'a' pour quitter : ";
        std::cin >> move;


        if (move != 'z' && move != 'd' && move != 's' && move != 'q' && move != 'a')
        {
            std::cout << "erreur , mauvaise touche" << std::endl;
            std::cout << "oui";
        }
        else
        {
            if (move == 'a')
            {
                // L'utilisateur peut appuyer sur 'q' pour quitter le jeu
                break;
            }
            game.Move(move);
        }
        
          

        if (game.IsGameOver()) {
            std::cout << "Game Over!" << std::endl;
            break;
        }
    }

    return 0;

}