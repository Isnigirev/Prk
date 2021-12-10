#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
using namespace std;
//==================================================================================================

enum fg :char
{
	_ = '_',
	X = 'X',
	O = 'O',
};
struct Coord
{
	int y;
	int x;
};
#pragma pack (push,1)
struct Game
{
	int iSize = 3;
	char PL, PC;
	char** cArr = new char* [iSize];
	int iTimer;
	char iWin = 'W', iW = 'W';
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
void dellcArr(int iSize, char** cArr)
{
	for (int y = 0; y < iSize; y++)
	{
		delete[] cArr[y];
	}
	delete[] cArr;
}
void seeArr(int iSize, char** cArr)
{
	cout << "   ";
	for (int x = 0; x < iSize; x++)
	{
		cout << x + 1 << " ";
	}

	cout << endl;

	for (int y = 0; y < iSize; y++)
	{
		cout << " " << y + 1 << "|";

		for (int x = 0; x < iSize; x++)
		{
			cout << cArr[y][x] << "|";
		}
		cout << endl;
	}
}
int getWin(int iSize, char** cArr, char One, char cW = '_')
{
	int getWin = 0;

	for (int y = 0; y < iSize; y++)
	{
	//Вправо
		for (int x = 0; x < iSize; x++)
		{
			if (cArr[y][x]== One)
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
			return One;
		}
	}
	//Вниз
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
			return One;
		}
	}
	//Вниз и вправо
	for (int x = 0; x < iSize; x++)
	{
		for (int y = 0; y < iSize; y++)
		{
			if (cArr[y][x] == One)
			{
				for (int y1 = 0, x1 = 0; y1 < iSize - y; y1++, x1++)
				{
					if (cArr[y1][x1] == One)
					{
						getWin++;
					}
					else
					{
						getWin = 0;
						break;
					}
				}
			}
			if (getWin >= iSize)
			{
			return One;
			}
			else
			{
				getWin = 0;
			}
		}
		
	}
	//Вверх и вправо
	for (int y = iSize - 1; y >= 0; y--)
	{
		for (int x = iSize - 1; x >= 0; x--)
		{
			if (cArr[y][x] == One)
			{
				for (int y1 = y, x1 = x; y1 + 1 > 0; x1++,y1--)
				{
					if (cArr[y1][x1] == One)
					{
						getWin++;
					}
					else
					{
						getWin = 0;
						break;
					}
				}
			}
			if (getWin >= iSize)
			{
				return One;
			}
			else
			{
				getWin = 0;
			}
		}
	}
	return cW;
}
int getNch(int iSize, char** cArr, char One, char cW = '_')
{	
	int igetNch = 0;

	for (int y = 0; y < iSize; y++)
	{
		for (int x = 0; x < iSize; x++)
		{
			if (cArr[y][x] == fg::_)
				igetNch++;
		}
	}
	if (igetNch > 0)
	{
		return cW;
	}
	else
	{
		return 'Nch';
	}
}

Coord turnPL(Game g)
{
	Coord c;
	cout << "Введите нужную клетку куда Вы хотите поставить фигуру: " << endl
		 << "(подсказка-->) вводите через пробел (1-у 2-х)" << endl;
	do {
	cin >> c.y >> c.x;
	c.y--, c.x--;
	if (g.cArr[c.y][c.x] != fg::_)
		cout << "Вы ввели занятую координату" << endl;
	} while (c.y >= g.iSize || c.x >= g.iSize || g.cArr[c.y][c.x] != fg::_);
	return c;
}
Coord turnPC(Game g)
{
	Coord c;
	//Для логики
	for (int y = 0; y < g.iSize; y++)
	{
		for (int x = 0; x < g.iSize; x++)
		{
			if (g.cArr[y][x] == fg::_)
			{
				g.cArr[y][x] = g.PC;
				if (getWin(g.iSize,g.cArr, g.PC) == g.PC)
				{
					g.cArr[y][x] = fg::_;
					return {y,x};
				}
				g.cArr[y][x] = fg::_;
			}
		}
	}

	for (int y = 0; y < g.iSize; y++)
	{
		for (int x = 0; x < g.iSize; x++)
		{
			if (g.cArr[y][x] == fg::_)
			{
				g.cArr[y][x] = g.PL;
				if (getWin(g.iSize, g.cArr, g.PL) == g.PL)
				{
					g.cArr[y][x] = fg::_;
					return { y,x };
				}
				g.cArr[y][x] = fg::_;
			}
		}
	}

	// Для первого хода
	srand(time(NULL));
	do
	{
		c.y = rand() % g.iSize;
		c.x = rand() % g.iSize;
		g.cArr[c.y][c.x];

	} while (g.cArr[c.y][c.x] != fg::_);

	return c;

	Coord buf[4];
	int ib{ 0 };
	if (g.cArr[0][0] == fg::_)
	{
		buf[ib] = { 0,0 };
		ib++;
	}
	else if (g.cArr[g.iSize-1][g.iSize - 1] == fg::_)
	{
		buf[ib] = { g.iSize - 1, g.iSize - 1};
		ib++;
	}
	else if (g.cArr[0][g.iSize - 1] == fg::_)
	{
		buf[ib] = { 0, g.iSize - 1 };
		ib++;
	}
	else if (g.cArr[0][g.iSize - 1] == fg::_)
	{
		buf[ib] = { g.iSize - 1, 0 };
		ib++;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	Game g;
	
	cout << "Введите нужное поле (по умолчанию инициализируется 3х3): " << endl
		 << "(должно быть от 2 и более)" << endl;
	do
	{
	cin >> g.iSize;

	if (g.iSize < 2 || g.iSize > 6)
		cout << "Вы ввели недопустимое поле (должно быть от 2 до 6)" << endl;
	} while (g.iSize < 2 || g.iSize > 6);
	
	inicArr(g.iSize, g.cArr);

	cout << "Выберите фигуру: " << endl
		 << "x или O (английская раскладка)" << endl;
	cin >> g.PL;
	if (g.PL == 'X' || g.PL == 'x')
	{
		g.PL = fg::X;
		g.PC = fg::O;
	}
	else if (g.PL == 'O' || g.PL == 'o')
	{
		g.PL = fg::O;
		g.PC = fg::X;
	}
	else
	{
		cout << "Вы выбрали не верный символ.... " << endl;
		return 0;
	}
	
	do
	{	
		seeArr (g.iSize, g.cArr);

		if (g.iTimer % 2 == 0)
		{
			//g.cArr[0][4] = g.PL, g.cArr[1][3] = g.PL, g.cArr[2][2] = g.PL, g.cArr[3][1] = g.PL, g.cArr[4][0] = g.PL;
			Coord c = turnPL(g);
			g.cArr[c.y][c.x] = g.PL;
			g.iW = getWin(g.iSize, g.cArr, g.PL, g.iW);
		}
		else
		{
			Coord c = turnPC(g);
			g.cArr[c.y][c.x] = g.PC;
			g.iW = getWin(g.iSize,g.cArr, g.PC,g.iW);
		}

		cout << "\033[2J\033[1;1H";
		
		g.iTimer++;

		g.iW = getNch(g.iSize, g.cArr, g.PC, g.iW);

	} while (g.iWin == g.iW);
	
	cout << "Выйграла: " << g.iW << endl;

	dellcArr(g.iSize, g.cArr);

	return 0;
}