#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX_ELM 10000
#define TIMES 1000
#define NUMBER rand() % 1000 + 1;

int GCD_div(int, int);
int GCD_sub(int, int);

int main()
{
	srand(time(0));
	int *a = (int*)malloc(MAX_ELM * sizeof(int)), *b = (int*)malloc(MAX_ELM * sizeof(int)), size;
	if (!a || !b) return 1;
	clock_t start, stop, div = 0, sub = 0;

	for (int i = 0; i < TIMES; i++)
	{
		for (int i = 0; i < MAX_ELM; i++)
		{
			a[i] = NUMBER;
			b[i] = NUMBER;
		}
		
		size = MAX_ELM;
		start = clock();
		while (size--) GCD_div(a[size], b[size]);
		stop = clock();
		div += stop - start;

		size = MAX_ELM;
		start = clock();
		while (size--) GCD_sub(a[size], b[size]);
		stop = clock();
		sub += stop - start;

		printf("\r%.2lf%%", (double)i / TIMES * 100);
	}
	printf("\n\nTime for division:\t%.3lf", div / (double)CLOCKS_PER_SEC);
	printf("\nTime for subtraction:\t%.3lf", sub / (double)CLOCKS_PER_SEC);

	free(a);
	free(b);
	_getch();
	return 0;
}

int GCD_div(int a, int b)
{
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}
int GCD_sub(int a, int b)
{
	while (a != b)
		if (a > b) a -= b;
		else b -= a;
	return a;
}