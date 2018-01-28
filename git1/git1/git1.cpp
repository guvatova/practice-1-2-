// git1.cpp: РѕРїСЂРµРґРµР»СЏРµС‚ С‚РѕС‡РєСѓ РІС…РѕРґР° РґР»СЏ РєРѕРЅСЃРѕР»СЊРЅРѕРіРѕ РїСЂРёР»РѕР¶РµРЅРёСЏ.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h> 
#include <fstream>

using namespace std;

void selection(int *ar, int size)
{
	clock_t startt = clock();
	getchar();
	ofstream foutt("C://Users//Ruta//Desktop//Git//git1//selection.txt");
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
	foutt << "\nОтсортированный массив:\n";
	for (int i = 0; i < size; i++)
	{
		foutt << ar[i] << "\n";
	}
	clock_t endd = clock();
	double secondss = (double)(endd - startt) / CLOCKS_PER_SEC;
	foutt << secondss;
	foutt.close();
}

void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB)
{
	clock_t start = clock();
	getchar();
	ofstream fout("C://Users//Ruta//Desktop//Git//git1//radix.txt");
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
	fout << "\nОтсортированный массив:\n";
	for (int i = 0; i < sizeAB; i++)
	{
		fout << br[i] << "\n";
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	fout << seconds;
	fout.close();
}


int main()
{
	setlocale(LC_ALL,"Rus");
	int size=60000;//кол-во элементов в массиве
	int sizeC = 30000;//макс число среди элементов
	ifstream file;
	file.open("C://Users//Ruta//Desktop//Git//git1//arr_in.txt");
	int *ar = new int[size];
	for (int i = 0; i < size; i++)
	{
		file >> ar[i];
	}
	int *br = new int[size];
	int *cr = new int[sizeC];
	int sizeAB = size;

	radix(ar, br, cr, sizeC, sizeAB);
	selection(ar, size);
	
	cout << "Массив рассортирован!\n";
	system("pause");
	return 0;

}


