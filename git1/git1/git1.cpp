// git1.cpp: –æ–ø—Ä–µ–¥–µ–ª—è–µ—Ç —Ç–æ—á–∫—É –≤—Ö–æ–¥–∞ –¥–ª—è –∫–æ–Ω—Å–æ–ª—å–Ω–æ–≥–æ –ø—Ä–∏–ª–æ–∂–µ–Ω–∏—è.
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

int main()
{
	setlocale(LC_ALL,"Rus");
	int size;
	cout << "¬‚Â‰ËÚÂ ‡ÁÏÂ Ï‡ÒÒË‚‡: ";
	cin >> size;

	clock_t start = clock();
	getchar();
	int *ar = new int[size];
	for (int i = 0; i < size; i++)
	{
		ar[i] = rand() % 60 + 30;
		cout << ar[i] << "\t";
	}
	selection(ar, size);
	cout << "\n\nŒÚÒÓÚËÓ‚‡ÌÌ˚È Ï‡ÒÒË‚:\n";
	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << "\t";
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nThe time: %f seconds\n", seconds);
	system("pause");
	return 0;

}


