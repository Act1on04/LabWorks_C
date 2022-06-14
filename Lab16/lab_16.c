#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <curses.h>


unsigned i, j, n=5;
int winX = 40, winY = 7;
int winH = 3, winW = 7;
int otstup = 1;
int pI=1, pJ=1;
int Multi;

void InputMatrix(int mtrx[][n], int color);
void RandomMatrix(int mtrx[][n]);
void PrintMatrixWin(int mtrx[][n], int color);
int Multiplication(int mtrx[][n], int color);
void PrintPobDiagMatrix(int mtrx[][n], int color);
void ConfStdSrc(int flag);

int main()
{
  setlocale(LC_ALL,"Rus");
  int a[n][n];

  initscr(); //ініціалізація ncurses
  if (!has_colors()) { // ініціалізація кольорового режиму
    endwin();
    printf("Colors are not supported!");
    return EXIT_FAILURE;
  }
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  init_pair(3, COLOR_BLUE, COLOR_GREEN);
  curs_set(0); 
  
  // MakeStdSrc();
  // Вводим матрицу
  // RandomMatrix(a);  
  InputMatrix(a, 2);
  clear();
  // Мигаем матрицей
  PrintMatrixWin(a, 2);
  sleep(2);
  PrintMatrixWin(a, 1);
  sleep(2);
  PrintMatrixWin(a, 2);
  sleep(1);
  clear();
  // Считаем произведение столбцов или элементов столбцов
  Multi = Multiplication(a, 3);
  // Выводим произведение ниже побочной диагонали матрицы
  PrintPobDiagMatrix(a, 2);
  refresh(); 

  getch(); //очікування введення користувача
  endwin(); //завершення роботи з ncurses
  return EXIT_SUCCESS;
}

void RandomMatrix(int mtrx[][n])
// Формирование массива случайных элементов из заданного диапазона
{
  int a_min=0, a_max=10;
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      mtrx[i][j]=rand()%( a_max- a_min)+ a_min;
}

void ConfStdSrc(int flag)
{
  wattron(stdscr, COLOR_PAIR(1));
  box(stdscr, 0, 0);
  mvwprintw(stdscr, 0, 1, "LabWork 16 Variant 7");
  if (flag == 1)
    for (int i = 0; i < n; i++)
    {
      mvwprintw(stdscr, winY-2, winX+winW/2+(winW+otstup)*i, "%d", i+1);
      mvwprintw(stdscr, winY+winH/2+(winH+otstup)*i, winX-2, "%d", i+1);
    }
  refresh(); 
}

void InputMatrix(int mtrx[][n], int color)
// Формирование массива вручную
{
  WINDOW *winMatrix[n][n];
  
  ConfStdSrc(1);
  wattron(stdscr, COLOR_PAIR(2));
  mvwprintw(stdscr, winY-4, winX+7, "Введите значения матрицы");
  refresh();
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
    {
      winMatrix[i][j] = newwin( winH, winW, winY+(winH+otstup)*i, winX+(winW+otstup)*j);
      box(winMatrix[i][j], 0, 0 );
      wbkgd(winMatrix[i][j], COLOR_PAIR(color));
      wrefresh(winMatrix[i][j]);
      mvwscanw(winMatrix[i][j], 1, 1, "%d", &mtrx[i][j]);
    }
}

int Multiplication(int mtrx[][n], int color)
{
  WINDOW *win;
  // произведение строки на столбец
  int multi=0;
  // произведение всех элементов
  // int multi=1;
  ConfStdSrc(0);
  win = newwin( 3, 100, 3, 10);
  box(win, 0, 0 );
  mvwprintw(win, 0, 1, "Ввод");
  wbkgd(win, COLOR_PAIR(color));
  // произведение строки на столбец
  mvwprintw(win, 1,2, "Введите через пробел строку и столбец для подсчёта их произведения (от 1 до 5): ");
  // произведение всех элементов
  // mvwprintw(win, 1,2, "Введите через пробел строку и столбец для подсчёта произведения их элементов (от 1 до 5): ");
  wrefresh(win);
  wscanw(win, "%d %d", &pI, &pJ);
  for (i=0;i<n;i++)
  {
    // произведение строки на столбец
    multi=multi+mtrx[pI-1][i]*mtrx[i][pJ-1];
    // произведение всех элементов
    // multi=multi*mtrx[pI-1][i]*mtrx[i][pJ-1];
  }
  wclear(win);
  box(win, 0, 0 );
  mvwprintw(win, 0, 1, "Результат");
  // произведение строки на столбец
  mvwprintw(win, 1,2, "Произведение строки %d на столбец %d равно %d", pI, pJ, multi);
  // произведение всех элементов
  // mvwprintw(win, 1,2, "Произведение всех элементов строки %d и столбца %d равно %d", pI, pJ, multi);
  wrefresh(win);
  getch();  
  delwin(win);
  return multi;
}

void PrintMatrixWin(int mtrx[][n], int color)
// Вывод матрицы
{
  WINDOW *winMatrix[n][n];
  
  ConfStdSrc(1);
  wattron(stdscr, COLOR_PAIR(2));
  mvwprintw(stdscr, winY-4, winX+11, "Введённая матрица");
  refresh();
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
    {
      winMatrix[i][j] = newwin( winH, winW, winY+(winH+otstup)*i, winX+(winW+otstup)*j);
      box(winMatrix[i][j], 0, 0 );
      wbkgd(winMatrix[i][j], COLOR_PAIR(color));
      mvwprintw(winMatrix[i][j], 1, 1, "%-5d", mtrx[i][j]);
      wrefresh(winMatrix[i][j]);
    }
}

void PrintPobDiagMatrix(int mtrx[][n], int color)
{
  WINDOW *winMatrix[n][n];
  
  ConfStdSrc(1);
  wattron(stdscr, COLOR_PAIR(2));
  mvwprintw(stdscr, winY-4, winX-20, "Элементы расположенные ниже побочной диагонали заменяем на полученное Произведение");
  refresh();
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
    {
      winMatrix[i][j] = newwin( winH, winW, winY+(winH+otstup)*i, winX+(winW+otstup)*j);
      box(winMatrix[i][j], 0, 0 );
      if (i+j>n-1)
      {
        wbkgd(winMatrix[i][j], COLOR_PAIR(color)|A_REVERSE);
        mvwprintw(winMatrix[i][j], 1, 1, "%-5d", Multi);
      }
      else
      {
        wbkgd(winMatrix[i][j], COLOR_PAIR(color));
        mvwprintw(winMatrix[i][j], 1, 1, "%-5d", mtrx[i][j]);
      }
      wrefresh(winMatrix[i][j]);
    }
}
