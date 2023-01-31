#pragma once

void changeDirection(snake*& sArr, int NoP, char c) {
	for (int playerCount = 0; playerCount < NoP; playerCount++) {
		if (c == sArr[playerCount].upK) {
			if (sArr[playerCount]._direction != _down) {
				sArr[playerCount]._direction = _up;
			}
		}
		else if (c == sArr[playerCount].downK){
			if(sArr[playerCount]._direction != _up){
				sArr[playerCount]._direction = _down;
			}
		}
		else if (c == sArr[playerCount].leftK){
			if (sArr[playerCount]._direction != _right) {
				sArr[playerCount]._direction = _left;
			}
		}
		else if (c == sArr[playerCount].rightK){
			if (sArr[playerCount]._direction != _left) {
				sArr[playerCount]._direction = _right;
			}
		}
	}
}

void moveSnakes(snake*& sArr, int NoP) {
	for (int playerCount = 0; playerCount < NoP; playerCount++) {
		if (sArr[playerCount].alive) {
			for (int snakeSize = sArr[playerCount].size; snakeSize > 0; snakeSize--) {
				sArr[playerCount].body[snakeSize] = sArr[playerCount].body[snakeSize - 1];
			}
			switch (sArr[playerCount]._direction) {
			case _up:
				sArr[playerCount].body[0].ri--;
				if (sArr[playerCount].body[0].ri == -1) {
					sArr[playerCount].body[0].ri = height - 1;
				}
				break;
			case _down:
				sArr[playerCount].body[0].ri++;
				if (sArr[playerCount].body[0].ri == height) {
					sArr[playerCount].body[0].ri = 0;
				}
				break;
			case _left:
				sArr[playerCount].body[0].ci--;
				if (sArr[playerCount].body[0].ci == -1) {
					sArr[playerCount].body[0].ci = width - 1;
				}
				break;
			case _right:
				sArr[playerCount].body[0].ci++;
				if (sArr[playerCount].body[0].ci == width) {
					sArr[playerCount].body[0].ci = 0;
				}
				break;
			}
		}
	}
}

void snakeHittingItself(snake*& sArr, int NoP) {
	for (int playerCount = 0; playerCount < NoP; playerCount++) {
		for (int snakeSize = sArr[playerCount].size; snakeSize > 0; snakeSize--) {
			if (sArr[playerCount].body[0].ri == sArr[playerCount].body[snakeSize].ri and
				sArr[playerCount].body[0].ci == sArr[playerCount].body[snakeSize].ci) {
				sArr[playerCount].alive = false;
			}
		}
	}
}

void snakeHittingWall(snake*& sArr, int NoP, char** board) {
	for (int playerCount = 0; playerCount < NoP; playerCount++) {
		int snekR = sArr[playerCount].body[0].ri;
		int snekC = sArr[playerCount].body[0].ci;
		if (board[snekR][snekC] == 'x') {
			sArr[playerCount].alive = false;
			gotoRC(snekR, snekC);
			cout << char(-37);
		}
	}
}

void snakeDeathCheck(snake*& sArr, int NoP, char** board) {
	snakeHittingItself(sArr, NoP);
	snakeHittingWall(sArr, NoP, board);
}

bool allSnakesDead(snake*& sArr, int NoP) {
	for (int playerCount = 0; playerCount < NoP; playerCount++) {
		if (sArr[playerCount].alive) {
			return false;
		}
	}
	return true;
}

void growSnake(snake& snek) {
	snek.score++;
	coordinate* newSnekBody = new coordinate[snek.size + 1];
	for (int i = 0; i < snek.size; i++) {
		newSnekBody[i] = snek.body[i];
	}
	newSnekBody[snek.size] = snek.body[snek.size - 1];
	snek.size++;
	//delete[] snek.body;

	snek.body = newSnekBody;
}

