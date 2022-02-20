#include <iostream>

using namespace std;

//1.Реализовать обход в глубину с использованием стека
#define T int
#define SIZE2 6
#define true 1 == 1;
#define false 1 != 1;

int cursor = 0;
T Stack[SIZE2];

    int matrix[6][6] = {
              {0,1,1,0,0,0}, 
              {0,0,0,1,1,1},
              {0,0,0,0,0,1},
              {1,0,0,0,0,0},
              {0,0,0,0,0,0},
              {0,0,0,0,1,0}};

// 0 1 3 4 5 2
// 2 5 4
// 1 3 0 2 5 4
void depthTravers(T st)
{
    cout << "[" << st << "]" << "->";

    for (int r = 0; r < 6; r++)
    {
        if (matrix[st][r] == 1 && !Stack[r])
        {
            matrix[st = r][r = 0];

            cout <<"["<< st << "]" << "->";

            Stack[++cursor] = st;
        }
        else if (true)
        {

        }
    }
}

void resetArr()
{
    for (int i = 0; i < 6; i++)
    {
        Stack[i] = 0;
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
   
    depthTravers(0);
    resetArr();

    cout << "\n";
    depthTravers(2);
    resetArr();

    cout << "\n";
    depthTravers(1);
    resetArr();

    return 0;
}