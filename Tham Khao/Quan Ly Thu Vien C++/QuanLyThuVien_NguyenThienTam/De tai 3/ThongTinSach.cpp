#include"ThongTinSach.h"


void Nhap_Thong_Tin_Sach(SACH &x)
{
	fflush(stdin);
	cout << "\nNhap ten sach: ";
	getline(cin, x.Ten_Sach);

	cout << "\nNhap so trang sach: ";
	x.So_Trang = Nhap_So_Nguyen();

	x.Tac_Gia = Nhap_Ten("\nNhap ten tac gia: ");

	cout << "\nNhap nam xuat ban sach: ";
	x.Nam_Xuat_Ban = Nhap_So_Nguyen();

	x.Trang_Thai = '0'; // mặc định khi ta nhập vào 1 quyển sách mới thì quyển sách đó có thể cho mượn được 

	cout << "\n\nNhap vi tri sach: ";
	getline(cin , x.Vi_Tri);
}

void Xuat_Thong_Tin_Sach(SACH x)
{
	cout << "\nMa sach: "  << x.Ma_Sach;
	cout << "\nTen sach: " << x.Ten_Sach;
	cout << "\nSo trang: " << x.So_Trang;
	cout << "\nTac gia: " << x.Tac_Gia;
	cout << "\nNam xuat ban: " << x.Nam_Xuat_Ban;
	cout << "\nTrang thai: " << x.Trang_Thai;
	cout << "\nVi tri: " << x.Vi_Tri;
}

void Xuat_Thong_Tin_Sach_1(SACH x, int y)
{
	gotoXY(0, y);
	cout << x.Ma_Sach;
	gotoXY(10, y);
	cout << x.Ten_Sach;
	gotoXY(30, y);
	cout << x.Tac_Gia;
	gotoXY(50, y);
	cout << x.So_Trang;
	gotoXY(57, y);
	cout << x.Nam_Xuat_Ban;
	gotoXY(62, y);
	cout << x.Trang_Thai;
	gotoXY(74, y);
	cout << x.Vi_Tri;
}

void Xuat_Thong_Tin_Sach_2(SACH x, int y)
{
	gotoXY(0, y);
	cout << x.Ma_Sach;
	gotoXY(10, y);
	cout << x.Ten_Sach;
	gotoXY(30, y);
	cout << x.Tac_Gia;
	gotoXY(50, y);
	cout << x.So_Trang;
	gotoXY(60, y);
	cout << x.Nam_Xuat_Ban;
	gotoXY(70, y);
	cout << x.Vi_Tri;
}
void In_Khung(int tdy)
{
	gotoXY(0, tdy);
	cout << "Ma sach";
	gotoXY(10, tdy);
	cout << "Ten sach";
	gotoXY(30, tdy);
	cout << "Tac gia";
	gotoXY(50, tdy);
	cout << "Trang";
	gotoXY(57, tdy);
	cout << "NXB";
	gotoXY(62, tdy);
	cout << "Trang thai";
	gotoXY(74, tdy);
	cout << "Vi tri";
}

bool Kiem_Tra_Ki_Tu_So(char c)
{
	if(c < '0' || c > '9')
	{
		return false;
	}
	return true;
}

// hàm chuyển đổi chuỗi số sang số nguyên
int Chuoi_Sang_So(string str)
{
	int Sum = 0;
	int length = str.length();
	int mu = length - 1;
	for(int i = 0; i < length; i++)
	{
		Sum += ((str[i] - 48) * pow(10, mu-- * 1.0));
	}
	return Sum;
}


int Nhap_So_Nguyen()
{
	string str;
	char c;
	c = getch(); // nhập kí tự đầu tiên

	// vòng lặp lặp vô tận cho đến khi ta nhấn phím enter <=> kết thúc việc nhập
	while((int)c != 13)
	{

		if(int(c) == 8)
		{

			if(str.length() != 0) // nếu như độ dài chuỗi bằng 0 thì ko cho xóa tiếp
			{
				cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
			}
			if(str.length() != 0) // xóa kí tự cuối trong chuỗi string 
			{
				str.erase(str.begin() + (str.length() - 1));
			}
		}
		else // nếu không phải là kí tự enter và Backpace thì kiểm tra nếu là kí tự số thì thêm vào chuỗi
		{
			cout << c;
			if(Kiem_Tra_Ki_Tu_So(c) == false)
			{
				cout << "\nKieu du lieu khong hop le. Xin nhap lai\n";
				str.resize(0);
			}
			else
			{
				str.push_back(c);
			}
		}
		c = getch();
	}
	return Chuoi_Sang_So(str);
}



// hàm chuẩn hóa chuỗi theo nguyên tắc: viết hoa chữ cái đầu và mỗi từ cách nhau 1 khoảng trắng
void Chuan_Hoa(string &str)
{
	str.insert(str.begin() + 0, ' '); // thêm vào đầu kí tự khoảng trắng
	str.insert(str.begin() + str.length(), ' '); // thêm vào cuối kí tự khoảng trắng. Nếu không thêm thì sẽ không kiểm tra kí tự cuối cùng, vì i < chiều dài - 1

	for(int i = 0; i < str.length() - 1; i++)
	{

		if(str[i] == ' ' && str[i + 1] == ' ') // nếu 2 kí tự liên tiếp nhau là khoảng trắng thì xóa 1 kí tự khoảng trắng
		{
			str.erase(str.begin() + i);
			i--;
		}
		else if(str[i] == ' ' && str[i + 1] != ' ') // nếu kí tự thứ i là khoảng trắng và kí tự i + 1 khác khoảng trắng thì in hoa kí tự i + 1(nếu là kí tự thường)
		{
			if(str[i + 1] >= 97 && str[i + 1] <= 122)
			{
				str[i + 1] -= 32;

			}
			// vòng lặp có tác dụng chuẩn hóa các kí tự tiếp theo sau kí tự vừa được chuẩn hóa thành các kí tự thường
			for(int j = i + 2; ; j++)
			{
				if(str[j] >= 65 && str[j] < 97)
				{
					str[j] += 32;
				}
				else if(str[j] == ' ') // khi gặp khoảng trằng thì dừng 
				{
					i = j - 1; // trả i bằng j - 1, bởi sau đó i++
					break;
				}
			}
		}
	}

	if(str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
	if(str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1);
	}
}

// hàm loại bỏ các khoảng trắng dư thừa
void Chuan_Hoa_Khoang_Trang(string &str)
{
	// xóa khoảng trắng mà vì i < str.length() - 1, nên chiều dài phải khác 0 thì mới duyệt
	if(str.length() != 0)
	{
		for(int i = 0; i < str.length() - 1; i++)
		{
			if(str[i] == ' ' && str[i + 1] == ' ')
			{
				str.erase(str.begin() + i);
				i--;
			}
		}
		if(str[0] == ' ')
		{
			str.erase(str.begin() + 0);
		}
		if(str[str.length() - 1] == ' ')
		{
			str.erase(str.begin() + str.length() - 1);
		}
	}
}

// hàm chuẩn hóa theo nguyên tắc in hoa các kí tự của chuỗi
void Chuan_Hoa_In_Hoa(string &str)
{
	int length = str.length();
	for(int i = 0; i < length; i++)
	{
		if(str[i] >= 97 && str[i] <= 122)
		{
			str[i] -= 32;
		}
	}
}

// hàm trả về false nếu chuỗi toàn khoảng trắng. Ngược lại trả về true
bool Kiem_Tra_Khoang_Trang(string str)
{
	int length = str.length();
	for(int i = 0; i < length; i++)
	{
		if(str[i] != ' ')
		{
			return true;
		}
	}
	return false;
}

// hàm kiểm tra dữ liệu của chuỗi nhập vào phải là các kí tự số hoặc kí tự chữ cái. Ngược lại sai trả về false 
bool Kiem_Tra_Du_Lieu(string str)
{
	if(str[0] < 65 || str[0] > 122)
	{
		return false;
	}
	return true;
}

// Hàm nhập dữ liệu trả về kiểu dữ liệu sau khi hợp lệ 
string Nhap_Ten(string str)
{

	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	string s;
	bool KT;
	do
	{
		cout << str;
		getline(cin, s);
		Chuan_Hoa(s);
		KT = Kiem_Tra_Du_Lieu(s);
		if(KT == false)
		{
			if(s.length() == 0)
			{
				cout << "\nDu lieu khong duoc de trong. Xin nhap lai";
			}
			else if(s[0] > '0' && s[0] < '9')
			{
				cout << "\nDu lieu phai la ki tu. Xin nhap lai";
			}
			system("pause");
		}

	}while(KT == false);

	return s;
}

// Hàm nhập dữ liệu chuỗi bình thường , kí tự số và kí tự 
string Nhap_Du_Lieu_Chuoi(int x, int y)
{
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	string s;
	bool KT;
	do
	{

		getline(cin, s);
		Chuan_Hoa(s);
		KT = Kiem_Tra_Du_Lieu(s);
		if(KT == false)
		{
			gotoXY(x, y);
			cout << "\nDu lieu khong hop le. Xin nhap lai";
			system("pause");
		}

	}while(KT == false);

	return s;
}


/*DO HOA*/

int Nhap_So_Nguyen_1(int x, int y)
{
	string str;
	char c;
	int length = 0;
	bool KT;
	do{
		c = getch(); // nhập kí tự đầu tiên
		// vòng lặp lặp vô tận cho đến khi ta nhấn phím enter <=> kết thúc việc nhập
		while((int)c != 13)
		{

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
			else // nếu không phải là kí tự enter và Backpace thì kiểm tra nếu là kí tự số thì thêm vào chuỗi
			{
				cout << c;
				length++;
				if(Kiem_Tra_Ki_Tu_So(c) == false)
				{
					gotoXY(20, y + 1);
					cout << "Kieu du lieu khong hop le. Xin nhap lai\n";
					system("pause");
					gotoXY(20, y + 1);
					cout << "                                         ";
					gotoXY(0, y + 2);
					cout << "                                         ";
					gotoXY(x + length, y);
					str.resize(0);
				}
				else 
				{
					str.push_back(c);

				}
			}
			c = getch();
		}

	}while(str.length() == 0);

	return Chuoi_Sang_So(str);
}

void Nhap_So_Nguyen_2(string &str, int &a, int cd, int x, int y, int &cd_max, bool &check_esc, bool &check_enter)
{
	//string str;
	char c;
	int length = cd;
	bool KT;

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
					cout << "Du lieu toi da " << cd_max << " con so . Xin kiem tra lai !\n";
					system("pause");
					gotoXY(20, y + 2);
					cout << "                                                                   ";
					gotoXY(0, y + 3);
					cout << "                                                               ";
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
		}

		if(str.length() == 0)
		{
			TextColor(12);
			gotoXY(20, y + 2);
			cout << "Du lieu khong duoc de trong. Xin kiem tra va nhap lai\n";
			system("pause");
			gotoXY(20, y + 2);
			cout << "                                                       ";
			gotoXY(0, y + 3);
			cout << "                                                       ";
			gotoXY(x + str.length(), y);
			TextColor(7);
		}

	}while(str.length() == 0);

	a = Chuoi_Sang_So(str);
}


void Nhap_So_Nguyen_3(string &str, int &a, int cd, int x, int y, int &cd_max, bool &Kiem_Tra, bool&check, bool &left, bool &right)
{
	//string str;
	char c;
	int length = cd;
	bool KT;

	//	do{

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
		else if((int)c == 27)
		{

			Kiem_Tra = true;
			return;

		}
		else if((int)c ==  13)
		{
			check = true;
			break;
		}
		else if(c == -32)
		{
			c = getch();
			if((int)c == 75)
			{
				a = Chuoi_Sang_So(str);
				left = true;
				return;

			}
			else if((int)c == 77)
			{
				a = Chuoi_Sang_So(str);
				right = true;
				return;
			}

		}
	}
	a = Chuoi_Sang_So(str);
}

string Nhap_Ten_1(int x, int y) // Hàm nhập dữ liệu toàn kí tự . VD: họ, tên, giới tính. Kí tự bắt đầu phải là kí tự 
{
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	string str;
	bool KT;
	int length = 0; // biến cho con trỏ dịch đến cuối
	char c;

	do
	{
		c = getch();

		while(int(c) != 13)
		{

			if(int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
			{

				if(length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if(str.length() != 0) // xóa kí tự cuối trong chuỗi string 
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

			c = getch();
		}

		Chuan_Hoa(str); // hàm chuẩn hóa
		KT = Kiem_Tra_Du_Lieu(str);


		if(KT == false)
		{
			if(str.length() == 0)
			{
				gotoXY(20, y + 1);
				cout << "Du lieu khong duoc de trong. Xin nhap lai\n";
				system("pause");
				gotoXY(20, y + 1);
				cout << "                                         ";
				gotoXY(0, y + 2);
				cout << "                                         ";
				gotoXY(x + length, y);
			}
			else if(str[0] > '0' && str[0] < '9')
			{

				gotoXY(20, y + 1);
				cout << "Du lieu phai la ki tu. Xin nhap lai\n";
				system("pause");
				gotoXY(20, y + 1);
				cout << "                                   ";
				gotoXY(0, y + 2);
				cout << "                                     ";
				gotoXY(x + length, y);
			}
			str.resize(0);
		}

	}while(KT == false);

	return str;
}

void Nhap_Ten_2(string &str, int cd, int x, int y, int &cd_max, bool &Kiem_Tra, bool &check_enter, bool &left, bool &right)
{
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	bool KT;
	int length = cd; // biến cho con trỏ dịch đến cuối
	char c;

	//	do
	//	{


	while(true)
	{
		c = getch();
		if(int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
		{

			if(length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
			{
				cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
				length--;
			}
			if(str.length() != 0) // xóa kí tự cuối trong chuỗi string 
			{
				str.erase(str.begin() + (str.length() - 1));
			}
		}
		else if(c >= 65 && c <= 122 || c == ' ')
		{
			if(str.length() < cd_max)
			{
				cout << c;
				length++; // cập nhật vị trí con trỏ chỉ vị
				str.push_back(c);
			}
			else
			{
				TextColor(12);
				gotoXY(20, y + 2);
				cout << "Du lieu toi da " << cd_max << " ki tu . Xin kiem tra lai !";
				getch();
				gotoXY(20, y + 2);
				cout << "                                                                   ";
				gotoXY(x + length, y);
				TextColor(7);
			}
		}
		else if(c > '0' && c < '9')
		{
			TextColor(12);
			gotoXY(20, y + 2);
			cout << "Du lieu phai la ki tu. Xin nhap lai";
			getch();
			gotoXY(20, y + 2);
			cout << "                                   ";
			gotoXY(x + length, y);
			TextColor(7);
		}
		else if((int)c == 27)
		{
			Kiem_Tra = true;
			return;
		}
		else if((int)c == 13)
		{
			check_enter = true;
			if(Kiem_Tra_Khoang_Trang(str) == false)
			{
				str.erase(0);
			}
			break;
		}
		else if(c == -32)
		{
			c = getch();
			if((int)c == 75)
			{
				left = true;
				if(Kiem_Tra_Khoang_Trang(str) == false)
				{
					str.erase(0);
				}
				return;


			}
			else if((int)c == 77)
			{
				right = true;
				if(Kiem_Tra_Khoang_Trang(str) == false)
				{
					str.erase(0);
				}
				return;
			}
		}
	}

}

void Nhap_Thong_Tin_Sach_1(SACH &a, int x, int y)
{

	char c;
	bool KT = false;
	do
	{

		gotoXY(0, y);
		a.Ma_Sach = Nhap_Ten_1(x, y);


		gotoXY(10, y);
		a.Ten_Sach = Nhap_Ten_1(x += 10, y);


		gotoXY(30, y);
		a.Tac_Gia = Nhap_Ten_1(x += 20, y);


		gotoXY(50, y);
		a.So_Trang = Nhap_So_Nguyen_1(x += 20, y);


		gotoXY(57, y);
		a.Nam_Xuat_Ban = Nhap_So_Nguyen_1(x += 7, y);


		gotoXY(62, y);
		a.Trang_Thai = '0';
		a.Vi_Tri = Nhap_Ten_1(x += 5, y);


		gotoXY(20, 7);
		cout << "Ban co muon luu thong tin sach.";
		gotoXY(20, 8);
		cout << "Y(YES)";
		gotoXY(20, 9);
		cout << "N(NO)";

		c = getch();

		if(c == 'y' || c == 'Y')
		{
			break;
		}

	}while(c != 'y' || c != 'Y');
}

void In_Khung_1(int tdy)
{
	gotoXY(0, tdy);
	cout << "Ma sach";
	gotoXY(10, tdy);
	cout << "Ten sach";
	gotoXY(30, tdy);
	cout << "Tac gia";
	gotoXY(50, tdy);
	cout << "Trang";
	gotoXY(60, tdy);
	cout << "NXB";
	gotoXY(70, tdy);
	cout << "Vi tri";
}

void In_Khung_Them_Vi_Tri_Bat_Ki(int tdy)
{
	gotoXY(0, tdy);
	cout << "Ma sach";
	gotoXY(10, tdy);
	cout << "Ten sach";
	gotoXY(30, tdy);
	cout << "Tac gia";
	gotoXY(50, tdy);
	cout << "Trang";
	gotoXY(60, tdy);
	cout << "NXB";
	gotoXY(70, tdy);
	cout << "Vi tri";
	gotoXY(20, tdy + 6);
	cout << "Vi tri can them:";
}

void Nhap_Du_Lieu_Chuoi_2(string &str, int cd, int x, int y, int &cd_max)
{
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	bool KT;
	int length = cd; // biến cho con trỏ dịch đến cuối
	char c;

	do
	{
		c = getch();
		while(int(c) != 13)
		{

			if(int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
			{

				if(length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
				{
					cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
					length--;
				}
				if(str.length() != 0) // xóa kí tự cuối trong chuỗi string 
				{
					str.erase(str.begin() + (str.length() - 1));
				}
			}
			else 
			{
				if(str.length() < cd_max)
				{
					cout << c;
					length++; // cập nhật vị trí con trỏ chỉ vị
					str.push_back(c);
				}
				else
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Du lieu toi da " << cd_max << " ki tu. Xin kiem tra lai !\n";
					system("pause");
					gotoXY(20, y + 2);
					cout << "                                                             ";
					gotoXY(0, y + 3);
					cout << "                                                              ";
					gotoXY(x + length, y);
					TextColor(7);
				}

			}
			c = getch();

		}

		if(str.length() == 0)
		{
			TextColor(12);
			gotoXY(20, y + 2);
			cout << "Du lieu khong duoc de trong. Xin nhap lai\n";
			system("pause");
			gotoXY(0, y + 3);
			cout << "                                             ";
			gotoXY(20, y + 2);
			cout << "                                              ";
			gotoXY(x + length, y);
			TextColor(7);
		}
		//str.resize(0);
	}while(str.length() == 0);
}


void Nhap_Du_Lieu_Chuoi_3(string &str, int cd, int x, int y, int &cd_max, bool &Kiem_Tra, bool& check, bool &left, bool &right)
{
	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	bool KT;
	int length = cd; // biến cho con trỏ dịch đến cuối
	char c;

	//do
	//{
	while(true)
	{
		c = getch();
		if(int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
		{

			if(length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
			{
				cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
				length--;
			}
			if(str.length() != 0) // xóa kí tự cuối trong chuỗi string 
			{
				str.erase(str.begin() + (str.length() - 1));
			}
		}
		else if((int)c == 27)
		{
			Kiem_Tra = true; // nếu nhấn kí tự ESC thì thoát
			return;
		}
		else if((int)c ==  13)
		{
			check = true; // nếu nhấn kí tự enter thì lưu
			if(Kiem_Tra_Khoang_Trang(str) == false)
			{
				str.erase(0);
			}
			break;
		}
		else if(c == -32)
		{

			c = getch();
			if((int)c == 75)
			{
				left = true;
				if(Kiem_Tra_Khoang_Trang(str) == false)
				{
					str.erase(0);
				}
				return;
			}
			else if((int)c == 77)
			{

				right = true;
				if(Kiem_Tra_Khoang_Trang(str) == false)
				{
					str.erase(0);
				}
				return;
			}
		}
		else
		{
			if(str.length() < cd_max)
			{
				cout << c;
				length++; // cập nhật vị trí con trỏ chỉ vị
				str.push_back(c);
			}
			else
			{
				TextColor(12);
				gotoXY(20, y + 2);
				cout << "Du lieu toi da " << cd_max << " ki tu. Xin kiem tra lai !";
				getch();
				gotoXY(20, y + 2);
				cout << "                                                                ";
				gotoXY(x + length, y);
				TextColor(7);
			}

		}

	}
}

// trả về true là tiếp tục thực hiện lệnh hiện tại
bool Xac_Nhan()
{
	int luachon;
	do{
		cout << "\n\n\t\t Ban co muon tiep tuc khong ?";
		cout << "\n1. Co";
		cout << "\n2. Khong";

		cout << "\nNhap lua chon: ";
		luachon = Nhap_So_Nguyen();

		if(luachon != 1  && luachon != 2)
		{
			cout << "\nLua chon khong hop le(luachon == 1 hoac luachon == 2). Xin nhap lai";
			system("pause");
		}
		else
		{
			if(luachon == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}while(luachon != 1 || luachon != 2);
}

bool Xac_Nhan_1(int x, int y)
{
	char c ;

	TextColor(15);
	gotoXY(x, y);
	cout << "Ban co muon luu khong ?";
	gotoXY(x + 5, y + 2);
	cout << "Co";
	gotoXY(x + 10, y + 2);
	cout << "Khong";

	bool KT;
	while(true)
	{
		c = getch();
		if(c == -32)
		{
			while(true)
			{
				c = getch();
				if(c == 75)
				{
					KT = true;
					TextColor(15);
					gotoXY(x + 10, y + 2);
					cout << "Khong";

					TextColor(10);
					gotoXY(x + 5, y + 2);
					cout << "Co";

				}
				else if(c == 77)
				{
					KT = false;
					TextColor(15);
					gotoXY(x + 5, y + 2);
					cout << "Co";

					TextColor(10);
					gotoXY(x + 10, y + 2);
					cout << "Khong";
				}

				c = getch();
				if(c == 13)
				{
					gotoXY(x, y);
					cout << "                                      ";
					gotoXY(x + 5, y + 2);
					cout << "    ";
					gotoXY(x + 10, y + 2);
					cout << "       ";
					TextColor(7);
					return KT;
				}
			}
		}
	}
}


// hàm đọc thông tin từ file
void Doc_Thong_Tin_Sach_File(ifstream &file, SACH &x)
{
	getline(file, x.Ma_Sach, ',');
	file.seekg(1, 1);
	getline(file, x.Ten_Sach, ',');
	file >> x.So_Trang;
	file.seekg(2, 1);
	getline(file, x.Tac_Gia, ',');
	file >> x.Nam_Xuat_Ban;
	file.seekg(2, 1);
	file >> x.Trang_Thai;
	file.seekg(2, 1);
	getline(file, x.Vi_Tri);

}

// hàm ghi thông tin lên file
void Ghi_Thong_Tin_Sach_File(ofstream &file, SACH x)
{
	file << x.Ma_Sach << ", ";
	file << x.Ten_Sach << ", ";
	file << x.So_Trang << ", "; 
	file << x.Tac_Gia << ", ";
	file << x.Nam_Xuat_Ban << ", ";
	file << x.Trang_Thai << ", ";
	file << x.Vi_Tri;
}