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

void basic(int point, int ck, int inputck) {
	gotoxy(0, 18);


	printf("□□□□□□□□□□□□\n");

	gotoxy(0, 0);
	printf("------------------------\n");
	gotoxy(27, 10);
	printf("%d 점", point);
	gotoxy(10, 8);
	printf("%.2f %%", (double)point / (300 * ck) * 100);
	gotoxy(0, 1);
}

int main() {
	int s = 0;
	int ck = 1;
	clock_t timer = clock();
	int point = 0;
	basic(point, ck, 0);

	while (s < sizeof(note) / sizeof(note[0])) {

		if (_kbhit()) {
			int c = _getch();
			/*printf("입력 값 : %c\n", c);*/


			int tmp = s - 10;
			if (tmp > 0) {
				if (note[tmp][0] == 1) {
					if (c == 'a') {
						ck++;
						gotoxy(1, 20);
						if (30 < clock() - timer && clock() - timer < 100) {
							printf("BEST");
							point += 300;
							
						}
						else if ((clock() - timer <= 30 && clock() - timer > 0) || (clock() - timer >= 100 && clock() - timer < 200)) {
							printf("GOOD");
							point += 100;
						
						}
						else if (clock() - timer <= 0) {
							printf("SLOW");
							point += 50;
						
						}
						else if (clock() - timer >= 200) {
							printf("FAST");
							point += 50;
							
						}
						else {
							printf("MISS");
							
						}
					}
				}

				if (note[tmp][1] == 1) {
					if (c == 's') {
						ck++;
						gotoxy(7, 20);
						if (30 < clock() - timer && clock() - timer < 100) {
							printf("BEST");
							point += 300;

						}
						else if ((clock() - timer <= 30 && clock() - timer > 0) || (clock() - timer >= 100 && clock() - timer < 200)) {
							printf("GOOD");
							point += 100;

						}
						else if (clock() - timer <= 0) {
							printf("SLOW");
							point += 50;

						}
						else if (clock() - timer >= 200) {
							printf("FAST");
							point += 50;

						}
						else {
							printf("MISS");

						}
					}
				}

				if (note[tmp][2] == 1) {
					if (c == ';') {
						ck++;
						gotoxy(13, 20);
						if (30 < clock() - timer && clock() - timer < 100) {
							printf("BEST");
							point += 300;

						}
						else if ((clock() - timer <= 30 && clock() - timer > 0) || (clock() - timer >= 100 && clock() - timer < 200)) {
							printf("GOOD");
							point += 100;

						}
						else if (clock() - timer <= 0) {
							printf("SLOW");
							point += 50;

						}
						else if (clock() - timer >= 200) {
							printf("FAST");
							point += 50;

						}
						else {
							printf("MISS");

						}
					}
				}

				if (note[tmp][3] == 1) {
					if (c == '\'') {
						ck++;
						gotoxy(19, 20);
						if (30 < clock() - timer && clock() - timer < 100) {
							printf("BEST");
							point += 300;

						}
						else if ((clock() - timer <= 30 && clock() - timer > 0) || (clock() - timer >= 100 && clock() - timer < 200)) {
							printf("GOOD");
							point += 100;

						}
						else if (clock() - timer <= 0) {
							printf("SLOW");
							point += 50;

						}
						else if (clock() - timer >= 200) {
							printf("FAST");
							point += 50;

						}
						else {
							printf("MISS");

						}
					}
				}
			}
		} 
		/*else if (note[tmp][0] == 1 || note[tmp][1] == 1 || note[tmp][2] == 1 || note[tmp][3] == 1) {

		}*/

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
			basic(point, ck, 0);
		}

		
	}
}