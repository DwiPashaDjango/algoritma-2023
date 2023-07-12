#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <windows.h>
#include <iomanip>
#include <string.h>

using namespace std;

int maks, top, pill, kararakter, i;
int top2;
char elemen, aa, bb;
char stack[20], infiks[20], postfiks[20], stack2[10], hasil[20];
void delay();

void gotoxy(short int x, short int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}

int create(int x)
{
    top = 0;
    gotoxy(50, 3);
    printf("   ");
    for (i = 0; i < 100; i++)
    {
        gotoxy(50, 4 + i);
        printf("       ");
    }

    if (x <= 20)
    {
        for (i = 0; i <= x; i++)
        {
            if (i == x)
            {
                gotoxy(60, 4 + i);
                printf("â");
            }
            else
            {
                gotoxy(59, 4 + i);
                printf("|      |");
            }
        }
    }
}

int push(char aa)
{
    gotoxy(50, 2);
    printf("        ");
    if (top == maks)
    {
        gotoxy(20, 2);
        printf("");
    }
    else
    {
        stack[top] = aa;
        for (i = 0; i < 11; i++)
        {
            gotoxy(50 + i, 3);
            cout << " ";
            gotoxy(51 + i, 3);
            cout << aa;
            delay();
        }

        for (i = 0; i < (maks - top); i++)
        {
            gotoxy(61, 3 + i);
            cout << " ";
            gotoxy(61, 4 + i);
            cout << aa;
            delay();
        }

        top = top + 1;
    }
}

int pop()
{
    gotoxy(20, 2);
    printf("        ");
    if (top == 0)
    {
        gotoxy(23, 2);
        printf("");
    }
    else
    {
        bb = stack[top - 1];
        for (i = (maks - (top - 1)); i > 0; i++)
        {
            gotoxy(31, 3 + i);
            cout << " ";
            gotoxy(61, 2 + i);
            cout << bb;
            delay();
        }

        for (i = 10; i < 21; i++)
        {
            gotoxy(50 + i, 3);
            cout << " ";
            gotoxy(51 + i, 3);
            cout << bb;
            delay();
        }

        gotoxy(71, 3);
        printf(" ");
        top = top - 1;
    }
}

int main()
{
    maks = 0;
    top = 0;

    do
    {
        gotoxy(3, 1);
        printf("===============================");
        gotoxy(3, 2);
        printf("      Program Stack 2IA01      ");
        gotoxy(3, 3);
        printf("===============================");
        gotoxy(4, 4);
        printf("1 : Buat Stack baru (Create)");
        gotoxy(4, 5);
        printf("2 : Tambah Elemen   (Push)");
        gotoxy(4, 6);
        printf("3 : Hapus Elemen    (Pop)");
        gotoxy(4, 7);
        printf("4 : Keluar");
        gotoxy(3, 9);
        printf("===============================");

        for (i = 10; i < 20; i++)
        {
            gotoxy(3, i);
            printf("                           ");
        }

        gotoxy(3, 10);
        printf("Masukan Pilihan : ");
        cin >> pill;

        switch (pill)
        {
        case 1:
            gotoxy(3, 12);
            printf("Masukan Kapasitas Stack (maksimal 20) : ");
            cin >> maks;
            create(maks);
            break;
        case 2:
            if (maks == 0)
            {
                gotoxy(3, 12);
                printf("Stack belum di buat. Buat Stack terlebih dahulu");
                getch();
            }
            else
            {
                gotoxy(3, 12);
                printf("Masukan satu karakter : ");
                cin >> elemen;
                push(elemen);
            }
            break;
        case 3:
            if (maks == 0)
            {
                gotoxy(3, 12);
                printf("Stack belum di buat. Buat Stack terlebih dahulu");
                getch();
            }
            else
            {
                pop();
            }
            break;

        default:
            break;
        }
    } while (pill != 4);
}

void delay()
{
    for (int y = 1; y < 100; y++)
    {
        for (int x = 1; x < 100; x++)
        {
            for (int p = 1; p < 30; p++)
            {
                cout << "";
            }
        }
    }
}