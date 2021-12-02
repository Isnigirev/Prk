#include <iostream>
#include <ctime>


using namespace std;
namespace Space
{
	void inicArrtipeFloat(const int SIZE, float Arr[])
	{
		
		srand(time(nullptr));
		for (size_t i = 0; i < SIZE; i++)
		{	float fRandom = (rand() % 100) - 50;
			Arr[i] = fRandom;
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
			(Arr[i] >= 0) ? fSumm += 1 : fNegsumm += 1; //test
		}

		cout << "pozitiv: " << fSumm << ", "
			<< "negativ: " << fNegsumm << endl;
	}
}
