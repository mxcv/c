//З довільного одновимірного масиву дійсних чисел сформувати масив, в
//якому першу половину елементів упорядковано за спаданням, а другу – за
//зростанням.

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#define MAX_ELM 256

void sort(int*, int, bool(*)(int, int));
bool ascendig(int a, int b) { return a < b; }
bool decline(int a, int b) { return a > b; }

int main()
{
	int a[MAX_ELM], size = 0;
	do {
		printf("a[%i] = ", size);
		scanf_s("%i", &a[size]);
	} while (a[size] && ++size < MAX_ELM);

	sort(a, size / 2, ascendig);
	sort(&a[size / 2], size / 2 + (size & 1), decline);

	printf("\n");
	for (int i = 0; i < size; i++)
		printf("a[%i] = %i\n", i, a[i]);

	_getch();
	return 0;
}

void sort(int* arr, int n, bool(*compare)(int, int)) //bubble
{
	for (int i = 0, t; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (compare(arr[j], arr[j + 1]))
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
}