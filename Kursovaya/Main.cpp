#include <locale.h>
#include <stack>
#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <time.h>

	using namespace std;
	int i, j;
	ofstream fout;

	void DFS_No_Rec(int** G, const int n);
	void Init_Matrix(int** G, const int n);
	void Out_Matrix(int** G, const int n);
	void Input_Matrix(int** G, const int n);
	void Delete_Matrix(int** G, const int n);
	void find_comps(int** G, const int n);

	void main()
	{

		setlocale(LC_ALL, "Rus");
		bool  check = false;
		int n;
		cout << " ������� ���������� ������ � �����: ";
		cin >> n;
		int** G = new int* [n];//����
		for (i = 0; i < n; i++)
		{
			G[i] = new int[n];
		}
		while (check == false)
		{
			cout << "\n �������� ��������: \n 1) ������������� ���� ������� : " << n << ", ��������������� �������;\n 2) ��������� ���� �� �����;\n ";
			int z = _getch() - 48;
			switch (z)
			{
			case 1:
				cout << "1\n\n";
				Init_Matrix(G, n);
				check = true;
				break;
			case 2:
				cout << "2\n\n";
				Input_Matrix(G, n);
				check = true;
				break;
			default:
				cout << "\n ������ ������. ����������, ������� ���������� ����� ��������! \n\n";
				break;

			}
		}
		system("cls");
		fout.open("output.txt", ofstream::app);
		cout << " ������� ��������� �����: \n";
		fout << " ������� ��������� �����: \n";
		Out_Matrix(G, n);
		cout << " ���������� ���������: \n";
		fout << " ���������� ���������: \n";
		find_comps(G, n);
		fout << "\n=========================\n\n";
		fout.close();
		Delete_Matrix(G, n);
		system("pause>>void");
	}

	vector <int> comp;

	void dfs(int** G, int n, int v, bool* used) 
	{
		used[v] = true;
		comp.push_back(v);
		for (int i = 0; i < n; i++)
		{
			if (G[v][i] == 1 && used[i] == false) //��������� ������� � ��� �������
			{
				dfs(G, n, i, used); //�������� ��������
			}
		}
	}

	void find_comps(int** G, const int n)
	{
		bool* used = new bool [n];
		for (int i = 0; i < n; ++i)
			used[i] = false;
		for (int i = 0; i < n; ++i)
			if (used[i] == false) {
				comp.clear();
				dfs(G, n, i, used);
				for (size_t k = 0; k < comp.size(); ++k)
				{
					if ((k < 1) && (comp.size() > 1))
					{
						cout << " " << comp[k] + 1;
						fout << " " << comp[k] + 1;
					}
					if ((k >= 1) && (comp.size() > 1))
					{
						cout << " --> " << comp[k] + 1;
						fout << " --> " << comp[k] + 1;
					}
				}
				cout << endl;
				fout << endl;
			}
	}


		

	void Init_Matrix(int** G, const int n)
	{
		srand(time(NULL));
		for (i = 0; i < n; i++)
		{
			G[i][i] = 0;
			for (j = 0; j < i; j++)
			{
				if (rand() % 100 <= 5) //���������� ����� ���������� �������
					G[i][j] = 1;
				else
					G[i][j] = 0;
				if (rand() % 100 <= 5)
					G[j][i] = 1;
				else
					G[j][i] = 0;
			}
			for (j = 0; j < n; j++)
			{
				G[j][i] = G[i][j];
			}
		}
	}

	void Out_Matrix(int** G, const int n)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << " " << G[i][j];
				fout << " " << G[i][j];
			}
			cout << endl;
			fout << endl;
		}
		cout << endl;
		fout << endl;
	}

	void Input_Matrix(int** G, const int n)
	{
		ifstream fin;
		fin.open("input.txt");
		if (!fin.is_open())
		{
			cout << "������ ��� �������� �����!\n";
			system("pause>>void");
		}
		else
		{
			string str;
			int iin = 0;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					fin >> str;
					for (int m = 0; m < str.length(); m++)
					{
						if (str.at(m) == '1' || str.at(m) == '0')
						{
							iin = stoi(str);
							G[i][j] = iin;
						}
						else
						{
							cout << "� ���� ������� ������������ ������.\n";
							system("pause>>void");
						}
					}
				}
			}
			fin.close();
		}
	}

	void Delete_Matrix(int** G, const int n)

	{

		for (i = 0; i < n; i++)

			delete[] G[i];

		delete[] G;

	}