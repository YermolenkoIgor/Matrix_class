#include "precompiler.h"
#include "constructors.h"
//деструктор
TMatrix :: ~TMatrix()
{
    for (int i=0; i<N; i++)
        delete[]arr[i];
    delete[]arr;
}
//конструктор по-умолчанию
TMatrix::TMatrix()
{
    N = 2;
    M = 2;
    arr = new T* [N];
    for (int i = 0; i < N; i++)
        arr[i] = new T [M];

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
          arr[i][j] = 0.;
}
//нулевая матрица (или рандомная)
TMatrix::TMatrix(int N, int M)
{
    this-> M = M;
    this-> N = N;

    arr = new T* [N];
    for (int i = 0; i < N; i++)
        arr[i] = new T [M];

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            arr[i][j] = 0.; //(rand() % 100); // rand()/(RAND_MAX+1.)*100.;
}

TMatrix::TMatrix(int N, int M, T **matr)
{
    this-> M = M;
    this-> N = N;

    arr = new T* [N];
    for (int i = 0; i < N; i++)
        arr[i] = new T [M];

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            arr[i][j] = matr[i][j];
}

TMatrix::TMatrix(const TMatrix &matrixToCopy) // конструктор копии
{
    this-> M = matrixToCopy.M;
    this-> N = matrixToCopy.N;
    //старую arr удаляется?
    arr = new T* [N];
    for (int i = 0; i < N; i++)
        arr[i] = new T [M];
 
    for(int i=0; i<this->N; i++)
        for(int j=0; j<this->M; j++)
            arr[i][j] = matrixToCopy.arr[i][j];// заполняем матрицу значениями матрицы matrixToCopy
}

istream& operator >> (istream& t, TMatrix& obj)
{
    for (int i=0; i<obj.N; i++)
        delete[]obj.arr[i];
    delete[]obj.arr;
    
    cin >> obj.N;
    cin >> obj.M;
    cout << "\n Enter your Matrix: "  << endl;
    
    obj.arr = new T* [obj.N];
    for (int i = 0; i < obj.N; i++)
        obj.arr[i] = new T [obj.M];

    for(int i=0;i<obj.N;i++)
        for(int j= 0;j<obj.M;j++)
            t >> obj.arr[i][j];
    return t;
}

ostream &operator << (ostream &t, const TMatrix &obj)
{
    for (int i=0;i<obj.N;i++)
    {
        for (int j= 0;j<obj.M;j++)
            t << obj.arr[i][j] << " ";
        t << endl;
    }
    return t;
}

const TMatrix& TMatrix :: operator = (const TMatrix& obj)
{
    if(&obj != this)
    {
        if(this->N != obj.N | this->M != obj.M)
        {
            for (int i=0; i<obj.N; i++)
                delete[]this->arr[i];
            delete[]this->arr;
                
            this->N = obj.N;
            this->M = obj.M;
            
            this->arr = new T* [N];
            for (int i = 0; i < N; i++)
                this->arr[i] = new T [M];
        }
        for (int i=0;i<obj.N;i++)
            for (int j= 0;j<obj.M;j++)
                this-> arr[i][j] = obj.arr[i][j];    
    }
    return *this;
}

TMatrix TMatrix :: operator + (const TMatrix& obj)
{
    TMatrix box(this->N, this->M, this->arr);

    if ( ( this->N != obj.N) | (this->M != obj.M) )
        cout << "Addition of matrices is possible only if they have the same size";
    else
        for (int i=0;i<obj.N;i++)
            for (int j=0;j<obj.M;j++)
                box.arr[i][j] += obj.arr[i][j];//cout<<box.arr[i][j];

    return box;
}

TMatrix TMatrix :: operator - (const TMatrix& obj)
{
    TMatrix box(this->N, this->M, this->arr);

    if ( ( this->N != obj.N) | (this->M != obj.M) )
        cout << "Subtraction of matrices is possible only if they have the same size";
    else
        for (int i=0;i<obj.N;i++)
            for (int j=0;j<obj.M;j++)
                box.arr[i][j] -= obj.arr[i][j];//cout<<box.arr[i][j];

    return box;
}

TMatrix TMatrix :: operator * (const TMatrix& obj)
{
    //Результатом умножения матриц A n×m и B m×k будет матрица C n×k
    TMatrix box(N, obj.M);
    
    if(M != obj.N)
        cout << "Matrixes must have same size for *" << endl;
    else
        for(int i = 0; i < N; i++)
            for(int j = 0; j < obj.M; j++)
                for(int k = 0; k < M; k++)
                    box.arr[i][j] += arr[i][k]*obj.arr[k][j];

return box;
}

TMatrix TMatrix :: operator -= (const TMatrix& obj)
{
    if ((this->N!=obj.N) | (this->M!=obj.M))
        cout << "Matrixes must have same size for -=";
    else
        for (int i=0;i<obj.N;i++)
            for (int j=0;j<obj.M;j++)
                this->arr[i][j] -= obj.arr[i][j];
        
    return *this;
}

TMatrix TMatrix :: operator += (const TMatrix& obj)
{
    if ((this->N!=obj.N) | (this->M!=obj.M))
        cout << "Matrixes must have same size for +=";
    else
        for (int i=0;i<obj.N;i++)
            for (int j=0;j<obj.M;j++)
                this->arr[i][j] += obj.arr[i][j];
        
    return *this;
}

TMatrix TMatrix :: operator *= (const TMatrix& obj)
{
    TMatrix box(this->N, this->M);
    
    if ( (this->N != obj.N) | (this->M != obj.M) )
        cout << "Matrixes must have same size for *=";
    else
        for (int i=0;i<box.N;i++)
            for (int j=0;j<box.M;j++)
                box.arr[i][j] = this->arr[i][j] * obj.arr[i][j];
        
    return box;
}

TMatrix operator * (TMatrix& A, T obj)
{
    TMatrix box(A.N, A.M, A.arr);

    for (int i=0;i<A.N;i++)
        for (int j=0;j<A.M;j++)
            box.arr[i][j] *= obj;

    return box;
}

TMatrix operator / (TMatrix& A, T obj)
{
    TMatrix box(A.N, A.M, A.arr);

    for (int i=0;i<A.N;i++)
        for (int j=0;j<A.M;j++)
            box.arr[i][j] /= obj;

    return box;
}

TMatrix& operator *= (TMatrix& A, T obj)
{
    for (int i=0;i<A.N;i++)
        for (int j= 0;j<A.M;j++)
            A.arr[i][j] *= obj;

    return A;
}

TMatrix& operator /= (TMatrix& A, T obj)
{
    if(obj == 0)
        cout << "divided by zero :(" << endl;
    else
        for (int i=0;i<A.N;i++)
            for (int j= 0;j<A.M;j++)
                A.arr[i][j] /= obj;

    return A;
}

T TMatrix :: operator () (int i,int j)
{
    if((i < this->N) | (j < this->M))
        return this->arr[i][j];
    else
        return -666;
}

//Возвращает матрицу matrix без row-ой строки и col-того столбца, результат в newMatrix
void TMatrix :: minor(T **matrix, int size, int row, int col, T **newMatrix)
{
    int offsetRow = 0; //Смещение индекса строки в матрице
    int offsetCol = 0; //Смещение индекса столбца в матрице
    for(int i = 0; i < size-1; i++) 
    {
        //Пропустить row-ую строку
        if(i == row) 
            offsetRow = 1; //Как только встретили строку, которую надо пропустить, делаем смещение для исходной матрицы
 
        offsetCol = 0; //Обнулить смещение столбца
        for(int j = 0; j < size-1; j++) 
        {  
            if(j == col) 
                offsetCol = 1; //Пропустить col-ый столбец //Встретили нужный столбец, пропускаем его смещением

            newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
        }
    }
}

 //Вычисление определителя матрицы разложение по первой строке
T TMatrix :: detrecur(T **matrix, int size) 
{
    T det = 0;
    int degree = 1; // (-1)^(1+j) из формулы определителя
 
    //Условие выхода из рекурсии
    if(size == 1)
        return matrix[0][0];  
    else 
        if(size == 2) 
            return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
        else 
        {
            //Матрица без строки и столбца
            T **newMatrix = new T*[size-1];
            for(int i = 0; i < size-1; i++) 
                newMatrix[i] = new T[size-1];
        
            //Раскладываем по 0-ой строке, цикл бежит по столбцам
            for(int j = 0; j < size; j++) 
            {
                minor(matrix, size, 0, j, newMatrix);

                det = det + (degree * matrix[0][j] * detrecur(newMatrix, size-1));//Рекурсивный вызов
            
                degree = -degree;//"Накручиваем" степень множителя
            }

            for(int i = 0; i < size-1; i++) 
                delete[] newMatrix[i];//Чистим память на каждом шаге рекурсии
            delete[] newMatrix; 
        }
    return det;
}

T TMatrix :: determnt()
{
    return detrecur(this->arr, this->N);
}

TMatrix TMatrix :: transpon()
{
    TMatrix box(this->M, this->N);

    for (int i=0;i<this->M;i++)
            for (int j= 0;j<this->N;j++)
                box.arr[i][j] = this->arr[j][i]; 

    return box;    
}

int menu(int max_menu) {
int i_menu;
cout << "\n\nInput number of the action 1-" << max_menu << endl;
do
    {
    cout << "1  - Exit                         \n";
    cout << "2  - Operation +                  \n";
    cout << "3  - Operation -                  \n";
    cout << "4  - Operation  +=                \n";
    cout << "5  - Operation *                  \n";
    cout << "6  - Op-n = (matrix redefinition) \n";
    cout << "7  - Operation -=                 \n";
    cout << "8  - Operation *=                 \n";
    cout << "9  - Keyboard input of Ma1        \n";
    cout << "10 - Multiplie on number          \n";
    cout << "11 - Division on number           \n";
    cout << "12 - Determinant Ma4:             \n";
    cout << "13 - Transponir Ma2:              \n";
    cout << "14 - ...                          \n";
    cout << "15 - Ma1[i][j] = "            << endl;

    cout << endl;
    cin >> i_menu;
    }
while( (i_menu < 0) || (i_menu > max_menu));

return i_menu;
}
