// ConsoleApplication30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(NULL));
	const unsigned int ROWS = 5;
	const unsigned int COLS = 4;

	int arr[ROWS][COLS] = { 0 };

	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	if (a>b)
	{
		a = a^b;
		b = a^b;
		a = a^b;
	}
	for (unsigned int i = 0; i < ROWS; ++i)
	{
		for (unsigned int j = 0; j < COLS; ++j)
		{
			arr[i][j] = rand() % (b - a) + a;
			//[a,b]=>[a, b) [5, 15)
		}
	}
	for (int i = 0; i<ROWS; i++)
	{
		for (int j = 0; j<COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	//P.Ако елемент на масива е над средната стойност на масива, то той да се замени с минимума на масива;
/*	int arrAvg = 0, minElem = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			minElem = (minElem < arr[i][j]) ? minElem : arr[i][j];
			arrAvg += arr[i][j];
		}
	}
	arrAvg /= ROWS*COLS;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j]>arrAvg)
				arr[i][j] = minElem;
		}
	}
	cout << endl << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	*/
/*	int sumOfarow = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sumOfarow += arr[i][j];
			if (i == j)
			{
				arr[i][j] = sumOfarow;
			}
		}
		sumOfarow = 0;
	}
	*/
	int sumOfarow = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sumOfarow += arr[i][j];
		}
		for (int j = 0; j < COLS; j++)
		{
			if (i == j)
			{
				arr[i][j] = sumOfarow;
			}
		}
		//arr[i][i] = sumOfarow;
		sumOfarow = 0;
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}
