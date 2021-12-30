#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>    // Win32API Header File
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <stack>

#include <cmath>
#include <cstring>

#define word unsigned int

using namespace std;

#define Red  RGB (255,0,0)
#define Lime RGB (206,255,0)
#define Blue RGB (0,0,255)

static HWND    hConWnd; // "unable to open include file 'cstdio.h' "

int     BCX_Line(HWND, int, int, int, int, int = 0, HDC = 0);
int     BCX_Circle(HWND, int, int, int, int = 0, int = 0, HDC = 0);

HWND    GetConsoleWndHandle(void);

int flag[11];
word c[11][11], l[11]; // "namespace name expected" 

void DFS_no_rec(int** a, bool* visited, int n, int v) { //обход графа без рекурсии
	stack <int> stack;
	stack.push(v);
	while (!stack.empty())
	{
		if (visited[stack.top()] == false)
		{
			visited[stack.top()] = true;
			cout << stack.top() + 1;
			v = stack.top();
			stack.pop();
			for (int i = n - 1; i > 0; i--)
			{
				if (a[v][i] == 1 && visited[i] == false)
				{
					stack.push(i);
				}
			}
		}
		else
		{
			stack.pop();
		}
	}
}

int min2(int n) {
	int i, result;
	for (i = 0; i < n; i++)
		if (!(flag[i])) result = i;
	for (i = 0; i < n; i++)
		if ((l[result] > l[i]) && (!flag[i])) result = i;
	return result;
}


word minim(word x, word y) {
	if (x < y) return x;
	return y;
}


int main() {

	setlocale(LC_ALL, "Russian");
	int i, j, n, p, xn, xk;
	char s[80], path[80][11];
	POINT pt[11];
	const double PI = 4. * atan(1.);

	cout << "Ввидите размер графа: ";
	cin >> n;                   // " earlierdeclaration of 'main() '  "
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			c[i][j] = 0;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++) {
			cout << " задайте длины рёбер  x" << i + 1 << " do x" << j + 1 << ": ";
			cin >> c[i][j];
		}

	cout << "   ";
	for (i = 0; i < n; i++) cout << "    X" << i + 1;
	cout << endl << endl;
	for (i = 0; i < n; i++)
	{
		printf("X%d", i + 1);
		for (j = 0; j < n; j++)
		{
			printf("%6d", c[i][j]);
			c[j][i] = c[i][j];
		}
		printf("\n\n");
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (c[i][j] == 0)
				c[i][j] = 65535; //nekonecno
	cout << " задайте начальную точку: ";
	cin >> xn;
	cout << " задайте конечную точку: ";
	cin >> xk;
	xk--;
	xn--;
	if (xn == xk) {
		cout << "Начальная и конечные точки совпадают." << endl;
		cin.get();
		return 1;
	}

	for (i = 0; i < n; i++) {
		flag[i] = 0;
		l[i] = 65535;
	}
	l[xn] = 0;
	flag[xn] = 1;
	p = xn;
	_itoa(xn + 1, s, 10);
	for (i = 1; i <= n; i++) {
		strcpy(path[i], "X");
		strcat(path[i], s);
	}
	do {
		for (i = 0; i < n; i++)
			if ((c[p][i] != 65535) && (!flag[i]) && (i != p))
			{
				if (l[i] > l[p] + c[p][i])
				{
					_itoa(i + 1, s, 10);
					strcpy(path[i + 1], path[p + 1]);
					strcat(path[i + 1], "-X");
					strcat(path[i + 1], s);
				}
				l[i] = minim(l[i], l[p] + c[p][i]);
			}
		p = min2(n);
		flag[p] = 1;
	} while (p != xk);
	if (l[p] != 65535) {
		cout << "Put: " << path[p + 1] << endl;
		cout << "Dlina puti: " << l[p] << endl;
	}
	else
		cout << "Путь не существует!" << endl;

}