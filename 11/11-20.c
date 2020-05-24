//Дано натуральні числа n та m, що визначають відповідно кількість рядків та
//стовпців у деякій генерованій матриці дійсних чисел.Переставити місцями
//перший і останній рядки цієї матриці.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define ROWS 10
#define COLS 10

void ShowMatrix(int[][COLS], int, int, const char*);
void RandMatrix(int[][COLS], int, int);

int main()
{
	srand(time(NULL));
	int arr[ROWS][COLS], n, m;
	printf("n = ");
	scanf_s("%i", &n);
	printf("m = ");
	scanf_s("%i", &m);

	if (n > 0 && m > 0 && n <= ROWS && m <= COLS)
	{
		RandMatrix(arr, n, m);
		ShowMatrix(arr, n, m, "M(before)");

		if (m > 1)
			for (int i = 0, t; i < m; i++)
			{
				t = arr[0][i];
				arr[0][i] = arr[n - 1][i];
				arr[n - 1][i] = t;
			}

		ShowMatrix(arr, n, m, "M(after)");
	}
	else printf("Incorrect input!");
	_getch();
	return 0;
}

void ShowMatrix(int arr[][COLS], int r, int c, const char* name)
{
	printf("\n%s\n\n", name);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			printf("%i\t", arr[i][j]);
		printf("\n\n");
	}
}
void RandMatrix(int arr[][COLS], int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			arr[i][j] = rand() % 100 + 1;
}