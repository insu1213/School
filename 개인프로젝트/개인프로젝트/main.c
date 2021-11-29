#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

int note[][4] = {
{0, 0, 0, 0},
{1, 0, 1, 0},
{ 0, 0, 0, 0 },
{0, 1, 0, 1},
{ 0, 0, 0, 0 },
{1, 0, 1, 0},
{ 0, 0, 0, 0 },
{1, 1, 1, 1},
{ 0, 0, 0, 0 },
{0, 1, 1, 0},
{ 0, 0, 0, 0 },
{1, 1, 0, 1},
{ 0, 0, 0, 0 },
{0, 0, 0, 0},
{ 0, 0, 0, 0 },
{1, 0, 1, 0},
{ 0, 0, 0, 0 },
{1, 1, 1, 1},
{ 0, 0, 0, 0 },
{0, 1, 1, 0},
{ 0, 0, 0, 0 },
{1, 0, 0, 1},
{ 0, 0, 0, 0 },
{0, 1, 0, 1},
{ 0, 0, 0, 0 },
{1, 0, 1, 0},
{ 0, 0, 0, 0 },
{1, 0, 0, 1},
{ 0, 0, 0, 0 },
{0, 1, 1, 0},
{ 0, 0, 0, 0 },
{1, 0, 0, 1},
{ 0, 0, 0, 0 },
{1, 0, 0, 1},
{ 0, 0, 0, 0 },
{1, 0, 1, 0},
{ 0, 0, 0, 0 },
{1, 1, 1, 1},
{ 0, 0, 0, 0 },
{0, 1, 1, 0},
{ 0, 0, 0, 0 },
{1, 0, 0, 1},
{ 0, 0, 0, 0 },
{0, 1, 0, 1},
{ 0, 0, 0, 0 },
{1, 0, 1, 0},
{ 0, 0, 0, 0 },
{1, 1, 1, 1},
{ 0, 0, 0, 0 },
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 }
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

void basic() {
	gotoxy(1, 18);
	printf("----------------------\n");
	gotoxy(0, 0);
	printf("----------------------\n");
	printf(0, 1);
}

int main() {
	int s = 0;
	clock_t timer = clock();
	basic();

	while (s < sizeof(note) / sizeof(note[0])) {

		if (_kbhit()) {
			int c = _getch();
			/*printf("�Է� �� : %c\n", c);*/
			int tmp = s - 10;
			if (tmp > 0) {
				if (note[tmp][0] == 1) {
					if (c == 'a') {
						gotoxy(1, 20);
						printf("GOOD");
					}
				}

				if (note[tmp][1] == 1) {
					if (c == 's') {
						gotoxy(7, 20);
						printf("GOOD");
					}
				}

				if (note[tmp][2] == 1) {
					if (c == ';') {
						gotoxy(13, 20);
						printf("GOOD");
					}
				}

				if (note[tmp][3] == 1) {
					if (c == '\'') {
						gotoxy(19, 20);
						printf("GOOD");
					}
				}
			}
		}

		if (clock() - timer >= 200) {
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
			basic();
		}

		
	}
}