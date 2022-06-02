#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
// #include <Windows.h>

#define N 10

unsigned i, j, n=N+1;
int min_znach, max_znach;

void InputMatrix(int mtrx[][n]);
void RandomMatrix(int mtrx[][n]);
void PrintMatrix(int mtrx[][n]);
void SaveMatrix(int mtrx[][n]);
void PrintLowerMatrix(int mtrx[][n]);
int MinElem(int mtrx[][n]);
int MaxElem(int mtrx[][n]);
float ArithmeticMean(int n1, int n2);

int main()
{
  srand(time(0));
  setlocale(LC_ALL,"Rus");
  // SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
  // SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

  while (n>N || n<2)
    {
      printf("\nВведите розмерность матрицы (n<%d): n = ",N);
      scanf("%d",&n);
    }

  int a[n][n];

  RandomMatrix(a);  
  // InputMatrix(a);
  PrintMatrix(a);
  PrintLowerMatrix(a);
  min_znach = MinElem(a);
  max_znach = MaxElem(a);

  printf("\n\nМинимальное значение равно %d",min_znach);
  printf("\nМаксимальное значение равно %d",max_znach);
  printf("\nСреднее арифметическое значение равно %-.1f", ArithmeticMean(min_znach,max_znach));

  puts ("\n\nEnd.");
  return 0;
}

void InputMatrix(int mtrx[][n])
// Формирование массива вручную
{
  printf("\n\nВведите значения для матрицы A:");
  for (i=0;i<n;i++)
    {
      printf("\n");
      for (j=0;j<n;j++)
      {
        printf("a[%d][%d]=",i+1,j+1);
        scanf ("%d", &mtrx[i][j]);
      }
    }
}

void RandomMatrix(int mtrx[][n])
// Формирование массива случайных элементов из заданного диапазона
{
  int a_min=0, a_max=0;
  while ( a_min>=a_max)
    {
      printf("\nВведите диапозон допустимых знач. для матрицы a_min i a_max: ");
      scanf("%d %d",& a_min, &a_max);
    }

  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      mtrx[i][j]=rand()%( a_max- a_min)+ a_min;
}

void PrintMatrix(int mtrx[][n])
// Вывод матрицы
{
  printf("\n\nМатрица  A:");
  for (i=0;i<n;i++)
    {
      printf("\n");
      for (j=0;j<n;j++)
        printf("a[%d][%d]=%-4d", i+1, j+1, mtrx[i][j]);
    }
}

void PrintLowerMatrix(int mtrx[][n])
// Вывод элементов расположенных ниже главной диагонали Матрицы A.
{
  printf("\n\nЭлементы расположенные ниже главной диагонали Матрицы A:");
  for (i=0;i<n;i++)
    {
      for (j=0;j<n;j++)
        if (i>j)
          printf("a[%d][%d]=%-4d", i+1, j+1, mtrx[i][j]);
      printf("\n");
    }
}

int MinElem(int mtrx[][n])
// Находим Минимальное значение среди элементов расположенных ниже главной диагонали Матрицы A
{
  int res=mtrx[1][0]; 
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      if ((i>j) && (res > mtrx[i][j])) res=mtrx[i][j];
  return res;
}

int MaxElem(int mtrx[][n])
// Находим Максимальное значение среди элементов расположенных ниже главной диагонали Матрицы A
{
  int res=mtrx[1][0]; 
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      if ((i>j) && (res < mtrx[i][j])) res=mtrx[i][j];
  return res;
}

float ArithmeticMean(int n1, int n2)
{
  return (float)(n1+n2)/2;
}
