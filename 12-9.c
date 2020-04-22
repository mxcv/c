//З довільного одновимірного масиву дійсних чисел сформувати масив, в
//якому першу половину елементів упорядковано за спаданням, а другу – за
//зростанням.

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#define MAX_ELM 256

void sort_asc(int*, int);
void sort_dec(int*, int);

int main()
{
	int a[MAX_ELM], size = 0;
	do {
		printf("a[%i] = ", size);
		scanf_s("%i", &a[size]);
	} while (a[size] && ++size < MAX_ELM);

	sort_dec(a, size / 2);
	sort_asc(&a[size / 2], size / 2 + (size & 1));

	printf("\n");
	for (int i = 0; i < size; i++)
		printf("a[%i] = %i\n", i, a[i]);

	_getch();
	return 0;
}

void sort_asc(int* arr, int size)	//bubble
{
	for (int i = 0, t; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
}
void sort_dec(int* arr, int size)	//bubble
{
	for (int i = 0, t; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (arr[j] < arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
}