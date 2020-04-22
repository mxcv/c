//Дано рядок. Розділити всі символи
//вказаного рядка пробілами.

#include <stdio.h>
#include <conio.h>
#define SIZE 256

int main()
{
	char s[SIZE], s2[SIZE * 2];
	printf("Input a string: ");
	gets_s(s, SIZE);

	int i, i2;
	for (i = i2 = 0; s[i] != '\0'; i++)
	{
		s2[i2++] = s[i];
		s2[i2++] = ' ';
	}
	s2[i2 ? i2 - 1 : i2] = '\0';

	printf("\nThis string with separeted symblos: %s", s2);
	_getch();
	return 0;
}