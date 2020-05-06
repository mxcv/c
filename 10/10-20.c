//Дано довільні одновимірний масив дійсних чисел М1 та дійсні числа x та y (x<y).
//З масиву М1 сформувати масив М2, в якому замінено нулями усі числа,
//котрі більші за x та менші за y.

#include <stdio.h>
#include <conio.h>
#define MAX_ELM 256

int main()
{
	float a[MAX_ELM], b[MAX_ELM], x, y;
	int size = 0;

	do {
		printf("a[%i] = ", size);
		scanf_s("%f", &a[size]);
	} while (a[size] && ++size < MAX_ELM);
	
	printf("Enter x, y: ");
	scanf_s("%f%f", &x, &y);
	
	for (int i = 0; i < size; i++)
		printf("b[%i] = %f\n", i, b[i] = a[i] > x && a[i] < y ? 0 : a[i]);

	_getch();
	return 0;
}