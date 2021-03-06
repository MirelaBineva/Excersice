// zad2_test.cpp : Defines the entry point for the console application.
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
	//B)
	for (int i = 0; i < ROWS; i++)
	{
		cout << "{ ";
		for (int j = 0; j < COLS; j++)
		{
			if (j == COLS - 1)
			{
				cout << arr[i][j];
			}
			else
				cout << arr[i][j] << " , " << "\t";
		}
		if (i == ROWS - 1)
		{
			cout << "} ";
			cout << endl;
		}
		else
		{
			cout << "}, ";
			cout << endl;
		}
	}
	//C) Elementi po koloni
	cout << endl << endl;
	for (int i = 0; i < COLS; i++)
	{
		cout << "[ ";
		for (int j = 0; j < ROWS; j++)
		{
			if (j == ROWS - 1)
			{
				cout << arr[j][i];
			}
			else
			{
				cout << arr[j][i] << "," << "\t";
			}
		}
		if (i == COLS - 1)
		{
			cout << "]";
			cout << endl;
		}
		else
		{
			cout << "],";
			cout << endl;
		}
	}
	//D.	Да се отпечатат елементите по главния диагонал;
	cout << endl;
	unsigned int min = ROWS<COLS ? ROWS : COLS;
	cout << "Glaven: ";
	for (unsigned int i = 0; i<min; ++i)
		cout << arr[i][i] << "\t";
	cout << endl;
	//E.	Да се отпечатат елементите по вторичния диагонал;
	cout << endl;
	cout << "Vtorichen: ";
	for (unsigned int i = 0; i<min; ++i)
		cout << arr[i][min - 1 - i] << "\t";
	cout << endl;
	//pod i nad osnovniq
	//pod
	cout << endl;
	cout << "Pod osnoven: ";
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << arr[i][j] << " ";
		}
	}
	cout << endl << endl;
	//nad
	cout << "Nad osnoven: ";
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = COLS - 1; j > i; --j)
		{
			cout << arr[i][j] << " ";
		}
	}
	//pod i nad vtorichen
	cout << endl << "Pod vtorichen: ";
	for (int i = 1; i < ROWS; i++)
	{
		for (int j = COLS - i; j < COLS; j++)
		{
			cout << arr[i][j] << " ";
		}
	}
	cout << endl << "Nad vtorichen: ";
	for (int i = 0; i < ROWS - 1; i++)
	{
		for (int j = 0; j < COLS - i - 1; j++)
		{
			cout << arr[i][j] << " ";
		}
	}
	//F.	Да се намери максималния елемент в масива;
	cout << endl;
	int max = arr[0][0];
	unsigned int mrow = 0, mcol = 0;
	for (unsigned int i = 0; i < ROWS; ++i) {
		for (unsigned int j = 0; j < COLS; ++j) {
			if (arr[i][j]>max) {
				max = arr[i][j];
				mrow = i;
				mcol = j;
			}
		}
	}
	cout << "In the array the max element is "
		<< max << " and the row is " << mrow + 1
		<< " and the column is " << mcol + 1
		<< endl;
	//G.	Да се намери минималния елемент на масива;
	cout << endl;
	int minEl = arr[0][1];
	unsigned int minRow = 0, minCol = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] < minEl)
			{
				minEl = arr[i][j];
				minRow = i ;
				minCol = j ;
			}
		}
	}
	cout << "Min el: " << minEl << " Col: " << minCol + 1 << " Row: " << minRow + 1 << endl;
	//H.	Да се дефинира нов едномерен масив, в който да се съхранят максимумите по редове;
	cout << endl;
	int arrMaxRow[ROWS];
	for (int i = 0; i < ROWS; ++i)
	{
		arrMaxRow[i] = arr[i][0];
		for (int j = 1; j < COLS; ++j)
		{
			if (arrMaxRow[i]<arr[i][j])
				arrMaxRow[i] = arr[i][j];
		}
	}
	cout << "Max elements by rows are : ";
	for (int i = 0; i < ROWS; ++i) 
	{
		cout << arrMaxRow[i] << "\t";
	}
	cout << endl;
	//I.	Да се дефинира нов едномерен масив, в който да се съхранят минимумите по колони
/*	int arrMinCol[COLS];
	for (int i = 0; i < COLS; i++)
	{
		arrMinCol[i] = arr[i][0];
		for (int j = 1; j < ROWS; j++)
		{
			if (arrMinCol[i] >= arr[j][i])
			{
				arrMinCol[i] = arr[j][i];
			}
		}
	}
	cout << "Min elements by cols are: ";
	for (int i = 0; i < COLS; i++)
	{
		cout << arrMinCol[i] << "\t";
	}
	cout << endl;
	*/
	//J.	Да се намери максималната сума по колони на масива;
	int arrSumCol[COLS] = { 0 };
	for (int i = 0; i < COLS; ++i) {
		for (int j = 0; j < ROWS; ++j)
		{
			arrSumCol[i] += arr[j][i];
		}
	}
	int maxSumCol = arrSumCol[0];
	for (int i = 1; i < COLS; ++i)
	{
		if (maxSumCol < arrSumCol[i])
			maxSumCol = arrSumCol[i];
	}

	cout << "Max sum by columns is " << maxSumCol << endl;
	//K.Да се намери минималната сума по редове на масива;
	int arrSumRow[ROWS] = { 0 };
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arrSumRow[i] += arr[i][j];
		}
	}
	int minSumRow = arrSumRow[0];
	for (int i = 1; i < ROWS; i++)
	{
		if (minSumRow > arrSumRow[i])
			minSumRow = arrSumRow[i];
	}
	cout << "Min sum by rows is: " << minSumRow << endl;
	//L.	Да се заменят елементите на масива със сбора от индексите на елемента;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = i + j;
		}
	}
	//M.	Да се замени всеки четен елемент на масива с квадрата на номера на реда, в който се намира;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = i*i;
		}
	}
	//N.	Ако елемент от масива, съвпада с произведението от индексите му, то той да се замени със средната стойност на реда, в който се намира;

	//масив за средните стойности по редове
	double arrAvgByRow[ROWS] = { 0 };
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arrAvgByRow[i] += arr[i][j];
		}
		arrAvgByRow[i] /= ROWS;
	}

	//извършване на замяната
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] == i*j)
				arr[i][j] = arrAvgByRow[i];
		}
	}
	//O.	Да се изброят броя на цифрите, които съставят елементите на масива;
	unsigned int cntDigets = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] == 0)
				cntDigets++;
			else
				cntDigets += log10(arr[i][j]) + 1;
		}
	}
	cout << "The number of digits of the elments of the array are: " << cntDigets << endl;

	//P.	Ако елемент на масива е над средната стойност на масива, то той да се замени с минимума на масива;
	int arrAvg = 0, minElem = arr[0][0];
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
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	//	Q.Всички елементи по главния диагонал на масива, да се заменят със сума от елементите от съответния ред;
	cout << endl;
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


  
