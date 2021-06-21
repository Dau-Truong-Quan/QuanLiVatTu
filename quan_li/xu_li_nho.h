#pragma once
#include"KhaiBao.h"

void chuan_hoa_chu(string& a);
int kt_ma_nv_trung(string a, DS_NHAN_VIEN ds_nv);
string tao_ma_nv(DS_NHAN_VIEN ds_nv);
void them_1_vt(tree& t, vat_tu* p);
int tao_ma_vt(tree t);
bool kiem_tra_ma_vt_trung(tree t, int ma);
int xuat_ds_nhan_vien(DS_NHAN_VIEN ds_nv);
//===========================================  LAY GIO HE THONG

string chuyenngaythanhchuoi(Date date);
string chuyensothanhchuoi(int number);
void BaoLoi(string s);
void Box_BaoLoi();
int Kiem_tra_phim(char c);
string so_sang_chuoi(int number);
bool Kiem_Tra_Du_Lieu(char c);
bool Kiem_Tra_Ki_Tu_So(char c);
void xoa_hienthi_box_baoloi();
int dem_cthd(CHI_TIET_HOA_DON* p);


//------------------------------------- ------------------------------------CHUYEN CAY SANG MANG
void chuyen_cay_sang_danh_sach(tree t, vat_tu* vt[], int& n);

void chuan_hoa_chu(string& a)
{
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
	// kt giua
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i + 1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
	// ------------------------------------ bien doi chu hoa  ----------------------
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			i++;
			if (a[i] >= 97 && a[i] <= 122)
			{
				a[i] -= 32;
			}
		}
		else if (a[i] >= 97 && a[i] <= 122)
		{
			a[i] -= 32;
		}

	}
}
//========================================== THEM MOT VAT TU
void them_1_vt(tree& t, vat_tu* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else if (p->ma_vt > t->ma_vt)
	{
		them_1_vt(t->pRight, p);
	}
	else if (p->ma_vt < t->ma_vt)
	{
		them_1_vt(t->pLeft, p);
	}
}
vat_tu* khoi_tao_node_vat_tu()
{
	vat_tu* p = new vat_tu();
	p->pRight = NULL;
	p->pLeft = NULL;
	return p;
}
bool kiem_tra_ma_vt_trung(tree t, int ma)
{
	if (t == NULL)
	{
		return false;
	}
	else if (t->ma_vt == ma)
	{
		return true;
	}
	else if (t->ma_vt < ma)
	{
		kiem_tra_ma_vt_trung(t->pRight, ma);
	}
	else if (t->ma_vt > ma)
	{
		kiem_tra_ma_vt_trung(t->pLeft, ma);
	}


}
// ----------------------------------------------- tao ma vat tu
int tao_ma_vt(tree t)
{
	int ma;
	do
	{
		ma = rand() % (9999 - 1000 + 1) + 1000;
	} while (kiem_tra_ma_vt_trung(t, ma) == true);
	return ma;
}
// ================================================ TAO MA NHAN VIEN ==================== 
string tao_ma_nv(DS_NHAN_VIEN ds_nv)
{
	string a = "NV0000";
	do
	{
		for (int i = 2; i < a.length(); i++)
		{
			a[i] = rand() % (9) + 48;
		}
	} while (kt_ma_nv_trung(a, ds_nv) >= 0); // ----------    KIEM TRA BI TRUNG THI TAO LAI MA MOI
	return a;
}
//--------------------------------------------------------------     THEM MOT NHAN VIEN
void them_1_nv(DS_NHAN_VIEN& ds_nv, NHAN_VIEN* nv)
{
	ds_nv.ds[ds_nv.sl] = nv;
	ds_nv.sl++;
}

// ------------------------------------------------- KIEM TRA MA NHAN VIEN BI TRUNG ---------------------
int kt_ma_nv_trung(string a, DS_NHAN_VIEN ds_nv)
{
	for (int i = 0; i < ds_nv.sl; i++)
	{
		if (ds_nv.ds[i]->ma_nv == a)
		{
			return i;
		}
	}
	return -1;
}
int kt_ma(string a, DS_NHAN_VIEN ds_nv)
{
	for (int i = 0; i < ds_nv.sl; i++)
	{
		//kt ma vt a ton tai
		if (ds_nv.ds[i]->ma_nv == a)
		{
			//kt chua lap hoa don
			return i;
		}
	}
	return -1;
}
//=================================== chuyen ngay tu man hinh vao
string chuyensothanhchuoi(int number)
{
	if (number == 0) return "0";
	string s = "";
	while (number != 0)
	{
		s = char((number % 10) + 48) + s;
		number = number / 10;
	}
	return s;
}
string chuyenngaythanhchuoi(Date date)
{
	string s = "";
	string temp = "";
	temp = chuyensothanhchuoi(date.ngay);
	s += temp + "/";
	temp = chuyensothanhchuoi(date.thang);
	s += temp + "/";
	temp = chuyensothanhchuoi(date.nam);
	s += temp;
	return s;
}

bool Kiem_Tra_Ki_Tu_So(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}
bool check_chu(string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] > 64 && a[i] < 91)
		{
			continue;
		}
		return false;
	}
}

int nhap_so_nguyen(int& n) // Hàm nhập dữ liệu toàn số .
{

	string str;
	if (n != 0)
		str = so_sang_chuoi(n);
	else str = "";
	bool KT = false;
	int length = str.length(); // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
		c = _getch();
		if (c == 0 || c == -32)
			c = _getch();
		while (int(c) != 13)
		{
			if (c == 27)
			{
				return -1;
			}
			if (Kiem_Tra_Du_Lieu(c) == false) // nếu nhập kí tự là chữ
			{
				
				c = _getch();
				continue;
			}
			if (int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
			{

				if (length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if (str.length() != 0) // xóa kí tự cuối trong chuỗi string 
				{
					str.erase(str.begin() + (str.length() - 1));
				}
			}
			else
			{
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
			}
			c = _getch();
		}
		if (c == 13)
		{
			int dem = 1;
			int dem1 = 0;
			for (int i = 0; i < length; i++)
			{
				if ((int)str[i] == 32)
					dem++;
				else
					dem1++;
			}

			if (length == 0 || (dem >= 2 && dem1 == 0))
			{
				BaoLoi("KHONG DUOC DE TRONG");
				KT = false;
			}
			else
			{
				chuan_hoa_chu(str);
				KT = true;
			}

		}
	} while (KT == false);
	cout << endl;
	n = atoi(str.c_str()); // chuyen doi chuoi sang so
}
//flag =0 nhap toan ki tu, flag=1 nhap ki tu va so, flag =2 nhap gioitinh, flag = 3 nhap(n) và xuat(x), flag = 4 yes(y) va no(n)
int nhap_ki_tu(string& str, int flag)
{
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	bool KT = false;;
	int length = str.length(); // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
		c = _getch();
		if (c == 0 || c == -32)
		{
			c = _getch();
		}
		while (int(c) != KEY_ENTER)
		{

			if (c == KEY_ESC)
			{
				return -1;
			}
			int k = Kiem_tra_phim(c);
			if (k == 1) // phím chức năng
			{
				
				break;
			}
			if (k == 2 && (flag == 0 || flag == 2)) // nếu nhập kí tự là số
			{
				
				break;
			}

			if (int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
			{

				if (length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if (str.length() != 0) // xóa kí tự cuối trong chuỗi string 
				{
					str.erase(str.begin() + (str.length() - 1));
				}
			}
			else
			{
				TextColor(15);
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
			}
			break;
		}
		if (c == 13)
		{
			int dem = 1;
			int dem1 = 0;
			for (int i = 0; i < length; i++)
			{
				if ((int)str[i] == 32)
					dem++;
				else
					dem1++;
			}
			if (length == 0 || (dem >= 2 && dem1 == 0))
			{
				BaoLoi("KHONG DUOC DE TRONG");
				KT = false;
			}
			else if (flag == 0 || flag == 1)
				KT = true;
			else if (flag == 2) // flag=2 nhap gioi tinh
			{
				if (dem1 != 0)
				{
					chuan_hoa_chu(str);
					if (str == "NAM" || str == "NU")
						KT = true;
					else
					{
						BaoLoi("GIOI TINH CHI NAM HOAC NU");
						while (length > 0)
						{
							cout << "\b \b";
							str.pop_back();
							length--;
						}
						KT = false;
					}
				}
			}
			else if (flag == 3) 
			{
				if (dem1 != 0)
				{
					chuan_hoa_chu(str);
					if (str == "X" || str == "N")
						KT = true;
					else
					{
						BaoLoi("LOAI HD CHI NHAN HD(N)  HOAC HD(X)");
						while (length > 0)
						{
							cout << "\b \b";
							str.pop_back();
							length--;
						}
						KT = false;
					}
				}
			}
			else if (flag == 4) // flag = 4
			{
				if (dem1 != 0)
				{
					chuan_hoa_chu(str);
					if (str == "Y" || str == "N")
						KT = true;
					else
					{
						BaoLoi("CHI DUOC CHON YES(Y)  HOAC NO(N)");
						while (length > 0)
						{
							cout << "\b \b";
							str.pop_back();
							length--;
						}
						KT = false;
					}
				}
			}


		}
	} while (KT == false);
	cout << endl;
	chuan_hoa_chu(str);
}
// =============================================== NHAP SO THUC
int nhap_so_thuc(float& n) // Hàm nhập dữ liệu toàn số .
{

	string str;
	if (n != 0)
		str = so_sang_chuoi(n);
	else str = "";
	bool KT = false;
	int length = str.length(); // biến cho con trỏ dịch đến cuối
	char c;
	do
	{
		c = _getch();
		if (c == 0 || c == -32)
			c = _getch();
		while (int(c) != 13)
		{
			if (c == 27)
			{
				return -1;
			}
			if (Kiem_Tra_Du_Lieu(c) == false) // nếu nhập kí tự là chữ
			{
				BaoLoi("CHI DUOC NHAP SO");
				c = _getch();
				continue;
			}
			if (int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
			{

				if (length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if (str.length() != 0) // xóa kí tự cuối trong chuỗi string 
				{
					str.erase(str.begin() + (str.length() - 1));
				}
			}
			else
			{
				cout << c;
				length++; // cập nhật vụ trí con trỏ chỉ vị
				str.push_back(c);
			}
			c = _getch();
		}
		if (c == 13)
		{
			int dem = 1;
			int dem1 = 0;
			for (int i = 0; i < length; i++)
			{
				if ((int)str[i] == 32)
					dem++;
				else
					dem1++;
			}
			if (length == 0 || (dem >= 2 && dem1 == 0))
			{
				BaoLoi("KHONG DUOC DE TRONG");
				KT = false;
			}
			else
			{
				chuan_hoa_chu(str);
				KT = true;
			}

		}
	} while (KT == false);
	cout << endl;
	n = atoi(str.c_str()); // chuyen doi chuoi sang so
}
void BaoLoi(string s) {
	int n = s.length();
	int x = wherex(), y = wherey();
	Box_BaoLoi();
	TextColor(RED);
	/*gotoxy(boxx + 28, boxy + 42);*/
	gotoxy(53, 44);
	cout << s;
	Sleep(1500);
	/*for (int i = 0; i < n; i++)
	{
		gotoxy(boxx + 28 + i, boxy + 42);
		cout << " ";
	}*/
	xoa_hienthi_box_baoloi();
	gotoxy(x, y);
	TextColor(7);
}

int Kiem_tra_phim(char c)
{
	int arr[32] = { 72,75,77,80,81,73,44,46,59,39,47,93,91,92,61,82,83,79,71,-122,-123,68,67,66,65
	,64,63,62,61,60,59,96 };
	if (Kiem_Tra_Ki_Tu_So(c) == true) // so
		return 2;
	// nhấn shift + key
	if (GetKeyState(VK_SHIFT) & 0x8000)
		return 1;
	for (int i = 0; i < 32; i++)
	{
		if (c == arr[i])
			return 1;
	}
	return 0;
}
// -------------------------------- chuyển dữ liệu số thành chuỗi
string so_sang_chuoi(int number)
{
	return to_string(number);
}
bool Kiem_Tra_Du_Lieu(char c)
{
	if ((c >= 48 && c <= 57) || c == 8) // nếu là số thì rt true <> false;
	{
		return true;
	}
	return false;
}
//void Box_BaoLoi()
//{
//	int tungdo = 45;
//	TextColor(14);
//	gotoxy(86, tungdo - 1);
//	cout << "THONG BAO";
//	TextColor(76);
//	gotoxy(boxx, tungdo); cout << char(201);
//	for (int i = 1; i < boxs + 1; i++) cout << char(205);
//	cout << char(187);
//	gotoxy(boxx, tungdo + 1); cout << char(186);
//	gotoxy(boxx + boxs + 1, tungdo + 1); cout << char(186);
//	gotoxy(boxx, tungdo + 2); cout << char(186);
//	gotoxy(boxx + boxs + 1, tungdo + 2); cout << char(186);
//	gotoxy(boxx, tungdo + 3); cout << char(186);
//	gotoxy(boxx + boxs + 1, tungdo + 3); cout << char(186);
//	gotoxy(boxx, tungdo + 4); cout << char(186);
//	gotoxy(boxx + boxs + 1, tungdo + 4); cout << char(186);
//	gotoxy(boxx + 1, tungdo + 5);
//	for (int i = 1; i <= boxs; i++) cout << char(205);
//	gotoxy(boxx, tungdo + 5); cout << char(200);
//	gotoxy(boxx + boxs + 1, tungdo + 5); cout << char(188);
//	TextColor(7);
//}
void Box_BaoLoi()
{
	rectangle(40, 43, 50, 3, RED);
}
void xoa_hienthi_box_baoloi()
{
	gotoxy(40, 43);
	cout << "                                                                  ";
	gotoxy(40, 44);
	cout << "                                                                  ";
	gotoxy(40, 45);
	cout << "                                                                  ";
}
//void xoa_hienthi_box_baoloi()
//{
//	int tungdo = 45;
//	gotoxy(86, tungdo - 1);
//	cout << "               ";
//	TextColor(4);
//	gotoxy(boxx, tungdo); cout << " ";
//	for (int i = 1; i < boxs + 1; i++) cout << " ";
//	cout << " ";
//	gotoxy(boxx, tungdo + 1); cout << " ";
//	gotoxy(boxx + boxs + 1, tungdo + 1); cout << " ";
//	gotoxy(boxx, tungdo + 2);  cout << " ";
//	gotoxy(boxx + boxs + 1, tungdo + 2); cout << " ";
//	gotoxy(boxx, tungdo + 3);  cout << " ";
//	gotoxy(boxx + boxs + 1, tungdo + 3); cout << " ";
//	gotoxy(boxx, tungdo + 4); cout << " ";
//	gotoxy(boxx + boxs + 1, tungdo + 4); cout << " ";
//	gotoxy(boxx + 1, tungdo + 5);
//	for (int i = 1; i <= boxs; i++) cout << " ";
//	gotoxy(boxx, tungdo + 5); cout << " ";
//	gotoxy(boxx + boxs + 1, tungdo + 5); cout << " ";
//	TextColor(7);
//}
//------------------------------------------------- KHOI TAO HOA DON
HOA_DON* khoi_tao_hoa_don()
{
	HOA_DON* p = new HOA_DON;
	p->pNext = NULL;
	return p;
}
CHI_TIET_HOA_DON* khoi_tao_cthd()
{
	CHI_TIET_HOA_DON* p = new CHI_TIET_HOA_DON;
	p->pNext = NULL;
	return p;
}
//==================================================   HAM THÊM MỘT HÓA ĐƠN
void them_1_hoa_don(HOA_DON*& pHead, HOA_DON* p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (HOA_DON* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}

}
// =======================       THEM 1 CHI TIET HOA DON
void them_1_chi_tiet_hoa_don(CHI_TIET_HOA_DON*& pHead, CHI_TIET_HOA_DON* p)
{
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (CHI_TIET_HOA_DON* k = pHead; k != NULL; k = k->pNext)
		{
			if (k->pNext == NULL)
			{
				k->pNext = p;

			}
			break;
		}
	}

}
int dem_cthd(CHI_TIET_HOA_DON* p)
{
	int dem = 0;
	if (p == NULL)
	{
		return dem;
	}
	else for (CHI_TIET_HOA_DON* k = p; k != NULL; k = k->pNext)
	{
		if (k != NULL)
		{
			dem = dem + 1;
		}
	}
	return dem;
}
//------------------------------------- ------------------------------------CHUYEN CAY SANG MANG
void chuyen_cay_sang_danh_sach(tree t, vat_tu* vt[], int& n)
{
	if (t != NULL)
	{
		vt[n] = new vat_tu;
		vt[n]->ma_vt = t->ma_vt;
		vt[n]->ten_vt = t->ten_vt;
		vt[n]->sl_ton = t->sl_ton;
		vt[n]->dvt = t->dvt;
		n = n + 1;
		chuyen_cay_sang_danh_sach(t->pLeft, vt, n);
		chuyen_cay_sang_danh_sach(t->pRight, vt, n);
	}
}


//====================================== xuat danh sach nhan vien =========================
int xuat_ds_nhan_vien(DS_NHAN_VIEN ds_nv)
{
	int page = 1;
	char key;
	int number = ds_nv.sl;

	while (1) {
		rectangle(20, 5, 100, 37, WHITE);
		rectangle(21, 6, 98, 3, WHITE);
		rectangle(5, 46, 80, 3, WHITE);
		gotoxy(6, 47);
		cout << "  ESC: THOAT    |    <- : QUA TRAI       |   ->: QUA PHAI";
		gotoxy(22, 7); cout << "     MA NHAN VIEN                     HO VA TEN                      GIOI TINH ";
		gotoxy(42, 5); cout << static_cast<char>(203);
		gotoxy(42, 41); cout << static_cast<char>(202);
		for (int i = 1; i < 36; i++)
		{
			gotoxy(42, 5 + i);
			cout << static_cast<char>(186);
		}
		gotoxy(85, 5); cout << static_cast<char>(203);
		gotoxy(85, 41); cout << static_cast<char>(202);
		for (int i = 1; i < 36; i++)
		{
			gotoxy(85, 5 + i);
			cout << static_cast<char>(186);
		}
		for (int i = 15 * (page - 1); i < ds_nv.sl && i < 15 * page; i++)
		{
			gotoxy(23, i % 15 * 2 + 9);
			cout << ds_nv.ds[i]->ma_nv;
			gotoxy(55, i % 15 * 2 + 9);
			cout << ds_nv.ds[i]->ho << " " << ds_nv.ds[i]->ten;
			gotoxy(95, i % 15 * 2 + 9);
			cout << ds_nv.ds[i]->phai;
			int r = 0;
			int number = ds_nv.sl;
			if (number % 15 > 0 && number/15>0)
			{
				r = 1;
			}
			gotoxy(122, 47);
			cout << "TRANG  " << page << "/" << number / 3 + r;

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
