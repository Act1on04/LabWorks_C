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


int main()
{
  SetConsoleCP(1251);       
  SetConsoleOutputCP(1251); 
  FILE *deviceDB;

  printf(" -= Заполнение файла данными об устройствах =-\n");

  if ((deviceDB = fopen("deviceDB.dat", "ab")) == NULL)
  {
    printf("\n[-] Ошибка открытия файла данных deviceDB.dat");
    return EXIT_FAILURE;
  }
  inputDevice(deviceDB);
  fclose(deviceDB);

  return EXIT_SUCCESS;
}  

int inputDevice(FILE* fileDB)
{
  char ch;
  int num;
  Device device;
  do
  {
    printf("\n Введите данные на устройство: ");
    printf("\n  Название: ");
    scanf("%s", device.name);
    printf("  Вес: ");
    scanf("%f", &device.weight);
    printf("  Цена: ");
    scanf("%f", &device.price);
    printf("  Гарантийный срок: ");
    scanf("%d", &device.guarantee);

    do
    {
      printf("\n Введите количество покупных изделий для устройства (не больше 50): ");
      scanf("%d", &num);
    } while (num > 50 || num < 0);

    for (int i = 0; i < 50; i++)
      if (i < num)
      {
        printf("\n  Введите данные покупного изделия №%d: ", i+1);
        printf("\n   Название: ");
        scanf("%s", device.items[i].name);
        printf("   Цена: ");
        scanf("%d", &device.items[i].price);
        printf("   Количество: ");
        scanf("%d", &device.items[i].quantity);
        printf("   Продавец: ");
        scanf("%s", device.items[i].salesman);
      }
      else
      {
        device.items[i].name[0] = '\0';
        device.items[i].price = 0;
        device.items[i].quantity = 0;
        device.items[i].salesman[0] = '\0';
      }

    fwrite(&device, sizeof(Device), 1, fileDB);
    printf("\n Закончить ввод данных? y/n ");
    ch = getch(); 
  } while (ch != 'y' && ch != 'Y' && ch != 'н' && ch != 'Н');

  printf("\n\n[+] Данные записаны в файл deviceDB.dat\n");
  return EXIT_SUCCESS;
}


