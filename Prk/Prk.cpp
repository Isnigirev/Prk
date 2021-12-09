#include <iostream>
#include <ctime>
#include <string>

using namespace std;
//==================================================================================================

enum fg :char
{
	_ = '_',
	X = 'X',
	O = 'O',
};
#pragma pack (push,1)
struct Game
{
	int iSize = 5, y = 0,x = 0;
	char PL, PC;
	char** cArr = new char* [iSize];
	int iTimer;
};
#pragma pack (pop)

void inicArr(int iSize, char** cArr)
{
	for (int y = 0; y < iSize; y++)
		cArr[y] = new char[iSize];

	for (int y = 0; y < iSize; y++)
	{
		for (int x = 0; x < iSize; x++)
		{
			cArr[y][x] = fg::_;
		}
	}
}
void seeArr(int iSize, char** cArr)
{
	for (int y = 0; y < iSize; y++)
	{
		for (int x = 0; x < iSize; x++)
		{
			cout << "|" << cArr[y][x];
		}
		cout << endl;
	}
}
int getWin(int iSize, char** cArr, char One)
{
	int getWin = 0;

	for (int y = 0; y < iSize; y++)
	{
	//-->
		for (int x = 0; x < iSize; x++)
		{
			if (cArr[y][x]==One)
			{
				getWin++;
			}
			else
			{
				getWin = 0;
			}
		}
		if (getWin >= iSize)
		{
			return getWin;
			break;
		}
	}
	//|
	for (int x = 0; x < iSize; x++)
	{
		for (int y = 0; y < iSize; y++)
		{
			if (cArr[y][x] == One)
			{
				getWin++;
			}
			else
			{
				getWin = 0;
			}
		}
		if (getWin >= iSize)
		{
			return getWin;
			break;
		}
	}
	//-|
	for (int x = 0; x < iSize; x++)
	{
		for (int y = 0; y < iSize; y++)
		{
			if (cArr[y][x] == One)
			{
				for (int i = 0; i < iSize-1; i++)
				{
					if (cArr[y][x] == One)
					{
						getWin++;
						cArr[y + 1][x + 1];
					}
				}
			}
			if (getWin >= iSize)
			{
			return getWin;
			break;
			}
			else
			{
				getWin = 0;
			}
		}
		
	}
	//-|
	for (int y = iSize - 1; y >= 0; y--)
	{
		for (int x = iSize - 1; x >= 0; x--)
		{
			if (cArr[y][x] == One)
			{
				for (int i = 0; i < iSize; i++)
				{
					if (cArr[y][x] == One)
					{
						getWin++;
						cArr[y - 1][x + 1];
					}
				}
			}
			if (getWin >= iSize)
			{
				return getWin;
				break;
			}
			else
			{
				getWin = 0;
			}
		}
	}
}
int getCoorPL(int n, int iSize)
{
	cout << "Введите нужную клетку куда Вы хотите поставить фигуру: " << endl
		 << "(подсказка-->) Вы вводите" << n << "координату" << endl;
	cin >> n;
	n--;

	if ( n >  iSize)
	{
		cout << "Вы введи не верные координаты.... нужно ввести число не превышающее: "
			 << iSize - 1 << endl;
		cin >> n;
		n--;
		return n;
	}
	else
	{
		return n;
	}
}

void main()
{
	setlocale(LC_ALL, "ru");
	Game g;
	inicArr(g.iSize, g.cArr);
	
	srand(time(NULL));

	cout << "Выберите фигуру: " << endl
		 << "x или O (английская раскладка)" << endl;

	//cin >> g.PL;
	g.PL = fg::O;//delete
	(g.PL == 'X' || g.PL == 'x') ? g.PL = fg::X, g.PC = fg::O : g.PL = fg::O, g.PC = fg::X;

	do
	{	
		seeArr (g.iSize, g.cArr);
		
		if (g.iTimer % 2 == 0)
		{
			g.cArr[g.y = getCoorPL(g.y, g.iSize)][g.x = getCoorPL(g.x, g.iSize)] ;//?
			g.cArr[g.y][g.x] = g.PL;
			g.PL = getWin(g.iSize, g.cArr, g.PL);
		}
		else
		{

		}

		cout << "\033[2J\033[1;1H";
		g.PL = getWin(g.iSize, g.cArr, g.PL);
		g.iTimer++;

	} while (g.PL != g.iSize);

	for (int y = 0; y < g.iSize; y++)
	{
		delete [] g.cArr [y];
	}
	delete[] g.cArr;
}