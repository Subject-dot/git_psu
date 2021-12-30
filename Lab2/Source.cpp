#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <locale.h>
#include <malloc.h>
#include <ctime>

using namespace std;

int multiplication(void);
void shell();
void qs(int* items, int left, int right);


int main()
{
	setlocale(LC_ALL, "russian");
	int NumberTask;
	int n;
	int* items = NULL;
	cout << "Выберете номер задания:";
	cin >> NumberTask;
	switch (NumberTask)
	{
	case 1:
		multiplication();
		break;
	case 2:
		shell();
		break;
	case 3:
		cout << "Алгоритм Быстрой сортировки\n";
		cout << "Введите размер массива:\n";
		cin >> n;
		qs(items, 0, n-1);
		break;
	case 4:
		cout << "Алгоритм стандартной сортировки\n";
		cout << "Введите размер массива:\n";
		cin >> n;
		QuickSort(n);
	default:
		cout << "Eror";
		break;
	}
}
int multiplication(void) // 7
{
	setlocale(LC_ALL, "russian");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int i, j, r, n;
	int elem_c;
	int** a = NULL;
	int** b = NULL;
	int** c = NULL;
	
	cout << "Введите размерность массива: " << endl;
	cin >> n;
	system("cls");

	a = (int**)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)calloc(n, sizeof(int));
	}
	b = (int**)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		b[i] = (int*)calloc(n, sizeof(int));
	}
	c = (int**)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		c[i] = (int*)calloc(n, sizeof(int));
	}

	cout << "\n\n";
	cout << "Матрица №1:\n";
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			
		}
	
	}

	cout << "\n\n";
	cout << "Матрица №2:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			
		}
		
	}
	cout << "\n\n";
	cout << "Результат перемножения:\n";
	clock_t start = clock();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			elem_c = 0;
			for (r = 0; r < n; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
				
			}
			
		}
	}
	clock_t end = clock();
	cout << "\n\n\nВремя на перемножение матриц в миллисекундах:" << end - start;
	free(a);
	free(b);
	free(c);
	return(0);
}


void shell()
{
	system("cls");
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	int i, j, gap, k;
	int x, a[5];
	int* items = NULL;
	int n;
	cout << "Алгоритм Шелла\n";
	cout << "Введите размер массива:\n";
	cin >> n;
	items = (int*)calloc(n, sizeof(int));


	/*for (int i = 0; i < n; i++) 
	{
		items[i] = rand() % 1000 + 1;
	}*/

	/*items[0] = 0;
	for (int i = 1; i < n; i++)
	{
		items[i] = items[i - 1] + 1;
	}*/

	/*items[0] = n;
	for (int i = 1; i < n; i++)
	{
		items[i] = items[i - 1] - 1;
	}*/

	/*items[0] = 1;
	for (int i = 1; i < n/2; i++)
	{
		items[i] = items[i - 1] + 1;
	}
	for (int i = n/2; i < n; i++)
	{
		items[i] = items[i - 1] - 1;
	}*/
	cout << "Начальный массив:\n";

	/*for (i = 0; i < n; i++)
	{
		cout << items[i];
		cout << " ";
	}*/
	clock_t start = clock();
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < n; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
	clock_t end = clock();
	cout << "\nРезультат сортировки массива:\n";
	/*for (i = 0; i < n; i++)
	{
		cout << items[i];
		cout << " ";
	}*/
	cout << "\nВремя: ";
	cout << end - start << "\n";
	free(items);
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	system("cls");
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
int i, j;
int x, y;
items = (int*)calloc(right+1, sizeof(int));


for (int i = 0; i < right+1; i++)
{
	items[i] = rand() % 1000 + 1;
}

/*items[0] = 0;
for (int i = 1; i < n; i++)
{
	items[i] = items[i - 1] + 1;
}*/

/*items[0] = n;
for (int i = 1; i < n; i++)
{
	items[i] = items[i - 1] - 1;
}*/

/*items[0] = 1;
for (int i = 1; i < n/2; i++)
{
	items[i] = items[i - 1] + 1;
}
for (int i = n/2; i < n; i++)
{
	items[i] = items[i - 1] - 1;
}*/
cout << "Начальный массив:\n";

for (i = 0; i < right+1; i++)
{
	cout << items[i];
	cout << " ";
}

clock_t start = clock();
i = left; j = right;
/* выбор компаранда */
x = items[(left + right) / 2];
do {
	while ((items[i] < x) && (i < right)) i++;
	while ((x < items[j]) && (j < left)) j--;
	if (i<= j) {
		y = items[i];
		items[i] = items[j];
		items[j] = y;
		i++; j--;
	}
} while (i <= j);
if (left < j) qs(items, left, j);
if (i < right) qs(items, i, right);
clock_t end = clock();
cout << "\nРезультат сортировки массива:\n";

for (i = 0; i < right+1; i++)
{
	cout << items[i];
	cout << " ";
}

cout << "\nВремя: ";
cout << end - start << "\n";
free(items);
}

int comp(const void*, const void*);

int QuickSort(int n)
{
	int i;
	int* massive = NULL;
	massive = (int*)calloc(n, sizeof(int));

	printf("Исходный массив: ");
	for (i = 0; i < n; i++)
	{
		cout << massive[i];
	}

	qsort(massive, n, sizeof(int), comp);

	printf("Отсортированный массив: ");
	for (i = 0; i < n; i++)
	{
		cout << massive[i];
	}

	return 0;
}

/* сравнение целых */
int comp(const void* i, const void* j)
{
	return *(int*)i - *(int*)j;
}

//void shell()
//{
//	system("cls");
//	setlocale(LC_ALL, "russian");
//	srand(time(NULL));
//	int i, j, gap, k;
//	int x, a[5];
//	int* items = NULL;
//	int n;
//	cout << "Алгоритм Шелла\n";
//	cout << "Введите размер массива:\n";
//	cin >> n;
//	items = (int*)calloc(n, sizeof(int));
//
//
//	/*for (int i = 0; i < n; i++)
//	{
//		items[i] = rand() % 1000 + 1;
//	}*/
//
//	/*items[0] = 0;
//	for (int i = 1; i < n; i++)
//	{
//		items[i] = items[i - 1] + 1;
//	}*/
//
//	/*items[0] = n;
//	for (int i = 1; i < n; i++)
//	{
//		items[i] = items[i - 1] - 1;
//	}*/
//
//	/*items[0] = 1;
//	for (int i = 1; i < n/2; i++)
//	{
//		items[i] = items[i - 1] + 1;
//	}
//	for (int i = n/2; i < n; i++)
//	{
//		items[i] = items[i - 1] - 1;
//	}*/
//	cout << "Начальный массив:\n";
//
//	/*for (i = 0; i < n; i++)
//	{
//		cout << items[i];
//		cout << " ";
//	}*/
//	clock_t start = clock();
//	qsort(void *items, n-1, sizeof(int), )