#pragma once

bool foodIsOnWall(char** board, coordinate foodPosition) {
	return (board[foodPosition.ri][foodPosition.ci] == 'x');
}

bool foodIsOnSnake(snake*& sArr, int NoP, coordinate foodPosition) {
	for (int playerCount = 0; playerCount < NoP; playerCount++) {
		for (int snakeSize = 0; snakeSize < sArr[playerCount].size; snakeSize++) {
			if (foodPosition.ri == sArr[playerCount].body[snakeSize].ri and foodPosition.ci == sArr[playerCount].body[snakeSize].ci) {
				return true;
			}
		}
	}
	return false;
}

void generateFood(char** board, snake*& sArr, int NoP, coordinate& foodPosition) {
	do {
		foodPosition.ri = rand() % height;
		foodPosition.ci = rand() % width;
	} while (foodIsOnWall(board, foodPosition) or foodIsOnSnake(sArr, NoP, foodPosition));
}

void spawnCheck(char** board, snake*& sArr, int NoP, food &primaryFood) {
	if (!primaryFood.spawned) {
		generateFood(board, sArr, NoP, primaryFood.foodPosition);
		printFood(primaryFood);
		primaryFood.spawned = true;
	}
}

void foodConsumedCheck(snake*& sArr, int NoP, food& primaryFood) {
	for (int playerCount = 0; playerCount < NoP; playerCount++) {
		if (sArr[playerCount].body[0].ri == primaryFood.foodPosition.ri and sArr[playerCount].body[0].ci == primaryFood.foodPosition.ci) {
			growSnake(sArr[playerCount]);
			primaryFood.spawned = false;
			break;
		}
	}
}