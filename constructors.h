#ifndef CONSTRUCTORS_H_INCLUDED
#define CONSTRUCTORS_H_INCLUDED
//дружественные ф-ии
int menu(int max_menu);
TMatrix& operator *= (TMatrix&, T);
TMatrix& operator /= (TMatrix&, T);
TMatrix  operator *  (TMatrix&, T);
TMatrix  operator /  (TMatrix&, T);
istream& operator >> (istream&, TMatrix&);
ostream& operator << (ostream&, const TMatrix&);//взятие и всувание в потоккккк

#endif // CONSTRUCTORS_H_INCLUDED
