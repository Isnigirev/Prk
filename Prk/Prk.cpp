#include <iostream>
#include "mylib.h"

using namespace std;

#define True(a)\
((a >= 0 && a < 100) ? cout << "true" : cout << "false")

void main()
{
	setlocale(LC_ALL, "ru");

	//1.

	/*const int SIZE = 10;
	float Arr[SIZE]{};

	Space::inicArrtipeFloat(SIZE, Arr);
	Space::printArr(SIZE, Arr);
	Space::summArr(SIZE, Arr);*/

	//2.

	/*Описать макрокоманду (через директиву define), проверяющую, 
	входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля (включительно) до 
	переданного ей второго аргумента (исключительно) и возвращает true или false, 
	вывести на экран «true» или «false».
	*/
	
	int iPress; // 80%
	
	cin >> iPress;
	
	True(iPress);
	
	//3.


}


