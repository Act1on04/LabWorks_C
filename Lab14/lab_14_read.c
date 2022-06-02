#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


typedef struct Purchased_st
{
  char name[30];
  int price;
  int quantity;
  char salesman[30];
} Purchased;

typedef struct Device_st {
  char name[50];
  float weight;
  float price; 
  int guarantee;
  Purchased items[50];
} Device;

int fullPrintDevice();
int choicePrintDevice();

int main()
{
  SetConsoleCP(1251);       
  SetConsoleOutputCP(1251); 
  char c;

  printf(" -= ������ �� ����� ������ �� ����������� =-\n");

  while (1)
  {
    puts("\n1 - ������ ���� ������ �� �����������");
    puts("2 - ������ ������ � ����������� �� �������");
    puts("0 - �����");
    c = getch(); 
    switch (c)
    {
    case '1':
      fullPrintDevice();
      break;
    case '2':
      choicePrintDevice();
      break;
    case '0':
      return EXIT_SUCCESS;
    default:
      puts("������� �����");
    }
  }
}  

void print_shapka()
{
  printf("\n------------------------------------------------------------------------------------------------");
  printf("\n| N |      ��������      |  ���  |  ����  |��������-|             �������� �������             |");
  printf("\n|   |                    |       |        |��� ���� |                                          |");
  printf("\n------------------------------------------------------------------------------------------------");
}

void print_stroka(unsigned num, Device device)
{
  printf("\n|%3d|%-20s|%-7.2f|%-8.2f|%-9d|N |   ��������   |����|���-��|  ��������  |", num, device.name, device.weight, device.price, device.guarantee);
  printf("\n|   |                    |       |        |         |------------------------------------------|");
  int i=0;
  while (device.items[i].name[0] != '\0') 
    {
      printf("\n|   |                    |       |        |         |%-2d|%14s|%4d|%6d|%12s|", i+1, device.items[i].name, device.items[i].price, device.items[i].quantity, device.items[i].salesman);
      i++;
    }
  printf("\n|----------------------------------------------------------------------------------------------|");
}

int fullPrintDevice()
{
  unsigned num = 0;
  Device device;
  FILE *fileDB;

  if ((fileDB = fopen("deviceDB.dat", "rb")) == NULL)
  {
    printf("\n[-] ������ �������� ����� ������ deviceDB.dat");
    return EXIT_FAILURE;
  }
  printf("\n - ������ ������ ��������� -");
  print_shapka();
  while (fread(&device, sizeof(Device), 1, fileDB)) 
  {
    print_stroka(++num, device);
  }
  fclose(fileDB);
  printf("\n\n[+] ������ �� ����������� ��������� �� ����� deviceDB.dat\n");
  return EXIT_SUCCESS;
}

int choicePrintDevice()
{
  unsigned num = 0, choice;
  Device device;
  FILE *fileDB;

  if ((fileDB = fopen("deviceDB.dat", "rb")) == NULL)
  {
    printf("\n[-] ������ �������� ����� ������ deviceDB.dat");
    return EXIT_FAILURE;
  }

  do
  {
    printf("\n ������� ���������� ������������ �������� ������� ��� ������� ������: ");
    scanf("%d", &choice);
  } while (choice < 0);

  printf("\n- ������ �����������, ������������ ������ %d �������� ������� -", choice);
  printf("\n--------------------------------------------------------------");
  printf("\n| N |   ��������   |   ��������   |���-��|�������� ����������|");
  printf("\n--------------------------------------------------------------");

  while (fread(&device, sizeof(Device), 1, fileDB)) 
  { 
    int i=0;
    while (device.items[i].name[0] != '\0') 
      {
        if (device.items[i].quantity > choice)
          {
            printf("\n|%-3d|%-14s|%14s|%6d|%19s|", ++num, device.items[i].salesman, device.items[i].name, device.items[i].quantity, device.name);
            printf("\n|------------------------------------------------------------|");
          }
        i++;
      }
  }
  printf("\n");
  fclose(fileDB);
  return EXIT_SUCCESS;
}