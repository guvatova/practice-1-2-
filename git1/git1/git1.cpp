// git1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void selection(int *ar, int size)
{
	int i, j, mx, nmx;
	for (i = 0; i < size - 1; i++)
	{
		mx = ar[i];
		nmx = i;
		for (j = i + 1; j < size; j++)
		{
			if (ar[j]<mx)
			{
				mx = ar[j];
				nmx = j;
			}
		}
		ar[nmx] = ar[i];
		ar[i] = mx;
	
	}
}

int main()
{
	setlocale(LC_ALL,"Rus");
	int size;
	cout << "������� ������ �������: ";
	cin >> size;
	int *ar = new int[size];
	for (int i = 0; i < size; i++)
	{
		ar[i] = rand() % 60 + 30;
		cout << ar[i] << "\t";
	}
	selection(ar, size);
	cout << "\n\n��������������� ������:\n";
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << "\t";
	}
	system("pause");
	return 0;

}


