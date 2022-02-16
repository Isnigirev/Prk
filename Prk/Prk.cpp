#include <iostream>

//1. Описать очередь с приоритетным исключением
#define SIZE1 10

typedef struct
{
    int iPr;
    int iDat;
}Node;

Node* Arr[SIZE1];
int iHead;
int iTail;
int iItems;

void INIT()
{
    for (int i = 0; i < SIZE1; ++i)
    {
        Arr[i] = nullptr;
    }
    iHead = 0;
    iTail = 0;
    iItems = 0;
}

void INS(int iPr, int iDat)
{
    Node *node = (Node*) malloc(sizeof(Node));

    node->iDat = iDat;
    node->iPr = iPr;

    int iFlag;

    if (iItems == 0)
    {
        Arr[iTail++] = node;
        iItems++;
    }
    else if (iItems == SIZE1)
    {
        std::cout << "Очередь заполнена" << std::endl;
        return;
    }
    else
    {
        int iI = 0;
        int iIdx = 0;
        Node* tmp;
        for (iI = iHead; iI < iTail; ++iI)
        {
            iIdx = iI % SIZE1;

            if (Arr[iIdx]->iPr > iPr)
            {
                break;
            }
            else
            {
                iIdx++;
            }
        }
        iFlag = iIdx % SIZE1;
        iI++;

        while (iI <= iTail)
        {
            iIdx = iI % SIZE1;

            tmp = Arr[iIdx];

            Arr[iIdx] = Arr[iFlag];

            Arr[iFlag] = tmp;

            iI++;
        }
        Arr[iFlag] = node;
        iItems++;
        iTail++;
    }
}

Node* rem()
{
    if (iItems == 0)
    {
        return nullptr;
    }
    else
    {
        int iIdx = iHead++ % SIZE1;
        Node* tmp = Arr[iIdx];
        Arr[iIdx] = nullptr;
        iItems--;
        return tmp;
    }
}

void PQ()
{
    std::cout << "[ ";
    for (int i = 0; i < SIZE1; i++)
    {
        if (Arr[i] == nullptr)
        {
            std::cout << "[*, *] ";
        }
        else
        {
            std::cout << "[" << Arr[i]->iPr << ", " << Arr[i]->iDat << "]";
        }
    }
    std::cout << " ]\t";
}

//2 Реализовать перевод из десятичной в двоичную систему счисления 
//с использованием стека.
#define T int
#define SIZE2 1000
#define true 1 == 1;
#define false 1 != 1;

typedef int boolean;

int cursor = -1;
T Stack[SIZE2];


boolean push(T data)
{

    if (cursor < SIZE2)
    {
        Stack[++cursor] = data;
        return true;
    }
    else
    {
        std::cout << " Стэк переполен! " << std::endl;
        return false;
    }
}

int Rec1(int a)
{
    if (a == 0)
    {
        return 0;
    }

    Rec1(a / 2);

    std::cout << (a % 2);
}

T pop()
{
    if (cursor != -1)
    {
        Rec1(Stack[cursor]);
        std::cout << "<- ";
        return Stack[cursor--];
    }
    else
    {
        std::cout << " Стэк пуст " << std::endl;
        return -1;
    }

}


int main()
{
    setlocale(LC_ALL, "Ru");
   
    INIT();

    INS(1, 16);
    INS(2, 12);
    INS(1, 11);
    INS(2, 65);
    INS(3, 88);
    INS(4, 22);
    INS(5, 82);
    INS(3, 12);
    INS(4, 85);
    INS(6, 64);

    PQ();
    std::cout << std::endl;

    for (int i = 0; i < 7; i++)
    {
        Node *n = rem();
        std::cout << n->iPr << ", " << n->iDat << ", ";
    }

    std::cout << std::endl;
    PQ();

    INS(1, 12);
    INS(3, 85);
    INS(2, 64);

    std::cout << std::endl;
    PQ();


    push(8);   // 1000
    push(2);   // 10
    push(5);   // 101
    push(9);   // 1001
    push(1);   // 1
    std::cout << std::endl;
    while (cursor != -1)
    {
        std::cout << pop() << ", ";
    }

    return 0;
}