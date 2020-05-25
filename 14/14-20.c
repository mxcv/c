/*Організувати базу даних для складу військового та інтендантського
майна військової частини, використавши структуру з наступними полями:
– найменування обмундирування (верхній одяг, білизна, головні убори, взуття, ремені, зброя тощо);
– кількість кожної одиниці обмундирування або зброї;
– інвентарний номер кожної одиниці обмундирування або зброї.
Додатковий сервіс: вивести на екран інформацію про стан складу і
про можливі нестачі після введення кількості новобранців частини.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h>
#include "menu.h"
#define ARRAY_GROWTH 10

struct Item
{
	char name[64];
	int quantity, *id;
};

bool fill_elm(struct Item* element);
bool fill_num(int* number, int size);
void clear_stream() { char s[1]; gets_s(s, 1); }
void error();

void show(struct Item* arr, int size);
void add(struct Item** arr, int* size, int* max_size);
void edit(struct Item* arr, int size);
void del(struct Item* arr, int* size);
void checkup(struct Item* arr, int size);

int main()
{
	struct Item* base = NULL;
	int size = 0, max_size = 0;
	
	while (true)
	{
		printf("\t\tItems\n\nAdd\n\nEdit\n\nDelete\n\nClear\n\nCheck up\n\n");
		show(base, size);

		switch (choose(5, 9, 2, 1))
		{
		case 1: add(&base, &size, &max_size);	break;
		case 2: edit(base, size);				break;
		case 3: del(base, &size);				break;
		case 4:
			for (int i = 0; i < size; ++i)
				free(base[i].id);
			size = 0;							break;
		case 5: checkup(base, size);			break;
		default:
			free(base);
			return 0;
		}
		system("cls");
	}
}

bool fill_elm(struct Item* element)
{
	printf("Name: ");
	gets_s(element->name, 64);

	printf("Quantity: ");
	if (!scanf_s("%i", &element->quantity)) return false;
	
	element->id = (int*)malloc(element->quantity * sizeof(int));
	if (!element->id) return false;
	for (int i = 0; i < element->quantity; ++i)
		element->id[i] = i + 1;

	clear_stream();
	return true;
}
bool fill_num(int* number, int size)
{
	printf("Enter number: ");
	bool success = scanf_s("%i", number) && --*number >= 0 && *number < size;
	clear_stream();
	return success;
}
void error()
{
	system("cls");
	printf("Something went wrong...");
	Sleep(2000);
}

void show(struct Item* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("#%i.\n", i + 1);
		printf("\tName:\t\t%s\n", arr[i].name);
		printf("\tQuantity:\t%i\n", arr[i].quantity);
	}
}
void add(struct Item** arr, int* size, int* max_size)
{
	if (!*size)
	{
		*arr = (struct Item*)malloc(ARRAY_GROWTH * sizeof(struct Item));
		*max_size = ARRAY_GROWTH;
	}
	else if (!(*size % *max_size))
	{
		*arr = (struct Item*)realloc(arr, *size + ARRAY_GROWTH * sizeof(struct Item));
		*max_size += ARRAY_GROWTH;
	}
	if (!*arr) exit(0);

	struct Item new_element, temp;
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
void edit(struct Item* arr, int size)
{
	int n;
	if (fill_num(&n, size))
	{
		struct Item new_element;
		system("cls");
		if (fill_elm(&new_element))
		{
			free(arr[n].id);
			arr[n] = new_element;
		}
		else error();
	}
	else error();
}
void del(struct Item* arr, int* size)
{
	int n;
	if (fill_num(&n, size))
	{
		--*size;
		free(arr[n].id);
		for (int i = n; i < *size; ++i)
			arr[i] = arr[i + 1];
	}
	else error();
}
void checkup(struct Item* arr, int size)
{
	int n;
	printf("The number of items you need: ");
	if (!scanf_s("%i", &n)) error();
	else
	{
		bool found = false;
		for (int i = 0; i < size; ++i)
		{
			if (arr[i].quantity < n)
			{
				printf("\n%i unit%s of \"%s\" %s not enough",
					n - arr[i].quantity, n - arr[i].quantity > 1 ? "s" : "", arr[i].name, n - arr[i].quantity > 1 ? "are" : "is");
				found = true;
			}
		}
		if (!found) printf("\nEverything is enough.");
		_getch();
	}
	clear_stream();
}