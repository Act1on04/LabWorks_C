#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <locale.h>
// #include <Windows.h>

#define N 10

int main()
{
  setlocale(LC_ALL,"Rus");
  // SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
  // SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

  int i, j, sum=0;
  int n=N+1;

  while (n>N || n<2)
  {
      printf("\n������� ����������� ������� (n<%d): n = ",N);
      scanf("%d",&n);
  }

  int A[n];
  int *Ap = A;

  // ������ �������� �������
  puts ("������� �������� �������: ");
  for (i=0; i<n; i++)
  {
      printf(" A(%d)=", i);
      scanf ("%d", (Ap+i));
  }
  // �������  ������� �������� �������
  puts ("\n��� ������ A: ");
  for (i=0; i<n; i++)
    printf(" A(%d)=%d ", i, *(Ap+i));

  for (i=0; i<n; i++)
    if (*(Ap+i)%6 == 0)
    {
      sum += *(Ap+i);
    }
    
  printf("\n ����� �������� ������� ������� 6 ����� %d ", sum);


  int B[N] =  {14, 21, 6, 35, 4, 5, 6, 7, 8, 9};
  int *Bp = B;

  puts ("\n��� ������ B: ");
  for (i=0; i<N; i++)
    printf(" B(%d)=%d ", i, *(Bp+i));

  sum=0;

  for (i=0; i<N; i++)
    if (*(Bp+i)%7 == 0)
    {
      sum += *(Bp+i);
    }
    
  printf("\n ����� �������� ������� ������� 7 ����� %d ", sum);


  puts ("\n\n End.");
}