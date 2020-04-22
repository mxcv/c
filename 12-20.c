//З довільного одновимірного масиву дійсних чисел М1 сформувати
//упорядкований за спаданням масив М2, який містить елементи М1,
//ціла частина яких є непарними числами.

#include <stdio.h>
#include <conio.h>
#define MAX_ELM 256

void sort_dec(float* arr, int n);

int main()
{
	float m1[MAX_ELM], m2[MAX_ELM];
	int size1 = 0, size2 = 0;
	do {
		printf("m1[%i] = ", size1);
		scanf_s("%f", &m1[size1]);
		if ((int)m1[size1] & 1) m2[size2++] = m1[size1];
	} while (m1[size1] && ++size1 < MAX_ELM);

	sort_dec(m2, size2);

	printf("\n");
	for (int i = 0; i < size2; i++)
		printf("m2[%i] = %f\n", i, m2[i]);

	_getch();
	return 0;
}

void sort_dec(float* arr, int n) //bubble
{
	float t;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] < arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
}