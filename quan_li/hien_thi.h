#pragma once

#include "mylib.h"
#include <string>
#include <iostream>
#include <ctime>
#include <math.h>

const int YELLOW = 14;
const int WHITE = 15;
const int BLACK = 0;
const int BLUE = 3;
const int GREEN = 10;
const int RED = 4;

using namespace std;
void press_key();
void Normal();
void Normalw();
void HighLight();
void rectangle(int x, int y, int width, int height, int color);
void mauChu(int x, int y, int color, string chu);
void DangNhap();
void clear_screen(int x, int y, int width, int height);

void press_key() {
	SetColor(WHITE);
	char menu2[3][50] = { "<-  ->: DI CHUYEN", "      ENTER: CHON", "       ESC: THOAT" };
	for (int i = 0; i < 3; i++) {
		gotoxy(3 + i * 20, 38);
		cout << menu2[i];
	}
}
void Normal() {
	SetColor(BLUE);
	SetBGColor(BLACK);
}
void Normalw()
{
	SetColor(WHITE);
	SetBGColor(BLACK);
}
void HighLight() {
	SetColor(BLUE);
	SetBGColor(WHITE);
}
void rectangle(int x, int y, int width, int height, int color)
{
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


void clear_screen(int x, int y, int width, int height)
{
	for (int i = 0; i < height; ++i)
	{
		gotoxy(x, i + y);
		for (int j = 0; j < width; ++j)
		{
			cout << " ";
		}
	}
	SetBGColor(BLACK);
	SetColor(WHITE);
}
void DangNhap() {
	rectangle(0, 0, 145, 39, GREEN);
	TieuDe();
	rectangle(45, 15, 50, 15, GREEN);
	rectangle(46, 16, 48, 14, GREEN);
	rectangle(52, 19, 37, 3, GREEN);
	mauChu(63, 16, RED, "=> DANG NHAP <=");
	rectangle(65, 26, 10, 3, GREEN);
	mauChu(66, 27, RED, " ENTER ");
	mauChu(55, 19, WHITE, "NguoiDung:");
	rectangle(52, 23, 37, 3, GREEN);
	mauChu(57, 23, WHITE, "MatKhau:");
	gotoxy(55, 20);
}
