#include"DanhSachThongTinSach.h"


// Hàm nhập thông tin quyển sách và đưa vào trong danh sách
void Menu_Xu_Li(LISTSACH &x)
{
	int luachon;
	do{
		clrscr(); // hàm hỗ trợ xóa màn hình
		cout << "\n\n\t\t =============== Menu ===============\n";
		cout << "\n1. Nhap thong tin sach moi vao danh sach ";
		cout << "\n2. Them thong tin sach moi vao vi tri bat ki trong danh sach";
		cout << "\n3. Xoa thong tin sach trong danh sach";
		cout << "\n4. Sua thong tin sach trong danh sach";
		cout << "\n5. Tim kiem thong tin sach trong danh sach";
		cout << "\n6. Xuat danh sach thong tin sach";
		cout << "\n7. Ket thuc";
		cout << "\n\t *** Note ***";
		cout << "\nTrang thai: ";
		cout << "\n+ 0: Cho muon duoc";
		cout << "\n+ 1: Da co doc gia muon";
		cout << "\n+ 2: Sach da thanh ly";
		cout << "\n\n\t\t =============== End ================";

		cout << "\nNhap lua chon: ";
		luachon = Nhap_So_Nguyen();

		if(luachon < 1 || luachon > 7)
		{
			cout << "\nLua chon khong ton tai. Xin nhap lai lua chon";
			system("pause");
		}
		else 
		{
			if(luachon == 1)
			{
				Nhap_Danh_Sach_Thong_Tin_Sach(x);
			}
			else if(luachon == 2)
			{
				clrscr();
				SACH y;


				TextColor(14);
				gotoXY(27, 0);
				cout << "***********************";

				TextColor(14);
				gotoXY(27, 1);
				cout << "*";
				TextColor(14);
				gotoXY(49, 1);
				cout << "*";

				TextColor(11);
				gotoXY(28, 1);
				cout << " NHAP THONG TIN SACH ";

				TextColor(14);
				gotoXY(27, 2);
				cout << "***********************";


				gotoXY(0, 4);
				cout << "********************************************************************************";

				TextColor(15);
				gotoXY(33, 4);
				cout << " HUONG DAN ";


				gotoXY(1, 6);   cout << "Bam ESC de thoat !";
				gotoXY(1, 8);   cout << "Di chuyen qua lai:   " << (char)26 << "    " << (char)27 ;
				gotoXY(1, 10);  cout << "Bam ENTER de luu";

				TextColor(14);
				gotoXY(0, 12);
				cout << "********************************************************************************"; 



				// hàm in khung thêm thông tin sách vào vị trí bất kì
				TextColor(10);
				In_Khung_Them_Vi_Tri_Bat_Ki(14);
				TextColor(7);

				int vitri;
				bool kt_esc;
				bool kt_enter;
				bool KT ;
				bool check_esc;

				while(true)
				{

					KT = false;
					check_esc = false;
					y = Nhap_Thong_Tin_Sach_3(x, 0, 16, KT, check_esc, vitri);
					if(check_esc == true)
					{
						break;
					}
					else if(KT == true)
					{
						Them_Vi_Tri_Bat_Ki(x, vitri, y);
					}
				}
			}
			else if(luachon == 3)
			{
				Menu_Xoa(x);
			}
			else if(luachon == 4)
			{
				/*clrscr();
				Menu_Sua(x);
				cout << "\n";
				system("pause");*/
			}
			else if(luachon == 5)
			{
				clrscr();
				Menu_Tim_Kiem(x);
				cout << endl;
			}
			else if(luachon == 6)
			{
				clrscr();
				Xuat_Danh_Sach_Thong_Tin_Sach(x);
				cout << endl << endl;
				system("pause");
			}
			else if(luachon == 7)
			{
				break;
			}
		}

	}while((luachon < 1 || luachon > 7) || luachon != 7);
}
// menu làm nhiệm vụ xóa theo các tiêu chí do người dùng định nghĩa
void Menu_Xoa(LISTSACH &x)
{
	int luachon;
	do
	{
		clrscr();
		cout << "\n\n\t\t ================= Menu =================";
		cout << "\n1. Xoa thong tin sach tai 1 vi tri bat ki trong danh sach";
		cout << "\n2. Xoa thong tin sach theo ma sach";
		cout << "\n3. Xoa thong tin sach theo ten sach";
		cout << "\n4. Xoa thong tin sach theo trang thai(sach da thanh ly)";
		cout << "\n5. Thoat";
		cout << "\n\n\t\t ================= End ==================";
		cout << "\nNhap lua chon: ";
		luachon = Nhap_So_Nguyen();

		if(luachon < 1 || luachon > 5)
		{
			cout << "\nLua chon khong hop le. Xin nhap lai";
			system("pause");
		}
		else
		{
			if(luachon == 1)
			{
				int vitri;
				int size = x.size;
				do{
					clrscr();
					cout << "\n\tNhap vi tri can xoa: ";
					vitri = Nhap_So_Nguyen();
					if(vitri < 0 || vitri >= size)
					{
						cout << "\nVi tri can xoa khong hop le(Vitri > 0 hoac Vitri <= size). Xin nhap lai";
						system("pause");
					}
				}while(vitri < 0 || vitri >= size);

				Xoa_Vi_Tri_Bat_Ki(x, vitri);
			}
			else if(luachon == 2)
			{
				Xoa_Theo_Ma_Sach(x);
			}
			else if(luachon == 3)
			{
				Xoa_Theo_Ten_Sach(x);
			}
			else if(luachon == 4)
			{
				Xoa_Theo_Trang_Thai(x);
			}
			else if(luachon == 5)
			{
				break;
			}
		}

	}while((luachon < 1 || luachon > 5) || luachon != 5);
}

// Hàm xóa tại 1 vị trí bất kì
void Xoa_Vi_Tri_Bat_Ki(LISTSACH &x, int vitri)
{
	int size = x.size;
	for(int i = vitri; i < size - 1; i++)
	{
		x.LIST[i] = x.LIST[i + 1];
	}

	Cap_Phat_Lai_Bo_Nho(x, x.size - 1, x.size - 1); // giảm vùng nhớ đi 1 ô nhớ
	x.size--; // giảm kích thước mảng
}

// Hàm xóa dựa vào mã sách
void Xoa_Theo_Ma_Sach(LISTSACH &x)
{
	string masach;
	bool KT = false; // mặc định là danh sách chưa tồn tại mã sách
	int size = x.size;
	int i;

	// vòng lặp kiểm tra xem mã sách cần xóa có tồn tại trong danh sách chưa. Nếu ko có yêu cầu người dùng nhập lại
	do
	{
		clrscr();
		cout << "\nNhap ma sach can xoa: ";
		getline(cin, masach);
		for(i = 0; i < size; i++)
		{
			if(stricmp(x.LIST[i].Ma_Sach.c_str(), masach.c_str()) == 0) // hàm stricmp() : so sánh 2 chuỗi ko phân biệt hoa thường
			{
				KT = true; // danh sách có tồn tại mã sách
				break;
			}
		}
		if(KT == false)
		{
			cout << "\nMa sach chua ton tai trong danh sach.Xin nhap lai";
			// nếu sau khi kiểm tra mà mã sách cần xóa chưa tồn tại trong danh sách thì hỏi người dùng có muốn xóa thông tin sách theo mã sách nữa không
			if(Xac_Nhan() == false) 
			{
				break;
			}
		}
		else 
		{
			Xoa_Vi_Tri_Bat_Ki(x, i);
		}

	}while(KT == false);
}

// hàm xóa dựa vào tên sách
void Xoa_Theo_Ten_Sach(LISTSACH &x)
{
	string tensach;
	bool KT = false; // mặc định là danh sách chưa tồn tại mã sách

	// vòng lặp kiểm tra xem tên sách cần xóa có tồn tại trong danh sách chưa. Nếu ko có yêu cầu người dùng nhập lại
	do
	{
		clrscr();
		fflush(stdin);
		cout << "\n\t Nhap ten sach can xoa: ";
		getline(cin, tensach);
		for(int i = 0; i < x.size; i++)
		{
			if(stricmp(x.LIST[i].Ten_Sach.c_str(), tensach.c_str()) == 0)
			{
				KT = true; // danh sách có tồn tại mã sách
				Xoa_Vi_Tri_Bat_Ki(x, i);
				i--; // lùi lại 1 vị trí. Tình huống 2 tên sách nằm cạnh nhau
			}
		}
		if(KT == false)
		{
			cout << "\nTen sach chua ton tai trong danh sach. Xin nhap lai";
			if(Xac_Nhan() == false)
			{
				break;
			}
		}

	}while(KT == false);
}

// hàm xóa dựa vào trạng thái
void Xoa_Theo_Trang_Thai(LISTSACH &x)
{
	for(int i = 0; i < x.size; i++)
	{
		if(x.LIST[i].Trang_Thai == '2')
		{
			Xoa_Vi_Tri_Bat_Ki(x, i);
			i--;// lùi lại 1 vị trí
		}
	}
}

// menu làm nhiệm vụ sửa thông tin 1 quyển sách theo các tiêu chí do người dùng định nghĩa
void Menu_Sua(LISTSACH &x)
{
	int size = x.size;
	int tdy = 3;
	In_Khung(tdy);
	for(int i = 0; i < size; i++)
	{
		Xuat_Thong_Tin_Sach_1(x.LIST[i], tdy += 2);
	}
}

// menu làm nhiệm vụ tìm kiếm thông tin 1 quyển sách theo các tiêu chí do người dùng định nghĩa
void Menu_Tim_Kiem(LISTSACH x)
{
	int luachon;
	do
	{
		clrscr();
		cout << "\n\n\t\t =================== Menu ===================";
		cout << "\n1. Tim kiem thong tin sach theo ma sach";
		cout << "\n2. Tim kiem thong tin sach theo ten sach";
		cout << "\n3. Tim kiem thong tin sach theo tac gia";
		cout << "\n4. Thoat";
		cout << "\n\n\t\t =================== End ====================";

		cout << "\nNhap lua chon: ";
		luachon = Nhap_So_Nguyen();

		if(luachon < 0 || luachon > 4)
		{
			cout << "\nLua chon khong hop le(luachon: 1 ---> 4). Xin nhap lai";
			system("pause");
		}
		else
		{
			if(luachon == 1)
			{
				clrscr();
				Tim_Kiem_Theo_Ma_Sach(x);
				cout << endl;
			}
			else if(luachon == 2)
			{
				clrscr();
				Tim_Kiem_Theo_Ten_Sach(x);
				cout << endl;
			}
			else if(luachon == 3)
			{
				clrscr();
				Tim_Kiem_Theo_Tac_Gia(x);
				cout << endl;	
			}
			else if(luachon == 4)
			{
				break;
			}
		}
	}while((luachon < 0 || luachon > 4) || luachon != 4);
}

// Hàm tìm kiếm theo mã sách
void Tim_Kiem_Theo_Ma_Sach(LISTSACH x)
{
	string masach;
	bool KT = false; // mặc định là danh sách chưa tồn tại mã sách
	int size = x.size;
	int i;

	// vòng lặp có tác dụng nhập mã sách cần tìm kiếm
	do{
		clrscr();
		cout << "\nNhap ma sach can tim kiem: ";
		getline(cin, masach);
		for(i = 0; i < size; i++)
		{
			if(stricmp(x.LIST[i].Ma_Sach.c_str(), masach.c_str()) == 0) // hàm stricmp() : so sánh 2 chuỗi ko phân biệt hoa thường
			{
				KT = true; // danh sách có tồn tại mã sách
				break;
			}
		}
		if(KT == true)
		{
			clrscr();
			gotoXY(15, 0);
			cout << "* THONG TIN SACH CAN TIM CO MA SACH " << masach << " *";
			In_Khung(3);
			Xuat_Thong_Tin_Sach_1(x.LIST[i], 5);
		}
		else 
		{
			cout << "\nMa sach chua ton tai. Xin kiem tra lai";
			if(Xac_Nhan() == false)
			{
				break;
			}
		}

	}while(KT == false);
}

// hàm tìm kiếm theo tên sách
void Tim_Kiem_Theo_Ten_Sach(LISTSACH x)
{

	bool KT; // biến có tác dụng kiểm tra xem tên sách cân tìm kiếm có tồn tại trong danh sách hay không
	int size = x.size;

	string tensach;

	// in đồ họa tìm kiếm sách
	TextColor(14);
	gotoXY(18, 0); cout << "********************************************";
	gotoXY(18, 1); cout << "*";
	gotoXY(61, 1); cout << "*";

	TextColor(10);
	gotoXY(19, 1); cout << "  TIM KIEM THONG TIN SACH THEO TEN SACH ";

	TextColor(14);
	gotoXY(18, 2); cout << "********************************************";

	TextColor(15);
	gotoXY(30, 4); cout << "Bam ESC de thoat !";

	TextColor(15);
	gotoXY(0, 8);  cout << "Nhap ten sach can tim kiem:";
	int length = 0;



	TextColor(14);
	gotoXY(25, 14); cout << "****************************";
	gotoXY(25, 15); cout << "*";
	gotoXY(52, 15); cout << "*";

	TextColor(10); gotoXY(26, 15); cout << "  THONG TIN SACH CAN TIM ";

	TextColor(14);
	gotoXY(25, 16); cout << "****************************";

	TextColor(11);
	In_Khung(18);

	while(true)
	{

		int td_y = 20; // biến giữ tọa độ y 
		KT = false;  //mặc định là danh sách chưa tồn tại tên sách
		// vòng lặp kiểm tra xem tên sách cần tìm kiếm có tồn tại trong danh sách chưa. Nếu có thì xuất ra màn hình
		do
		{
			// in nền và in chuỗi hiện tại đè lên nên đó
			gotoXY(28, 8);
			TextColor(140);
			cout << "                    ";
			gotoXY(28, 8);
			cout << tensach;
			gotoXY(28 + length, 8);


			// vòng lặp nhập tên sách cần tìm kiếm , nếu khung nhập để trống thì nhắc nhở người dùng
			char c;
			do
			{

				// in nền và in chuỗi hiện tại đè lên nên đó
				gotoXY(28, 8);
				TextColor(140);
				cout << "                    ";
				gotoXY(28, 8);
				cout << tensach;
				gotoXY(28 + length, 8);

				while(true) // vòng lặp có tác dụng nhập chuỗi và kiểm tra độ dài chuỗi
				{
F:
					c = getch();
					length = tensach.length(); // biến cho con trỏ dịch đến cuối

					if(int(c) == 8) // nếu ấn phím Backspace thì xóa 1 kí tự ở cuối
					{

						if(length > 0) // nếu như độ dài biến con trỏ dịch bằng 0 thì ko cho xóa tiếp
						{
							// trước khi xóa thì in lại nền và chuỗi nhập trước đó trên nền
							gotoXY(28, 8);
							TextColor(140);
							cout << "                    ";
							gotoXY(28, 8);
							cout << tensach;
							gotoXY(28 + length, 8); // trỏ lại vị trí cuối

							cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
							length--;
						}
						if(tensach.length() != 0) // xóa kí tự cuối trong chuỗi string 
						{
							tensach.erase(tensach.begin() + (tensach.length() - 1));
						}
					}
					else if(c == 13)
					{
						break;
					}
					else if(c == 27)
					{
						TextColor(7);
						return; // thoát khi nhấn esc
					}
					else 
					{

						if((int)c == -32)
						{
							c = getch();
							if((int)c == 75 || (int)c == 77 || (int)c == 80 || (int)c == 72)
							{
								goto F;
							}

						}
						if(tensach.length() <= 18)
						{
							cout << c;
							length++; // cập nhật vị trí con trỏ chỉ vị
							tensach.push_back(c);
						}
						else
						{
							TextColor(12);
							gotoXY(20, 10);
							cout << "Du lieu toi da " << 18 << " ki tu. Xin kiem tra lai !\n";
							system("pause");
							gotoXY(20, 10);
							cout << "                                                          ";
							gotoXY(0, 11);
							cout << "                                                           ";
							gotoXY(28 + length, 8);
							TextColor(7);
						}

					}

				}

				if(tensach.length() == 0)
				{
					TextColor(12);
					gotoXY(20, 10);
					cout << "Du lieu khong duoc de trong. Xin nhap lai\n";
					system("pause");
					gotoXY(0, 11);
					cout << "                                           ";
					gotoXY(20, 10);
					cout << "                                         ";
					gotoXY(28 + length, 8);
					TextColor(7);

				}

			}while(tensach.length() == 0);

			// vòng lặp kiểm tra sự tồn tại của tên sách mà người dùng cần kiểm tra
			TextColor(7);
			for(int i = 0; i < size; i++)
			{
				if(stricmp(x.LIST[i].Ten_Sach.c_str(), tensach.c_str()) == 0)
				{

					TextColor(15);
					Xuat_Thong_Tin_Sach_1(x.LIST[i], td_y += 2);
					KT = true; // danh sách có tồn tại tên sách
				}
			}


			// nếu như tên sách chưa tồn tại trong danh sách thì xuất ra thông báo đến người dùng
			if(KT == false)
			{
				gotoXY(28, 8);
				TextColor(140);
				cout << "                    ";
				gotoXY(28, 8);
				cout << tensach;
				gotoXY(28 + length, 8); // trỏ lại vị trí cuối

				TextColor(12);
				gotoXY(30, 10);
				cout << "Ten sach chua ton tai trong danh sach";
				gotoXY(0, 11);
				system("pause");
				gotoXY(30, 10);
				cout << "                                       ";
				gotoXY(0, 11);
				cout << "                                       ";
				TextColor(7);

				// trước khi xóa thì in lại nền và chuỗi nhập trước đó trên nền
				gotoXY(28, 8);
				TextColor(140);
				cout << "                    ";
				gotoXY(28, 8);
				cout << tensach;
				gotoXY(28 + length, 8); // trỏ lại vị trí cuối
				TextColor(7);
			}
			else //  tên sách tồn tại
			{

				// trước khi xóa thì in lại nền và chuỗi nhập trước đó trên nền
				gotoXY(28, 8);
				TextColor(140);
				cout << "                    ";
				gotoXY(28, 8);
				cout << tensach;
				gotoXY(28 + length, 8); // trỏ lại vị trí cuối
			}

		}while(KT == false);

		if(KT == true)
		{
			TextColor(7);
			gotoXY(0, td_y + 2);
			system("pause");
			gotoXY(0, td_y + 2);
			cout << "                                            ";
			TextColor(15);
			for(int i = 20; i <= td_y; i += 2)
			{
				gotoXY(0, i);
				cout << "                                                                                    ";
			}
		}

	}
}

// hàm tìm kiếm theo tên tác giả
void Tim_Kiem_Theo_Tac_Gia(LISTSACH x)
{
	string tacgia;
	bool KT = false; // mặc định là danh sách chưa tồn tại tên tác giả
	int i;
	int size = x.size;
	int tdy = 3;
	// vòng lặp kiểm tra xem tên tác giả cần tìm kiếm có tồn tại trong danh sách chưa.
	do
	{
		clrscr();
		fflush(stdin);
		cout << "\nNhap ten tac gia can tim kiem: ";
		getline(cin, tacgia);

		for(i = 0; i < size; i++)
		{
			if(stricmp(x.LIST[i].Tac_Gia.c_str(), tacgia.c_str()) == 0)
			{
				In_Khung(3);
				Xuat_Thong_Tin_Sach_1(x.LIST[i], tdy += 2);
				KT = true; // danh sách có tồn tại tên tác giả
			}
		}
		if(KT == false)
		{

			cout << "\nTen tac gia chua ton tai trong danh sach. Xin kiem tra lai";
			if(Xac_Nhan() == false)
			{
				break;
			}
		}
	}while(KT == false);
}

// Hàm nhập thông tin quyển sách và đưa vào trong danh sách
void Nhap_Danh_Sach_Thong_Tin_Sach(LISTSACH &x)
{

	int luachon;
	do
	{

		clrscr(); // hàm hỗ trợ xóa màn hình
		cout << "\n1. Nhap thong tin sach";
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
				clrscr();

				TextColor(14);
				gotoXY(27, 0);
				cout << "***********************";

				TextColor(14);
				gotoXY(27, 1);
				cout << "*";
				TextColor(14);
				gotoXY(49, 1);
				cout << "*";

				TextColor(11);
				gotoXY(28, 1);
				cout << " NHAP THONG TIN SACH ";

				TextColor(14);
				gotoXY(27, 2);
				cout << "***********************";


				gotoXY(0, 4);
				cout << "********************************************************************************";

				TextColor(15);
				gotoXY(33, 4);
				cout << " HUONG DAN ";


				gotoXY(1, 6);  cout << "Bam ESC de thoat !";
				gotoXY(1, 8);  cout << "Di chuyen qua lai:   " << (char)26 << "    " << (char)27 ;
				gotoXY(1, 10); cout << "Bam ENTER de luu";

				TextColor(14);
				gotoXY(0, 12);
				cout << "********************************************************************************"; 

				TextColor(10);
				In_Khung_1(14);
				TextColor(7);
				bool check_esc = false;
				while(check_esc != true)
				{
					bool KT = false;

					SACH y = Nhap_Thong_Tin_Sach_2(x, 0, 16, KT, check_esc);

					if(KT == true)
					{
						if(x.size == 0)
						{
							x.LIST = new SACH;
						}
						else
						{
							Cap_Phat_Lai_Bo_Nho(x, x.size + 1, x.size);
						}
						x.LIST[x.size++] = y;
					}
				}
			}
			else if(luachon == 2) 
			{
				break;
			}
		}
	}while(luachon != 1 || luachon != 2);

}

// Hàm xuất danh sách các quyển sách
void Xuat_Danh_Sach_Thong_Tin_Sach(LISTSACH x)
{
	int size = x.size;
	int tdy = 4;

	TextColor(14);
	gotoXY(9, 0);
	cout << "***************************************************************";
	gotoXY(9, 1);
	cout << "*";
	gotoXY(71, 1);
	cout << "*";

	TextColor(10);
	gotoXY(11, 1);
	cout << " DANH SACH THONG TIN CAC QUYEN SACH HIEN CO TRONG THU VIEN ";

	TextColor(14);
	gotoXY(9, 2);
	cout << "***************************************************************";

	TextColor(11);
	In_Khung(tdy);

	TextColor(15);
	for(int i = 0; i < size; i++)
	{
		Xuat_Thong_Tin_Sach_1(x.LIST[i], tdy += 2);
	}

	TextColor(7);
}

// Hàm thêm vào 1 vị trí bất kì
void Them_Vi_Tri_Bat_Ki(LISTSACH &x, int vitri, SACH y)
{
	Cap_Phat_Lai_Bo_Nho(x, x.size + 1, x.size); // tăng vùng nhớ đi 1 ô nhớ
	for(int i = x.size - 1; i >= vitri; i--)
	{
		x.LIST[i + 1] = x.LIST[i];
	}
	x.LIST[vitri] = y;
	x.size++; // tăng kích thước vùng nhớ
}

// Hàm cấp phát lại vùng nhớ cho con trỏ
void Cap_Phat_Lai_Bo_Nho(LISTSACH &x, int size_new, int size_old)
{
	SACH *temp = new SACH[size_old];
	for(int i = 0; i < size_old; i++)
	{
		temp[i] = x.LIST[i];
	}
	//delete [] x.LIST;
	x.LIST = new SACH[size_new];
	for(int i = 0; i < size_old; i++)
	{
		x.LIST[i] = temp[i];
	}
	delete[] temp;
}

// Hàm kiểm tra mã sách nhập vào 
bool Kiem_Tra_Ma_Sach(LISTSACH x, string str)
{
	int size = x.size;
	Chuan_Hoa_Khoang_Trang(str); // chuẩn hóa khoảng trắng trước khi kiểm tra
	for(int i = 0; i < size; i++)
	{
		//char *s = (char*)x.LIST[i].Ma_Sach.c_str(); // chuyển từ string sang char*
		//char *s1 = (char*)str.c_str();// chuyển từ string sang char*
		if(stricmp(x.LIST[i].Ma_Sach.c_str(), str.c_str()) == 0) // hàm stricmp so sánh không phân biệt hoa thường
		{
			return true; // trả về true nghĩa là mã sách đó đã tồn tại trong danh sách 
		}
	}
	return false;
}

// Hàm nhập mã sách
string Nhap_Ma_Sach(LISTSACH x)
{
	bool KT;
	string str;
	do
	{

		fflush(stdin);
		cout << "\nNhap ma sach: ";
		getline(cin, str);
		KT = Kiem_Tra_Ma_Sach(x, str);
		if(KT == true)
		{
			cout << "\nMa sach da ton tai. Xin kiem tra lai he thong";
			system("pause");
		}
	}while(KT == true);
	return str;
}




SACH Nhap_Thong_Tin_Sach_2(LISTSACH sach, int x, int y, bool &Kiem_Tra, bool &check)
{
	SACH a;
	//char c ;

	string masach ;
	string tensach;
	int sotrang = 0;
	string so_trang;
	string tacgia;
	int namxuatban = 0;
	string nam_xuat_ban;
	string vitri;

	int VT = 1;
	int masach_max = 8;
	int tensach_max = 18;
	int sotrang_max = 6;
	int tacgia_max = 18;
	int namxuatban_max = 4;
	int vitri_max = 6;

	bool check_enter = false;

	// vòng lặp lặp vô tận cho đến khi người dùng nhập liệu xong tất cả các thuộc tính và lưu lại
	gotoXY(0 + masach.length(), y);
	bool left;
	bool right;
	while(true)
	{
		bool kt = false;
		bool Kiem_Tra_ESC = false;

		if(VT == 1)
		{

			bool KT;
			do
			{

				gotoXY(0 + masach.length(), y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_Du_Lieu_Chuoi_3(masach, masach.length(), x, y, masach_max, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					check = true;
					return a;
				}

				KT = Kiem_Tra_Ma_Sach(sach, masach);

				if(KT == true)
				{
					TextColor(12);
					gotoXY(20, y + 1);
					cout << "Ma sach da ton tai. Xin kiem tra va nhap lai !\n";
					system("pause");
					gotoXY(20, y + 1);
					cout << "                                                   \n";
					cout << "                                                ";
					TextColor(7);
				}

			}while(KT == true );

			if(check_enter == true)
			{
				if(masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 4);
						bool kiem_tra = Xac_Nhan_1(25, y + 4);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Ma_Sach);
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa(a.Vi_Tri);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
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

				VT = 6;
			}
			else if(right == true)
			{

				VT = 2;
			}
			gotoXY(10 + tensach.length(), y);

		}
		else if(VT == 2)
		{

			gotoXY(10 + tensach.length(), y);
			check_enter = false;
			left = false;
			right = false;
			Nhap_Du_Lieu_Chuoi_3(tensach, tensach.length(), x + 10, y, tensach_max, Kiem_Tra_ESC, check_enter, left, right);
			if(Kiem_Tra_ESC == true)
			{
				check = true;
				return a;
			}
			if(check_enter == true)
			{
				if(masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 4);
						bool kiem_tra = Xac_Nhan_1(25, y + 4);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Ma_Sach);
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa(a.Vi_Tri);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
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
			gotoXY(30 + tacgia.length(), y);
		}
		else if(VT == 3)
		{

			gotoXY(30 + tacgia.length(), y);
			check_enter = false;
			left = false;
			right = false;
			Nhap_Ten_2(tacgia, tacgia.length(), x + 30, y, tacgia_max, Kiem_Tra_ESC, check_enter, left, right);
			if(Kiem_Tra_ESC == true)
			{
				check = true;
				return a;
			}
			if(check_enter == true)
			{
				if(masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 4);
						bool kiem_tra = Xac_Nhan_1(25, y + 4);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Ma_Sach);
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa(a.Vi_Tri);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
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

			gotoXY(50 + so_trang.length(), y);
		}
		else if(VT == 4)
		{

			gotoXY(50 + so_trang.length(), y);
			check_enter = false;
			left = false;
			right = false;
			do
			{
				gotoXY(50 + so_trang.length(), y);
				Nhap_So_Nguyen_3(so_trang,sotrang, so_trang.length(), x + 50, y, sotrang_max, Kiem_Tra_ESC, check_enter, left, right);
				if(so_trang[0] == '0')
				{
					TextColor(12);
					gotoXY(25, y + 4);
					cout << "So trang khong duoc bang 0. Xin kiem tra lai";
					getch();
					gotoXY(25, y + 4);
					cout << "                                                 ";
					TextColor(7);
				}
			}while(so_trang[0] == '0');

			if(Kiem_Tra_ESC == true)
			{
				check = true;
				return a;
			}
			if(check_enter == true)
			{
				if(masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 4);
						bool kiem_tra = Xac_Nhan_1(25, y + 4);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Ma_Sach);
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa(a.Vi_Tri);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
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

			gotoXY(60 + nam_xuat_ban.length(), y);
		}
		else if(VT == 5)
		{
			do{

				gotoXY(60 + nam_xuat_ban.length(), y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_So_Nguyen_3(nam_xuat_ban,namxuatban, nam_xuat_ban.length(), x + 60, y, namxuatban_max, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					check = true;
					return a;
				}
				else if(nam_xuat_ban.length() != 0 && nam_xuat_ban.length() != namxuatban_max)
				{
					TextColor(12);
					gotoXY(25, y + 4);
					cout << "Du lieu phai co " << namxuatban_max << " so. Xin kiem tra lai";
					getch();
					gotoXY(25, y + 4);
					cout << "                                                                     ";
					TextColor(7);
				}
				else if(nam_xuat_ban[0] == '0')
				{
					TextColor(12);
					gotoXY(25, y + 4);
					cout << "Nam xuat ban khong hop le. Xin kiem tra lai";
					getch();
					gotoXY(25, y + 4);
					cout << "                                                                  ";
					TextColor(7);
				}

			}while((nam_xuat_ban.length() != 0 && nam_xuat_ban.length() != namxuatban_max) || nam_xuat_ban[0] == '0');

			if(check_enter == true)
			{
				if(masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 4);
						bool kiem_tra = Xac_Nhan_1(25, y + 4);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Ma_Sach);
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa(a.Vi_Tri);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
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
				VT = 6;
			}
			gotoXY(70 + vitri.length(), y);
		}
		else if(VT == 6)
		{
			gotoXY(70 + vitri.length(), y);
			check_enter = false;
			left = false;
			right = false;
			Nhap_Du_Lieu_Chuoi_3(vitri, vitri.length(), x + 70, y, vitri_max, Kiem_Tra_ESC, check_enter, left, right); 
			if(Kiem_Tra_ESC == true)
			{
				check = true;
				return a;
			}
			if(check_enter == true)
			{
				if(masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 4);
						bool kiem_tra = Xac_Nhan_1(25, y + 4);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Ma_Sach);
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa(a.Vi_Tri);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
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
				VT = 1;
			}
			gotoXY(x + masach.length(), y);

		}
	}
}


// Hàm nhập thông tin sách và thêm vào 1 vị trí bất kì trong thư viện
SACH Nhap_Thong_Tin_Sach_3(LISTSACH sach, int x, int y, bool &Kiem_Tra, bool &check, int &vitricanthem)
{
	SACH a;
	char c ;

	// các biến có chức năng lưu thông tin của các thuộc tính SÁCH
	string masach ;
	string tensach;
	int sotrang = 0;
	string so_trang;
	string tacgia;
	int namxuatban = 0;
	string nam_xuat_ban;
	string vitri;
	string vitri_them;


	// các biến lưu độ dài tối đa của biến
	int VT = 1;
	int masach_max = 8;
	int tensach_max = 18;
	int sotrang_max = 6;
	int tacgia_max = 18;
	int namxuatban_max = 4;
	int vitri_max = 6;
	int vitrithem_max = 6;

	bool check_enter = false;

	// vòng lặp lặp vô tận cho đến khi người dùng nhập liệu xong tất cả các thuộc tính và lưu lại
	gotoXY(0 + masach.length(), y);
	bool left;
	bool right;
	bool kiem_tra_vi_tri = false; // biến có tác dụng kiểm tra xem vị trí cần thêm có hợp lệ hay không

	while(true)
	{
		bool kt = false;
		bool Kiem_Tra_ESC = false;

		if(VT == 1)
		{

			bool KT;
			do
			{

				gotoXY(0 + masach.length(), y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_Du_Lieu_Chuoi_3(masach, masach.length(), x, y, masach_max, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					check = true;
					return a;
				}
				KT = Kiem_Tra_Ma_Sach(sach, masach);

				if(KT == true)
				{
					TextColor(12);
					gotoXY(20, y + 6);
					cout << "Ma sach da ton tai. Xin kiem tra va nhap lai !\n";
					system("pause");
					gotoXY(20, y + 6);
					cout << "                                                  ";
					gotoXY(0, y + 7);
					cout << "                                                ";
					TextColor(7);
				}

			}while(KT == true );

			if(check_enter == true)
			{
				if(kiem_tra_vi_tri == true && masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 6);
						bool kiem_tra = Xac_Nhan_1(25, y + 6);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							gotoXY(20 + 16, y + 4);
							cout << "          ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else if(vitri_them.length() == 0 || masach.length() == 0 || tensach.length() == 0 || so_trang.length() == 0 || tacgia.length() == 0 || nam_xuat_ban.length() == 0 || vitri.length() == 0)
				{

					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. DU LIEU CON TRONG\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                      ";
					gotoXY(0, y + 7);
					cout << "                                             ";
					TextColor(7);

				}
				else if(kiem_tra_vi_tri == false)
				{
					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. VI TRI THEM KHONG HOP LE\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                              ";
					gotoXY(0, y + 7);
					cout << "                                              ";
					TextColor(7);
				}
			}
			if(left == true)
			{

				VT = 7;
			}
			else if(right == true)
			{

				VT = 2;
			}

		}
		else if(VT == 2)
		{

			gotoXY(10 + tensach.length(), y);
			check_enter = false;
			left = false;
			right = false;
			Nhap_Du_Lieu_Chuoi_3(tensach, tensach.length(), x + 10, y, tensach_max, Kiem_Tra_ESC, check_enter, left, right);
			if(Kiem_Tra_ESC == true)
			{
				check = true;
				return a;
			}
			if(check_enter == true)
			{
				if(kiem_tra_vi_tri == true && masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 6);
						bool kiem_tra = Xac_Nhan_1(25, y + 6);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							gotoXY(20 + 16, y + 4);
							cout << "          ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else if(vitri_them.length() == 0 || masach.length() == 0 || tensach.length() == 0 || so_trang.length() == 0 || tacgia.length() == 0 || nam_xuat_ban.length() == 0 || vitri.length() == 0)
				{

					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. DU LIEU CON TRONG\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                      ";
					gotoXY(0, y + 7);
					cout << "                                             ";
					TextColor(7);

				}
				else if(kiem_tra_vi_tri == false)
				{
					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. VI TRI THEM KHONG HOP LE\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                              ";
					gotoXY(0, y + 7);
					cout << "                                              ";
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
		}
		else if(VT == 3)
		{

			gotoXY(30 + tacgia.length(), y);
			check_enter = false;
			left = false;
			right = false;
			Nhap_Ten_2(tacgia, tacgia.length(), x + 30, y, tacgia_max, Kiem_Tra_ESC, check_enter, left, right);
			if(Kiem_Tra_ESC == true)
			{
				check = true;
				return a;
			}
			if(check_enter == true)
			{
				if(kiem_tra_vi_tri == true && masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 6);
						bool kiem_tra = Xac_Nhan_1(25, y + 6);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							gotoXY(20 + 16, y + 4);
							cout << "          ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else if(vitri_them.length() == 0 || masach.length() == 0 || tensach.length() == 0 || so_trang.length() == 0 || tacgia.length() == 0 || nam_xuat_ban.length() == 0 || vitri.length() == 0)
				{

					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. DU LIEU CON TRONG\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                      ";
					gotoXY(0, y + 7);
					cout << "                                             ";
					TextColor(7);

				}
				else if(kiem_tra_vi_tri == false)
				{
					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. VI TRI THEM KHONG HOP LE\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                              ";
					gotoXY(0, y + 7);
					cout << "                                              ";
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
		}
		else if(VT == 4)
		{
			gotoXY(50 + so_trang.length(), y);
			check_enter = false;
			left = false;
			right = false;

			do
			{
				gotoXY(50 + so_trang.length(), y);
				Nhap_So_Nguyen_3(so_trang,sotrang, so_trang.length(), x + 50, y, sotrang_max, Kiem_Tra_ESC, check_enter, left, right);
				if(so_trang[0] == '0')
				{
					TextColor(12);
					gotoXY(25, y + 6);
					cout << "So trang sach khong hop le. Xin kiem tra lai\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                                ";
					gotoXY(0, y + 7);
					cout << "                                                ";
					TextColor(7);
				}
			}while(so_trang[0] == '0');
			if(Kiem_Tra_ESC == true)
			{
				check = true;
				return a;
			}
			if(check_enter == true)
			{
				if(kiem_tra_vi_tri == true && masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 6);
						bool kiem_tra = Xac_Nhan_1(25, y + 6);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							gotoXY(20 + 16, y + 4);
							cout << "          ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else if(vitri_them.length() == 0 || masach.length() == 0 || tensach.length() == 0 || so_trang.length() == 0 || tacgia.length() == 0 || nam_xuat_ban.length() == 0 || vitri.length() == 0)
				{

					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. DU LIEU CON TRONG\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                      ";
					gotoXY(0, y + 7);
					cout << "                                             ";
					TextColor(7);

				}
				else if(kiem_tra_vi_tri == false)
				{
					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. VI TRI THEM KHONG HOP LE\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                              ";
					gotoXY(0, y + 7);
					cout << "                                              ";
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
		}
		else if(VT == 5)
		{
			do{
				gotoXY(60 + nam_xuat_ban.length(), y);

				check_enter = false;
				left = false;
				right = false;
				Nhap_So_Nguyen_3(nam_xuat_ban,namxuatban, nam_xuat_ban.length(), x + 60, y, namxuatban_max, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					check = true;
					return a;
				}
				else if(nam_xuat_ban.length() != 0 && nam_xuat_ban.length() != namxuatban_max)
				{
					TextColor(12);
					gotoXY(25, y + 6);
					cout << "Du lieu phai co " << namxuatban_max << " so. Xin kiem tra lai\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                                                  ";
					gotoXY(0, y + 7);
					cout << "                                                 ";
					TextColor(7);
				}
				else if(nam_xuat_ban[0] == '0')
				{
					TextColor(12);
					gotoXY(25, y + 6);
					cout << "Nam xuat ban khong hop le. Xin kiem tra lai\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                                                  ";
					gotoXY(0, y + 7);
					cout << "                                                 ";
					TextColor(7);
				}


			}while((nam_xuat_ban.length() != 0 && nam_xuat_ban.length() != namxuatban_max) || nam_xuat_ban[0] == '0');

			if(check_enter == true)
			{
				if(kiem_tra_vi_tri == true && masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 6);
						bool kiem_tra = Xac_Nhan_1(25, y + 6);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							gotoXY(20 + 16, y + 4);
							cout << "          ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else if(vitri_them.length() == 0 || masach.length() == 0 || tensach.length() == 0 || so_trang.length() == 0 || tacgia.length() == 0 || nam_xuat_ban.length() == 0 || vitri.length() == 0)
				{

					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. DU LIEU CON TRONG\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                      ";
					gotoXY(0, y + 7);
					cout << "                                             ";
					TextColor(7);

				}
				else if(kiem_tra_vi_tri == false)
				{
					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. VI TRI THEM KHONG HOP LE\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                              ";
					gotoXY(0, y + 7);
					cout << "                                              ";
					TextColor(7);
				}
			}
			if(left == true)
			{
				VT = 4;
			}
			else if(right == true)
			{
				VT = 6;
			}
		}
		else if(VT == 6)
		{
			gotoXY(70 + vitri.length(), y);
			check_enter = false;
			left = false;
			right = false;
			Nhap_Du_Lieu_Chuoi_3(vitri, vitri.length(), x + 70, y, vitri_max, Kiem_Tra_ESC, check_enter, left, right); 
			if(Kiem_Tra_ESC == true)
			{
				check = true;
				return a;
			}

			if(check_enter == true)
			{
				if(kiem_tra_vi_tri == true && masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 6);
						bool kiem_tra = Xac_Nhan_1(25, y + 6);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							gotoXY(20 + 16, y + 4);
							cout << "          ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else if(vitri_them.length() == 0 || masach.length() == 0 || tensach.length() == 0 || so_trang.length() == 0 || tacgia.length() == 0 || nam_xuat_ban.length() == 0 || vitri.length() == 0)
				{

					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. DU LIEU CON TRONG\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                      ";
					gotoXY(0, y + 7);
					cout << "                                             ";
					TextColor(7);

				}
				else if(kiem_tra_vi_tri == false)
				{
					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. VI TRI THEM KHONG HOP LE\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                              ";
					gotoXY(0, y + 7);
					cout << "                                              ";
					TextColor(7);
				}
			}
			if(left == true)
			{
				VT = 5;
			}
			else if(right == true)
			{
				VT = 7;
			}

		}
		else if(VT == 7)
		{

			gotoXY(20 + 16 + vitri_them.length(), y + 4);
			check_enter = false;
			left = false;
			right = false;

			Nhap_So_Nguyen_3(vitri_them, vitricanthem, vitri_them.length(), 16 + 20, y + 4, vitrithem_max, Kiem_Tra_ESC, check_enter, left, right);
			if(Kiem_Tra_ESC == true)
			{
				check = true;
				return a;
			}

			if(vitri_them.length() != 0)
			{
				if(vitricanthem < 0 || vitricanthem >= sach.size)
				{
					kiem_tra_vi_tri = false;
					gotoXY(5, y + 6);
					TextColor(12);
					cout << "Vi tri can them khong hop le." << "(0 =< vitri va vitri < " << sach.size << ") . Xin kiem tra lai\n";
					system("pause");
					gotoXY(5, y + 6);
					cout << "                                                                                                            ";
					gotoXY(0, y + 7);
					cout << "                                                                     ";
					TextColor(7);
				}
				else
				{
					kiem_tra_vi_tri = true;
				}
			}

			if(check_enter == true)
			{
				if(kiem_tra_vi_tri == true && masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
				{
					while(true)
					{
						gotoXY(30, y + 6);
						bool kiem_tra = Xac_Nhan_1(25, y + 6);
						if(kiem_tra == true)
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Trang_Thai = '0';
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);
							Kiem_Tra = true;
							gotoXY(0, y);
							cout << "                                                                                   ";
							gotoXY(20 + 16, y + 4);
							cout << "          ";
							return a;
						}
						else
						{
							break;
						}
					}

				}
				else if(vitri_them.length() == 0 || masach.length() == 0 || tensach.length() == 0 || so_trang.length() == 0 || tacgia.length() == 0 || nam_xuat_ban.length() == 0 || vitri.length() == 0)
				{

					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. DU LIEU CON TRONG\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                      ";
					gotoXY(0, y + 7);
					cout << "                                             ";
					TextColor(7);

				}
				else if(kiem_tra_vi_tri == false)
				{
					TextColor(12);
					gotoXY(25, y + 6);
					cout << "KHONG THE LUU. VI TRI THEM KHONG HOP LE\n";
					system("pause");
					gotoXY(25, y + 6);
					cout << "                                              ";
					gotoXY(0, y + 7);
					cout << "                                              ";
					TextColor(7);
				}
			}
			if(left == true)
			{
				VT = 6;
			}
			else if(right == true)
			{
				VT = 1;
			}

		}
	}
}

// hàm có chức năng cập nhật 1 quyển sách mới vào thư viện
void Cap_Nhat_Sach(LISTSACH &x)
{
	clrscr();

	TextColor(14);
	gotoXY(27, 0);
	cout << "***********************";

	TextColor(14);
	gotoXY(27, 1);
	cout << "*";
	TextColor(14);
	gotoXY(49, 1);
	cout << "*";

	TextColor(11);
	gotoXY(28, 1);
	cout << " NHAP THONG TIN SACH ";

	TextColor(14);
	gotoXY(27, 2);
	cout << "***********************";


	gotoXY(0, 4);
	cout << "********************************************************************************";

	TextColor(15);
	gotoXY(33, 4);
	cout << " HUONG DAN ";


	gotoXY(1, 6);  cout << "Bam ESC de thoat !";
	gotoXY(1, 8);  cout << "Di chuyen qua lai:   " << (char)26 << "    " << (char)27 ;
	gotoXY(1, 10); cout << "Bam ENTER de luu";

	TextColor(14);
	gotoXY(0, 12);
	cout << "********************************************************************************"; 

	TextColor(10);
	In_Khung_1(14);
	TextColor(7);
	bool check_esc = false;
	while(check_esc != true)
	{
		bool KT = false;

		SACH y = Nhap_Thong_Tin_Sach_2(x, 0, 16, KT, check_esc);

		if(KT == true)
		{
			if(x.size == 0)
			{
				x.LIST = new SACH;
			}
			else
			{
				Cap_Phat_Lai_Bo_Nho(x, x.size + 1, x.size);
			}
			x.LIST[x.size++] = y;
		}
	}
}

// hàm thêm 1 quyển sách vào vị trí bất kì trong thư viện
void Them_Vao_Vi_Tri_Bat_Ki(LISTSACH &x)
{
	clrscr();
	SACH y;

	TextColor(14);
	gotoXY(27, 0);
	cout << "***********************";

	TextColor(14);
	gotoXY(27, 1);
	cout << "*";
	TextColor(14);
	gotoXY(49, 1);
	cout << "*";

	TextColor(11);
	gotoXY(28, 1);
	cout << " NHAP THONG TIN SACH ";

	TextColor(14);
	gotoXY(27, 2);
	cout << "***********************";


	gotoXY(0, 4);
	cout << "********************************************************************************";

	TextColor(15);
	gotoXY(33, 4);
	cout << " HUONG DAN ";


	gotoXY(1, 6);   cout << "Bam ESC de thoat !";
	gotoXY(1, 8);   cout << "Di chuyen qua lai:   " << (char)26 << "    " << (char)27 ;
	gotoXY(1, 10);  cout << "Bam ENTER de luu";

	TextColor(14);
	gotoXY(0, 12);
	cout << "********************************************************************************"; 



	// hàm in khung thêm thông tin sách vào vị trí bất kì
	TextColor(10);
	In_Khung_Them_Vi_Tri_Bat_Ki(14);
	TextColor(7);

	int vitri;
	bool kt_esc;
	bool kt_enter;
	bool KT ;
	bool check_esc;

	while(true)
	{

		KT = false;
		check_esc = false;
		y = Nhap_Thong_Tin_Sach_3(x, 0, 16, KT, check_esc, vitri);
		if(check_esc == true)
		{
			break;
		}
		else if(KT == true)
		{
			Them_Vi_Tri_Bat_Ki(x, vitri, y);
		}
	}
}
