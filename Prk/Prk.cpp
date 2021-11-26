#include <iostream>

using namespace std;

bool les5(int iArr5[], const int SIZE5)
{
	int SUMM1 = 0,
		SUMM2 = 0,
		c = SIZE5-1;


	for (int i = 1; i < SIZE5; i++, c--)
	{
		SUMM1 += iArr5[i];

		if (i + 1 != c)
		{
			SUMM2 += iArr5[c];
		}
		else
			break;

	}

	if (SUMM1==SUMM2)
	{
		cout << SUMM1 << " = " << SUMM2 << "-true, checkBalance" << endl;
		return "true";
	}
	else
	{	
		cout << SUMM1 << " не = " << SUMM2 << "-false, checkBalance" << endl;
		return "false";
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	const int SIZE5 = 6;

	int iArr5[SIZE5]{ 1, 2, 3, 1, 1,1 };

	les5 (iArr5, SIZE5);

	return 0;
}


