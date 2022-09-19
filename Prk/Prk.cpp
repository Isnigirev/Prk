#include <iostream>
#include <vector>

////////////////////////////////////-1-////////////////////////////////////

template <typename T>
void Swap(T* first, T* second)
{
    T*swap = new T(*first); // s = a;
    *first = *second;       // a = b;
    *second = *swap;        // b = s;

    delete swap;
}
////////////////////////////////////-2-////////////////////////////////////

template <typename T>
void SortPointers(std::vector <T *> *vectorsort)
{
    for (int i = 0; i < vectorsort->size(); i++)
    {
        for (int y = i + 1; y < vectorsort->size(); y++)
        {
            if (*vectorsort->at(i) > *vectorsort->at(y))
            {
                T *swap = vectorsort->at(i);
                vectorsort->at(i) = vectorsort->at(y);
                vectorsort->at(y) = swap;
            }
        }
    }
}


int main() {

    //////////////////////////////////-1-////////////////////////////////////
    std::cout << "////////////////////////////////////-1-////////////////////////////////////" << std::endl;
    int a = 5;
    int *first = &a;
    std::cout << "&a-> " << &a <<  "-> " << a << "\t&first - >" << first << "\t - >" << *first << std::endl;

    int b = 3;
    int *second = &b;
    std::cout << "&b-> " << &b << "-> " << b << "\t&second - >" << second << "\t - >" << *second << std::endl;

    Swap(&first, &second);

    std::cout << "&a-> " << &a << "-> " << a << "\t&first - >" << first << "\t - >" << *first << std::endl;
    std::cout << "&b-> " << &b << "-> " << b << "\t&second - >" << second << "\t - >" << *second << std::endl;

    ////////////////////////////////////-2-////////////////////////////////////
    std::cout << "////////////////////////////////////-2-////////////////////////////////////" << std::endl;
    int s = 1;
    int *sort = &s;
    int s1 = 9;
    int* sort1 = &s1;
    int s2 = 1;
    int* sort2 = &s2;

    std::vector <int *> A;
    A.push_back(first);     // -> 3
    A.push_back(second);    // -> 5
    A.push_back(sort);      // -> 1
    A.push_back(sort1);     // -> 9
    A.push_back(sort2);     // -> 1

    for (int i = 0; i < A.size(); i++)
    {
        std::cout << i <<  "-> " << A[i] << " " << *A[i] << std::endl;
    }

    std::cout << "////////////////////////////////////////////////////////////////////////" << std::endl;
    SortPointers(&A);

    for (int i = 0; i < A.size(); i++)
    {
        std::cout << i << "-> " << A[i] << " " << *A[i] << std::endl;
    }

    A.clear();

    return 0;
}