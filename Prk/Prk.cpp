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

		for (int x = 0; x < iSize; x++)
		{
			if (cArr[y][x]==One)
			{
				getWin++;
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

	do
	{
		if (g.iTimer%2==0)
		{
			g.PL = fg::O;
			g.cArr[1][0] = g.PL; g.cArr[1][1] = g.PL; g.cArr[1][2] = g.PL;
		}
		else
		{

		}
		if (g.iTimer==g.iSize)
			getWin (g.iSize, g.cArr, g.PL, g.iWinSize);

		cout << "\033[2J\033[1;1H";
		g.iTimer++;

	} while (g.getWin==g.iWinSize);

	for (int y = 0; y < g.iSize; y++)
	{
		delete [] g.cArr [y];
	}
	delete[] g.cArr;
}