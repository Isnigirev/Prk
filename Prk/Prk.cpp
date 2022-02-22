#include <iostream>

using namespace std;

//1.//////////////////////////////////
//Реализовать обход в глубину с использованием стека
#define T int
#define SIZE2 6
#define true 1 == 1;
#define false 1 != 1;
typedef int boolean;

int cursor = 0;
T Stack[SIZE2];

int matrix[SIZE2][SIZE2] = {
          {0,1,1,0,0,0},
          {0,0,0,1,1,1},
          {0,0,0,0,0,1},
          {1,0,0,0,0,0},
          {0,0,0,0,0,0},
          {0,0,0,0,1,0}};

void depthTravers(T st)
{
    int r;

    cout << st;

    Stack[st] = 1;

    for (int r = 0; r < SIZE2; ++r)
    {
        if (matrix[st][r] == 1 && !Stack[r])
        {
            cout << "->";
            depthTravers (r);
        }
    }
}
//1.//////////////////////////////////


void resetStack()
{
    for (int i = 0; i < SIZE2; i++)
    {
        Stack[i] = 0;
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
//1.//////////////////////////////////
    depthTravers(0);
    resetStack();

    cout << "\n";
    depthTravers(3);
    resetStack();

    cout << "\n";
    depthTravers(1);
    resetStack();
//1.//////////////////////////////////



    return 0;
}