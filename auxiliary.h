#pragma once

using namespace std;

#define height 20
#define width 40

enum direction {_up, _down, _left, _right};

struct coordinate {
	int ri;
	int ci;
};

struct snake {
	coordinate* body {};
	string pName{};
	int size{};
	int score{};
	char sym{};
	direction _direction{};

	int leftK, rightK, upK, downK;
	bool alive{};
};

struct food {
	coordinate foodPosition;
	bool spawned;
	char sym;
};

void nl(int i) {
    for (int j = 0; j < i; j++) {
        cout << "\n";
    }
}

void gotoRC(int rpos, int cpos) {
	COORD scrn{ 0, 0 };
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos; scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}