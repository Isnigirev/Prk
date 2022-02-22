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

int Counter;

//0->1
//0->3->4->5
//0->2
//обход графа рекурсивной функцией(с подсчётом только смежных 
//со стартовой вершин)

void DepthTraversSimpleGraph(T st)
{
    int r;

    cout << st;

    Stack[st] = 1;

    for (int r = 0; r < SIZE2; ++r)
    {
        if (matrix[st][r] == 1 && !Stack[r])
        {
            cout << "->";
            DepthTraversSimpleGraph(r);
        }
    }
}

void WidthTraversSimpleGraph(int start)
{
    TwoLinkList * queue = (TwoLinkList*)malloc(sizeof(TwoLinkList));
    initTwoLinkList(queue);
    TwoLinkEnqueue(queue, start);

    while (queue->size > 0)
    {
        int indx = TwoLinkDequeue(queue);
        if (Stack[indx] == 1) continue;
        Stack[indx] = 1;
        cout << indx;
        for (int i = 0; i < SIZE2; ++i)
        {
            if (get2dInt(indx, i) == 1 && Stack[i] == 0)
            {
                TwoLinkEnqueue(queue, i);
            }
        }
    }
}
//////////////////////////////////////

//обход графа по матрице смежности(с подсчётом всех вершин графа) 
//В конце обхода вывести два получившихся списка всех узлов в порядке уменьшения количества ссылок на них.

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
    //depthTravers(0);
    //resetStack();

    //cout << "\n";
    //depthTravers(0);
    //resetStack();

    //cout << "\n";
    //depthTravers(0);
    //resetStack();
//1.//////////////////////////////////

//2.//////////////////////////////////
    cout << endl; resetStack();
    DepthTraversSimpleGraph(0);
   /* cout << endl;resetStack();
    WidthTraversSimpleGraph(0);
    cout << endl;resetStack();
    WidthTraversSimpleGraph(3);
    cout << endl; resetStack();
    WidthTraversSimpleGraph(1);*/
    return 0;
}