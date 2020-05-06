//Знайти найбільший спільний дільник для елементів довільного
//одновимірного масиву цілих чисел. Рекомендовано застосування
//алгоритму Евкліда.

#include <stdio.h>
#include <conio.h>
#define MAX_ELM 256
int GCD(int*, int, int);

int main()
{
	int a[MAX_ELM], size = 0;
	do {
		printf("a[%i] = ", size);
		scanf_s("%i", &a[size]);
		if (a[size] < 0) a[size] *= -1;
	} while (a[size] && ++size < MAX_ELM);

	printf("The greatest common divisor: %i", GCD(a, size, *a));
	_getch();
	return 0;
}

int GCD(int* arr, int size, int gcd)
{
	if (size)
	{
		int t = *arr;
		while (t != gcd)
			if (t > gcd) t -= gcd;
			else gcd -= t;
		return GCD(arr + 1, size - 1, t);
	}
	return gcd;
}