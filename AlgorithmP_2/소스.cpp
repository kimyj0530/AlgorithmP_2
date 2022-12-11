#include "stdio.h"
#include "Windows.h"
#include "stdlib.h"
#include "time.h"
#define SIZE 16

double sec = 3;
int ran_num[SIZE] = {};


void timeBomb(double s, int number)
{
    system("cls");
    if (s < 0) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf("@ @@@@@@@@..@@ @@  @\n @@@..@@@@..@@@@@@  \n@@@@@@....  @@..@ @@\n......        ..@@@@\n@@..    %d번  ....@@\n@@@@..        ..@@@@\n@@......      ..@@@\n@@@@@@  ..  @@..  @@\n  @@@@..@@..@@@@@@@@\n @@@  @@@@@@@@  @  @\n", number);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return;
    }
    printf("\n\n\n  ┌───────────────────┐\n  │\t  ");
    if (s <= 0.5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    else if (s <= 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    else if (s <= 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("%.1lf초", s);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\t      │\n  └───────────────────┘");
    Sleep(10);
    timeBomb(s - 0.1, number);
}
void cnt_sort() {
    int i, j, n = SIZE, k, temp;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (ran_num[k] < ran_num[j])
            {
                k = j;
            }
        }
        temp = ran_num[i];
        ran_num[i] = ran_num[k];
        ran_num[k] = temp;
    }
};


int main(void) {
    int x = 0, y, t, z = 0;
    srand(time(NULL));
    for (y = 0; y < 100; y++) {
        ran_num[rand() % SIZE]++;
    }
    int g[SIZE] = {};
    for (int i = 0; i < SIZE; i++) {
        g[i] = (rand() % SIZE)+1;
        for (int j = 0; j < i; j++) {
            if (g[i] == g[j]) {
                i--;
                break;
            }
        }
    }
    timeBomb(sec, g[0]);
    cnt_sort();
    printf("가장많이 나온 번호는 %d번이고 %d번 생성되었다\n", g[0], ran_num[0]);
    for (t = 0; t < SIZE; t++) {
        printf("%d번 %d\n", g[t], ran_num[t]);
    }
    return 0;
