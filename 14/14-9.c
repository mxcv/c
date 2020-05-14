/*Організувати базу даних з інформацією про співробітників установи,
використавши структуру з наступними полями:
– ПІБ;
– дата народження(дд:мм:рррр); // ISO-8601 (YYYY-MM-DD) is better
– стать;
– річний дохід;
– кількість дітей.
Додатковий сервіс: вивести на екран відсортовану за прізвищем інформацію
про співробітників установи, що народилися в зазначений час року.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "menu.h"
#define ARRAY_GROWTH 10

struct Employee
{
	char name[64];
	time_t birthday;
	bool is_male;
	float salary;
	int children;
};

bool fill_elm(struct Employee* element);
bool fill_num(int* number, int size);
void clear_stream() { char s[1]; gets_s(s, 1); }
// scanf() leaves '\n' in the stream so it can cover gets()
void error();

void show(struct Employee* arr, int size, int number);
void add(struct Employee** arr, int* size, int* max_size);
void edit(struct Employee* arr, int size);
void del(struct Employee* arr, int* size);
void season(struct Employee* arr, int size);

int main()
{
	struct Employee* base = NULL;
	int size = 0, max_size = 0;

	while (true)
	{
		printf("\t\tEmployees\n\nAdd\n\nEdit\n\nDelete\n\nClear\n\nSeason birth\n\n");
		show(base, size, 0);

		switch (choose(5, 13, 2, 1))
		{
		case 1: add(&base, &size, &max_size); break;
		case 2: edit(base, size); break;
		case 3: del(base, &size); break;
		case 4: size = 0; break;
		case 5: season(base, size); break;
		default:
			free(base);
			return 0;
		}
		system("cls");
	}
}

bool fill_elm(struct Employee* element)
{
	struct tm full_birthday;
	full_birthday.tm_hour = full_birthday.tm_min = full_birthday.tm_sec = full_birthday.tm_isdst = 0;

	printf("Gender:\n\nMale\n\nFemale");
	switch (choose(2, 7, 2, 1))
	{
	case 1: element->is_male = true;	break;
	case 2: element->is_male = false;	break;
	default: return false;
	}

	printf("Name: ");
	gets_s(element->name, 64);

	printf("Birthday (YYYY MM DD): ");
	scanf_s("%i%i%i", &full_birthday.tm_year, &full_birthday.tm_mon, &full_birthday.tm_mday);
	full_birthday.tm_year -= 1900;
	--(full_birthday.tm_mon);
	if ((element->birthday = mktime(&full_birthday)) == -1) return false;

	printf("Salary: ");
	if (!scanf_s("%f", &element->salary)) return false;

	printf("Amount of children: ");
	if (!scanf_s("%i", &element->children)) return false;

	clear_stream();
	return true;
}
bool fill_num(int* number, int size)
{
	printf("Enter number: ");
	bool success = scanf_s("%i", number) && -- * number >= 0 && *number < size;
	clear_stream();
	return success;
}
void error()
{
	system("cls");
	printf("Something went wrong...");
	Sleep(2000);
}

void show(struct Employee* arr, int size, int number)
{
	for (int i = 0; i < size; ++i)
	{
		struct tm full_birthday;
		localtime_s(&full_birthday, &arr[i].birthday);
		char string_full_birthday[22];
		strftime(string_full_birthday, 22, "\tBirthday:\t%F", &full_birthday);

		printf("#%i.\n", number ? number : i + 1);
		printf("\tName:\t\t%s\n", arr[i].name);
		puts(string_full_birthday);
		printf("\tGender:\t\t%s\n", arr[i].is_male ? "male" : "female");
		printf("\tSalary:\t\t%.2f\n", arr[i].salary);
		printf("\tChildren:\t%i\n", arr[i].children);
	}
}
void add(struct Employee** arr, int* size, int* max_size)
{
	if (!*size)
	{
		*arr = (struct Employee*)malloc(ARRAY_GROWTH * sizeof(struct Employee));
		*max_size = ARRAY_GROWTH;
	}
	else if (!(*size % *max_size))
	{
		*arr = (struct Employee*)realloc(arr, *size + ARRAY_GROWTH * sizeof(struct Employee));
		*max_size += ARRAY_GROWTH;
	}
	if (!*arr) exit(0);

	struct Employee new_element, temp;
	if (fill_elm(&new_element))
	{
		int pos;
		for (pos = 0; pos < *size; ++pos)
			if (strcmp(new_element.name, (*arr)[pos].name) < 0)
				break;

		for (int i = pos; i < *size; ++i)
		{
			temp = (*arr)[i];
			(*arr)[i] = new_element;
			new_element = temp;
		}
		(*arr)[(*size)++] = new_element;
	}
	else error();
}
void edit(struct Employee* arr, int size)
{
	int n;
	if (fill_num(&n, size))
	{
		struct Employee new_element;
		system("cls");
		if (fill_elm(&new_element))
			arr[n] = new_element;
		else error();
	}
	else error();
}
void del(struct Employee* arr, int* size)
{
	int n;
	if (fill_num(&n, size))
	{
		--* size;
		for (int i = n; i < *size; ++i)
			arr[i] = arr[i + 1];
	}
	else error();
}
void season(struct Employee* arr, int size)
{
	int m[3];
	struct tm full_birthday;
	printf("Employees who were born in:\n\nWinter\n\nSpring\n\nSummer\n\nAutumn");
	switch (choose(4, 7, 2, 1))
	{
	case 1: *m = 11;	break;
	case 2: *m =  2;	break;
	case 3: *m =  5;	break;
	case 4: *m =  8;	break;
	default: return;
	}
	m[1] = *m != 11 ? m[0] + 1 : 0;
	m[2] = m[1] + 1;

	for (int i = 1; i <= size; ++i, ++arr)
	{
		localtime_s(&full_birthday, &arr->birthday);
		if (full_birthday.tm_mon == m[0] || full_birthday.tm_mon == m[1] || full_birthday.tm_mon == m[2])
			show(arr, 1, i);
	}
	system("pause");
}