#pragma once
#include"xu_li_nho.h"

void ghi_file_vat_tu(DS_VAT_TU ds_vt);


void Doc_Ngay_Thang_Nam(ifstream& filein, Date& date)
{
	filein >> date.ngay;
	filein.seekg(1, 1); // dịch sang phải 1 byte để bỏ qua kí tự '/'
	filein >> date.thang;
	filein.seekg(1, 1); // dịch sang phải 1 byte để bỏ qua kí tự '/'
	filein >> date.nam;
}
void Ghi_Ngay_Thang_Nam(ofstream& filein, Date date)
{
	filein << date.ngay << '/';

	filein << date.thang << '/';
	
	filein << date.nam;
}
//void khoi_Tao_dshd(DS_HOA_DON &ds_hd)
//{
//	ds_hd.pHead = NULL;
//	ds_hd.pHead->pNext = NULL;
//}
void doc_file_nhan_vien(DS_NHAN_VIEN& ds_nv)
{
	ifstream filein;
	
	
	
	filein.open("danh_sach_nhan_vien.txt", ios_base::in);
	
		int dem;
		filein >> dem;
		
	
		for (int i = 0; i < dem; i++)
		{
			filein.ignore();

			NHAN_VIEN* nv = new NHAN_VIEN;
			getline(filein, nv->ma_nv, ',');
			getline(filein, nv->ho, ',');
			getline(filein, nv->ten, ',');
			getline(filein, nv->phai, '\n');
	
			/*khoi_Tao_dshd(ds_nv.ds[i]->danh_sach_hd);*/
			filein >> nv->danh_sach_hd.sl; 
			// lay enter 
			
			for (int j = 0; j < nv->danh_sach_hd.sl; j++)
			{
				filein.ignore();

				HOA_DON* hd = khoi_tao_hoa_don();
				
				getline(filein, hd->so_hd, ',');
				Doc_Ngay_Thang_Nam(filein, hd->ngaylap);
				filein.ignore();
				getline(filein, hd->loai, '\n');
				
				
				filein >> hd->dsct_hoa_don.sl;
				

				for (int k = 0; k < hd->dsct_hoa_don.sl; k++)
				{
					CHI_TIET_HOA_DON* cthd = khoi_tao_cthd();
					filein.ignore();
					filein >> cthd->ma_vt;
					filein.ignore();
					filein >> cthd->so_luong;
					filein.ignore();
					filein >> cthd->don_gia;
					filein.ignore();
					filein >> cthd->VAT;
					
					them_1_chi_tiet_hoa_don(hd->dsct_hoa_don.pHead, cthd);
					
				}
				them_1_hoa_don(nv->danh_sach_hd.pHead, hd);
			}
			them_1_nv(ds_nv, nv);
		}
	
	filein.close();

}
void ghi_file_nhan_vien(DS_NHAN_VIEN& ds_nv)
{
	ofstream fileout;

	fileout.open("danh_sach_nhan_vien.txt", ios_base::out);
	
		fileout << ds_nv.sl << endl;


		for (int i = 0; i < ds_nv.sl; i++)
		{
			fileout << ds_nv.ds[i]->ma_nv << ',';
			fileout << ds_nv.ds[i]->ho <<  ',';
			fileout << ds_nv.ds[i]->ten << ',';
			fileout << ds_nv.ds[i]->phai << endl;

			fileout << ds_nv.ds[i]->danh_sach_hd.sl << endl;

			for (HOA_DON*p = ds_nv.ds[i]->danh_sach_hd.pHead;p!= NULL; p=p->pNext)
			{	
				fileout << p->so_hd << ',';
				string s = chuyenngaythanhchuoi(p->ngaylap);
				fileout << s << ',';				
				fileout << p->loai << endl;
				p->dsct_hoa_don.sl = dem_cthd(p->dsct_hoa_don.pHead);
				fileout << p->dsct_hoa_don.sl << endl;;

				for (CHI_TIET_HOA_DON* k = p->dsct_hoa_don.pHead; k != NULL; k = k->pNext)
				{
					fileout << k->ma_vt << ',';
					fileout << k->so_luong << ',';
					fileout << k->don_gia << ',';
					fileout << k->VAT << endl;
				}
			}
		}
	
	fileout.close();

}
//// ================================================== THEM NHAN VIEN ==============================
int them_nhan_vien(DS_NHAN_VIEN& ds_nv)
{
	rectangle(5, 46, 20, 3, WHITE);
	gotoxy(6, 47);
	cout << "  ESC: THOAT  ";
	Nocursortype(1);
	rectangle(46, 18, 50, 10, WHITE);
	gotoxy(60, 18);
	cout << "  NHAP NHAN VIEN  ";
	NHAN_VIEN* p = new NHAN_VIEN;
	int k = 0;
	p->ma_nv = tao_ma_nv(ds_nv);
	gotoxy(50, 20);
	cout << "ma nhan vien: " << p->ma_nv;
	gotoxy(50, 21);
	cout << "Nhap ho nhan vien:  ";
	/*cin.ignore();*/
	k= nhap_ki_tu(p->ho, 0);
	if (k == -1)
	{
		return -2;
	}
	gotoxy(50, 22);
	cout << "Nhap ten nhan vien:  ";
	k = nhap_ki_tu(p->ten, 0);
	if (k == -1)
	{
		return -2;
	}
	gotoxy(50, 23);
	cout << "Nhap gioi tinh nhan vien:  ";
	k = nhap_ki_tu(p->phai, 2);
	if (k == -1)
	{
		return -2;
	}
	chuan_hoa_chu(p->ho);
	chuan_hoa_chu(p->ten);
	chuan_hoa_chu(p->phai);
	them_1_nv(ds_nv,p);

	gotoxy(55, 27);
	cout << "THEM THANH CONG ";
	Sleep(1500);
	gotoxy(50, 27);
	cout << "                   ";

}
// ================================================================== XOA NHAN VIEN
void xoa_nv(DS_NHAN_VIEN& ds_nv)
{
	

	int kt;
	gotoxy(69, 47);
	cout << "|  ENTER: XOA";
	kt = xuat_ds_nhan_vien(ds_nv);
	if (kt == -1)
	{
		return;
	}
	xoa:
	string a;
	rectangle(122,9,40,3,WHITE);
	gotoxy(125, 10);
	cout << "Nhap ma nhan vien: "; kt = nhap_ki_tu(a,1);
	gotoxy(143, 10);
	cout << "                ";
	if (kt == -1)
	{
		return;
	}
	
	int vt = kt_ma(a, ds_nv);
	// xoa
	if (vt < 0)
	{
		gotoxy(125, 12);
		cout << "NHAN VIEN KHONG TON TAI" ;
		Sleep(1000);
		gotoxy(125, 12);
		cout << "                        ";
		gotoxy(125, 12);
		cout << "MOI NHAP LAI! ";
		Sleep(1000);
		gotoxy(125, 12);
		cout << "                        ";		
		goto xoa;
	}
	else if (ds_nv.ds[vt]->danh_sach_hd.pHead != NULL)
	{
		gotoxy(122, 12);
		cout << "KHONG DUOC XOA NHAN VIEN DA LAP HOA DON!";
		Sleep(1000);
		gotoxy(122, 12);
		cout << "                                         ";
		gotoxy(122, 12);
		cout << "MOI NHAP LAI! ";
		Sleep(1000);
		gotoxy(122, 12);
		cout << "                        ";
		system("cls");
		goto xoa;
	}
	else
	{
		for (int i = vt; i < ds_nv.sl - 1; i++)
		{
			ds_nv.ds[i]->ma_nv = ds_nv.ds[i + 1]->ma_nv;
			ds_nv.ds[i]->ten = ds_nv.ds[i + 1]->ten;
			ds_nv.ds[i]->ho = ds_nv.ds[i + 1]->ho;
			ds_nv.ds[i]->phai = ds_nv.ds[i + 1]->phai;
			ds_nv.ds[i]->danh_sach_hd = ds_nv.ds[i + 1]->danh_sach_hd;
		}

		NHAN_VIEN* tam = ds_nv.ds[ds_nv.sl - 1];
		ds_nv.sl--;
		delete tam;
		gotoxy(125, 12);
		cout << "DA XOA THANH CONG !" << endl;
		Sleep(1000);
		gotoxy(125, 12);
		cout << "                    " << endl;

	}
}
//======================================================     DOC FILE VAT TU
void doc_file_vat_tu(DS_VAT_TU& ds_vt)
{
	ifstream filein;
	filein.open("danh_sach_vat_tu.txt", ios_base::in);
	filein >> ds_vt.sl;
	for(int i=0;i<ds_vt.sl;i++)
	{
		filein.ignore();
		vat_tu* x = khoi_tao_node_vat_tu();
		filein >> x->ma_vt;
		filein.ignore();
		getline(filein, x->ten_vt, ',');
		getline(filein, x->dvt, ',');
		filein >> x->sl_ton;
		them_1_vt(ds_vt.TREE, x);
		

	}
	filein.close();

}



void nhap_vat_tu(DS_VAT_TU& ds_vt)
{
	int k;
	Nocursortype(1);
	rectangle(50, 9, 50, 20, WHITE);
	ofstream fileout;
	fileout.open("danh_sach_vat_tu.txt", ios::app);
	vat_tu* p = khoi_tao_node_vat_tu();
	gotoxy(55, 11);
	p->ma_vt = tao_ma_vt(ds_vt.TREE);
	cout << "MA VAT TU:  " << p->ma_vt;
	gotoxy(55, 13);
	cout << "NHAP TEN VAT TU:  ";k = nhap_ki_tu(p->ten_vt,0);
	if (k == -1)
		return;
	chuan_hoa_chu(p->ten_vt);
	gotoxy(55, 15);
	cout << "NHAP DON VI TINH:  ";nhap_ki_tu(p->dvt,0);
	if (k == -1)
		return;
	chuan_hoa_chu(p->dvt);
	p->sl_ton = 0;
	gotoxy(55, 17);
	cout << "SO LUONG TON:  "; nhap_so_thuc(p->sl_ton);
	if (k == -1)
		return;
	gotoxy(60, 22);
	cout << "THEM THANH CONG! ";
	Sleep(1500);
	gotoxy(60, 22);
	cout << "                  ";

	them_1_vt(ds_vt.TREE, p);
	ds_vt.sl++;
	ghi_file_vat_tu(ds_vt);
	
	fileout.close();
}
void ghi_file_vat_tu(DS_VAT_TU ds_vt)
{
	int n= 0;
	vat_tu* vt[100];
	ofstream fileout;
	fileout.open("danh_sach_vat_tu.txt", ios::out);
	chuyen_cay_sang_danh_sach(ds_vt.TREE, vt, n);
	fileout << ds_vt.sl << endl;
	for (int i = 0; i < n; i++)
	{
		
		fileout << vt[i]->ma_vt << ',';
		fileout << vt[i]->ten_vt << ',';
		fileout << vt[i]->dvt << ',';
		fileout << vt[i]->sl_ton << endl;
	}
	
	fileout.close();
}

void TieuDe() {
	ifstream file("TIEUDE.txt");
	string a;
	int i = 0;
	while (!file.eof()) {
		getline(file, a);
		gotoxy(5, i);
		cout << a;
		i++;
	}
	file.close();
}

