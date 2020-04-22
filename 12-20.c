//З довільного одновимірного масиву дійсних чисел М1 сформувати
//упорядкований за спаданням масив М2, який містить елементи М1,
//ціла частина яких є непарними числами.

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#define MAX_ELM 256

void insert(float*, int, float);

int main()
{
	float m1[MAX_ELM], m2[MAX_ELM];
	int size1 = 0, size2 = 0;
	do {
		printf("m1[%i] = ", size1);
		scanf_s("%f", &m1[size1]);
	} while (m1[size1] && ++size1 < MAX_ELM);

	for (int i = 0; i < size1; i++)
		if ((int)m1[i] & 1)
			insert(m2, size2++, m1[i]);

	printf("\n");
	for (int i = 0; i < size2; i++)
		printf("m2[%i] = %f\n", i, m2[i]);

	_getch();
	return 0;
}

void insert(float* arr, int size, float value)
{
	int pos = 0;
	while (pos < size)
		if (value > arr[pos++]) {
			pos--;
			break;
		}

	for (int i = pos, t; i < size; i++) {
		t = arr[i];
		arr[i] = value;
		value = t;
	}
	arr[size] = value;
}