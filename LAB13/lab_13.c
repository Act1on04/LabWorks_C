#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL,"Rus");

  FILE *A,*B,*C;

  A = fopen("a.txt", "r");
  B = fopen("b.txt", "r");
  C = fopen("c.txt", "w");
  FromABtoC(A,C);
  FromABtoC(B,C);
  fclose(A);
  fclose(B);
  fclose(C);

  A = fopen("a.txt", "a");
  B = fopen("b.txt", "r");
  FromBtoA(B,A,3);
  fclose(A);
  fclose(B);

  return EXIT_SUCCESS;
}  

void FromABtoC(FILE *fileAB, FILE *fileC)
{
  float num;
  while (fscanf(fileAB, "%f", &num) != EOF)
    if (num < 0)
      fprintf(fileC, "%g\n", num);
}

void FromBtoA(FILE *fileB, FILE *fileA, int count)
{
  float num, i=0;
  while (fscanf(fileB, "%f", &num) != EOF && (i < count))
  {
    fprintf(fileA, "\n%g", num);
    ++i;
  }
}
