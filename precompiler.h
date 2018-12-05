#ifndef PRECOMPILER_H_INCLUDED
#define PRECOMPILER_H_INCLUDED
#include <iostream>
#include <math.h>

using namespace std;

typedef double T;

class TMatrix{
private:
 T **arr;  // двумерный массив
 int N;  // число строк
 int M;  // число столбцов

public:
    TMatrix ();//конструктор по умолчанию
   ~TMatrix ();//деструктор
    TMatrix (int N, int M);//нулевая матрица
    TMatrix (int N, int M, T **matr);
    TMatrix (const TMatrix& matrixToCopy); // конструктор копии

    TMatrix  operator +  (const TMatrix&);
    TMatrix  operator -  (const TMatrix&);
    TMatrix  operator *  (const TMatrix&);//умножение матричное
    TMatrix  operator += (const TMatrix&);
    TMatrix  operator -= (const TMatrix&);
    TMatrix  operator *= (const TMatrix&);// покомпонентное умножение без изменения к.л. множителя
    const TMatrix& operator =  (const TMatrix&);
    void minor (T **, int, int, int, T **);
    T operator () (int,int);
    T detrecur (T **, int);//рекурсивное вычисление детерминанта
    TMatrix transpon();//возвращает транспонированную матрицу
    T determnt ();// возвращает детерминант

friend TMatrix  operator *  (TMatrix&, T);
friend TMatrix  operator /  (TMatrix&, T);
friend TMatrix& operator *= (TMatrix&, T);
friend TMatrix& operator /= (TMatrix&, T);
friend istream& operator >> (istream&, TMatrix&);
friend ostream& operator << (ostream&, const TMatrix&);
};

#endif // PRECOMPILER_H_INCLUDED
