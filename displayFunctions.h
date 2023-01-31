#pragma once

void displaySnakes(snake *& sArr, int NoP) {
	for (int playerCount = 0; playerCount < NoP; playerCount++) {
		if (sArr[playerCount].alive) {
			for (int snakeSize = 0; snakeSize < sArr[playerCount].size; snakeSize++) {
				gotoRC(sArr[playerCount].body[snakeSize].ri, sArr[playerCount].body[snakeSize].ci);
				cout << sArr[playerCount].sym;
			}
		}
	}
}

void displayScore(snake*& sArr, int NoP) {
	gotoRC(height + (height / 10), 0);
	for (int playerCount = 0; playerCount < NoP; playerCount++) {
		cout << sArr[playerCount].pName << "'s score: " << sArr[playerCount].score << "\n";
	}
}

void loadBoard(ifstream& reader, char**& board) {
	for (int r = 0; r < height; r++) {
		for (int c = 0; c < width; c++) {
			reader >> board[r][c];
		}
	}
}

void printBoard(char** board) {
	system("CLS");
	for (int i = 0; i < height; i++) {
		for (int c = 0; c < width; c++) {
			if (board[i][c] == 'x') {
				cout << char(-37);
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

void eraseSnakes(snake*& sArr, int NoP) {
	for (int playerCount = 0; playerCount < NoP; playerCount++) {
		for (int snakeSize = 0; snakeSize < sArr[playerCount].size; snakeSize++) {
			gotoRC(sArr[playerCount].body[snakeSize].ri, sArr[playerCount].body[snakeSize].ci);
			cout << " ";
		}
	}
}

void printFood(food PF) {
	gotoRC(PF.foodPosition.ri, PF.foodPosition.ci);
	cout << PF.sym;
}

void cinematicStart() {
	gotoRC(height/2 - 2, width / 2 - 10);
	cout << "   S"; Sleep(400);
	cout << "   N"; Sleep(400);
	cout << "   A"; Sleep(400);
	cout << "   K"; Sleep(400);
	cout << "   E"; Sleep(400);
	cout << "\n\t\  Enter any key to play!";
	char junk = _getch();
	system("cls");
}

void cinematicGameOver(int NoP) {
	gotoRC(height / 2 - 2, width / 2 - 8);
	cout << "  G"; Sleep(350);
	cout << "   A"; Sleep(350);
	cout << "   M"; Sleep(350);
	cout << "   E"; Sleep(350);
	gotoRC(height / 2 - 1, width / 2 - 8);
	cout << "  O"; Sleep(350);
	cout << "   V"; Sleep(350);
	cout << "   E"; Sleep(350);
	cout << "   R   "; Sleep(350);
	cout << "\n\t\  Enter any key to end!   ";
	gotoRC(height + (height / 10) + NoP, 0);
}