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
			cout << Arr[i] << endl;
		}
		cout << endl;
	}

	void summArr(const int SIZE, float Arr[])
	{
		float fSumm = 0,
			fNegsumm = 0;

		for (size_t i = 0; i < SIZE; i++)
		{
			(Arr[i] >= 0) ? fSumm += i : fNegsumm -= i; //test
		}

		cout << "Ñóììà ïîëîæèòåëüíûõ ÷èñåë: " << fSumm << ", "
			<< "Ñóììà îòðèöàòåëüíûõ ÷èñåë: " << fNegsumm << endl;
	}
}
