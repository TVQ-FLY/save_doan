#include"ThongTinDocGia.h"


void Nhap_Thong_Tin_Doc_Gia(DOCGIA &x)
{
	cout << "\nNhap ma doc gia: ";
	cin >> x.Ma_Doc_Gia;

	fflush(stdin);
	cout << "\nNhap ho doc gia: ";
	getline(cin, x.Ho);

	fflush(stdin);
	cout << "\nNhap ten doc gia: ";
	getline(cin, x.Ten);

	fflush(stdin);
	cout << "\nNhap gioi tinh doc gia: ";
	getline(cin, x.Phai);
	x.Trang_Thai = true; // Trạng thái thẻ có thể mượn được sách
}

void Xuat_Thong_Tin_Doc_Gia(DOCGIA x)
{
	cout << "\nMa so doc gia: " << x.Ma_Doc_Gia;
	cout << "\nHo doc gia: " << x.Ho;
	cout << "\nTen doc gia: " << x.Ten;
	cout << "\nGioi tinh: " << x.Phai;
	cout << "\nTrang thai the doc gia: " << x.Trang_Thai;
}

void Xuat_Thong_Tin_Doc_Gia_1(DOCGIA x , int tdy)
{
	gotoXY(0, tdy);
	cout << x.Ma_Doc_Gia;
	gotoXY(15, tdy);
	cout << x.Ho;
	gotoXY(30, tdy);
	cout << x.Ten;


	int ngay = x.ngaysinh.Ngay_Hien_Tai;
	int thang = x.ngaysinh.Thang_Hien_Tai;

	if(ngay <= 9 && thang <= 9)
	{

		gotoXY(55, tdy);
		cout << "0" << x.ngaysinh.Ngay_Hien_Tai << "/0" << x.ngaysinh.Thang_Hien_Tai << "/" << x.ngaysinh.Nam_Hien_Tai;
	}
	else if(ngay <= 9 || thang <= 9)
	{
		gotoXY(55, tdy);
		if(ngay <= 9)
		{
			cout << "0" << x.ngaysinh.Ngay_Hien_Tai << "/" << x.ngaysinh.Thang_Hien_Tai << "/" << x.ngaysinh.Nam_Hien_Tai;
		}
		else if(thang <= 9)
		{
			cout << x.ngaysinh.Ngay_Hien_Tai << "/0" << x.ngaysinh.Thang_Hien_Tai << "/" << x.ngaysinh.Nam_Hien_Tai;
		}
	}
	else
	{
		gotoXY(55, tdy);
		cout << x.ngaysinh.Ngay_Hien_Tai << "/" << x.ngaysinh.Thang_Hien_Tai << "/" << x.ngaysinh.Nam_Hien_Tai;
	}


	gotoXY(70, tdy);
	cout << x.Phai;
	gotoXY(76, tdy);
	cout << x.Trang_Thai;
}


void Xuat_Thong_Tin_Sua_Doc_Gia(DOCGIA x, int tdy)
{
	gotoXY(0, tdy);
	cout << x.Ma_Doc_Gia;
	gotoXY(15, tdy);
	cout << x.Ho;
	gotoXY(30, tdy);
	cout << x.Ten;


	int ngay = x.ngaysinh.Ngay_Hien_Tai;
	int thang = x.ngaysinh.Thang_Hien_Tai;

	if(ngay <= 9 && thang <= 9)
	{

		gotoXY(55, tdy);
		cout << "0" << x.ngaysinh.Ngay_Hien_Tai << "0" << x.ngaysinh.Thang_Hien_Tai << x.ngaysinh.Nam_Hien_Tai;
	}
	else if(ngay <= 9 || thang <= 9)
	{
		gotoXY(55, tdy);
		if(ngay <= 9)
		{
			cout << "0" << x.ngaysinh.Ngay_Hien_Tai << x.ngaysinh.Thang_Hien_Tai  << x.ngaysinh.Nam_Hien_Tai;
		}
		else if(thang <= 9)
		{
			cout << x.ngaysinh.Ngay_Hien_Tai << "0" << x.ngaysinh.Thang_Hien_Tai << x.ngaysinh.Nam_Hien_Tai;
		}
	}
	else
	{
		gotoXY(55, tdy);
		cout << x.ngaysinh.Ngay_Hien_Tai << x.ngaysinh.Thang_Hien_Tai << x.ngaysinh.Nam_Hien_Tai;
	}


	gotoXY(70, tdy);
	cout << x.Phai;
	gotoXY(76, tdy);
	cout << x.Trang_Thai;
}

void In_Khung_Doc_Gia(int tdy)
{
	gotoXY(0, tdy);
	cout << "Ma doc gia";
	gotoXY(15, tdy);
	cout << "Ho";
	gotoXY(30, tdy);
	cout << "Ten";
	gotoXY(55, tdy);
	cout << "Ngay sinh";
	gotoXY(70, tdy);
	cout << "Gioi tinh";
}

void In_Khung_Xuat(int tdy)
{
	gotoXY(0, tdy);
	cout << "Ma doc gia";
	gotoXY(15, tdy);
	cout << "Ho";
	gotoXY(30, tdy);
	cout << "Ten";
	gotoXY(55, tdy);
	cout << "Ngay sinh";
	gotoXY(70, tdy);
	cout << "Phai";
	gotoXY(76, tdy);
	cout << "TT";
}

void Tach_Ngay_Thang_Nam(string str, int &x, int &y, int &z)
{
	string s;

	s.push_back(str[0]);
	str.erase(str.begin() + 0);
	s.push_back(str[0]);
	str.erase(str.begin() + 0);
	x = Chuoi_Sang_So(s);
	s.resize(0);


	s.push_back(str[0]);
	str.erase(str.begin() + 0);
	s.push_back(str[0]);
	str.erase(str.begin() + 0);
	y = Chuoi_Sang_So(s);

	z = Chuoi_Sang_So(str);
}

void Nhap_Ngay_Sinh(DATE &ngaysinh, string &str, int cd, int x, int y, int cd_max, bool &Kiem_Tra, bool &check_esc, bool &check_enter, bool &left, bool &right)
{
	char c;
	int length = cd;
	do{

		// vòng lặp lặp vô tận cho đến khi ta nhấn phím enter <=> kết thúc việc nhập
		while(true)
		{
			c = getch();
			if(int(c) == 8)
			{

				if(length != 0) // nếu như độ dài chuỗi bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if(str.length() != 0) // xóa kí tự cuối trong chuỗi string 
				{
					str.erase(str.begin() + (str.length() - 1));
				}
			}
			else if(c >= '0' && c <= '9')// nếu không phải là kí tự enter và Backpace thì kiểm tra nếu là kí tự số thì thêm vào chuỗi
			{

				if(str.length() < cd_max)
				{
					cout << c;

					str.push_back(c);

					length++;
				}
				else
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Du lieu toi da " << cd_max << " con so . Xin kiem tra lai !";
					getch();
					gotoXY(20, y + 2);
					cout << "                                                                   ";
					gotoXY(x + length, y);
					TextColor(7);
				}

			}
			else if(c == 27)
			{
				check_esc = true;
				return;
			}
			else if(c == 13)
			{
				check_enter = true;
				break;
			}
			else if(c == -32)
			{
				c = getch();
				if(c == 75)
				{
					if(str.length() != 0 && str.length() != 8)
					{
						TextColor(12);
						gotoXY(20, y + 2);
						cout << "Du lieu phai co 8 so. Xin kiem tra lai";
						getch();
						gotoXY(20, y + 2);
						cout << "                                           ";
						TextColor(7);
						gotoXY(x + length, y);
					}
					else if(str.length() == 8)
					{
						int ngay, thang, nam;
						Tach_Ngay_Thang_Nam(str, ngay, thang, nam);

						ngaysinh.Ngay_Hien_Tai = ngay;
						ngaysinh.Thang_Hien_Tai = thang;
						ngaysinh.Nam_Hien_Tai = nam;

						bool a = true;
						bool b = true;
						bool c = true; 
						Kiem_Tra = Kiem_Tra_Tinh_Hop_Le_1(ngaysinh, a, b, c);

						if(Kiem_Tra == false)
						{
							if(a == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Ngay sinh khong hop le";
								getch();
								gotoXY(20, y + 2);
								cout << "                         ";
								TextColor(7);

							}
							if(b == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Thang sinh khong hop le";
								getch();
								gotoXY(20, y + 2);
								cout << "                             ";
								TextColor(7);
							}

							if(c == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Nam sinh khong hop le";
								getch();
								gotoXY(20, y + 2);
								cout << "                          ";
								TextColor(7);
							}
						}
					}

					left = true;
					return;
				}
				else if(c == 77)
				{
					if(str.length() != 0 && str.length() != 8)
					{
						TextColor(12);
						gotoXY(20, y + 2);
						cout << "Du lieu phai co 8 so. Xin kiem tra lai";
						getch();
						gotoXY(20, y + 2);
						cout << "                                           ";
						TextColor(7);
						gotoXY(x + length, y);
					}
					else if(str.length() == 8)
					{
						int ngay, thang, nam;
						Tach_Ngay_Thang_Nam(str, ngay, thang, nam);

						ngaysinh.Ngay_Hien_Tai = ngay;
						ngaysinh.Thang_Hien_Tai = thang;
						ngaysinh.Nam_Hien_Tai = nam;

						bool a = true;
						bool b = true;
						bool c = true; 
						Kiem_Tra = Kiem_Tra_Tinh_Hop_Le_1(ngaysinh, a, b, c);

						if(Kiem_Tra == false)
						{
							if(a == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Ngay sinh khong hop le";
								getch();
								gotoXY(20, y + 2);
								cout << "                         ";
								TextColor(7);

							}
							if(b == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Thang sinh khong hop le";
							    getch();
								gotoXY(20, y + 2);
								cout << "                             ";
								TextColor(7);
							}

							if(c == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Nam sinh khong hop le";
								getch();
								gotoXY(20, y + 2);
								cout << "                          ";
								TextColor(7);
							}
						}
					}
					right = true;
					return;
				}
			}

		}


		if(str.length() != 0 && str.length() != 8)
		{
			TextColor(12);
			gotoXY(20, y + 2);
			cout << "Du lieu phai co 8 so. Xin kiem tra lai";
			getch();
			gotoXY(20, y + 2);
			cout << "                                           ";
			TextColor(7);
			gotoXY(x + length, y);
		}
		else if(str.length() == 8)
		{
			int ngay, thang, nam;
			Tach_Ngay_Thang_Nam(str, ngay, thang, nam);

			ngaysinh.Ngay_Hien_Tai = ngay;
			ngaysinh.Thang_Hien_Tai = thang;
			ngaysinh.Nam_Hien_Tai = nam;

			bool a = true;
			bool b = true;
			bool c = true; 
			Kiem_Tra = Kiem_Tra_Tinh_Hop_Le_1(ngaysinh, a, b, c);

			if(Kiem_Tra == false)
			{
				if(a == false)
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Ngay sinh khong hop le";
					getch();
					gotoXY(20, y + 2);
					cout << "                         ";
					TextColor(7);

				}
				if(b == false)
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Thang sinh khong hop le";
					getch();
					gotoXY(20, y + 2);
					cout << "                             ";
					TextColor(7);
				}

				if(c == false)
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Nam sinh khong hop le";
					getch();
					gotoXY(20, y + 2);
					cout << "                          ";
					TextColor(7);
				}
			}
		}

	}while(str.length() != 0 && str.length() != 8);

}


// hàm xuất thông tin độc giả ra file
void Xuat_Thong_Tin_Doc_Gia_File(ofstream &file, DOCGIA x)
{
	file << "\nMa doc gia: " << x.Ma_Doc_Gia;
	file << "\nHo: " << x.Ho;
	file << "\nTen: " << x.Ten;
	file << "\nPhai: " << x.Phai;
	file << "\nNgay sinh: " << x.ngaysinh.Ngay_Hien_Tai << "/" << x.ngaysinh.Thang_Hien_Tai << "/" << x.ngaysinh.Nam_Hien_Tai;
	file << "\nTrang thai the: " << x.Trang_Thai;
}

// hàm đọc file thông tin độc giả
void Doc_File_Thong_Tin_Doc_Gia(ifstream &file, DOCGIA &x)
{
	file >> x.Ma_Doc_Gia;
	file.seekg(2, 1);
	getline(file, x.Ho, ',');
	file.seekg(1, 1);
	getline(file, x.Ten, ',');
	Doc_File_Ngay_Thang_Nam(file, x.ngaysinh);
	getline(file, x.Phai, ',');
	file.seekg(1, 1);
	file >> x.Trang_Thai;
	file.seekg(2, 1);
}

// hàm ghi file thông tin độc giả lên file
void Ghi_File_Thong_Tin_Doc_Gia(ofstream &file, DOCGIA x)
{
	file << x.Ma_Doc_Gia << ", ";
	file << x.Ho << ", ";
	file << x.Ten << ", ";
	Ghi_File_Ngay_Thang_Nam(file, x.ngaysinh);
	file << ", ";
	file << x.Phai << ", ";
	file << x.Trang_Thai;
}