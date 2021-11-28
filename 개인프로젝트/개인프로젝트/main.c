#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

int note[][4] = {
{0, 0, 0, 0},
{1, 0, 1, 0},
{0, 1, 0, 1},
{1, 0, 1, 0},
{1, 1, 1, 1},
{0, 1, 1, 0},
{1, 1, 0, 1},
{0, 0, 0, 0},
{1, 0, 1, 0},
{1, 1, 1, 1},
{0, 1, 1, 0},
{1, 0, 0, 1},
{0, 1, 0, 1},
{1, 0, 1, 0},
{1, 0, 0, 1},
{0, 1, 1, 0},
{1, 0, 0, 1},
{1, 0, 0, 1},
{1, 0, 1, 0},
{1, 1, 1, 1},
{0, 1, 1, 0},
{1, 0, 0, 1},
{0, 1, 0, 1},
{1, 0, 1, 0},
{1, 1, 1, 1},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0}
};

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void insu(int j) {
	for (int i = 0; i < 4; i++) {
		if (note[j][i] == 1) {
			printf(" ==== ");
		}
		else {
			printf("      ");
		}
	}
}

int main() {
	int s = 0;
	clock_t timer = clock();

	while (s < sizeof(note) / sizeof(note[0])) {

		if (clock() - timer >= 1000) {
			system("cls");
			if (s - 10 > 0) {
				for (int j = s; j > s - 10; j--) {
					insu(j);
					printf("\n");
					printf("\n");
					/*gotoxy(0, 0);*/

				}
			}
			else {
				for (int j = s; j > 0; j--) {
					insu(j);
					printf("\n");
					printf("\n");
					/*gotoxy(0, 0);*/

				}
			}

			s++;
			timer = clock();
		}

		if (_kbhit()) {
			int c = _getch();
			/*printf("ÀÔ·Â °ª : %c\n", c);*/
			if (s > 10) {
				if (note[s][0] == 1) {
					if (c == 'a') {
						gotoxy(1, 20);
						printf("GOOD");
					}
				}

				if (note[s][1] == 1) {
					if (c == 's') {
						gotoxy(7, 20);
						printf("GOOD");
					}
				}

				if (note[s][2] == 1) {
					if (c == ';') {
						gotoxy(13, 20);
						printf("GOOD");
					}
				}

				if (note[s][3] == 1) {
					if (c == '\'') {
						gotoxy(19, 20);
						printf("GOOD");
					}
				}
			}
		}
	}
}