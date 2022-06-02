#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
// #include <Windows.h>

#define N 100
#define K 5

int main()
{
  srand(time(0));
  setlocale(LC_ALL,"Rus");
  // SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
  // SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

  unsigned i, j, n=N+1, k=K+1;
  float arithmetic_mean=0;

  while (n>N || n<2)
  {
      printf("\n Введите розмерность матрицы (n<%d): n = ",N);
      scanf("%d",&n);
  }

  int A[n];

  while (k<1 || k>K)
  {
      printf("\n Введите коэффициент отбора (0<k<%d): k = ",K);
      scanf("%d",&k);
  }

  // Вводим значения массива
  puts (" Введите элементы массива: ");
  for (i=0; i<n; i++)
  {
      printf("  A(%d)=", i);
      scanf ("%d", &A[i]);
      arithmetic_mean += *(A+i);
  }
  
  // Значения массива задаём случайным образом от 0 до 1000
  // При этом практически невозможно отобрать элементы, 
  // значение которых хотя бы в 2 раза превышает среднее арифметическое значение массива.
  // Нужен массив в котором лишь пару элементов будут иметь большие значения, а остальные маленькие
  // for (i=0;i<n;i++)
  //   {
  //     *(A+i)=rand()%1000;
  //     arithmetic_mean += *(A+i);
  //   }

  arithmetic_mean = arithmetic_mean / n;

  // Выводим  текущие значения массива
  puts ("\n Ваш массив A: ");
  for (i=0; i<n; i++)
    printf(" A(%d)=%d ", i, *(A+i));
  printf("\n Среднее арифметическое значение равно %-.1f ", arithmetic_mean);

  // Основное задание
  printf("\n\n Элементы массива, значение которых в %d раз больше среднего арифметического значения массива:", k);
  for (i=0; i<n; i++)
    if (*(A+i) / k > arithmetic_mean)
    {
      printf("\n  A(%d)=%d", i, *(A+i));
    }
    
   puts ("\n\n End.");
}