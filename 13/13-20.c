//Дано декілька рядків. Об’єднати вказані рядки та відсортувати
//в результуючому рядку символи за зростанням їх ASCII-кодів.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define SIZE 256

void sort(char*);

int main()
{
	char *buffer, *result;
	int n;

	printf("String number: ");
	scanf_s("%i", &n);
	if (n < 1) return 1;

	buffer = (char*)malloc(SIZE * sizeof(char));
	result = (char*)malloc(SIZE * sizeof(char) * n);
	if (!buffer || !result) return 1;
	gets_s(result, SIZE * n);
	// skips left '\n' in the stream and sets '\0' for the next strcat

	for (int i = 0; i < n; i++)
	{
		printf("%i. ", i + 1);
		gets_s(buffer, SIZE);
		strcat_s(result, SIZE * n, buffer);
	}
	
	sort(result);
	printf("\nConcatenated sorted string: %s", result);
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