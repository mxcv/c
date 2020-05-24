#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "menu.h"
#define ARROW_PRESSED 224
#define UP 72
#define DOWN 80
#define ENTER 13
#define ESCAPE 27

void gotoxy(int x, int y)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hStdOut, cursorPos);
}
void showCurs(bool visible)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ccInfo;
	ccInfo.bVisible = visible;
	ccInfo.dwSize = 20;
	SetConsoleCursorInfo(hStdOut, &ccInfo);
}
int choose(int options, int x, int y, int space)
{
	const char *arrow = "<-", *del_arrow = "  ";
	int curs = y, last_line = y + ((options - 1) * (space + 1)),
		key = 1, button;

	showCurs(false);
	gotoxy(x, curs);
	printf(arrow);

	while (true)
		if (_kbhit() && ((button = _getch()) == ARROW_PRESSED || button == ENTER || button == ESCAPE))
		{
			gotoxy(x, curs);
			printf(del_arrow);
			if (button == ARROW_PRESSED)
			{
				button = _getch();
				if (button == UP)
				{
					if (curs > y)
					{
						--key;
						curs -= space + 1;
					}
					else
					{
						key = options;
						curs = last_line;
					}
				}
				else if (button == DOWN)
				{
					if (curs < last_line)
					{
						++key;
						curs += space + 1;
					}
					else
					{
						key = 1;
						curs = y;
					}
				}
				gotoxy(x, curs);
				printf(arrow);
			}
			else
			{
				gotoxy(0, 0);
				showCurs(true);
				system("cls");
				return (button == ENTER ? key : USER_PRESSED_ESC);
			}
		}
}