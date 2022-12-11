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
        printf("@ @@@@@@@@..@@ @@  @\n @@@..@@@@..@@@@@@  \n@@@@@@....  @@..@ @@\n......        ..@@@@\n@@..    %d��  ....@@\n@@@@..        ..@@@@\n@@......      ..@@@\n@@@@@@  ..  @@..  @@\n  @@@@..@@..@@@@@@@@\n @@@  @@@@@@@@  @  @\n", number);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return;
    }
    printf("\n\n\n  ������������������������������������������\n  ��\t  ");
    if (s <= 0.5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    else if (s <= 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    else if (s <= 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("%.1lf��", s);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("\t      ��\n  ������������������������������������������");
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

    srand((unsigned)time(NULL)); //rand�� seed�� ����

    // ���� �ð��� ���� ������ ���� time.h ��������� �̿��Ͽ� �Žð����� �ٸ����� �޵��� �Ͽ���.

    for (y = 0; y < 100; y++) {

        ran_num[rand() % SIZE]++; // ������ �߻����� �ش� �迭�� ī��Ʈ ��

    }

    for (t = 0; t < SIZE; t++) {

        printf("num[%d]   %d\n", t, ran_num[t]);

        if (ran_num[t] > ran_num[x]) { // ������ ũ�� ��

            x = t;

        }
    }
    timeBomb(sec, x);

    printf("���帹�� ������ ���� %d�̰� %d�� �����Ǿ���\n", x, ran_num[x]);
    for (t = 0; t < SIZE-1; t++) {
        printf("%d�� %d\n", t+1, ran_num[t+1]);
    }
    return 0;
}