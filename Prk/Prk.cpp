#include <iostream>
#include "mylib.h"

using namespace std;

#define ForLes2(a) \
((a >= 0 && a < 100) ? cout << "true" : cout << "false")

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

//void isortMass3(const int SIZE, int Arr3[])
//{
//	cout << "Массив был в таком виде в момент инициализации пользователем: " << endl;
//	for (int i = 0; i < SIZE; i++)	cout << Arr3[i] << " ";
//	cout << endl;
//
//	int Zero = 0;
//
//	for (int i = 0; i < SIZE-1; i++)
//	{
//		SwapINT(SIZE,Arr3[i],Arr3[i + 1],Zero);
//	}
//
//	cout << "Массив стал таким после сортировки: " << endl;
//	for (int i = 0; i < SIZE; i++)	cout << Arr3[i] << " ";
//	cout << endl;
//}

void main()
{
	setlocale(LC_ALL, "ru");

	//1.

	/*const int SIZE = 10;
	float Arr[SIZE]{};

	forfrstHW::inicArrtipeFloat(SIZE, Arr);
	forfrstHW::printArr(SIZE, Arr);
	forfrstHW::summArr(SIZE, Arr);*/

	//2.

	/*int iPress;
	cin >> iPress;
	ForLes2(iPress);*/
	
	//3.

	//int iArr3[MASS1]{ 10,3,4,1,11 };

	//for (int i = 0; i < MASS1; i++)
	//{
	//	cout << "Введите " << i << " элемент массива" << endl;
	//	cin >> iArr3[i];
	//}

	//isortMass3(MASS1, iArr3);

	//4.




}


