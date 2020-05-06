//Знайти найбільший спільний дільник для елементів довільного
//одновимірного масиву цілих чисел. Рекомендовано застосування
//алгоритму Евкліда.

#include <stdio.h>
#include <conio.h>
#define MAX_ELM 256
int GCD(int, int);

int main()
{
	int a[MAX_ELM], size = 0;
	do {
		printf("a[%i] = ", size);
		scanf_s("%i", &a[size]);
		if (a[size] < 0) a[size] *= -1;
	} while (a[size] && ++size < MAX_ELM);
	
	int result = *a;
	while (--size) result = GCD(result, a[size]);

	printf("The greatest common divisor: %i", result);
	_getch();
	return 0;
}

int GCD(int a, int b)
{
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}