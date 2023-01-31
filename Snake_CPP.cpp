// Snake_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <string>
#include <math.h>
#include <time.h>
#include "auxiliary.h"
#include "snakeFunctions.h"
#include "displayFunctions.h"
#include "foodFunctions.h"

void initMovementKeysAndSymbols(snake*& sArr, int NoP) {
    switch (NoP) {
    case 4:
        sArr[3].upK = '8';
        sArr[3].leftK = '4';
        sArr[3].downK = '5';
        sArr[3].rightK = '6';
        sArr[3].sym = 35;
    case 3:
        sArr[2].upK = 'I';
        sArr[2].leftK = 'J';
        sArr[2].downK = 'K';
        sArr[2].rightK = 'L';
        sArr[2].sym = 64;
    case 2:
        sArr[1].upK = 72;
        sArr[1].leftK = 75;
        sArr[1].downK = 80;
        sArr[1].rightK = 77;
        sArr[1].sym = 36;
    case 1:
        sArr[0].upK = 'W';
        sArr[0].leftK = 'A';
        sArr[0].downK = 'S';
        sArr[0].rightK = 'D';
        sArr[0].sym = 43; 
    }
}
void initSnakes(int NoP, snake*& mainSnakes) {
    for (int i = 0; i < NoP; i++) {
        mainSnakes[i].body = new coordinate[3];

        mainSnakes[i].body[0].ri = height / 7;
        mainSnakes[i].body[0].ci = 8 * (i + 1);

        mainSnakes[i].body[1].ri = (height / 7) - 1;
        mainSnakes[i].body[1].ci = 8 * (i + 1);

        mainSnakes[i].body[2].ri = (height / 7) - 2;
        mainSnakes[i].body[2].ci = 8 * (i + 1);
        
        mainSnakes[i].size = 3;
        mainSnakes[i].score = 0;
        mainSnakes[i].alive = true;
        mainSnakes[i]._direction = _down;
        mainSnakes[i].pName = "Player " + to_string(i + 1);
    }
    initMovementKeysAndSymbols(mainSnakes, NoP);
}
void initFood(food& eatable) {
    eatable.spawned = false;
    eatable.sym = '0';
}

int main() 
{
    srand(time(NULL));
    ifstream level1Reader("level1.txt");
    ifstream level2Reader("level2.txt");
    char** board = new char* [height];
    for (int i = 0; i < height; i++) {board[i] = new char[width];}
    
    cinematicStart();
    int NoP = 2, levelIn = 2;
    cout << "Enter the number of players (1 - 4): ";
    cin >> NoP;
    snake* mainSnakes = new snake[NoP];
    food primaryFood;

    cout << "Enter the level (1/2): ";
    cin >> levelIn;
    switch (levelIn) {
    case 1:
        loadBoard(level1Reader, board);
        break;
    case 2:
        loadBoard(level2Reader, board);
        break;
    }
    
    initSnakes(NoP, mainSnakes);
    initFood(primaryFood);
    printBoard(board);
    
    while (!allSnakesDead(mainSnakes, NoP)) {
        spawnCheck(board, mainSnakes, NoP, primaryFood);
        if (_kbhit()) {
            char ch = _getch();
            if (ch == -32) {
                ch = _getch();
                changeDirection(mainSnakes, NoP, ch);
            }
            else {
                changeDirection(mainSnakes, NoP, toupper(ch));
            }
        }
        eraseSnakes(mainSnakes, NoP);
        moveSnakes(mainSnakes, NoP);
        foodConsumedCheck(mainSnakes, NoP, primaryFood);
        displaySnakes(mainSnakes, NoP);
        displayScore(mainSnakes, NoP);
        snakeDeathCheck(mainSnakes, NoP, board);
        Sleep(150);
    }
    cinematicGameOver(NoP);
    
    for (int i = 0; i < height; i++) {
        delete[] board[i];
    }
    delete[] board;
    delete[] mainSnakes;
    
    return _getch();
}