#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define N 10

unsigned i, j, n=N+1;

void InputArray(int mtrx[n]);
void PrintArray(FILE *file, int mtrx[n]);
int get_index_subsequence(int mtrx[n]);
int get_min(int mtrx[n], int index);

int main()
{
  setlocale(LC_ALL,"Rus");
  FILE *file;
  file = fopen("result.txt", "w+t");

  while (n>N || n<2)
    {
      printf("\n������� ����������� ��c���� (n<%d): n = ",N);
      scanf("%d",&n);
    }

  int a[n];

  InputArray(a);
  PrintArray(file, a);
  fprintf(file, "\n������ ������ ���������� ������������������ ������������� �������� ������ �: %d", get_index_subsequence(a));
  int min_index = get_min(a, get_index_subsequence(a));
  fprintf(file, "\n���������� ������� � ���������� ������������������ ������������� �������� ������ � ��� A(%d) = %d\n" ,min_index,a[min_index]);

  fclose(file);
  puts ("\n\nEnd.");
  return 0;
}

void InputArray(int mtrx[n])
// ������������ ������� �������
{
  printf("\n\n������� �������� ��� ������� A: \n");
  for (i=0; i<n; i++)
  {
    printf("  A(%d)=", i);
    scanf ("%d", &mtrx[i]);
  }
}

void PrintArray(FILE *file, int mtrx[n])
// ����� �������
{
  fprintf(file, "\n\n������  A:");
  for (i=0;i<n;i++)
    {
      fprintf(file, " A(%d)=%d ", i, mtrx[i]);
    }
}

int get_index_subsequence(int mtrx[n])
//���������� ���������� ������� ����� ������� ������������������ ������������� �����
{
  int len = 0, len_i = len;
  for (int i = 0; i < N; i++)
  {
      int n = i; 
      while (mtrx[i] > 0) i++;
      
      int delta = i - n;
      if ((delta > 0) && (delta > len))
        { len = delta; len_i = n; }
  }
  return len_i;
}

int get_min(int mtrx[n], int index)
//���������� ������������ �������� � ���������� ������������������ ������������� �����
{
  int min_i = index;
    for (int i = index; mtrx[i] > 0 && i<n; i++)
      if (mtrx[i] < mtrx[min_i]) min_i = i;
  return min_i;
}
