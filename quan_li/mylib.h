#pragma once

#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
using namespace std;
#define Enter 13
#define PASSWORD "abcdef"
#define CYAN 3
#define BLACK 0
#define WHITE 15

void Nocursortype(bool);
void gotoxy(short x, short y);
int wherex(void);
int wherey(void);
void clreol();
void SetColor(WORD color);
void SetBGColor(WORD color);
void clrscr();
void resizeConsole();
void Nocursortype(bool isVisible);
void rectangle(int x, int y, int width, int height, int color);
void mauChu(int x, int y, int color, string chu);


void rectangle(int x, int y, int width, int height, int color)
{
    // 201----205----203-----205-----187
    // |              |               |
    // 186           186             186
    // |              |               |
    // 200----205----202----205-----188
    // 218 --- 196 --- 194 --- 196 --- 191
    // 179             179             179
    // 195 --- 196 --- 197 --- 196 --- 180
    // 179             179             179
    // 192 --- 196 --- 193 --- 196 --- 217
    SetColor(color);
    gotoxy(x, y);
    cout << static_cast<char>(201);
    for (int i = x; i < x + width - 2; i++) {
        gotoxy(i + 1, y);
        cout << static_cast<char>(205);
        gotoxy(i + 1, y + height - 1);
        cout << static_cast<char>(205);
    }
    gotoxy(x + width - 1, y);
    cout << static_cast<char>(187) << endl;
    for (int i = y; i < y + height - 1; i++) {
        gotoxy(x, i + 1);
        cout << static_cast<char>(186);
        gotoxy(x + width - 1, i + 1);
        cout << static_cast<char>(186) << endl;
    }
    gotoxy(x, y + height - 1);
    cout << static_cast<char>(200);
    gotoxy(x + width - 1, y + height - 1);
    cout << static_cast<char>(188);
    SetColor(WHITE);
}
void mauChu(int x, int y, int color, string chu) {
    SetColor(color);
    gotoxy(x, y);
    cout << chu;
    SetColor(WHITE);
}



void TextColor(int color) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void Nocursortype(bool isVisible)
{
    CONSOLE_CURSOR_INFO Info;
    if (isVisible) Info.bVisible = TRUE;
    else Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void gotoxy(short x, short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

int wherex(void)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey(void)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol() {
    COORD coord;
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    coord.X = info.dwCursorPosition.X;
    coord.Y = info.dwCursorPosition.Y;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
        info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
    gotoxy(info.dwCursorPosition.X, info.dwCursorPosition.Y);
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clrscr() {
    system("cls");
}
void resizeConsole() {
    HWND console = GetConsoleWindow();
    SetWindowPos(console, 0, 50, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1200, 830, TRUE);
}