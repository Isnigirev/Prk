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
	int iSize = 3;
	char PL, PC;
	char** cArr = new char* [iSize];
	int iTimer, iWinSize = 3, getWin;
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
int getWin(int iSize, char** cArr, char One, int iWinSize)
{
	for (int y = 0; y < iSize; y++)
	{
		int getWin = 0;
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
		if (getWin == iWinSize)
			return getWin;
	}
	//|!^
	for (int x = 0; x < iSize; x++)
	{
		int getWin = 0;

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
		if (getWin == iWinSize)
			return getWin;
	}
	//-|!^
	for (int x = 0; x < iSize; x++)
	{
		int getWin = 0;

		for (int y = 0; y < iSize; y++)
		{
			if (cArr[y][x] == One)
			{
				for (int i = 0; i < iSize-y; i++)
				{
					if (cArr[y][x] == cArr[y + 1][x + 1])
					{
						getWin++;
						cArr[y + 1][x + 1]; //?
					}
					else
					{
						getWin = 0;
					}
				}
			}
			else
			{
				getWin = 0;
			}
		}
		if (getWin == iWinSize)
			return getWin;
	}
	//-|^

	for (int x = 0; x < iSize; x++)
	{
		int getWin = 0;

		for (int y = 0; y < iSize; y++)
		{
			if (cArr[y][x] == One)
			{
				for (int i = iSize; 0 < iSize - y; i--)
				{
					if (cArr[y][x] == cArr[y - 1][x + 1]) //test
					{
						getWin++;
						cArr[y - 1][x - 1];
					}
					else
					{
						getWin = 0;
					}
				}
			}
			else
			{
				getWin = 0;
			}
		}
		if (getWin == iWinSize)
			return getWin;
	}



}
void main()
{
	Game g;
	inicArr(g.iSize, g.cArr);
	seeArr (g.iSize, g.cArr);
	srand(time(NULL));

	cout << "Выберите фигуру: " << endl
		 << "x или O (английская раскладка)" << endl;
	cin >> g.PL;
	if (g.PL != 'x' || g.PL != 'X' || g.PL != 'O', g.PL != 'o')
	{
		cout << "Вы выбрали недопустимую фигуру...." << endl;
	}
	else
	{
		(g.PL == 'x' || g.PL == 'X') ? g.PL = fg::X, g.PC = fg::O : g.PL = fg::O, g.PC = fg::X;

		do
		{
			if (g.iTimer % 2 == 0)
			{
				g.PL = fg::O;
				g.cArr[0][0] = g.PL; g.cArr[1][1] = g.PL; g.cArr[2][2] = g.PL;
				g.getWin = getWin(g.iSize, g.cArr, g.PL, g.iWinSize);
			}
			else
			{

			}
			if (g.iTimer == g.iSize)


				cout << "\033[2J\033[1;1H";
			g.iTimer++;

		} while (!g.getWin);

		/*for (int y = 0; y < g.iSize; y++)
		{
			delete [] g.cArr [y];
		}
		delete[] g.cArr;*/

	}
	
}