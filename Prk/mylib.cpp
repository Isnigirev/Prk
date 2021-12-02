#include <iostream>
#include <ctime>


using namespace std;
namespace forfrstHW
{
	void inicArrtipeFloat(const int SIZE, float Arr[])
	{
		srand(time(nullptr));
		for (size_t i = 0; i < SIZE; i++)
		{
			Arr[i] = (rand() % 100) - 50;
		}
	}

	void printArr(const int SIZE, float Arr[])
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			cout << printf ("%0.3f",Arr[i]) << endl;
		}
		cout << endl;
	}

	void summArr(const int SIZE, float Arr[])
	{
		float fSumm = 0,
			fNegsumm = 0;

		for (size_t i = 0; i < SIZE; i++)
		{
			(Arr[i] >= 0) ? fSumm += 1 : fNegsumm += 1;
		}

		cout << "Сумма положительный чисел: " << fSumm << ", "
			 << "Сумма отрицательных чисел: " << fNegsumm << endl;
	}


}
