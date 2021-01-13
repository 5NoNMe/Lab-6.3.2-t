#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

template <typename T>
void Input(T* a, const int size, int i) {
	cout << "a[" << i << "] = ";
	cin >> a[i];
	if (i < size - 1)
		Input(a, size, i + 1);
	else
		cout << endl;
}

template <typename T>
void Print(T* a, const int size, int i)
{
	cout << a[i] << ' ';
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

template <typename T>
void indexMax(T* a, const int size, T max, int imax, int i, bool flag)
{
	if (i < size)
	{
		if ((a[i] % 2) == 0)
		{
			if (!flag)
			{
				flag = true;
				max = a[i];
				imax = i;
			}
			else if (max < a[i])
			{
				max = a[i];
				imax = i;
			}

		}
		indexMax(a, size, max, imax, i + 1, flag);
	}
	else
	{
		if (!flag)
		{
			cout << "Всі числа не парні. " << endl;
		}
		else
		{
			cout << "Індекс найбільшого парного елемента масиву: " << imax << endl;
		}
	}

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	int n = 0;
	cout << "Введіть розмір масиву: "; cin >> n;
	int* a = new int[n];

	Input(a, n, 0);
	Print(a, n, 0);
	indexMax(a, n, a[0], 0, 0, false);

	delete[] a;

	return 0;
}