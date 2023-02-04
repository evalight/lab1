#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void FillInc(int A[], int n) {
    int a = 1;

    for (int i = 0; i < n; i++) {
        A[i] = a;
        a++;

    }
}

void FillDec(int A[], int n) {
    int a = 10;
    for (int i = 0; i < n; i++) {
        A[i] = a;
        a--;

    }
}

void FillRand(int A[], int n) {
    srand(time(NULL));
    int a;
    for (int i = 0; i < n; i++) {
        a = rand() % 11;
        A[i] = a;

    }
}

int CheckSum(int A[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += A[i];
    }
    return s;

}

int RunNumber(int A[], int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > A[i + 1]) {
            k += 1;
        }
    }
    return k;
}

float AvgSer(int A[], int n){
    int k = 0;
    int len = 1 ;
    int s = 0 ;
    for (int i = 0; i < n; i++) {

        if (A[i] > A[i + 1]) {
            k += 1;
            s+=len;
            len = 1;
        }else{
            len+=1;
        }
    }
    return (float)s/(float)RunNumber(A,n);
}

void PrintMas(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int A[10];
    int n = 10;
    FillInc(A, n);
    printf("Массив врзраст:\n");
    PrintMas(A, n);
    printf("Убывающий массив:\n");
    FillDec(A, n);
    PrintMas(A, n);
    printf("Массив случайных чисел:\n");
    FillRand(A, n);
    PrintMas(A, n);
    printf("Контрольная сумма %d \n", CheckSum(A, n));
//    int s[10] = A;
    printf("Кол Серий : %d \n", RunNumber(A, n));
    printf("Средняя длинна Серии: %.1f",AvgSer(A,n));
    return 0;
}