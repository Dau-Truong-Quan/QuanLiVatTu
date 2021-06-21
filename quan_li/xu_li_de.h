#pragma once
#include"doc_ghi_file.h"
#include<iostream>
using namespace std;

// ================================================   DANH SACH NHAN VIEN ===================
int kt_ma_nv_trung(string a, DS_NHAN_VIEN ds_nv);
string tao_ma_nv(DS_NHAN_VIEN ds_nv);
//void them_nhan_vien(DS_NHAN_VIEN& ds_nv);
//void xuat_ds_nhan_vien(DS_NHAN_VIEN ds_nv);
void hieu_chinh(DS_NHAN_VIEN& ds_nv);
void xoa_nv(DS_NHAN_VIEN& ds_nv);
int kt_ma(string a, DS_NHAN_VIEN ds_nv);
void xoa_1_vt(tree& t, int ma);
void hoan_vi_2_nv(nhan_vien*& p, nhan_vien*& q);
void sap_xep_ds_nv(ds_nhan_vien& ds_nv);
string TenDayDuCuaNhanVien(NHAN_VIEN nv);
//=================================================== DANH SACH VAT TU
bool kiem_tra_ma_vt_trung(tree t, int ma);
int tao_ma_vt(tree t);
void nhap_vat_tu(DS_VAT_TU& ds_vt);
void chuyen_cay_sang_danh_sach(tree t, vat_tu* vt[], int& n);
int xuat_ds_vt(vat_tu* vt[], int n);
void hoan_vi_2_vt(vat_tu* a, vat_tu* b);
void sap_xep_ds_vt(vat_tu* vt[], int& n);
void node_the_mang(tree& t, vat_tu*& x);
void xoa_vat_tu(DS_VAT_TU& ds_vt);
void hieu_chinh_vat_tu(DS_VAT_TU& ds_vt);
void hieu_chinh(tree& t, int  a);
vat_tu* kt_ma_vt(tree t, int ma);
//=========================================================      DANH SACH HOA DON

HOA_DON* khoi_tao_hoa_don();
string tao_ma_hd(DS_HOA_DON ds_hd);
bool kt_ma_hd_trung(string a, HOA_DON* pHead);
void lap_hoa_don(DS_NHAN_VIEN& ds_nv, DS_VAT_TU& ds_vt);
string check_loai(string loai);
void xuat_dshd(DS_HOA_DON dshd);
long long TinhTongTienMotVatTu(CHI_TIET_HOA_DON* cthd);
long long TinhTongGiaTriHoaDon(CHI_TIET_HOA_DON* pHead);
void thong_ke_hoa_don(DS_NHAN_VIEN ds_nv);

//==================================================        CHI TIET HOA DON
void them_1_cthd(CHI_TIET_HOA_DON*& pHead, CHI_TIET_HOA_DON* p);
int nhap_1_cthd(CHI_TIET_HOA_DON*& p);

int kiem_tra_thoi_gian(Date batdau, Date ketthuc, Date kiemtra);
int KiemTraThoiGian(int ngay, int thang, int nam);
int SoSanhThoiGian(Date a, Date b);
int dem_so_hoa_don_trong_mot_khoang_thoi_gian(DS_NHAN_VIEN ds_nv, Date batdau, Date ketthuc);
void TraVeMangHoaDon(string** a, DS_NHAN_VIEN ds_nv, Date batdau, Date ketthuc);


// thong ke
void thong_ke_vat_tu(DS_NHAN_VIEN ds_nv, tree ds_vt);
void hoan_doi_thong_ke(thong_ke*& a, thong_ke*& b);
void sap_xep_thong_ke(thong_ke_vt& ds_tk);
void TraVeMangVatTuXuat(thong_ke_vt& ds_tk, DS_NHAN_VIEN ds_nv, tree t, Date batdau, Date ketthuc);
int kiem_tra_da_co_vat_tu(thong_ke_vt tk, string ten);
void them_1_tk(thong_ke_vt& ds_tk, thong_ke* tk);
template <typename T>
std::string to_string(T value)
{
	//create an output string stream
	std::ostringstream os;
	//throw the value into the string stream
	os << value;
	//convert the string stream into a string and return
	return os.str();
}
// =============================================================    MENU   =================
char thucdon[so_item][50] = { "       THEM NHAN VIEN       ",
							  "  XUAT DANH SACH NHAN VIEN  ",
							  "       XOA NHAN VIEN        ",
							  "         HIEU CHINH         ",
							  "         THEM VAT TU        ",
							  "     IN DANH SACH VAT TU    ",
							  "       XOA MOT VAT TU       ",
							  "      HIEU CHINH VAT TU     ",
							  "        LAP HOA DON         ",
							  "        XUAT HOA DON        ",
							  "  XUAT HOA DON THEO NGAY    ",
							  "      THONG KE VAT TU       ",
							  "            THOAT           " };

void Normal() {
	SetColor(15);
	SetBGColor(0);
}
void HighLight() {
	SetColor(15);
	SetBGColor(0);
}
int MenuDong(char td[so_item][50]) {
	system("cls");
	TieuDe();
	Normal();
	Nocursortype(0);
	int chon = 0;
	int i;
	for (i = 0; i < so_item; i++)
	{
		gotoxy(cot, dong + i * 2);
		cout << td[i];
	}
	rectangle(cot - 1, dong + chon * 2 - 1, 30, 3, WHITE);
	HighLight();
	gotoxy(cot, dong + chon * 2);
	cout << td[chon];
	char kytu;
	do {
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu) {
		case Up:if (chon + 1 > 1)
		{
			Normal();
			rectangle(cot - 1, dong + chon * 2 - 1, 30, 3, BLACK);
			gotoxy(cot, dong + chon * 2);
			cout << td[chon];
			chon--;
			rectangle(cot - 1, dong + chon * 2 - 1, 30, 3, WHITE);
			HighLight();
			gotoxy(cot, dong + chon * 2);
			cout << td[chon];
			Normal();

		}
			   break;
		case Down:if (chon + 1 < so_item)
		{
			Normal();
			rectangle(cot - 1, dong + chon * 2 - 1, 30, 3, BLACK);
			gotoxy(cot, dong + chon * 2);
			cout << td[chon];
			chon++;
			rectangle(cot - 1, dong + chon * 2 - 1, 30, 3, WHITE);
			HighLight();
			gotoxy(cot, dong + chon * 2);
			cout << td[chon];
			Normal();

		}
				 break;
		case 13:
			return chon + 1;
		}  // end switch
	} while (1);
}


void menu()
{
	DS_NHAN_VIEN ds_nv;
	DS_VAT_TU ds_vt;
	NHAN_VIEN nv;
	HOA_DON hd;

	doc_file_nhan_vien(ds_nv);
	doc_file_vat_tu(ds_vt);
	bool kt = true;
	while (kt == true)
	{
		int luachon = MenuDong(thucdon);
		switch (luachon)
		{
		case 1:
		{
			int k = 0;
			system("cls");
			if (ds_nv.sl == 500)
			{
				cout << " Them khong thanh cong! data da day " << endl;
				system("pause");
			}
			else
			{
				k = them_nhan_vien(ds_nv);
				if (k == -2)
					break;
				ghi_file_nhan_vien(ds_nv);
			}
			// ham them
			break;
		}
		case 2:
		{
			system("cls");
			sap_xep_ds_nv(ds_nv);
			xuat_ds_nhan_vien(ds_nv);
			break;
		}
		case 3:
		{
			system("cls");
			xoa_nv(ds_nv);
			ghi_file_nhan_vien(ds_nv);
			break;
		}
		case 4:
		{
			system("cls");
			hieu_chinh(ds_nv);
			ghi_file_nhan_vien(ds_nv);
			break;
		}
		case 5:
		{
			system("cls");
			nhap_vat_tu(ds_vt);

			break;
		}
		case 6:
		{
			system("cls");
			int n = 0;
			vat_tu* vt[100];
			chuyen_cay_sang_danh_sach(ds_vt.TREE, vt, n);
			sap_xep_ds_vt(vt, n);
			xuat_ds_vt(vt, n);

			/*xuat_kieu_nhi_phan(ds_vt.TREE);*/

			break;
		}
		case 7:
		{
			system("cls");
			gotoxy(65, 47);
			cout << "| ENTER: XOA";
			int n = 0;
			vat_tu* vt[100];
			chuyen_cay_sang_danh_sach(ds_vt.TREE, vt, n);
			sap_xep_ds_vt(vt, n);
			int k;
			k = xuat_ds_vt(vt, n);
			if (k == -1)
				break;
			xoa_vat_tu(ds_vt);
			ghi_file_vat_tu(ds_vt);
			break;
		}
		case 8:
		{
			
			system("cls");
			gotoxy(63, 47);
			cout << "| ENTER: HIEU CHINH";
			int n = 0;
			vat_tu* vt[100];
			chuyen_cay_sang_danh_sach(ds_vt.TREE, vt, n);
			sap_xep_ds_vt(vt, n);
			int k;
			k = xuat_ds_vt(vt, n);
			if (k == -1)
				break;

			hieu_chinh_vat_tu(ds_vt);
			ghi_file_vat_tu(ds_vt);
			break;
		}
		case 9:
		{
			system("cls");
			lap_hoa_don(ds_nv, ds_vt);
			ghi_file_nhan_vien(ds_nv);
			break;
			/*XuatChiTietHoaDon( nv, hd);*/
		}
		case 10:
		{
			system("cls");
			string a;
			Nocursortype(1);
		nhaplai:
			gotoxy(63, 6);
			cout << "              ";
			rectangle(30, 5, 50, 3, WHITE);
			gotoxy(31, 6);
			cout << " NHAP MA NHAN VIEN LAP HOA DON:  ";

			rewind(stdin);
			int n = nhap_ki_tu(a, 1);
			if (n == -1)
				break;
			if (kt_ma_nv_trung(a, ds_nv) >= 0)
			{
				int i = kt_ma_nv_trung(a, ds_nv);
				xuat_dshd(ds_nv.ds[i]->danh_sach_hd);
			}
			else
			{
				gotoxy(30, 15);
				SetColor(RED);
				cout << " KHONG THAY NHAN VIEN! ";
				Sleep(1500);
				gotoxy(30, 15);
				cout << "                       ";
				goto nhaplai;
			}

			break;
		}
		case 11:
		{
			system("cls");
			thong_ke_hoa_don(ds_nv);
			break;
		}
		case 12:
		{
			system("cls");
			thong_ke_vat_tu(ds_nv, ds_vt.TREE);
			break;
		}
		case 13:
		{
			
			kt = false;
			break;
		}

		}
	}
}



// -------------------------------  SAP XEP NHAN VIEN
void sap_xep_ds_nv(ds_nhan_vien& ds_nv)
{
	for (int i = 0; i < ds_nv.sl -1; i++)
	{
		for (int j = i + 1; j < ds_nv.sl; j++)
		{
			if (ds_nv.ds[i]->ten > ds_nv.ds[j]->ten)
			{
				hoan_vi_2_nv(ds_nv.ds[i], ds_nv.ds[j]);
			}
			else if (ds_nv.ds[i]->ten == ds_nv.ds[j]->ten)
			{
				if (ds_nv.ds[i]->ho > ds_nv.ds[j]->ho)
				{
					hoan_vi_2_nv(ds_nv.ds[i], ds_nv.ds[j]);
				}
			}
		}
	}
}
//--------------------------------------------   HOAN VI 2 NHAN VIEN
void hoan_vi_2_nv(nhan_vien*& p, nhan_vien*& q)
{
	nhan_vien* tam = new nhan_vien;
	tam->ho = p->ho;
	tam->ma_nv = p->ma_nv;
	tam->ten = p->ten;
	tam->phai = p->phai;
	tam->danh_sach_hd = p->danh_sach_hd;

	p->ho = q->ho;
	p->ma_nv = q->ma_nv;
	p->ten = q->ten;
	p->phai = q->phai;
	p->danh_sach_hd = q->danh_sach_hd;

	q->ho = tam->ho;
	q->ma_nv = tam->ma_nv;
	q->ten = tam->ten;
	q->phai = tam->phai;
	q->danh_sach_hd = tam->danh_sach_hd;
	delete tam;
}
//=============================================  HIEU CHINH NHAN VIEN
void hieu_chinh(DS_NHAN_VIEN& ds_nv)
{

	int h;
	gotoxy(65, 47);
	cout << "| ENTER: HIEU CHINH";
	
	h = xuat_ds_nhan_vien(ds_nv);
	if (h == -1)
	{
		return;
	}
	Nocursortype(1);
nhaplai:
	gotoxy(143, 10);
	cout << "               ";
	rectangle(122, 9, 40, 6, WHITE);
	string a;
	gotoxy(125, 10);
	cout << "NHAP MA NHAN VIEN: ";
	int k = nhap_ki_tu(a, 1);
	if (k == -1)
	{
		return;
	}
	int vt = kt_ma(a, ds_nv);
	if (vt < 0)
	{
		gotoxy(125, 16);
		cout << "NHAN VIEN KHONG TON TAI!! ";
		Sleep(1000);
		gotoxy(125, 16);
		cout << "                            ";
		goto nhaplai;

	}
	else
	{
		int kt = 0;
		cin.ignore();
		gotoxy(125, 11);
		cout << "HO NHAN VIEN: " << ds_nv.ds[vt]->ho;
		kt = nhap_ki_tu(ds_nv.ds[vt]->ho, 0);
		if (kt == -1)
		{
			return;
		}
		gotoxy(125, 12);
		cout << "TEN NHAN VIEN: " << ds_nv.ds[vt]->ten;
		kt = nhap_ki_tu(ds_nv.ds[vt]->ten, 0);
		if (kt == -1)
		{
			return;
		}
		gotoxy(125, 13);
		cout << "GIOI TINH NHAN VIEN: " << ds_nv.ds[vt]->phai;
		kt = nhap_ki_tu(ds_nv.ds[vt]->phai, 0);
		if (kt == -1)
		{
			return;
		}
		gotoxy(125, 16);
		cout << "THAY DOI THANH CONG! ";
		Sleep(1000);
		gotoxy(125, 16);
		cout << "                       ";
	}
}
//============================================================================                   VAT TU




int xuat_ds_vt(vat_tu* vt[], int n)
{
	int page = 1;
	char key;
	int number = n;

	while (1) {
		rectangle(20, 5, 100, 37, WHITE);
		rectangle(21, 6, 98, 3, WHITE);
		rectangle(5, 46, 80, 3, WHITE);
		gotoxy(6, 47);
		cout << " ESC: THOAT   |    <- : QUA TRAI     |     ->: QUA PHAI";
		gotoxy(22, 7); cout << " MA VAT TU              TEN VAT TU                 DON VI TINH           SO LUONG TON ";
		gotoxy(38, 5); cout << static_cast<char>(203);
		gotoxy(38, 41); cout << static_cast<char>(202);
		for (int i = 1; i < 36; i++)
		{
			gotoxy(38, 5 + i);
			cout << static_cast<char>(186);
		}
		gotoxy(62, 5); cout << static_cast<char>(203);
		gotoxy(62, 41); cout << static_cast<char>(202);
		for (int i = 1; i < 36; i++)
		{
			gotoxy(62, 5 + i);
			cout << static_cast<char>(186);
		}
		gotoxy(91, 5); cout << static_cast<char>(203);
		gotoxy(91, 41); cout << static_cast<char>(202);
		for (int i = 1; i < 36; i++)
		{
			gotoxy(91, 5 + i);
			cout << static_cast<char>(186);
		}
		for (int i = 15 * (page - 1); i < number && i < 15 * page; i++)
		{
			gotoxy(25, i % 15 * 2 + 10);
			cout << vt[i]->ma_vt;
			gotoxy(45, i % 15 * 2 + 10);
			cout << vt[i]->ten_vt;
			gotoxy(75, i % 15 * 2 + 10);
			cout << vt[i]->dvt;
			gotoxy(97, i % 15 * 2 + 10);
			cout << vt[i]->sl_ton;
			gotoxy(120, 47);
			int r = 0;
			if (number % 15 > 0);
			{
				r = 1;
			}
			cout << "TRANG " << page << "/" << (number / 15)+ r;
		}

		key = _getch();
		if (key == 0) key = _getch();
		switch (key) {
		case Left: if (page > 1) {
			page--;
			system("cls");

		}
				 break;
		case Right: if (page * 15 < number) {
			page++;
			system("cls");
		}
				  break;
		case KEY_ENTER:
		{
			return 1;
		}
		case KEY_ESC:
		{
			return -1;
		}
		}



	}


}
//=============================================== SAP XEP 2 VAT TU
void sap_xep_ds_vt(vat_tu* vt[], int& n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (vt[i]->ten_vt > vt[j]->ten_vt)
			{
				hoan_vi_2_vt(vt[i], vt[j]);
			}
		}
	}
}
//-------------------------------------------------------  HOAN VI 2 VAT TU
void hoan_vi_2_vt(vat_tu* a, vat_tu* b)
{
	vat_tu* tam = new vat_tu;
	tam->ten_vt = a->ten_vt;
	tam->ma_vt = a->ma_vt;
	tam->dvt = a->dvt;
	tam->sl_ton = a->sl_ton;
	//  a nhan gia tri b
	a->ten_vt = b->ten_vt;
	a->ma_vt = b->ma_vt;
	a->dvt = b->dvt;
	a->sl_ton = b->sl_ton;
	// b nhan gia tri a
	b->ten_vt = tam->ten_vt;
	b->ma_vt = tam->ma_vt;
	b->dvt = tam->dvt;
	b->sl_ton = tam->sl_ton;
	delete tam;
}
//================================== xoa vat tu
void xoa_vat_tu(DS_VAT_TU& ds_vt)
{
	Nocursortype(1);
	
	int a = 0;
	rectangle(122, 9, 40, 3, WHITE);
	gotoxy(125, 10);
	int k;
	cout << "NHAP MA VAT TU CAN XOA: "; k = nhap_so_nguyen(a);
	if (k == -1)
		return;
	bool kt = kiem_tra_ma_vt_trung(ds_vt.TREE, a);
	if (kt == true)
	{
		//xoa
		xoa_1_vt(ds_vt.TREE, a);
		ds_vt.sl--;
		gotoxy(125, 13);
		cout << "XOA THANH CONG!" << endl;
		Sleep(1000);
		gotoxy(125, 13);
		cout << "                                ";
	}
	else
	{
		gotoxy(125, 13);
		cout << "MA VAT TU KHONG TON TAI !!";
		Sleep(1000);
		gotoxy(125, 13);
		cout << "                                ";
		
		
	}
}
void xoa_1_vt(tree& t, int ma)
{
	if (t != NULL)
	{
		if (t->ma_vt == ma)
		{
			vat_tu* x = t;//x se luu node can giai phong
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else if (t->pLeft != NULL && t->pRight != NULL)
			{
				//tim node the mang: trai cung cay con phai
				node_the_mang(t->pRight, x);
			}
			delete x;
		}
		else if (t->ma_vt < ma)
		{
			xoa_1_vt(t->pRight, ma);
		}
		else if (t->ma_vt > ma)
		{
			xoa_1_vt(t->pLeft, ma);
		}
	}
}
void node_the_mang(tree& t, vat_tu*& x)
{
	if (t->pLeft != NULL)
	{
		node_the_mang(t->pLeft, x);
	}
	else//trai cung
	{
		hoan_vi_2_vt(t, x);
		x = t;//x se luu vi tri node nay de ty nua giai phong
		t = t->pRight;
	}
}
//========================= HIEU CHINH VAT TU ====================
void hieu_chinh_vat_tu(DS_VAT_TU& ds_vt)
{
	Nocursortype(1);
	rectangle(122, 9, 40, 6, WHITE);
	
nhaplai:
	int a = 0;
	int k;

	gotoxy(143, 10);
	cout << "               ";
	gotoxy(125, 10);
	cout << "MA VAT TU CAN HIEU CHINH:  ";
	k = nhap_so_nguyen(a);
	if (k == -1)
	{
		return;
	}
	bool kt = kiem_tra_ma_vt_trung(ds_vt.TREE, a);
	if (kt == true)
	{
		hieu_chinh(ds_vt.TREE, a);
	}
	else
	{
		gotoxy(125, 17);
		cout << " KHONG TON TAI VAT TU!!!  ";
		Sleep(1000);
		gotoxy(125, 17);
		cout << "                           ";
		goto nhaplai;

	}
}

void hieu_chinh(tree& t, int  a)
{
	if (t != NULL)
	{
		if (t->ma_vt == a)
		{

			gotoxy(125, 11);
			cout << "TEN VAT TU " << t->ten_vt;
			nhap_ki_tu(t->ten_vt, 0);
			gotoxy(125, 12);
			cout << "DON VI TINH: " << t->dvt;
			nhap_ki_tu(t->dvt, 0);

		}
		else if (t->ma_vt < a)
		{
			hieu_chinh(t->pRight, a);
		}
		else if (t->ma_vt > a)
		{
			hieu_chinh(t->pLeft, a);
		}
	}
}

// =========================================================                          LAP HOA DON
void lap_hoa_don(DS_NHAN_VIEN& ds_nv, DS_VAT_TU& ds_vt)
{
	Nocursortype(1);
nhaplai:
	string a = "";
	rectangle(9, 5, 50, 3, WHITE);
	gotoxy(40, 6);
	cout << "             ";
	gotoxy(10, 6);
	cout << " NHAP MA NHAN VIEN LAP HOA DON:  ";
	int n = nhap_ki_tu(a, 1);
	if (n == -1)
		return;
	int ma = kt_ma_nv_trung(a, ds_nv);
	if (ma < 0)
	{
		gotoxy(10, 10);
		cout << " KHONG TON TAI NHAN VIEN ";
		Sleep(1000);
		gotoxy(10, 10);
		cout << "                           ";
		goto nhaplai;
	}
	else
	{
	NhapLai:
		gotoxy(80, 5); cout << "                                               ";
		gotoxy(80, 6); cout << "                                               ";
		gotoxy(80, 7); cout << "                                               ";
		gotoxy(80, 8); cout << "                                               ";
		gotoxy(80, 9); cout << "                                               ";
		gotoxy(80, 10); cout << "                                              ";
		gotoxy(80, 11); cout << "                                              ";
		gotoxy(80, 12); cout << "                                              ";
		gotoxy(80, 13); cout << "                                              ";
		gotoxy(80, 14); cout << "                                              ";
		gotoxy(80, 15); cout << "                                              ";
		Nocursortype(0);
		hoa_don* p = khoi_tao_hoa_don();
		bool kt = true;
		while (kt == true)
		{
			gotoxy(10, 12);
			cout << "CHON LOAI HOA DON ";
			string str[2] = { " HOA DON NHAP " ,"HOA DON XUAT" };
			for (int i = 0; i < 2; i++)
			{
				gotoxy(10, 15 + i * 2);
				cout << str[i];
			}
			int chon = 0;
			rectangle(9, 14, 15, 3, WHITE);

			char key;

			while (1)
			{
				key = _getch();
				if (key == -32) key = _getch();
				switch (key)
				{
				case Up: if (chon == 1) {
					rectangle(9, 14 + chon * 2, 15, 3, BLACK);
					chon--;
					rectangle(9, 14 + chon * 2, 15, 3, WHITE);
				}
					   break;
				case Down: if (chon == 0) {
					rectangle(9, 14 + chon * 2, 15, 3, BLACK);
					chon++;
					rectangle(9, 14 + chon * 2, 15, 3, WHITE);
				}break;
				case KEY_ENTER:
					break;
				}

				if (key == KEY_ENTER)
					break;

			}

			switch (chon + 1)
			{
			case 1:
			{

				Nocursortype(1);
				rectangle(80, 5, 45, 5, WHITE);
				p->so_hd = tao_ma_hd(ds_nv.ds[ma]->danh_sach_hd);
				p->loai = "N";
				gotoxy(81, 6);
				cout << "LOAI HOA DON:  " << check_loai(p->loai);
				gotoxy(81, 7);
				cout << "MA HOA DON:  " << p->so_hd;

				string s = chuyenngaythanhchuoi(p->ngaylap);
				gotoxy(81, 8);
				cout << "NGAY LAP: " << s;
				bool h = true;
				while (h == true)
				{
					chi_tiet_hoa_don* k = khoi_tao_cthd();
					int m = nhap_1_cthd(k);
					if (m == -2)
						return;
					them_1_cthd(p->dsct_hoa_don.pHead, k);
					vat_tu* t = kt_ma_vt(ds_vt.TREE, k->ma_vt);
					if (t != NULL)
					{
						int vt1, vt2;
						vt1 = t->sl_ton;
						vt2 = k->so_luong;
						t->sl_ton = vt1 + vt2;
						ghi_file_vat_tu(ds_vt);
					}
					else
					{

						vat_tu* vt = khoi_tao_node_vat_tu();
						vt->sl_ton = k->so_luong;
						vt->ma_vt = k->ma_vt;
						rectangle(80, 20, 45, 6, WHITE);
						gotoxy(70, 26);
						cout << "VAT TU HIEN CHUA CO TRONG KHO! VUI LONG NHAP THEM THONG TIN";
						gotoxy(81, 21);
						cout << "TEN VAT TU: "; nhap_ki_tu(vt->ten_vt, 0);
						gotoxy(81, 22);
						cout << "DON VI TINH:  "; cin >> vt->dvt;
						them_1_vt(ds_vt.TREE, vt);
						ds_vt.sl++;
						ghi_file_vat_tu(ds_vt);
					}
					gotoxy(75, 25);
					cout << "BAN CO MUON TIEP TUC LAP CHI TIET HOA DON? ";
					string tieptuc;
					nhap_ki_tu(tieptuc, 4);
					if (tieptuc == "N")
					{
						h = false;
					}
				}
				
				break;
			}
			case 2:
			{
				Nocursortype(1);
				rectangle(80, 5, 45, 5, WHITE);
				p->so_hd = tao_ma_hd(ds_nv.ds[ma]->danh_sach_hd);
				p->loai = "X";
				gotoxy(81, 6);
				cout << "LOAI HOA DON:  " << check_loai(p->loai);
				gotoxy(81, 7);
				cout << "MA HOA DON:  " << p->so_hd;
				gotoxy(81, 8);
				string s = chuyenngaythanhchuoi(p->ngaylap);

				cout << "NGAY LAP: " << s;
				bool h = true;
				while (h == true)
				{
					
				nhap_lai:
					chi_tiet_hoa_don* k = khoi_tao_cthd();
					int m = nhap_1_cthd(k);
					if (m == -2)
						return;
					them_1_cthd(p->dsct_hoa_don.pHead, k);
					vat_tu* t = kt_ma_vt(ds_vt.TREE, k->ma_vt);
					if (t != NULL)
					{
						if (t->sl_ton > k->so_luong)
						{
							float vt1 = 0, vt2 = 0, vt3 = 0;
							vt1 = t->sl_ton;
							vt2 = k->so_luong;
							vt3 = vt1 - vt2;
							t->sl_ton = vt1 - vt2;
							ghi_file_vat_tu(ds_vt);

						}
						else
						{
							gotoxy(70, 26);
							cout << "SO LUONG VAT TU TRONG KHO HIEN KHONG DU!!! SO LUONG CON: " << t->sl_ton;
							Sleep(3000);
							gotoxy(70, 26);
							cout << "                                                                                ";
							goto nhap_lai;

						}

					}
					else
					{
						vat_tu* vt = khoi_tao_node_vat_tu();
						vt->sl_ton = k->so_luong;
						vt->ma_vt = k->ma_vt;
						gotoxy(70, 26);
						cout << "VAT TU HIEN CHUA CO TRONG KHO! VUI LONG NHAP LAI THONG TIN ";
						Sleep(1000);
						gotoxy(70, 26);
						cout << "                                                            ";
						goto nhap_lai;

					}

					gotoxy(75, 25);
					cout << "BAN CO MUON TIEP TUC LAP CHI TIET HOA DON (Y/N)? ";
					string tieptuc;
					nhap_ki_tu(tieptuc, 4);
					if (tieptuc == "N")
					{
						h = false;
					}

				}

				break;
			}

			}
			gotoxy(75, 26);
			cout << "BAN CO MUON TIEP TUC LAP HOA DON (Y/N)? ";
			string tieptuc2;
			nhap_ki_tu(tieptuc2, 4);
			if (tieptuc2 == "N")
			{
				them_1_hoa_don(ds_nv.ds[ma]->danh_sach_hd.pHead, p);
				ds_nv.ds[ma]->danh_sach_hd.sl++;
				kt = false;
			}
			else
			{
				goto NhapLai;
			}
		}
	}
}
//---------------------------------------------            XUAT DANH SACH HOA DON
void xuat_dshd(DS_HOA_DON dshd)
{
	int y = 1;
	Nocursortype(0);
	for (HOA_DON* k = dshd.pHead; k != NULL; k = k->pNext)
	{
		
		rectangle(25, 10, 60, 20, WHITE);
		gotoxy(26, 11);
		cout << "    NGAY LAP          SO HOA DON           LOAI      ";
		gotoxy(42, 10); cout << static_cast<char>(203);
		gotoxy(42, 29); cout << static_cast<char>(202);
		for (int i = 1; i < 19; i++)
		{
			gotoxy(42, 10 + i);
			cout << static_cast<char>(186);
		}
		gotoxy(60, 10); cout << static_cast<char>(203);
		gotoxy(60, 29); cout << static_cast<char>(202);
		for (int i = 1; i < 19; i++)
		{
			gotoxy(60, 10 + i);
			cout << static_cast<char>(186);
		}
		if (k->loai == "X")
		{
			gotoxy(67, y * 2 + 11);
			cout << " XUAT!";
		}
		else
		{
			gotoxy(67, y * 2 + 11);
			cout << " NHAP";
		}
		string gio = chuyenngaythanhchuoi(k->ngaylap);
		gotoxy(30, y * 2 + 11);
		cout << gio;

		gotoxy(48, y * 2 + 11);
		cout << k->so_hd;
		y++;
	}
	char c;
	c = _getch();
	if (c == -32)
	{
		c = _getch();
	}
	if (c == KEY_ESC)
	{
		return;
	}
}
string check_loai(string loai)
{
	string s;
	if (loai == "N")
	{
		s = "NHAP";
		return s;
	}
	return "XUAT";
}

//-------------------------------------------------------- KIEM TRA MA VAT TU VA TRA VE GIA TRI CUA NODE HIEN TAI
vat_tu* kt_ma_vt(tree t, int ma)
{
	if (t != NULL)
	{
		if (t->ma_vt == ma)
		{
			return t;
		}
		else if (t->ma_vt < ma)
		{
			kt_ma_vt(t->pRight, ma);
		}
		else if (t->ma_vt > ma)
		{
			kt_ma_vt(t->pLeft, ma);
		}
	}
	else
	{
		return NULL;
	}
}



//----------------------------------- tao ma hoa don
string tao_ma_hd(DS_HOA_DON ds_hd)
{
	string a = "HD0000";
	do
	{
		for (int i = 2; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (kt_ma_hd_trung(a, ds_hd.pHead) == true); // ----------    KIEM TRA BI TRUNG THI TAO LAI MA MOI
	return a;
}
//---------------------------------------------------  KIEM TRA MA HOA DON BI TRUNG
bool kt_ma_hd_trung(string a, HOA_DON* pHead)
{
	for (HOA_DON* k = pHead; k != NULL; k = k->pNext)
	{
		if (k->so_hd == a)
		{
			return true;
		}
	}
	return false;
}
//==============================================================            DANH SACH HOA DON
//bool KiemTraRong(DS_CHI_TIET_HOA_DON ds_cthd)
//{
//	if (ds_cthd == NULL) return true;
//	return false;
//}
////                                                                 THEM VAT TU VAO CUOI DANH SACH
//bool them_vao_cuoi_danh_dach(DS_CHI_TIET_HOA_DON &ds_cthd, CHI_TIET_HOA_DON cthd)
//{
//	DS_CHI_TIET_HOA_DON p = new ds_chi_tiet_hoa_don;
//	if (p == NULL) return false;
//	p->data_cthd = cthd;
//	p->pNext = NULL;
//
//	if (ds_cthd == NULL)
//	{
//		ds_cthd = p;
//	}
//	else
//	{
//		DS_CHI_TIET_HOA_DON q;
//		for (q = ds_cthd; q->pNext != NULL; q = q->pNext);
//		q->pNext = p;
//	}
//	return true;
//}
//
//
//long long tinh_tong_tien_1_vt(CHI_TIET_HOA_DON cthd)
//{
//	long long tong = 0;
//	tong = (cthd.don_gia * cthd.so_luong);
//
//	return tong * double((100 + cthd.VAT) / 100.0);
//}
//long long TinhTongGiaTriHoaDon(DS_CHI_TIET_HOA_DON dscthd)
//{
//	long long tong = 0;
//	DS_CHI_TIET_HOA_DON p = dscthd;
//	if (p == NULL) return 0;
//	while (p != NULL)
//	{
//		tong += tinh_tong_tien_1_vt(p->data_cthd);
//		p = p->pNext;
//	}
//	return tong;
//}
//
//
// =================================================                                        CHI TIET HOA DON
void them_1_cthd(CHI_TIET_HOA_DON*& pHead, CHI_TIET_HOA_DON* p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else for (CHI_TIET_HOA_DON* k = pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == NULL)
		{
			k->pNext = p;
			break;
		}
	}
}
int nhap_1_cthd(CHI_TIET_HOA_DON*& p)
{
	int k = 0;
	p->ma_vt = 0;
	p->so_luong = 0;
	p->VAT = 0;
	p->don_gia = 0;
	rectangle(80, 10, 45, 6, WHITE);
	gotoxy(96, 11);
	cout << "               ";
	gotoxy(96, 12);
	cout << "                ";
	gotoxy(94, 13);
	cout << "                     ";
	gotoxy(91, 14);
	cout << "                     ";
	gotoxy(81, 11);
	cout << "NHAP MA VAT TU: ";
	k = nhap_so_nguyen(p->ma_vt);
	if (k == -1)
	{
		return -2;
	}

	gotoxy(81, 12);
	cout << "NHAP SO LUONG: ";
	k = nhap_so_thuc(p->so_luong);
	if (k == -1)
	{
		return -2;
	}

	gotoxy(81, 13);
	cout << "NHAP DON GIA: ";
	k = nhap_so_nguyen(p->don_gia);
	if (k == -1)
	{
		return -2;
	}
	gotoxy(81, 14);
	cout << "NHAP THUE: ";
	k = nhap_so_thuc(p->VAT);
	if (k == -1)
	{
		return -2;
	}

}
//===============================================      LIET KE HOA DON TRONG 1 KHOANG THOI GIAN
void thong_ke_hoa_don(DS_NHAN_VIEN ds_nv)
{
	
	Date batdau, ketthuc;
NhapLai:
	gotoxy(25, 1);
	cout << "BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN ";
	int ngbd = 0, thbd = 0, nambd = 0, ngkt = 0, thkt = 0, namkt = 0;
	int a, b;
	int k;
	int kq;
	int n;
	string** arr;
	Nocursortype(1);

	gotoxy(30, 3);   cout << "Tu ngay: ";
	gotoxy(40, 3);   cout << "  ";
	gotoxy(42, 3);   cout << "/";
	gotoxy(43, 3);   cout << "  ";
	gotoxy(45, 3);   cout << "/";
	gotoxy(46, 3);   cout << "    ";
	gotoxy(51, 3);   cout << "Den ngay: ";
	gotoxy(62, 3);   cout << "  ";
	gotoxy(64, 3);   cout << "/";
	gotoxy(65, 3);   cout << "  ";
	gotoxy(67, 3);   cout << "/";
	gotoxy(68, 3);   cout << "                                     ";

	gotoxy(40, 3); k = nhap_so_nguyen(ngbd); if (k == -1)return;
	gotoxy(43, 3); k = nhap_so_nguyen(thbd); if (k == -1)return;
	gotoxy(46, 3); k = nhap_so_nguyen(nambd); if (k == -1)return;

	gotoxy(62, 3); k = nhap_so_nguyen(ngkt); if (k == -1)return;
	gotoxy(65, 3); k = nhap_so_nguyen(thkt);  if (k == -1)return;
	gotoxy(68, 3); k = nhap_so_nguyen(namkt); if (k == -1)return;
	batdau.ngay = ngbd;
	batdau.thang = thbd;
	batdau.nam = nambd;
	ketthuc.ngay = ngkt;
	ketthuc.thang = thkt;
	ketthuc.nam = namkt;
	a = KiemTraThoiGian(batdau.ngay, batdau.thang, batdau.nam);
	b = KiemTraThoiGian(ketthuc.ngay, ketthuc.thang, ketthuc.nam);
	if (a == 0 || b == 0)
	{
		BaoLoi("Thoi Gian Nhap Vao Khong Hop Le");
		Sleep(100);
		system("cls");
		goto NhapLai;
	}
	else
	{
		n = dem_so_hoa_don_trong_mot_khoang_thoi_gian(ds_nv, batdau, ketthuc);
		arr = new string * [n];
		kq = SoSanhThoiGian(ketthuc, batdau);
		if (kq == -1)
		{
			BaoLoi("Thoi Gian Nhap Vao Khong Hop Le");
			Sleep(1000);
			ngbd = thbd = nambd = 0;
			ngkt = thkt = namkt = 0;
			goto NhapLai;
		}
		arr = new string * [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new string[5]{ "" };
		}
		TraVeMangHoaDon(arr, ds_nv, batdau, ketthuc);

		if (n < 1)
		{
			gotoxy(30, 10);
			cout << "DANH SACH RONG !!";
			Sleep(1000);
			gotoxy(30, 10);
			cout << "                  ";
			goto NhapLai;
		}
		gotoxy(10, 6);
		cout << "SO HOA DON ";
		gotoxy(23, 6);
		cout << "SO NGAY LAP ";
		gotoxy(35, 6);
		cout << "   LOAI HOA DON ";
		gotoxy(55, 6);
		cout << "SO HO TEN NHAN VIEN ";
		gotoxy(80, 6);
		cout << "SO TRI GIA HOA DON ";
	
		for (int i = 0; i < n; i++)
		{
			gotoxy(10, 8 + i * 2);
			cout << arr[i][0];
			gotoxy(23, 8 + i * 2);
			cout << arr[i][1];
			gotoxy(40, 8 + i * 2);
			cout << arr[i][2];
			gotoxy(55, 8 + i * 2);
			cout << arr[i][3];
			gotoxy(80, 8 + i * 2);
			cout << arr[i][4];

		}
		gotoxy(30, 30);
		cout << "NHAN PHIM BAT KI DE TIEP TUC HOAC NHAN PHIM ESC DE THOAT";
		char c;
		c = _getch();
		if (c == -32)
		{
			c = _getch();
		}
		if (c == KEY_ESC)
		{
			return;
		}
		else
		{
			goto NhapLai;
		}
	}
}
int kiem_tra_thoi_gian(Date batdau, Date ketthuc, Date kiemtra)
{
	// nam kiem tra nam ngoai batdau, ketthuc
	if (kiemtra.nam < batdau.nam || kiemtra.nam > ketthuc.nam) return 0;

	if (kiemtra.nam == batdau.nam)
	{
		// thang kiem tra nam ngoai batdau
		if (kiemtra.thang < batdau.thang) return 0;
		// ngay kiem tra nam ngoai batdau
		if (kiemtra.thang == batdau.thang && kiemtra.ngay < batdau.ngay) return 0;
	}

	if (kiemtra.nam == ketthuc.nam)
	{
		if (kiemtra.thang > ketthuc.thang) return 0;
		if (kiemtra.thang == ketthuc.thang && kiemtra.ngay > ketthuc.ngay) return 0;
	}
	// thoi gian hop le, nam giua ngay bat dau va ngay ket thuc
	return 1;
}
int KiemTraThoiGian(int ngay, int thang, int nam)
{
	// vtkhonghople: ngay = 0, thang = 1, nam = 2
	Date hientai;
	hientai = LayGioHeThong();
	if (nam > hientai.nam)
	{
		return 0;
	}
	else if (thang <= 0 || thang > 12 || (nam == hientai.nam && thang > hientai.thang))
	{
		return 0;
	}
	else if (nam == hientai.nam && thang == hientai.thang && ngay > hientai.ngay)
	{
		return 0;
	}
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (ngay <= 0 || ngay > 31)
		{
			return 0;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (ngay <= 0 || ngay > 30)
		{
			return 0;
		}
		break;
	case 2:
		if ((nam % 4 == 0 && (ngay <= 0 || ngay > 29)) || (nam % 4 != 0 && (ngay <= 0 || ngay > 28)))
		{
			return 0;
		}
		break;
	}
	return 1;
}
int SoSanhThoiGian(Date a, Date b)
{
	if (a.nam > b.nam) return 1;
	else if (a.nam < b.nam) return -1;
	else
	{
		if (a.thang > b.thang) return 1;
		else if (a.thang < b.thang) return -1;
		else
		{
			if (a.ngay > b.ngay) return 1;
			else if (a.ngay < b.ngay) return -1;
			else return 0;
		}
	}
}int dem_so_hoa_don_trong_mot_khoang_thoi_gian(DS_NHAN_VIEN ds_nv, Date batdau, Date ketthuc)
{
	int dem = 0;
	int kiemTra;
	Date ngaylap;
	HOA_DON* hd = NULL;

	for (int i = 0; i < ds_nv.sl; i++)
	{
		hd = ds_nv.ds[i]->danh_sach_hd.pHead;
		while (hd != NULL)
		{
			ngaylap = hd->ngaylap;
			if (kiem_tra_thoi_gian(batdau, ketthuc, ngaylap)) dem++;
			hd = hd->pNext;
		}
	}
	return dem;
}

void TraVeMangHoaDon(string** a, DS_NHAN_VIEN ds_nv, Date batdau, Date ketthuc)
{
	CHI_TIET_HOA_DON* cthd;
	HOA_DON* hd;
	NHAN_VIEN nv;
	int kt;
	Date ngaylap;
	int j = 0;
	long long tien;
	string s;
	for (int i = 0; i < ds_nv.sl; i++)
	{
		nv = *ds_nv.ds[i];
		hd = nv.danh_sach_hd.pHead;
		while (hd != NULL)
		{

			ngaylap = hd->ngaylap;
			if (kiem_tra_thoi_gian(batdau, ketthuc, ngaylap))
			{
				tien = TinhTongGiaTriHoaDon(hd->dsct_hoa_don.pHead);
				s = to_string(tien);
				a[j][0] = hd->so_hd;						// So HD
				a[j][1] = chuyenngaythanhchuoi(ngaylap);		// Ngay lap		
				if (hd->loai == "X") a[j][2] = "XUAT";	// Loai hd
				else a[j][2] = "NHAP";
				a[j][3] = TenDayDuCuaNhanVien(nv);				// nv lap
				a[j][4] = s;							// Tri gia hoa don
				j++;
			}
			hd = hd->pNext;
		}
	}
}
long long TinhTongTienMotVatTu(CHI_TIET_HOA_DON* cthd)
{
	long long tong = 0;
	int gia = cthd->don_gia;
	float sl = cthd->so_luong;
	float thue = cthd->VAT;
	tong = (gia * static_cast<long long>(sl));

	return tong * double((100.0 + static_cast<long long>(thue)) / 100.0);
}
long long TinhTongGiaTriHoaDon(CHI_TIET_HOA_DON* pHead)
{
	long long tong = 0;
	CHI_TIET_HOA_DON* p = pHead;
	if (p == NULL) return 0;
	while (p != NULL)
	{
		tong += TinhTongTienMotVatTu(p);
		p = p->pNext;
	}
	return tong;
}
string TenDayDuCuaNhanVien(NHAN_VIEN nv)
{
	return nv.ho + " " + nv.ten;
}
void TraVeMangVatTuXuat(thong_ke_vt& ds_tk, DS_NHAN_VIEN ds_nv, tree t, Date batdau, Date ketthuc)
{

	for (int i = 0; i < ds_nv.sl; i++)
	{
		for (HOA_DON* k = ds_nv.ds[i]->danh_sach_hd.pHead; k != NULL; k = k->pNext)
		{
			if (k->loai == "X" && kiem_tra_thoi_gian(batdau, ketthuc, k->ngaylap))
			{
				for (CHI_TIET_HOA_DON* cthd = k->dsct_hoa_don.pHead; cthd != NULL; cthd = cthd->pNext)
				{
					long long tien;
					string tenvt;
					int ma = cthd->ma_vt;
					vat_tu* vt = kt_ma_vt(t, ma);
					if (vt != NULL)
					{
						tenvt = vt->ten_vt;
					}
					tien = TinhTongTienMotVatTu(cthd);
					thong_ke* p = new thong_ke;
					p->tenvt = tenvt;
					p->tien = tien;
					if (kiem_tra_da_co_vat_tu(ds_tk, tenvt) >= 0)
					{
						int i = kiem_tra_da_co_vat_tu(ds_tk, tenvt);
						long long monney = 0;
						monney = ds_tk.ds_tk[i]->tien;
						monney += tien;
						ds_tk.ds_tk[i]->tien = monney;
					}
					else
					{
						them_1_tk(ds_tk, p);
					}
				}
			}
		}
	}
}
void them_1_tk(thong_ke_vt& ds_tk, thong_ke* tk)
{
	ds_tk.ds_tk[ds_tk.sl] = tk;
	ds_tk.sl++;
}
int kiem_tra_da_co_vat_tu(thong_ke_vt tk, string ten)
{
	for (int i = 0; i < tk.sl; i++)
	{
		if (tk.ds_tk[i]->tenvt == ten)
		{
			return i;
		}
	}
	return -1;
}
void sap_xep_thong_ke(thong_ke_vt& ds_tk)
{
	for (int i = 0; i < ds_tk.sl - 1; i++)
	{
		for (int j = i + 1; j < ds_tk.sl; j++)
		{
			if (ds_tk.ds_tk[i]->tien < ds_tk.ds_tk[j]->tien)
			{
				hoan_doi_thong_ke(ds_tk.ds_tk[i], ds_tk.ds_tk[j]);
			}
		}
	}
}
void hoan_doi_thong_ke(thong_ke*& a, thong_ke*& b)
{
	thong_ke* y = new thong_ke;
	
	y->tenvt = a->tenvt;
	y->tien = a->tien;
	
	a->tenvt = b->tenvt;
	a->tien = b->tien;
	
	b->tenvt = y->tenvt;
	b->tien = y->tien;
	delete y;
}
void thong_ke_vat_tu(DS_NHAN_VIEN ds_nv, tree ds_vt)
{
	
	Date batdau, ketthuc;
	int ngbd = 0, thbd = 0, nambd = 0, ngkt = 0, thkt = 0, namkt = 0;
	int a, b;
	int kq;
	
	thong_ke_vt tk;
NhapLai:
	int n = 0;
	gotoxy(25, 1);
	cout << "BANG LIET KE TOP 10 VAT TU TRONG KHOANG THOI GIAN ";
	Nocursortype(1);
	gotoxy(30, 3);   cout << "Tu ngay: ";
	gotoxy(40, 3);   cout << "  ";
	gotoxy(42, 3);   cout << "/";
	gotoxy(43, 3);   cout << "  ";
	gotoxy(45, 3);   cout << "/";
	gotoxy(46, 3);   cout << "    ";
	gotoxy(51, 3);   cout << "Den ngay: ";
	gotoxy(62, 3);   cout << "  ";
	gotoxy(64, 3);   cout << "/";
	gotoxy(65, 3);   cout << "  ";
	gotoxy(67, 3);   cout << "/";
	gotoxy(68, 3);   cout << "                                     ";
	int k = 0;
	gotoxy(40, 3); k = nhap_so_nguyen(ngbd); if (k == -1)return;
	gotoxy(43, 3); k = nhap_so_nguyen(thbd); if (k == -1)return;
	gotoxy(46, 3); k = nhap_so_nguyen(nambd); if (k == -1)return;

	gotoxy(62, 3); k = nhap_so_nguyen(ngkt); if (k == -1)return;
	gotoxy(65, 3); k = nhap_so_nguyen(thkt);  if (k == -1)return;
	gotoxy(68, 3); k = nhap_so_nguyen(namkt); if (k == -1)return;
	batdau.ngay = ngbd;
	batdau.thang = thbd;
	batdau.nam = nambd;
	ketthuc.ngay = ngkt;
	ketthuc.thang = thkt;
	ketthuc.nam = namkt;
	a = KiemTraThoiGian(batdau.ngay, batdau.thang, batdau.nam);
	b = KiemTraThoiGian(ketthuc.ngay, ketthuc.thang, ketthuc.nam);
	if (a == 0 || b == 0)
	{
		if (a == 0 || b == 0)
			BaoLoi("Thoi Gian Nhap Vao Khong Hop Le");
		ngbd = thbd = nambd = 0;
		ngkt = thkt = namkt = 0;
		goto NhapLai;
	}
	else
	{


		kq = SoSanhThoiGian(ketthuc, batdau);
		if (kq == -1)
		{
			BaoLoi("Thoi Gian Nhap Vao Khong Hop Le");
			ngbd = thbd = nambd = 0;
			ngkt = thkt = namkt = 0;
			goto NhapLai;
		}
		TraVeMangVatTuXuat(tk, ds_nv, ds_vt, batdau, ketthuc);
		sap_xep_thong_ke(tk);
		Nocursortype(0);
		if (tk.sl < 1)
		{
			gotoxy(30, 10);
			cout << "DANH SACH RONG !!";
			Sleep(1000);
			gotoxy(30, 10);
			cout << "                  ";
			goto NhapLai;
		}
		if (tk.sl >= 10)
		{
			rectangle(25, 10, 60, 20, WHITE);
			gotoxy(26, 11);
			cout << "   VI TRI           TEN VAT TU           DOANH THU      ";
			gotoxy(42, 10); cout << static_cast<char>(203);
			gotoxy(42, 29); cout << static_cast<char>(202);
			for (int i = 1; i < 19; i++)
			{
				gotoxy(42, 10 + i);
				cout << static_cast<char>(186);
			}
			gotoxy(60, 10); cout << static_cast<char>(203);
			gotoxy(60, 29); cout << static_cast<char>(202);
			for (int i = 1; i < 19; i++)
			{
				gotoxy(60, 10 + i);
				cout << static_cast<char>(186);
			}
			for (int i = 1; i < 11; i++)
			{
				gotoxy(33, i * 2 + 11);
				cout << i;
				gotoxy(49, i * 2 + 11);
				cout << tk.ds_tk[i - 1]->tenvt;
				gotoxy(65, i * 2 + 11);
				cout << tk.ds_tk[i - 1]->tien;
			}
		}
		else
		{
			rectangle(25, 10, 60, 20, WHITE);
			gotoxy(26, 11);
			cout << "   VI TRI           TEN VAT TU           DOANH THU      ";
			gotoxy(42, 10); cout << static_cast<char>(203);
			gotoxy(42, 29); cout << static_cast<char>(202);
			for (int i = 1; i < 19; i++)
			{
				gotoxy(42, 10 + i);
				cout << static_cast<char>(186);
			}
			gotoxy(60, 10); cout << static_cast<char>(203);
			gotoxy(60, 29); cout << static_cast<char>(202);
			for (int i = 1; i < 19; i++)
			{
				gotoxy(60, 10 + i);
				cout << static_cast<char>(186);
			}
			for (int i = 1; i <= tk.sl; i++)
			{
				gotoxy(33, i * 2 + 11);
				cout << i;
				gotoxy(49, i * 2 + 11);
				cout << tk.ds_tk[i-1]->tenvt;
				gotoxy(65, i * 2 + 11);
				cout << tk.ds_tk[i-1]->tien;
			}
		}
		for (int l = 0; l < tk.sl; l++)
		{
			delete tk.ds_tk[l];
		}
		char c;
		c = _getch();
		if (c == -32)
		{
			c = _getch();
		}
		if (c == KEY_ESC)
		{
			return;
		}
		else
		{
			goto NhapLai;
		}

	}
}
