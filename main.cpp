#include "precompiler.h"
#include "constructors.h"

int main()
{
    int i_menu, max_menu, i, j, N, M;
    T **matr1, **matr2, **matr3, C;
    N = 5;
    M = 4;
    
    matr1 = new T* [N];
    for (i = 0; i < N; i++)
        matr1[i] = new T [M];
    
    matr2 = new T* [M];
    for (i = 0; i < M; i++)
        matr2[i] = new T [N];
    
    matr3 = new T* [N];
    for (i=0; i<N; i++)
        matr3[i] = new T [N];

    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
          matr1[i][j] = 1;
    
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
          matr2[i][j] = 1.+i+j;

    matr3[0][0] = 1; matr3[0][1] = 2; matr3[0][2] = 3; matr3[0][3] = 4; matr3[0][4] = 0;
    matr3[1][0] = 2; matr3[1][1] = 1; matr3[1][2] = 2; matr3[1][3] = 3; matr3[1][4] = 0;
    matr3[2][0] = 1; matr3[2][1] = 0; matr3[2][2] = 1; matr3[2][3] = 0; matr3[2][4] = 3;
    matr3[3][0] = 2; matr3[3][1] = 7; matr3[3][2] = 2; matr3[3][3] = 0; matr3[3][4] = 2;
    matr3[4][0] = 5; matr3[4][1] = 4; matr3[4][2] = 3; matr3[4][3] = 2; matr3[4][4] = 0;
    
    TMatrix Ma4(N,N,matr3);
    TMatrix Ma1(N,M,matr1);
    TMatrix Ma2(M,N,matr2);
    TMatrix Ma3(N,M);
    TMatrix Ma0;
    
    cout << "Ma4: construct\n" << Ma4 << '\n';
    cout << "Ma2: construct\n" << Ma2 << '\n';
    cout << "Ma1: construct\n" << Ma1 << '\n';
    cout << "Ma3:by default\n" << Ma3 << '\n';
    cout << "Ma0:by default\n" << Ma0 << '\n';
    
 max_menu = 18;
    while(true)
    {
        i_menu = menu(max_menu);

        switch(i_menu){
    case 1:
        cout << "\n exit...\n";
        exit(0);
        break;

    case 2:
        Ma0 = Ma1 + Ma1;
        cout << "\nAfter Ma1 + Ma1\n";
        cout << '\n';
        cout << Ma0;
        cout << endl;
        break;

    case 3:
        Ma0 = Ma1 - Ma3;
        cout << "\n After Ma1 - Ma3 \n";
        cout << '\n';
        cout << Ma0 << endl;
        break;

    case 4:
        Ma3 += Ma1;
        cout << "\n After Ma3 += Ma1 \n";
        cout << '\n';
        cout << Ma3;
        cout << endl;
        break;

    case 5:
        Ma0 = Ma1 * Ma2;
        cout << "\n After Ma1 * Ma2 \n";
        cout << '\n';
        cout << Ma0;
        Ma0 = Ma2 * Ma1;
        cout << '\n';
        cout << "\n After Ma2 * Ma1 \n";
        cout << '\n';
        cout << Ma0;
        cout << endl;
        break;

    case 6:
        cout<<"Redefinion of matrix ( operation = ), Ma2 = Ma1, Ma2:"<<endl;
        Ma2 = Ma1;
        cout << Ma2 << '\n';;
        cout << endl;
        break;

    case 7:
        Ma3 -= Ma1;
        cout << "\nAfter Ma3 -= Ma1\n";
        cout << '\n';
        cout << Ma3;
        cout << endl;
        break;

    case 8:
        Ma1 *= Ma2;
        cout << "\nAfter Ma1 *= Ma2 \n";
        cout << '\n';
        cout << Ma1;
        cout << endl;
        break;

    case 9:
        cout << "\n Enter N and M, please. \n";
        cin >> Ma0;
        cout << "\n Your new matrix: \n";
        cout << Ma0 << endl;
        break;

    case 10:

        cout << "\n Enter your number: \n";
        cin >> C;
        cout << "\n Ma2 * C =: \n";
        Ma0 = Ma2*C;
        cout << Ma0;
        break;

    case 11:

        cout << "\n Enter your number: \n";
        cin >> C;
        cout << "\n Ma2/C =: \n";
        Ma0 = Ma2/C;
        cout << Ma0;
        break;
        
    case 12:
        cout << "\n determint Ma4:\n" << Ma4.determnt() << endl;
        break;    
        
    case 13:
        
        cout << '\n' << Ma2.transpon() << endl;
        
        break;    
    
    case 14:

        cout << "\n ... \n";
        
        break;    
        
    case 15:
        cout << Ma1<< '\n';
        cin >> i;
        cin >> j;
        cout << '\n';
        cout << Ma1(i,j) << endl;
        break;

    default:
        cout<<"Error"<<endl;
        break;
    }
    }

    return 0;
}
