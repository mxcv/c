//Дано рядок. Розділити всі символи
//вказаного рядка пробілами.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define SIZE 256

int main()
{
	char s[SIZE], s2[SIZE * 2];
	printf("Input a string: ");
	gets_s(s, SIZE);

	*s2 = '\0';
	int i;
	for (i = 0; *(s + i) != '\0'; i++)
	{
		strncat(s2, s + i, 1);
		strcat(s2, " ");
	}
	if (*s2) *(s2 + i * 2 - 1) = '\0';

	printf("\nThis string with the separated symblos: %s", s2);
	_getch();
	return 0;
}