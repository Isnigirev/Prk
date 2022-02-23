#include <iostream>

using namespace std;

//1.//////////////////////////////////

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

//2.//////////////////////////////////
typedef struct {
    struct TwoLinkNode* head;
    struct TwoLinkNode* tail;
    int size;
} TwoLinkList;

void initTwoLinkList(TwoLinkList* lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode* next;
    struct TwoLinkNode* prev;
} TwoLinkNode;

boolean TwoLinkEnqueue(TwoLinkList* queue, T value) {
    TwoLinkNode* tmp = (TwoLinkNode*)malloc(sizeof(TwoLinkNode));
    if (tmp == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL) {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL) {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
}

T TwoLinkDequeue(TwoLinkList* queue) {
    if (queue->size == 0) {
        printf("Queue is empty \n");
        return -1;
    }
    TwoLinkNode* tmp = queue->head;
    T data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail) {
        queue->tail = NULL;
    }

    free(tmp);
    queue->size--;
    return data;
}

int SimpleGraph[SIZE2][SIZE2] = {
          {0,1,0,0,0,0},
          {0,0,1,0,0,0},
          {0,0,0,1,0,0},
          {0,0,0,0,1,0},
          {0,0,0,0,0,1},
          {0,0,0,0,0,0}};

int get2dInt(int row, int col)
{
    matrix[SIZE2][SIZE2];

    return matrix[row][col];
}

//////////////////////////////////////

int Counter = 0;

void DepthTraversGraph(T start, int indx, int& Counter)
{
    int r;

    for (int r = 0; r < SIZE2; ++r)
    {
        if (start == indx && matrix[start][r] == 1)
        {
            Stack[r] = 1;
            Counter++;
        }
        if (matrix[start][r] == 1 && !Stack[r])
        {
            DepthTraversGraph(r, indx, Counter);
        }
    }
}

int StackIsFull()
{
    int counter;

    for (int i = 0; i < SIZE2; i++)
    {
        if (Stack[i] == 0)
        {
            return 0;
        }
    }

    return 1;
}

void DepthTraversSimpleGraph(T start)
{
    int r;

    for (int r = 0; r < SIZE2; ++r)
    {
        if (matrix[start][r] == 1)
        {
            Stack[start] += 1;
        }
        if (matrix[start][r] == 1 &&!Stack[r])
        {
            DepthTraversSimpleGraph(r);
        }
        if (StackIsFull() == 1)
        {
            return;
        }
    }
}

void WidthTraversSimpleGraph(int start)
{
    TwoLinkList* queue = (TwoLinkList*)malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    TwoLinkEnqueue(queue, start);

    while (queue->size > 0)
    {
        int indx = TwoLinkDequeue(queue);
        if (Stack[indx] == 1) continue;

        for (int i = 0; i < SIZE2; ++i)
        {
            if (get2dInt(indx, i) == 1)
            {
                Stack[indx] += 1;
                TwoLinkEnqueue(queue, i);
            }
            if (Stack[SIZE2-1] > 0)
            {
                return;
            }
        }
    }
}

// 0-2
// 1-3
// 2-1
// 3-1
// 4-0
// 5-1



void StackPop()
{
    int CounterForStackPop = 0, Counter = 0;

    for (int i = 0; Counter < SIZE2; i++)
    {
        if (Stack[i] == Counter)
        {
            cout << "c " << i << "->" << Stack[i] << " смежных вершин\n";
            CounterForStackPop++;
        }
        if (i == SIZE2 - 1)
        {
            Counter++;
            i = 0;
        }
        if (CounterForStackPop == SIZE2 - 1)
        {
            break;
        }
    }
}

//////////////////////////////////////

int main()
{
    setlocale(LC_ALL, "Ru");
//1.//////////////////////////////////
    cout << "1.\n";
    depthTravers(0);
    resetStack();

    cout << "\n";
    depthTravers(3);
    resetStack();

    cout << "\n";
    depthTravers(1);
    resetStack();
//1.//////////////////////////////////

//2.//////////////////////////////////
    cout << "\n2.\n";
    // << "с циклическими связями. Нужно обойти этот граф двумя способами";
    // "и подсчитать количество ссылок на каждый из узлов графа (полустепень захода).";
   
    cout << "Обход в ширину\n";
    resetStack();
    WidthTraversSimpleGraph(0);
    StackPop();

    cout << "Обход в глубину\n";
    resetStack();
    DepthTraversSimpleGraph(0);
    StackPop();

    cout << "Обход графа рекурсивной функцией\n(с подсчётом только смежных со стартовой вершин)\n";   
    for (int i = 0; i < SIZE2; i++)
    {
        resetStack();
        DepthTraversGraph(i, i, Counter = 0);
        cout << "Всего смежных величи со стартовой величин " << i << "->" << Counter << "\n";
    }

    return 0;
}