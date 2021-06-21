#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<fstream>
#include <sstream>
#include"xu_li_nho.h"
#include"mylib.h"
#include <stdio.h>
#include<math.h>

const int so_item = 13;
const int dong = 10;
const int cot = 65;
const int Up = 72;
const int Down = 80;
const int Left = 75;
const int Right = 77;


#define boxx 50 //Vi tri x bat dau cua box
#define boxy 5 //Vi tri y bat dau cua box
#define boxs 80 //Box size
#define MAX 500
using namespace std;
// color
const int RED = 12;
#define CYAN 3
#define BLACK 0
#define WHITE 15
#define TOADOX 5
#define TOADOY 2
#define KEY_ESC 27
#define KEY_ENTER 13
using namespace std;

// ========================================= CHI TIET HOA DON ========================

struct Date
{
	int ngay, thang, nam;
};
Date LayGioHeThong()
{
	time_t t = time(NULL);
	struct tm* now = localtime(&t);
	Date date;
	date.ngay = now->tm_mday;
	date.thang = now->tm_mon + 1;
	date.nam = now->tm_year + 1900;
	return date;
}
struct chi_tiet_hoa_don
{
	int ma_vt;
	float so_luong;
	int don_gia;
	float VAT;
	bool trang_thai; // 1: mua 0: tra
	chi_tiet_hoa_don* pNext = NULL;

};
typedef struct chi_tiet_hoa_don CHI_TIET_HOA_DON;
struct ds_chi_tiet_hoa_don
{
	CHI_TIET_HOA_DON* pHead = NULL; 
	int sl = 0;
};
typedef struct ds_chi_tiet_hoa_don DS_CHI_TIET_HOA_DON;
// ========================================= DANH SACH hoa don ===========================================
struct hoa_don
{
	string so_hd ;
	Date ngaylap = LayGioHeThong();
	string loai ;// x: xuat n: nhap
	hoa_don* pNext = NULL;
	DS_CHI_TIET_HOA_DON dsct_hoa_don;

};
typedef struct hoa_don HOA_DON;
struct ds_hoa_don
{
	HOA_DON *pHead = NULL;
	int sl = 0;
};
typedef struct ds_hoa_don DS_HOA_DON;

//================================================ DS NHAN VIEN ==================================
struct nhan_vien
{
	string ma_nv;
	string ho;
	string ten;
	string phai;
	DS_HOA_DON danh_sach_hd;
};
typedef struct nhan_vien NHAN_VIEN;

struct ds_nhan_vien
{
	NHAN_VIEN* ds[500];
	int sl = 0;
};
typedef struct ds_nhan_vien DS_NHAN_VIEN;
//================================================= DS VAT TU ===========================================
struct vat_tu
{
	int ma_vt;
	string ten_vt;
	string dvt;
	float sl_ton;
	vat_tu* pLeft;
	vat_tu* pRight;
};
typedef struct vat_tu* tree;
struct ds_vat_tu
{
	tree TREE = NULL;
	int sl = 0;
};
typedef struct ds_vat_tu DS_VAT_TU;
//===================================================  THONG KE DOANH THU
struct ThongKe
{
	
	string tenvt ;
	long long tien;
};
typedef struct ThongKe thong_ke;
struct thong_ke_vt
{
	thong_ke* ds_tk[500];
	int sl = 0;
};