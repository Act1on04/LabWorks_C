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
  // SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
  // SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

  unsigned i, j, n=N+1, k=K+1;
  float arithmetic_mean=0;

  while (n>N || n<2)
  {
      printf("\n ������� ����������� ������� (n<%d): n = ",N);
      scanf("%d",&n);
  }

  int A[n];

  while (k<1 || k>K)
  {
      printf("\n ������� ����������� ������ (0<k<%d): k = ",K);
      scanf("%d",&k);
  }

  // ������ �������� �������
  puts (" ������� �������� �������: ");
  for (i=0; i<n; i++)
  {
      printf("  A(%d)=", i);
      scanf ("%d", &A[i]);
      arithmetic_mean += *(A+i);
  }
  
  // �������� ������� ����� ��������� ������� �� 0 �� 1000
  // ��� ���� ����������� ���������� �������� ��������, 
  // �������� ������� ���� �� � 2 ���� ��������� ������� �������������� �������� �������.
  // ����� ������ � ������� ���� ���� ��������� ����� ����� ������� ��������, � ��������� ���������
  // for (i=0;i<n;i++)
  //   {
  //     *(A+i)=rand()%1000;
  //     arithmetic_mean += *(A+i);
  //   }

  arithmetic_mean = arithmetic_mean / n;

  // �������  ������� �������� �������
  puts ("\n ��� ������ A: ");
  for (i=0; i<n; i++)
    printf(" A(%d)=%d ", i, *(A+i));
  printf("\n ������� �������������� �������� ����� %-.1f ", arithmetic_mean);

  // �������� �������
  printf("\n\n �������� �������, �������� ������� � %d ��� ������ �������� ��������������� �������� �������:", k);
  for (i=0; i<n; i++)
    if (*(A+i) / k > arithmetic_mean)
    {
      printf("\n  A(%d)=%d", i, *(A+i));
    }
    
   puts ("\n\n End.");
}