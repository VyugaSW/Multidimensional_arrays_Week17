
#include <Windows.h>
#include <iostream>

using namespace std;
//Задание 1. Написать функцию, добавляющую столбец
//двухмерному массиву в указанную позицию.

void Task1(int arr[3][3], int s1, int s2, int* string, int index) { //arr*string - новая строка
    int** Newarr = new int*[s1+1];                                  //int arr[3][3] - создал, чтобы не создавать и не 
                                                                    //инициализировать лишний раз дин. массив
    for (int i = 0, j = 0; i < s1 + 1; i++) {
        if (i == index)
            Newarr[i] = string;
        else{
            Newarr[i] = arr[j];
            j++;
        }
    }
    for (int i = 0; i < s1 + 1; i++) {
        for (int j = 0; j < s2; j++) {
            cout << Newarr[i][j] << " ";
        }
        cout << endl;
    }
}

//Задание 2. Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.

void Task2(int arr[3][3], int s1, int s2, int indexDel) { 
    int** Newarr = new int* [s1 -1];                                             
    for (int i = 0, j = 0; i < s1; i++) {
        if (indexDel == i)
            continue;
        else {
            Newarr[j] = arr[i];
            j++;
        }
        }
    for (int i = 0; i < s1 -1; i++) {
        for (int j = 0; j < s2; j++) {
            cout << Newarr[i][j] << " ";
        }
        cout << endl;
    }
}

//Задание 3. Дана матрица порядка M×N (M строк, N столбцов). Необходимо заполнить ее значениями и написать
//функцию, осуществляющую циклический сдвиг строк
//и / или столбцов массива указанное количество раз и в указанную сторону.

void Task3(int** arr, int M, int N, int times, char way) {
    int* tempArr = new int[M];
    int temp;
    switch (way) {
    //Вверх
    case ('u'):
        for (int i = 0; i < times; i++) {
            //Сохранение первой строки
            for (int i = 0; i < N; i++) {
                tempArr[i] = arr[0][i];
            }
            //Переназначение самого массива
            for (int i = 0; i < M - 1; i++) {
                for (int j = 0; j < N; j++) {
                    arr[i][j] = arr[i + 1][j];
                }
            }
            //Присвоение последней строки первой
            for (int i = 0; i < N; i++) {
                arr[M - 1][i] = tempArr[i];
            }
        }
        break;
    //Вниз
    case ('d'):
        for (int i = 0; i < times; i++) {

            for (int i = 0; i < N; i++) {
                tempArr[i] = arr[M - 1][i];
            }

            for (int i = M - 1; i > 0; i--) {
                for (int j = 0; j < N; j++) {
                    arr[i][j] = arr[i - 1][j];
                }
            }

            for (int i = 0; i < N; i++) {
                arr[0][i] = tempArr[i];
            }
        }
        break;
    //Влево
    case ('l'):

        for (int i = 0; i < times; i++) {

            for (int i = 0; i < M; i++) {
                tempArr[i] = arr[i][0];
            }
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N - 1; j++) {
                    arr[i][j] = arr[i][j + 1];
                }      
            }
            for (int i = 0; i < M; i++) {
                    arr[i][N - 1] = tempArr[i];
                }
        }
            break;
    //Вправо
    case ('r'):
        for (int i = 0; i < times; i++) {
            for (int i = 0; i < M; i++) {
                tempArr[i] = arr[i][N-1];
            }
            for (int i = 0; i < M; i++) {
                for (int j = N-1; j > 0; j--) {
                    arr[i][j] = arr[i][j - 1];
                }
            }
            for (int i = 0; i < M; i++) {
                arr[i][0] = tempArr[i];
            }
        }
        break;
        }

        delete[] tempArr;

        //Для проверки
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
 }




int main()
{   //Task 1
    int arr1[3][3] = {
        {1,2,3},
        {7,8,9},
        {10,11,12}
    };
    int str[3] = { 4,5,6 };
    //Task1(arr1, 3, 3, str, 1);


    //Task 2
    int arr2[3][3] = {
        {1,2,3},
        {7,8,9},
        {10,11,12}
    };
    //Task2(arr2, 3, 3, 1);

    //Task3
    char way;
    int times;
    int** arr3 = new int*[4];
    for (int i = 0; i < 4; i++) {
        arr3[i] = new int[3];
    }
    for (int i = 0, n = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            arr3[i][j] = n;
            n++;
        }
    }

    //Для проверки
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Enter way (u,d,l,r): ";
    cin >> way;
    cout << "Enter times: ";  
    cin >> times;

    Task3(arr3, 4, 3, 1, way);






}


