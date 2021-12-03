#include <iostream>
#include "mylib.h"
#include <fstream>

using namespace std;

#define ForLes2(a)((a >= 0 && a < 100) ? cout << "true": cout << "false")

#define MASS1 (5)

#define SwapINT(SIZE,ElemMassfrst,ElemMasstwo,Zero)\
		for (int i = 0; i < SIZE-1; i++)\
		{\
			if (ElemMassfrst>ElemMasstwo)\
			{\
			Zero=ElemMassfrst;\
			ElemMassfrst=ElemMasstwo;\
			ElemMasstwo=Zero;\
			}\
		}

void isortMass3(const int SIZE, int Arr3[])
{
	cout << "Массив был в таком виде в момент инициализации пользователем: " << endl;
	for (int i = 0; i < SIZE; i++)	cout << Arr3[i] << " ";
	cout << endl;

	int Zero = 0;

	for (int i = 0; i < SIZE-1; i++)
	{
		SwapINT(SIZE,Arr3[i],Arr3[i + 1],Zero);
	}

	cout << "Массив стал таким после сортировки: " << endl;
	for (int i = 0; i < SIZE; i++)	cout << Arr3[i] << " ";
	cout << endl;
}

#pragma pack (push,1)
struct Person
{
	string NAME;
	char CLASS;
	int ID;
	float SELL;
};
#pragma pack (pop)

void main()
{
	setlocale(LC_ALL, "ru");

	//1.

	const int SIZE = 10;
	float Arr[SIZE]{};

	forfrstHW::inicArrtipeFloat(SIZE, Arr);
	forfrstHW::printArr(SIZE, Arr);
	forfrstHW::summArr(SIZE, Arr);

	//2.
	
	cout << "Введите число в диапазоне от 0 (включительно) до 100: " << endl;
	int iPress;
	bool tru = true;
	cin >> iPress;
	ForLes2(iPress);

	//3.
	cout << endl;
	int iArr3[MASS1]{};

	for (int i = 0; i < MASS1; i++)
	{
		cout << "Введите " << i << " элемент массива" << endl;
		cin >> iArr3[i];
	}

	isortMass3(MASS1, iArr3);

	//4.

	Person *one = new Person;
	one->NAME = "Frstperson";
	one->CLASS = 'A';
	one->ID = 12500147;
	one->SELL = 35.000f;

	cout << one << " Переменная занимает памяти: " << sizeof(one);

	ofstream file1;
	file1.open("File1.txt");
	file1.is_open();

	if (!file1.is_open())
	{
		cout << "error open file1" << endl;
	}
	else
	{
		file1 << one->NAME << endl
			  <<"His age person: " << one->CLASS << endl
			  <<"His id person: " << one->ID << endl
			  <<"His sell person: " << one->SELL << endl;
	}
	file1.close();
	delete one;
}