#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// #include <string.h>

#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7

char* int_to_binary(unsigned u) 
{ 
  char * binary = malloc (10);
  register int t; 
  strcpy(binary, "0b");
  for (t=128; t>0; t = t/2) 
    if (u & t) strcat(binary, "1");
    else strcat(binary, "0");
  return binary;
}

int task1()
{
  FILE* file;
  unsigned a, b;
  int Y;

  if ((file = fopen("in.txt", "r")) == NULL)
  {
    printf("\n[-] Ошибка открытия файла входных данных in.txt");
    return EXIT_FAILURE;
  }
  fscanf(file, "a = %d\nb = %d", &a, &b);
  fclose(file);
  printf("\n a = %d\n b = %d\n", a, b);

  if ((file = fopen("out.txt", "w")) == NULL)
  {
    printf("\n[-] Ошибка открытия файла выходных данных out.txt");
    return EXIT_FAILURE;
  }

  Y = 16*(a + 3*b/2);
  printf("\n Y = 16*(a + 3*b/2) = %d\n", Y);
  fprintf(file, "Y = 16*(a + 3*b/2) = %d\n", Y);
  // 3*b можно записать как 4*b - b
  Y = (a + ((b << 2) - b >> 1)) << 4;
  printf("\n Y = (a + ((b << 2) - b >> 1)) << 4 = %d\n", Y);
  fprintf(file, "Y = (a + ((b << 2) - b >> 1)) << 4 = %d\n", Y);

  fclose(file);

  return EXIT_SUCCESS;
}

int task2()
{
    unsigned char number = 124;
    printf("\n------------------------------------------------------------");
    printf("\n| № |  Число   | Выделить | Обнулить |Установить|Инверт-ть |");
    printf("\n|---|----------|----------|----------|----------|----------|");
    printf("\n| 7 |   %3d    |3,4,5 бит | 1,2 бит  | 6,7 бит  |  2 бит   |", number);
    printf("\n|---|----------|----------|----------|----------|----------|");

    unsigned char highlight = number & ((1<<BIT3) | (1<<BIT4) | (1<<BIT5));
    unsigned char set_null = number & ~((1<<BIT1) | (1<<BIT2));
    unsigned char set_one = number | ((1<<BIT6) | (1<<BIT7));
    unsigned char invert = number ^ (1<<BIT2);

    printf("\n|   |%10d|%10d|%10d|%10d|%10d|", number, highlight, set_null, set_one, invert);
    printf("\n|   |%10s|%10s|%10s|%10s|%10s|", int_to_binary(number), int_to_binary(highlight), int_to_binary(set_null), int_to_binary(set_one), int_to_binary(invert));
    printf("\n------------------------------------------------------------");

  return EXIT_SUCCESS;
}

int main()
{
  SetConsoleCP(1251);       
  SetConsoleOutputCP(1251); 

  printf("\n[+] Задание 1:\n");
  task1();

  printf("\n[+] Задание 2:\n");
  task2();
  
  return EXIT_SUCCESS;
}