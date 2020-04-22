//Дано натуральні числа n та m, що визначають відповідно кількість рядків та
//стовпців у деяких генерованих матрицях натуральних чисел М1 і М2.
//Отримати матрицю М3 шляхом додавання матриць М1 і М2.

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
	int m1[ROWS][COLS], m2[ROWS][COLS], m3[ROWS][COLS], n, m;
	printf("n = ");
	scanf_s("%i", &n);
	printf("m = ");
	scanf_s("%i", &m);

	if (n > 0 && m > 0 && n <= ROWS && m <= COLS)
	{
		RandMatrix(m1, n, m);
		ShowMatrix(m1, n, m, "M1");

		RandMatrix(m2, n, m);
		ShowMatrix(m2, n, m, "M2");

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				m3[i][j] = m1[i][j] + m2[i][j];
		ShowMatrix(m3, n, m, "M3");
	}
	else printf("Incorrect input!");
	_getch();
	return 0;
}

void ShowMatrix(int arr[][COLS], int r, int c, const char* name)
{
	printf("\n");
	printf(name);
	printf("\n\n");
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