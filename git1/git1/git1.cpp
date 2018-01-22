// git1.cpp: РѕРїСЂРµРґРµР»СЏРµС‚ С‚РѕС‡РєСѓ РІС…РѕРґР° РґР»СЏ РєРѕРЅСЃРѕР»СЊРЅРѕРіРѕ РїСЂРёР»РѕР¶РµРЅРёСЏ.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h> 

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

void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB)
{
	int i, k, n;
	k = sizeC;
	n = sizeAB;
	for (i = 0; i <= k; i++)
		cr[i] = 0;
	for (i = 0; i < n; i++)
		cr[ar[i]] += 1;
	for (i = 1; i < k + 1; i++)
		cr[i] += cr[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		br[cr[ar[i]] - 1] = ar[i];
		cr[ar[i]] -= 1;
	}
}


int main()
{
	setlocale(LC_ALL,"Rus");
	int size;
	cout << "Введите размер массива: ";
	cin >> size;
	int sizeC = 100;
	clock_t start = clock();
	getchar();
	int *ar = new int[size];
	for (int i = 0; i < size; i++)
	{
		ar[i] = rand() % sizeC;
		cout << ar[i] << "\t";
	}
	int *br = new int[size];
	int *cr = new int[sizeC];
	int sizeAB = size;

	selection(ar, size);
	cout << "\n\nОтсортированный массив:\n";
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << "\t";
	}

	radix(ar, br, cr, sizeC, sizeAB);
	cout << "\n\nОтсортированный массив:\n";
	for (int i = 0; i < size; i++)
	{
		cout << br[i] << "\t";
	}

	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nThe time: %f seconds\n", seconds);
	system("pause");
	return 0;

}


