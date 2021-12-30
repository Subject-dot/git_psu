#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <string.h>
#include <Windows.h>

using namespace std;


void TaskOne();
void TaskTwo();
void TaskThree();
void TaskFour();
void TaskFive();

int main()
{
	setlocale(LC_ALL, "Rus");
	int Task = 0;
	printf("Выберите номер задания:\n");
	scanf("%d", &Task);
		switch (Task)
		{
		case 1:
			TaskOne();
			break;
		case 2:
			TaskTwo();
			break;
		case 3:
			TaskThree();
			break;
		case 4:
			TaskFour();
			break;
		case 5:
			TaskFive();
			break;
		}
}

void TaskOne()
{
	system("cls");
	setlocale(LC_ALL, "Rus");
	printf("Задание: написать программу, вычисляющую разницу между максимальным и минимальным элементами массива.\n");
	int n = 10, i = 0, k = 0;
	int max = -2147483648, min = 2147483647;
	int a[10];
	printf("Введите члены массива:\n");
	for (i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	k = max - min;
	printf("Разность между максимальным и минимальным числом: %d\n\n\n\n\n", k);
}

void TaskTwo()
{
	system("cls");
	setlocale(LC_ALL, "Rus");
	printf("Задание: написать программу, реализующую инициализацию массива случайными числами.\n");
	int n = 10, i = 0;
	int a[10];
	for (i = 0; i < n; i++) 
	{
		a[i] = rand() % 1000;
	}
	printf("Массив, заданный псевдослучайными числами:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n\n\n\n\n");
}

void TaskThree()
{
	system("cls");
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	printf("Задание: написать программу, реализующую создание массива произвольного размера, вводимого с клавиатуры.\n");
	int n = 0, i = 0, j;
	int* a = NULL;
	printf("Введите количество членов массива:\n");
	scanf("%d", &n);
	a = (int*)calloc(n,sizeof(int));
	for (i = 0; i < n; i++) 
	{
			a[i] = rand() % 100;
	}
	printf("Массив:\n");
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	printf("\n\n\n\n\n");
	free(a);
	getchar(); getchar();
}

void TaskFour()
{
	system("cls");
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	printf("Задание: написать программу, вычисляющую сумму значений в каждом столбце (или строке) двумерного массива.\n");
	int i, j, l = 0, sum[10] = { 0 }, summa = 0;
	int a[10][10];
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			summa = summa + a[i][j];
			if (j == 9)
			{
				sum[l] = sum[l] + summa;
				summa = 0;
				l++;
			}
		}
	}
	printf("Массив:\n");
	for (i = 0; i < 10; i++)
	{
		printf("\n");
		for (j = 0; j < 10; j++)
		{
			printf("%4d ", a[i][j]);
		}
	}
	printf("\nСумма по строкам соответсвенно:\n");
	for (l = 0; l < 10; l++)
	{
		printf("%4d ", sum[l]);
	}
}

int const col = 100;
struct student
{
	char famil[20];
	char name[20], facult[20];
	int nomzach;
} stud[col];


int AddInfo();
void Searchname(char* name, int k);
void Searchfamil(char* famil, int k);
void Searchfacult(char* facult, int k);
void Searchnomzach(int nomzach, int k);
void ShowAll(int k);

void TaskFive()
{
	char name[20], famil[20], facult[20], choice;
	int nomzach, k;
	setlocale(LC_ALL, "Rus");
	do {
		cout << "Выберите требуемое действие:\n1-Добавить информацию о студентах...\n2-Поиск студента по имени...\n";
		cout << "3-Поиск по фамилии...\n4-Поиск по факультету...\n5-Поиск по номеру зачетки...\n6-Показать всех студентов...\n7-Выход...\n";
		cin >> choice;
		switch (choice) {
		case '1':
			k = AddInfo();
			break;
		case '2':
			cout << "Введите имя:\n";
			cin >> name;
			Searchname(name, k);
			break;
		case '3':
			cout << "Введите фамилию:\n";
			cin >> famil;
			Searchfamil(famil, k);
			break;
		case '4':
			cout << "Введите факультет:\n";
			cin >> facult;
			Searchfacult(facult, k);
			break;
		case '5':
			cout << "Введите номер зачетки:\n";
			cin >> nomzach;
			Searchnomzach(nomzach, k);
			break;
		case '6':
			ShowAll(k);
			break;
		case '7':
			exit(0);
			break;
		default:
			cout << "Неправильный выбор\n";
			break;
		}
	} while (choice != '7');
}

int AddInfo()
{
	setlocale(LC_ALL, "Rus");
	int k, s;
	cout << "Введите количество записей:\n";
	cin >> k;
	cout << "Введите номер, с которого начинаете запись:\n";
	cin >> s;
	for ( int i=s-1; i < k; i++) {
		cout << "Введите имя студента[" << i << "]:\n";
		cin >> stud[i].name;
		cout << "Введите фамилию студента[" << i << "]:\n";
		cin >> stud[i].famil;
		cout << "Введите факультет студента[" << i << "]:\n";
		cin >> stud[i].facult;
		cout << "Введите номер зачетки[" << i << "]:\n";
		cin >> stud[i].nomzach;
	}
	return k;
}

void Searchname(char* name, int k)
{
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < k; i++) {
		if (_stricmp(name, stud[i].name) == 0) {
			cout << "Имя студента: " << stud[i].name << "\n";
			cout << "Фамилия студента: " << stud[i].famil << "\n";
			cout << "Факультет студента: " << stud[i].facult << "\n";
			cout << "Номер зачетки студента: " << stud[i].nomzach << "\n";
			cout << "##########################\n";
		}
		else
				cout << "Студент не найден!\n";
	}

}

void Searchfamil(char* famil, int k)
{
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < k; i++) {
		if (_stricmp(famil, stud[i].famil) == 0) {
			cout << "Имя студента: " << stud[i].name << "\n";
			cout << "Фамилия студента: " << stud[i].famil << "\n";
			cout << "Факультет студента: " << stud[i].facult << "\n";
			cout << "Номер зачетки студента: " << stud[i].nomzach << "\n";
			cout << "##########################\n";
		}
		else
				cout << "Студент не найден!\n";
	}

}

void Searchfacult(char* facult, int k)
{
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < k; i++) {
		if (_stricmp(facult, stud[i].facult) == 0) {
			cout << "Имя студента: " << stud[i].name << "\n";
			cout << "Фамилия студента: " << stud[i].famil << "\n";
			cout << "Факультет студента: " << stud[i].facult << "\n";
			cout << "Номер зачетки студента: " << stud[i].nomzach << "\n";
			cout << "##########################\n";
		}
		else
				cout << "Студент не найден!\n";
	}

}

void Searchnomzach(int nomzach, int k)
{
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < k; i++) {
		if (nomzach == stud[i].nomzach) {
			cout << "Имя студента: " << stud[i].name << "\n";
			cout << "Фамилия студента: " << stud[i].famil << "\n";
			cout << "Факультет студента: " << stud[i].facult << "\n";
			cout << "Номер зачетки студента: " << stud[i].nomzach << "\n";
			cout << "##########################\n";
		}
		else
				cout << "Студент не найден!\n";
	}
}

void ShowAll(int k)
{
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < k; i++) {
		cout << "Имя студента: " << stud[i].name << "\n";
		cout << "Фамилия студента: " << stud[i].famil << "\n";
		cout << "Факультет студента: " << stud[i].facult << "\n";
		cout << "Номер зачетки студента: " << stud[i].nomzach << "\n";
		cout << "##########################\n";
	}
}
