#include "stdio.h"
#include "Windows.h"
#include "stdlib.h"
#include "time.h"
#define SIZE 17

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
    //for (i = 0; i < n; i++)
    //{
        //printf("%d ", ran_num[i]);
    //}
};


int main(void) {
    int x = 0, y, t, z = 0;

    srand((unsigned)time(NULL)); //rand의 seed값 설정

    // 현재 시간에 대한 정보를 담은 time.h 헤더파일을 이용하여 매시간마다 다른값을 받도록 하엿음.

    for (y = 0; y < 100; y++) {

        ran_num[rand() % SIZE]++; // 난수를 발생시켜 해당 배열에 카운트 함

    }

    for (t = 0; t < SIZE; t++) {

        printf("num[%d]   %d\n", t, ran_num[t]);

        if (ran_num[t] > ran_num[x]) { // 순차적 크기 비교

            x = t;

        }
    }
    timeBomb(sec, x);

    printf("가장많이 생성된 수는 %d이고 %d번 생성되었다\n", x, ran_num[x]);
    for (t = 0; t < SIZE-1; t++) {
        printf("%d번 %d\n", t+1, ran_num[t+1]);
    }
    return 0;
}