#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.h"

using namespace std;

void FillArray(int* arr,int n, int num ) 
{
    for (int i = 0; i < n; i++)
    {
        //возводим число в степень i, число не хардкодим
        arr[i] = pow(num, i);
        cout << arr[i] << " ";
    }
}


void FreeMemory(int* arr) {
    delete[] arr;

    //Note to self: нужно делать только если в дальнейшем указатель еще планируется использовать
    arr = nullptr;
}

int main()
{

    int* pArr, n, num;
    num = 2;
    cout << "Enter size of your array: ";
    cin >> n;

    if (n > 0)
    {
        pArr = new (nothrow) int[n];

        if (pArr != nullptr)
        {
            FillArray(pArr, n, num);
            FreeMemory(pArr);

        }
        else
        {
            cout << "Error! Can not allocate memory!";
        }
    }

    cout << endl;

    const size_t m = 4;
    const size_t ns = 4;

    //Вот я и разобрался, как запихнуть new в функцию :)
    int** pArr1 = MemoryAlloc(ns, m);
    MatrixFill(pArr1, ns, m);
    MatrixDelete(pArr1, m);
    cout << endl;

    const size_t size = 115;
    char text[size] = {"The primary thing when you take a sword in your hands is your intention to cut the enemy, whatever the means."};
    char text2[size] = { "If you think only of hitting, springing, striking or touching the enemy, you will not be able actually to cut him." };

    string fName;
    string secondFName;

    cout << "Enter the name for the first file: ";
    cin >> fName;
         fName += ".txt";

    ofstream fout(fName);

            for (char element : text) {
                fout <<element;
            }
            fout.close();

    cout << "Enter the name for the first file: ";
    cin >> secondFName;
           secondFName += ".txt";

    ofstream sfout(secondFName);

            for (char element : text) {
                sfout << element;
            }
            sfout.close();

        return 0;
    
}

