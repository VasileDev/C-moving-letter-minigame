#include <iostream>

using namespace std;


// Matrix representation of the map
int mapMatrix[9][18] = {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
            };

// Player atributes
int player = 2;
int playerPos[2] = {1, 6};


// This function will draw the map of the game acording to the matrix
void DrawMap() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 18; j++) {
            if (mapMatrix[i][j] == 1) {
                std::cout << "A";
            } else if (mapMatrix[i][j] == 0) {
                std::cout << " ";
            } else if (mapMatrix[i][j]) { 
                std::cout << "X";
            } else {
                std::cout << "?";
            }
        }
        std::cout << "\n";
    }
}


// Captures a move from player
char CaptureMove() {
    return getchar();   
}


// Moves character left
void MoveLeft() {
    // Checking if there's an obstracle on the left of the character 
    if (mapMatrix[playerPos[0]][playerPos[1] - 1] == 1) {    
        
    } else {
        // Aux variable
        int swap = mapMatrix[playerPos[0]][playerPos[1] - 1];

        // Swapping the elem of the matrix where the player is located with its left neighbor
        mapMatrix[playerPos[0]][playerPos[1] - 1] = mapMatrix[playerPos[0]][playerPos[1]];

        // Updating player's position
        mapMatrix[playerPos[0]][playerPos[1]] = swap;
        playerPos[0] = playerPos[0];
        playerPos[1] = playerPos[1] - 1;
    }
}


// Moves character right
void MoveRight() { 
    // Checking if there's an obstracle in right of the character
    if (mapMatrix[playerPos[0]][playerPos[1] + 1] == 1) {

    } else {
        // Aux variable
        int swap = mapMatrix[playerPos[0]][playerPos[1] + 1];

        // Swapping the elem of the matrix where the player is located with its left neighbor
        mapMatrix[playerPos[0]][playerPos[1] + 1] = mapMatrix[playerPos[0]][playerPos[1]];

        // Updating player's position
        mapMatrix[playerPos[0]][playerPos[1]] = swap;
        playerPos[0] = playerPos[0];
        playerPos[1] = playerPos[1] + 1;
    }
}


// Moves character down
void MoveDown() { 
    // Checking if there's an obstracle under the character
    if (mapMatrix[playerPos[0] + 1][playerPos[1]] == 1) {

    } else {
        // Aux variable
        int swap = mapMatrix[playerPos[0] + 1][playerPos[1]];

        // Swapping the elem of the matrix where the player is located with its under neighbor
        mapMatrix[playerPos[0] + 1][playerPos[1]] = mapMatrix[playerPos[0]][playerPos[1]];

        // Updating player's position
        mapMatrix[playerPos[0]][playerPos[1]] = swap;
        playerPos[0] = playerPos[0] + 1;
        playerPos[1] = playerPos[1];
    }
}


// Moves character up
void MoveUp() { 
    // Checking if there's an obstracle above the character
    if (mapMatrix[playerPos[0] - 1][playerPos[1]] == 1) {

    } else {
        // Aux variable
        int swap = mapMatrix[playerPos[0] - 1][playerPos[1]];

        // Swapping the elem of the matrix where the player is located with its above neighbor
        mapMatrix[playerPos[0] - 1][playerPos[1]] = mapMatrix[playerPos[0]][playerPos[1]];

        // Updating player's position
        mapMatrix[playerPos[0]][playerPos[1]] = swap;
        playerPos[0] = playerPos[0] - 1;
        playerPos[1] = playerPos[1];
    }
}

int main() {
    // Setting the position of the player 
    mapMatrix[playerPos[0]][playerPos[1]] = player;
    DrawMap();
    bool run = true;
    while (run) {
        char move = CaptureMove();

        switch (move) {
            case 'a': 
                MoveLeft();
                DrawMap();
                break;
            case 'd': 
                MoveRight();
                DrawMap();
                break;
            case 'w': 
                MoveUp();
                DrawMap();
                break;
            case 's': 
                MoveDown();
                DrawMap();
                break;
            default:
                break;
        }
    }
    return 0;
}