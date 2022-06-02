#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <locale.h>
// #include <Windows.h>

#define N 10

int main()
{
  setlocale(LC_ALL,"Rus");
  // SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
  // SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

  int i, j, sum=0;
  int n=N+1;

  while (n>N || n<2)
  {
      printf("\nВведите розмерность матрицы (n<%d): n = ",N);
      scanf("%d",&n);
  }

  int A[n];
  int *Ap = A;

  // Вводим значения массива
  puts ("Введите элементы массива: ");
  for (i=0; i<n; i++)
  {
      printf(" A(%d)=", i);
      scanf ("%d", (Ap+i));
  }
  // Выводим  текущие значения массива
  puts ("\nВаш массив A: ");
  for (i=0; i<n; i++)
    printf(" A(%d)=%d ", i, *(Ap+i));

  for (i=0; i<n; i++)
    if (*(Ap+i)%6 == 0)
    {
      sum += *(Ap+i);
    }
    
  printf("\n Сумма елемнтов массива кратных 6 равна %d ", sum);


  int B[N] =  {14, 21, 6, 35, 4, 5, 6, 7, 8, 9};
  int *Bp = B;

  puts ("\nВаш массив B: ");
  for (i=0; i<N; i++)
    printf(" B(%d)=%d ", i, *(Bp+i));

  sum=0;

  for (i=0; i<N; i++)
    if (*(Bp+i)%7 == 0)
    {
      sum += *(Bp+i);
    }
    
  printf("\n Сумма елемнтов массива кратных 7 равна %d ", sum);


  puts ("\n\n End.");
}