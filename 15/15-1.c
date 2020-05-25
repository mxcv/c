//З довільного одновимірного масиву дійсних чисел
//сформувати масив, в якому першу половину елементів
//упорядковано за спаданням, а другу – за зростанням.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

void print_array(FILE*, int*, int, const char*, const char*);
void sort(int*, int, bool);

int main()
{
	char file_name[256];
	int a[256], size = 0, read_status;

	fprintf(stdout, "File name: ");
	gets_s(file_name, sizeof(file_name) / sizeof(*file_name));

	FILE* file = fopen(file_name, "r");
	if (!file) return 1;
	do read_status = fscanf(file, "%i", a + size);
	while (read_status && read_status != EOF && ++size < sizeof(a) / sizeof(*a));
	fclose(file);

	printf("Source: ");
	print_array(stdout, a, size, ", ", "\n");

	sort(a, size / 2, false);
	sort(a + size / 2, size / 2 + (size & 1), true);

	printf("Result: ");
	print_array(stdout, a, size, ", ", "\n");

	file = fopen(file_name, "w");
	if (!file) return 1;
	print_array(file, a, size, " ", "");
	fclose(file);

	_getch();
	return 0;
}

void print_array(FILE* stream, int* arr, int size, const char* delimiter, const char* end)
{
	for (int i = 0; i < size; ++i)
		fprintf(stream, "%i%s", arr[i], i < size - 1 ? delimiter : end);
}

void sort(int* arr, int size, bool asc)	//bubble
{
	for (int i = 0, t; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (asc ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
}
