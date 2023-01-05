#include"DanhSachThongTinDocGia.h"


//Khởi tạo cây nhị phân
void Init(Tree &t)
{
	t = NULL;
}

//Thêm 1 Node vào cây nhị phân
void Insert(Tree &t, DOCGIA x)
{
	if(t == NULL)
	{
		_Node *p  = new _Node;
		p->data = x;
		p->pLeft = p->pRight =  NULL;
		t = p;
	}
	else
	{
		if(x.Ma_Doc_Gia < t->data.Ma_Doc_Gia)
		{
			Insert(t->pLeft, x);
		}
		else if(x.Ma_Doc_Gia > t->data.Ma_Doc_Gia)
		{
			Insert(t->pRight, x);
		}
	}
}


// hàm xử lí các chức năng
void Menu_Xu_Li(Tree &t)
{

	int luachon;
	do
	{
		clrscr();
		cout << "\n\n\t\t ====================== Menu ======================";
		cout << "\n1. Nhap thong tin doc gia";
		cout << "\n2. Xuat danh sach thong tin doc gia";
		cout << "\n3. Xoa thong tin doc gia";
		cout << "\n4. Sua thong tin doc gia";
		cout << "\n5. Tim kiem doc gia";
		cout << "\n6. Thoat";
		cout << "\n\n\t\t ====================== End =======================";

		cout << "\nNhap lua chon: \n";
		luachon = Nhap_So_Nguyen();

		if(luachon < 0 || luachon > 6)
		{
			cout << "\nLua chon khong hop le. Xin nhap lai";
			system("pause");
		}
		else 
		{
			if(luachon == 1)
			{
				Nhap_Danh_Sach_Thong_Tin_Doc_Gia(t);
			}
			else if(luachon == 2)
			{
				clrscr();
				int tdy = 3;
				gotoXY(20, 0);
				TextColor(10);
				cout << "* DANH SACH DOC GIA HIEN CO TRONG THU VIEN *";
				TextColor(11);
				In_Khung_Xuat(tdy);
				TextColor(15);
				Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(t, tdy);
				TextColor(7);
				gotoXY(0, tdy + 3);
				system("pause");
			}
			else if(luachon == 3)
			{
				Menu_Xoa(t);
			}
			else if(luachon == 5)
			{
				Menu_Tim_Kiem(t);
				system("pause");
			}
			else if(luachon == 6)
			{
				break;
			}
		}

	}while(luachon < 0 || luachon > 6 || luachon != 6);
}

// menu làm nhiệm vụ xóa theo các tiêu chí do người dùng định nghĩa
void Menu_Xoa(Tree &t)
{
	int luachon;
	do
	{
		clrscr();
		cout << "\n\n\t\t ================= Menu =================";
		cout << "\n1. Xoa thong tin doc gia theo ma doc gia";
		cout << "\n2. Xoa thong tin doc gia theo ten doc gia";
		cout << "\n3. Xoa thong tin doc gia theo trang thai(trang thai = 0)";
		cout << "\n4. Thoat";
		cout << "\n\n\t\t ================= End ==================";

		cout << "\nNhap lua chon: ";
		luachon = Nhap_So_Nguyen();

		if(luachon < 0 || luachon > 4)
		{
			cout << "\nLua chon khong hop le. Xin nhap lai";
			system("pause");
		}
		else
		{
			if(luachon == 1)
			{
				int ma;
				cout << "\nNhap ma doc gia can xoa: ";
				ma = Nhap_So_Nguyen();
				Xoa_Theo_Ma_Doc_Gia(t, ma);
				system("pause");
			}
			else if(luachon == 2)
			{
				string str;
				fflush(stdin);
				cout << "\nNhap ten doc gia can xoa: ";
				getline(cin, str);

				int dem = 0;
				Count_Ten(t, str, dem);
				for(int i = 1; i <= dem; i++)
				{
					Xoa_Theo_Ten_Doc_Gia(t, str);
				}
			}
			else if(luachon == 3)
			{
				int dem = 0;
				Count_Trang_Thai(t, dem);
				for(int i = 1; i <= dem; i++)
				{
					Xoa_Theo_Trang_Thai(t);
				}
			}
			else if(luachon == 4)
			{
				break;
			}
		}
	}while(luachon < 0 || luachon > 4 || luachon != 4);
}

// menu làm nhiệm vụ tìm kiếm thông tin 1 độc giả theo các tiêu chí do người dùng định nghĩa
void Menu_Tim_Kiem(Tree t)
{
	int luachon;
	do
	{
		clrscr();
		cout << "\n\n\t\t ================= Menu =================";
		cout << "\n1. Tim kiem thong tin doc gia theo ma doc gia";
		cout << "\n2. Tim kiem thong tin doc gia theo ten doc gia";
		cout << "\n3. Tim kiem thong tin doc gia theo trang thai";
		cout << "\n4. Thoat";
		cout << "\n\n\t\t ================= End ==================";

		cout << "\nNhap lua chon: ";
		luachon = Nhap_So_Nguyen();

		if(luachon < 0 || luachon > 4)
		{
			cout << "\nLua chon khong hop le. Xin nhap lai";
			system("pause");
		}
		else
		{
			if(luachon == 1)
			{
				int ma;
				cout << "\nNhap ma: ";
				cin >> ma;
				bool KT ;
				Kiem_Tra_Ma_Doc_Gia(t, ma, KT);
				cout << endl << KT;
				system("pause");
			}
			else if(luachon == 4)
			{
				break;
			}
		}

	}while(luachon < 0 || luachon > 4 || luachon != 4);
}

// Phần tử p đang được thế mạng cho phần tử q
void TimPhanTuTheMang(Tree &p, Tree &q)
{
	// duyệt đến trái nhất của Node cần xóa 
	if(q->pLeft != NULL)
	{
		TimPhanTuTheMang(p, q->pLeft);
	}
	// đã tìm được node trái nhất
	else
	{
		p->data = q->data;
		p = q;
		q = q ->pRight;
	}
}

// hàm có chức năng xóa 1 độc giả bất kì theo mã độc giả
void Xoa_Theo_Ma_Doc_Gia(Tree &t, int madocgia)
{
	// duyệt cây để tìm phần tử cần xóa
	if(t->data.Ma_Doc_Gia < madocgia)
	{
		Xoa_Theo_Ma_Doc_Gia(t->pRight, madocgia);
	}
	else if(t->data.Ma_Doc_Gia > madocgia)
	{
		Xoa_Theo_Ma_Doc_Gia(t->pLeft, madocgia);
	}
	// đã tìm được phần tử cần xóa
	else
	{
		_Node *p = t;
		// Xóa node có 1 con hoặc ko có con nào
		if(t->pLeft == NULL)
		{
			t = t->pRight;
		}
		else if(t->pRight == NULL)
		{
			t = t->pLeft;
		}
		// xóa node có 2 con. TRÁI NHẤT CỦA CÂY CON PHẢI
		else
		{
			// trái nhất của cây con phải
			TimPhanTuTheMang(p, t->pRight); // tìm phần tử thế mạng
		}
		delete p;
	}
}

// hàm có tác dụng xóa 1 độc giả theo tên bất kì
void Xoa_Theo_Ten_Doc_Gia(Tree &t, string str)
{

	if(t != NULL)
	{
		Xoa_Theo_Ten_Doc_Gia(t->pLeft, str);
		if(stricmp(t->data.Ten.c_str(), str.c_str()) == 0)
		{
			Xoa_Theo_Ma_Doc_Gia(t, t->data.Ma_Doc_Gia);
			return; // sau khi tìm thấy độc giả cần xóa thì ngừng kiểm tra
		}
		Xoa_Theo_Ten_Doc_Gia(t->pRight, str);
	}
}

// hàm có tác dụng xóa tất cả các độc giả có trạng thái == 0
void Xoa_Theo_Trang_Thai(Tree &t)
{
	if(t != NULL)
	{
		Xoa_Theo_Trang_Thai(t->pLeft);
		if(t->data.Trang_Thai == false)
		{
			Xoa_Theo_Ma_Doc_Gia(t, t->data.Ma_Doc_Gia);
			return; // sau khi tìm thấy độc giả cần xóa thì ngừng kiểm tra
		}
		Xoa_Theo_Trang_Thai(t->pRight);
	}
}

// Duyệt cây nhị phân theo LNR
void Xuat_Danh_Sach_Thong_Tin_Doc_Gia(Tree t)
{
	if(t != NULL)
	{
		Xuat_Danh_Sach_Thong_Tin_Doc_Gia(t->pLeft);
		Xuat_Thong_Tin_Doc_Gia(t->data);
		cout << endl;
		Xuat_Danh_Sach_Thong_Tin_Doc_Gia(t->pRight);
	}
}

// hàm xuất danh sách độc giả
void Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(Tree t, int &tdy)
{
	if(t != NULL)
	{
		Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(t->pLeft, tdy);
		Xuat_Thong_Tin_Doc_Gia_1(t->data, tdy += 2);
		cout << endl << endl << endl;
		Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(t->pRight, tdy);
	}
}

void Xuat_Thong_Tin_Doc_Gia_Theo_Ma(Tree t, int ma, int y)
{
	if(t == NULL)
	{

		return;
	}
	if(t->data.Ma_Doc_Gia < ma)
	{
		Xuat_Thong_Tin_Doc_Gia_Theo_Ma(t->pRight, ma, y);

	}
	else if(t->data.Ma_Doc_Gia > ma)
	{
		Xuat_Thong_Tin_Doc_Gia_Theo_Ma(t->pLeft, ma, y);
	}
	else
	{
		Xuat_Thong_Tin_Doc_Gia_1(t->data, y);
		return;
	}

}
//hàm nhập danh sách độc giả
void Nhap_Danh_Sach_Thong_Tin_Doc_Gia(Tree &t)
{
	int luachon;
	do{

		clrscr(); // hàm xóa màn hình
		cout << "\n1. Nhap thong tin doc gia";
		cout << "\n2. Thoat";

		cout << "\nNhap lua chon: ";
		luachon = Nhap_So_Nguyen();

		if(luachon != 1 && luachon != 2)
		{
			cout << "\nLua chon khong hop le. Xin nhap lai";
			system("pause");
		}
		else
		{
			if(luachon == 1)
			{
				clrscr(); // hàm xóa màn hình
				DOCGIA x;
				bool KT;

				TextColor(14);
				gotoXY(24, 0);
				cout << "**************************";

				TextColor(14);
				gotoXY(24, 1);
				cout << "*";
				TextColor(14);
				gotoXY(49, 1);
				cout << "*";

				TextColor(11);
				gotoXY(25, 1);
				cout << " NHAP THONG TIN DOC GIA ";

				TextColor(14);
				gotoXY(24, 2);
				cout << "**************************";


				gotoXY(0, 4);
				cout << "********************************************************************************";

				TextColor(15);
				gotoXY(31, 4);
				cout << " HUONG DAN ";


				gotoXY(1, 6);  cout << "Bam ESC de thoat !";
				gotoXY(1, 8);  cout << "Di chuyen qua lai:   " << (char)26 << "    " << (char)27 ;
				gotoXY(1, 10); cout << "Bam ENTER de luu !";

				TextColor(14);
				gotoXY(0, 12);
				cout << "********************************************************************************"; 

				TextColor(10);
				In_Khung_Doc_Gia(14);
				TextColor(7);
				bool check = false;
				// vòng lặp có tác dụng cho người dùng nhập đến khi nào nhấn esc thì thoát, còn nhấn enter thì lưu bình thường
				while(check != true)
				{
					KT = false;
					x = Nhap_Thong_Tin_Doc_Gia_1(t, 0, 16, KT, check);

					if(KT == true)
					{
						//cout << sizeof(x.l); // xuất ra độ lớn của con trỏ
						Init(x.l); // khởi tạo cho mỗi độc giả 1 danh sách mượn trả
						Insert(t, x); // thêm 1 đgộc giả mới vào danh sách
					}
				}
			}
			else if(luachon == 2)
			{
				break;
			}
		}
	}while((luachon != 1 && luachon != 2) || luachon != 2);

}

//// hàm có tác dụng duyệt (LNR) xem mã độc giả có bị trùng trong cây nhị phân chưa. Nếu trùng trả về true. Ngược lại trả về false
//bool Kiem_Tra_Ma_Doc_Gia(Tree t, int ma)
//{
//	if(t == NULL)
//	{
//		return false;
//	}
//	else if(t->data.Ma_Doc_Gia < ma)
//	{
//		Kiem_Tra_Ma_Doc_Gia(t->pRight, ma);
//	}
//	else if(t->data.Ma_Doc_Gia > ma)
//	{
//		Kiem_Tra_Ma_Doc_Gia(t->pLeft, ma);
//	}
//	else if(t->data.Ma_Doc_Gia == ma)
//	{
//		cout << "\ntam";
//		return true; // có tồn tại
//	}
//}

// hàm có tác dụng duyệt (LNR) xem tên độc giả có bị trùng trong cây nhị phân chưa. Nếu trùng trả về true. Ngược lại trả về false
char Kiem_Tra_Ten(Tree t, string str)
{
	if(t != NULL)
	{
		Kiem_Tra_Ten(t->pLeft, str);
		if(stricmp(t->data.Ten.c_str(), str.c_str()) == 0)
		{
			return '1';
		}
		Kiem_Tra_Ten(t->pRight, str);
	}
	return '0';
}

// hàm nhập mã độc giả .Cây nhị phân tìm kiếm thì mã độc giả ko được phép trùng nhau
int Nhap_Ma_Doc_Gia(Tree t)
{
	int ma;
	bool KT;

	do
	{
		cout << "\nNhap ma doc gia: ";
		cin >> ma;

		//KT = Kiem_Tra_Ma_Doc_Gia(t, ma);

		if(KT == true)
		{
			cout << "\nMa doc gia da ton tai. Xin kiem tra lai";
			system("pause");
		}

	}while(KT == true);

	return ma;
}

// hàm có tác dụng đếm xem trong thư viện có bao nhiêu độc giả có cùng tên  
void Count_Ten(Tree t, string str, int &dem) 
{
	if(t != NULL)
	{
		Count_Ten(t->pLeft, str, dem);
		if(stricmp(t->data.Ten.c_str(), str.c_str()) == 0)
		{
			dem++;
		}
		Count_Ten(t->pRight, str, dem);
	}
}

// hàm có tác dụng đếm xem trong thư viện có bao nhiêu độc giả có cùng trạng thái = 0
void Count_Trang_Thai(Tree t, int &dem)
{
	if(t != NULL)
	{
		Count_Trang_Thai(t->pLeft, dem);
		if(t->data.Trang_Thai == false)
		{
			dem++;
		}
		Count_Trang_Thai(t->pRight, dem);
	}
}

void Kiem_Tra_Ma_Doc_Gia(Tree t, int ma, bool &Kiem_Tra)
{
	if(t == NULL)
	{
		Kiem_Tra = false;
		return;
	}
	else if(t->data.Ma_Doc_Gia < ma)
	{
		Kiem_Tra_Ma_Doc_Gia(t->pRight, ma, Kiem_Tra);
	}
	else if(t->data.Ma_Doc_Gia > ma)
	{
		Kiem_Tra_Ma_Doc_Gia(t->pLeft, ma, Kiem_Tra);
	}
	else if(t->data.Ma_Doc_Gia == ma)
	{
		Kiem_Tra = true;
		return; // có tồn tại
	}
}


void Kiem_Tra_Ma_Doc_Gia_In(Tree t, int madocgia, bool &Kiem_Tra, int y)
{
	if(t == NULL)
	{
		Kiem_Tra = false;
		return;
	}
	else if(t->data.Ma_Doc_Gia < madocgia)
	{
		Kiem_Tra_Ma_Doc_Gia_In(t->pRight, madocgia, Kiem_Tra, y);
	}
	else if(t->data.Ma_Doc_Gia > madocgia)
	{
		Kiem_Tra_Ma_Doc_Gia_In(t->pLeft, madocgia, Kiem_Tra, y);
	}
	else if(t->data.Ma_Doc_Gia == madocgia)
	{
		Kiem_Tra = true;
		TextColor(15);
		Xuat_Thong_Tin_Doc_Gia_1(t->data, y);
		TextColor(7);
		return; // có tồn tại
	}
}

DOCGIA Nhap_Thong_Tin_Doc_Gia_1(Tree t, int x, int y, bool &Kiem_Tra, bool &check)
{
	DOCGIA a;
	char c ;

	int madocgia = 0;
	string ma_doc_gia;
	string ho;
	string ten;
	string ngaysinh;
	string phai;

	int VT = 1;
	int madocgia_max = 10;
	int ho_max = 10;
	int ten_max = 20;
	int ngaysinh_max = 8;
	int phai_max = 5;

	bool check_enter = false;
	bool left = false;
	bool right = false;

	// vòng lặp lặp vô tận cho đến khi người dùng nhập liệu xong tất cả các thuộc tính và lưu lại
	gotoXY(0 + ma_doc_gia.length(), y);
	while(true)
	{
		bool kt = false;
		bool Kiem_Tra_ESC = false;

		if(VT == 1)
		{

			bool KT;
			do
			{
				gotoXY(0 + ma_doc_gia.length(), y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_So_Nguyen_3(ma_doc_gia, madocgia, ma_doc_gia.length(), x, y, madocgia_max, Kiem_Tra_ESC, check_enter, left, right); 

				if(Kiem_Tra_ESC == true)
				{
					check = true;
					return a;
				}
				Kiem_Tra_Ma_Doc_Gia(t, madocgia, KT); // hàm kiểm tra mã độc giả trùng. Nếu trùng KT ==  true

				if(KT == true)
				{
					TextColor(12);
					gotoXY(20, y + 4);
					cout << "Ma doc gia da ton tai. Xin kiem tra va nhap lai ";
					getch();
					gotoXY(20, y + 4);
					cout << "                                                    ";
					TextColor(7);
				}

			}while(KT == true);
			if(check_enter == true)
			{
				if(ma_doc_gia.length() != 0 && ho.length() != 0 && ten.length() != 0 && phai.length() != 0 && ngaysinh.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 4);
						bool kiem_tra = Xac_Nhan_1(25, y + 4);
						if(kiem_tra == true)
						{
							a.Ma_Doc_Gia = madocgia;
							a.Ho = ho;
							a.Ten = ten;
							a.Phai = phai;
							a.Trang_Thai = true;
							// chuẩn hóa theo qui tắc chuẩn
							Chuan_Hoa(a.Ho);
							Chuan_Hoa(a.Ten);
							Chuan_Hoa(a.Phai);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else
				{
					TextColor(12);
					gotoXY(25, y + 4);
					cout << "KHONG THE LUU. DU LIEU CON TRONG";
					getch();
					gotoXY(25, y + 4);
					cout << "                                      ";
					TextColor(7);
				}
			}
			if(left == true)
			{
				VT = 5;
			}
			else if(right == true)
			{
				VT = 2;
			}
			gotoXY(15 + ho.length(), y);
		}
		else if(VT == 2)
		{

			gotoXY(15 + ho.length(), y);
			check_enter = false;
			left = false;
			right = false;
			Nhap_Ten_2(ho, ho.length(), x + 15, y, ho_max, Kiem_Tra_ESC, check_enter, left, right);
			if(Kiem_Tra_ESC == true)
			{
				check = true;
				return a;
			}

			if(check_enter == true)
			{
				if(ma_doc_gia.length() != 0 && ho.length() != 0 && ten.length() != 0 && phai.length() != 0 && ngaysinh.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 4);
						bool kiem_tra = Xac_Nhan_1(25, y + 4);
						if(kiem_tra == true)
						{
							a.Ma_Doc_Gia = madocgia;
							a.Ho = ho;
							a.Ten = ten;
							a.Phai = phai;
							a.Trang_Thai = true;
							// chuẩn hóa theo qui tắc chuẩn
							Chuan_Hoa(a.Ho);
							Chuan_Hoa(a.Ten);
							Chuan_Hoa(a.Phai);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else
				{
					TextColor(12);
					gotoXY(25, y + 4);
					cout << "KHONG THE LUU. DU LIEU CON TRONG";
					getch();
					gotoXY(25, y + 4);
					cout << "                                      ";
					TextColor(7);
				}
			}
			if(left == true)
			{
				VT = 1;
			}
			else if(right == true)
			{
				VT = 3;
			}
			gotoXY(30 + ten.length(), y);
		}
		else if(VT == 3)
		{

			gotoXY(30 + ten.length(), y);
			check_enter = false;
			left = false;
			right = false;
			Nhap_Ten_2(ten, ten.length(), x + 30, y, ten_max, Kiem_Tra_ESC, check_enter, left, right);
			if(Kiem_Tra_ESC == true)
			{
				check = true;
				return a;
			}
			if(check_enter == true)
			{
				if(ma_doc_gia.length() != 0 && ho.length() != 0 && ten.length() != 0 && phai.length() != 0 && ngaysinh.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 4);
						bool kiem_tra = Xac_Nhan_1(25, y + 4);
						if(kiem_tra == true)
						{
							a.Ma_Doc_Gia = madocgia;
							a.Ho = ho;
							a.Ten = ten;
							a.Phai = phai;
							a.Trang_Thai = true;
							// chuẩn hóa theo qui tắc chuẩn
							Chuan_Hoa(a.Ho);
							Chuan_Hoa(a.Ten);
							Chuan_Hoa(a.Phai);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else
				{
					TextColor(12);
					gotoXY(25, y + 4);
					cout << "KHONG THE LUU. DU LIEU CON TRONG";
					getch();
					gotoXY(25, y + 4);
					cout << "                                      ";
					TextColor(7);
				}
			}
			if(left == true)
			{
				VT = 2;
			}
			else if(right == true)
			{
				VT = 4;
			}
			gotoXY(55 + ngaysinh.length(), y);
		}
		else if(VT == 4)
		{
			bool check_1 = false; // có tác dụng nếu như ngày tháng năm nhập vào hợp lệ thì giữ giá trị true
			// vòng lặp có tác dụng lặp đến khi nào độ dài khác 0 và khác 8 hay check_1 bằng false và độ dài bằng 8 
			do{

				gotoXY(55 + ngaysinh.length(), y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_Ngay_Sinh(a.ngaysinh, ngaysinh, ngaysinh.length(), x + 55, y, ngaysinh_max, check_1, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					check = true;
					return a;
				}


			}while((check_1 == false && ngaysinh.length() == 8) || (ngaysinh.length() != 8 && ngaysinh.length() != 0));

			if(check_enter == true)
			{
				if(ma_doc_gia.length() != 0 && ho.length() != 0 && ten.length() != 0 && phai.length() != 0 && ngaysinh.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 4);
						bool kiem_tra = Xac_Nhan_1(25, y + 4);
						if(kiem_tra == true)
						{
							a.Ma_Doc_Gia = madocgia;
							a.Ho = ho;
							a.Ten = ten;
							a.Phai = phai;
							a.Trang_Thai = true;
							// chuẩn hóa theo qui tắc chuẩn
							Chuan_Hoa(a.Ho);
							Chuan_Hoa(a.Ten);
							Chuan_Hoa(a.Phai);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else
				{
					TextColor(12);
					gotoXY(25, y + 4);
					cout << "KHONG THE LUU. DU LIEU CON TRONG";
					getch();
					gotoXY(25, y + 4);
					cout << "                                      ";
					TextColor(7);
				}
			}
			if(left == true)
			{
				VT = 3;
			}
			else if(right == true)
			{
				VT = 5;
			}
			gotoXY(70 + phai.length(), y);
		}
		else if(VT == 5)
		{
			gotoXY(70 + phai.length(), y);

			check_enter = false;
			left = false;
			right = false;
			do{
				gotoXY(70 + phai.length(), y);
				Nhap_Ten_2(phai,phai.length(), x + 70, y, phai_max, Kiem_Tra_ESC, check_enter, left, right);

				if(Kiem_Tra_ESC == true)
				{
					check = true;
					return a;
				}
				if(stricmp(phai.c_str(), "nam") != 0 && stricmp(phai.c_str(), "nu") != 0)
				{
					TextColor(12);
					gotoXY(20, y + 4);
					cout << "Gioi tinh khong hop le. Xin kiem tra va nhap lai ";
					getch();
					gotoXY(20, y + 4);
					cout << "                                                    ";
					TextColor(7);
				}
			}while(stricmp(phai.c_str(), "nam") != 0 && stricmp(phai.c_str(), "nu") != 0);
			if(check_enter == true)
			{
				if(ma_doc_gia.length() != 0 && ho.length() != 0 && ten.length() != 0 && phai.length() != 0 && ngaysinh.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 4);
						bool kiem_tra = Xac_Nhan_1(25, y + 4);
						if(kiem_tra == true)
						{
							a.Ma_Doc_Gia = madocgia;
							a.Ho = ho;
							a.Ten = ten;
							a.Phai = phai;
							a.Trang_Thai = true;
							// chuẩn hóa theo qui tắc chuẩn
							Chuan_Hoa(a.Ho);
							Chuan_Hoa(a.Ten);
							Chuan_Hoa(a.Phai);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else
				{
					TextColor(12);
					gotoXY(25, y + 4);
					cout << "KHONG THE LUU. DU LIEU CON TRONG";
					getch();
					gotoXY(25, y + 4);
					cout << "                                      ";
					TextColor(7);
				}
			}

			if(left == true)
			{
				VT = 4;
			}
			else if(right == true)
			{
				VT = 1;
			}
			gotoXY(0 + ma_doc_gia.length(), y);
		}
	}
}


// trả về số lượng độc giả hiện có trong thư viện
void So_Luong_Doc_Gia(Tree t, int &dem)
{
	if(t != NULL)
	{

		dem++;
		So_Luong_Doc_Gia(t->pLeft, dem);
		So_Luong_Doc_Gia(t->pRight, dem);
	}
}


void Xuat_Sua_Doc_Gia(Tree t, DOCGIA &x, int madocgia, int y)
{
	if(t == NULL)
	{
		return;
	}
	if(t->data.Ma_Doc_Gia > madocgia)
	{
		Xuat_Sua_Doc_Gia(t->pLeft, x, madocgia, y);
	}
	else if(t->data.Ma_Doc_Gia < madocgia)
	{
		Xuat_Sua_Doc_Gia(t->pRight, x, madocgia, y);
	}
	else if(t->data.Ma_Doc_Gia = madocgia)
	{
		x.Ma_Doc_Gia = madocgia;
		x.Ho = t->data.Ho;
		x.ngaysinh = t->data.ngaysinh;
		x.Phai = t->data.Phai;
		x.Ten = t->data.Ten;
		Xuat_Thong_Tin_Sua_Doc_Gia(t->data, y);
		return;
	}
}


void Dang_Ki_Doc_Gia(Tree &t)
{
	clrscr(); // hàm xóa màn hình
	DOCGIA x;
	bool KT;

	TextColor(14);
	gotoXY(24, 0);
	cout << "**************************";

	TextColor(14);
	gotoXY(24, 1);
	cout << "*";
	TextColor(14);
	gotoXY(49, 1);
	cout << "*";

	TextColor(11);
	gotoXY(25, 1);
	cout << " NHAP THONG TIN DOC GIA ";

	TextColor(14);
	gotoXY(24, 2);
	cout << "**************************";


	gotoXY(0, 4);
	cout << "********************************************************************************";

	TextColor(15);
	gotoXY(31, 4);
	cout << " HUONG DAN ";


	gotoXY(1, 6);  cout << "Bam ESC de thoat !";
	gotoXY(1, 8);  cout << "Di chuyen qua lai:   " << (char)26 << "    " << (char)27 ;
	gotoXY(1, 10); cout << "Bam ENTER de luu !";

	TextColor(14);
	gotoXY(0, 12);
	cout << "********************************************************************************"; 

	TextColor(10);
	In_Khung_Doc_Gia(14);
	TextColor(7);
	bool check = false;
	// vòng lặp có tác dụng cho người dùng nhập đến khi nào nhấn esc thì thoát, còn nhấn enter thì lưu bình thường
	while(check != true)
	{
		KT = false;
		x = Nhap_Thong_Tin_Doc_Gia_1(t, 0, 16, KT, check);

		if(KT == true)
		{
			//cout << sizeof(x.l); // xuất ra độ lớn của con trỏ
			Init(x.l); // khởi tạo cho mỗi độc giả 1 danh sách mượn trả
			Insert(t, x); // thêm 1 đgộc giả mới vào danh sách
		}
	}
}


void Xuat_Danh_Sach_Thong_Tin_Doc_Gia_2(Tree t)
{
	clrscr();
	int tdy = 3;
	gotoXY(20, 0);
	TextColor(10);
	cout << "* DANH SACH DOC GIA HIEN CO TRONG THU VIEN *";
	TextColor(11);
	In_Khung_Xuat(tdy);
	TextColor(15);
	Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(t, tdy);
	TextColor(7);
}