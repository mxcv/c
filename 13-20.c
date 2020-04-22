//Дано декілька рядків. Об’єднати вказані рядки та відсортувати
//в результуючому рядку символи за зростанням їх ASCII-кодів.

#include <stdio.h>
#include <string.h>
#include <conio.h>
#define SIZE 256

void sort(char*);

int main()
{
	char s[SIZE * 2], s2[SIZE];
	printf("Input the first string: ");
	gets_s(s, SIZE);
	printf("Input the second string: ");
	gets_s(s2, SIZE);

	strcat_s(s, s2);
	sort(s);

	printf("\nConcatenated sorted string: %s", s);
	_getch();
	return 0;
}

void sort(char* str) //insertion
{
	if (*str)
		for (int i = 1, t; str[i] != '\0'; i++)
			for (int j = i; j > 0 && str[j - 1] > str[j]; j--)
			{
				t = str[j];
				str[j] = str[j - 1];
				str[j - 1] = t;
			}
}