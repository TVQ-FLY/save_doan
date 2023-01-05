#include"XuLi.h"

void Xuat(Tree t, int &tdy)
{
	if(t != NULL)
	{
		Xuat(t->pLeft, tdy);

		Xuat_Thong_Tin_Doc_Gia(t->data);
		Xuat_Danh_Sach_Phieu_Muon_Tra(t ->data.l, tdy += 7);


		Xuat(t->pRight, tdy);
	}
}

void Nhap(Tree &t, int ma)
{
	if(t != NULL)
	{
		if(t->data.Ma_Doc_Gia == ma)
		{
			Nhap_Danh_Sach_Phieu_Muon_Tra(t ->data.l);
			return;
		}
		Nhap(t->pLeft, ma);
		Nhap(t->pRight, ma);
	}
}

// hàm có chức năng mượn sách 
void Muon_Sach(LIST &l, Tree &t, LISTSACH &sach)
{
	// xóa màn hình console
	clrscr();

	// các biến làm nhiệm vụ lưu thông tin khi nhập từ bàn phím
	string masach;
	int masach_max = 10;
	string ma;
	int maso = 0;
	int maso_max = 6;
	int VT = 1;
	char c;
	bool KT_ma;
	bool KT_sach;

	// in khung mượn sách
	In_Khung_Muon_Sach(4);
	int x = 5;
	int y = 15;
	int tdy = 25;
	TextColor(10);
	gotoXY(0, 15);  cout << "Ma doc gia muon sach:";
	gotoXY(35, 15); cout << "Ma sach can muon:";

	// in thông tin độc giả
	TextColor(13);
	gotoXY(25, tdy); cout << "***** THONG TIN DOC GIA *****";
	TextColor(11);
	In_Khung_Xuat(tdy + 2);
	TextColor(7);

	// in danh sách các quyển sách hiện có trong thư viện
	int size = sach.size;
	TextColor(14);
	gotoXY(9, tdy + 7);  cout << "***************************************************************";
	gotoXY(9, tdy + 8);  cout << "*";
	gotoXY(71, tdy + 8); cout << "*";
	TextColor(10);
	gotoXY(11, tdy + 8); cout << " DANH SACH THONG TIN CAC QUYEN SACH HIEN CO TRONG THU VIEN ";
	TextColor(14);
	gotoXY(9, tdy + 9l); cout << "***************************************************************";

	// vòng lặp có tác dụng in ra danh sách các quyển sách đang có trong thư viện
	TextColor(11);
	In_Khung(tdy + 11);
	int td_y = tdy + 11;
	TextColor(15);
	for(int i = 0; i < size; i++)
	{
		Xuat_Thong_Tin_Sach_1(sach.LIST[i], td_y += 2);
	}
	TextColor(7);

	// các biến kiểm tra 
	bool check_enter = false; // biến có tác dụng nhận phím enter từ bàn phím 
	bool left = false; // biến có tác dụng nhận phím điều khiển trái 
	bool right = false; // biến có tác dụng nhận phím điều khiển phải
	bool Kiem_Tra; // biến có tác dụng kiểm tra nếu bấm ESC thoát
	bool KT_Ma_Sach_Ton_Tai ; // biến kiểm tra mã sách xem có tồn tại trong thư viện chưa
	bool KT_Trang_Thai_Sach; // biến kiểm tra xem mã sách này có thề cho mượn được hay không

	gotoXY(21 + ma.length(), y);

	// vòng lặp lặp vô tận cho đến khi người dùng nhấn phím esc
	while(true)
	{
		// vòng lặp lặp cho đến khi nào nhấn enter kiểm tra lưu thông tin
		while(true)
		{

			// nếu chọn = 1 thì vô ô nhập mã độc giả nhập liệu
			if(VT == 1)
			{
				bool Kiem_Tra_Doc_Gia;
				bool Kiem_Tra_Dieu_Kien;
				int soluong = 0;
				// vòng lặp có tác dụng nhập liệu cho mã độc giả mượn sách
				do
				{
					check_enter = false;
					left = false;
					right = false;
					gotoXY(21 + ma.length(), y);
					Nhap_So_Nguyen_3(ma, maso, ma.length(), 21, y, maso_max, Kiem_Tra, check_enter, left, right);

					// nếu nhấn esc thì thoát
					if(Kiem_Tra == true)
					{
						return;
					}
					else if(check_enter == true)
					{

						break;
					}
					if(ma.length() != 0)
					{

						// hàm kiểm tra mã độc giả có tồn tại trong thư viện chưa. Kiem_Tra_Doc_Gia == true ==> có tồn tại
						Kiem_Tra_Ma_Doc_Gia(t, maso, Kiem_Tra_Doc_Gia);

						// nếu mã độc giả tồn tại trong thư viện 
						if(Kiem_Tra_Doc_Gia == true)
						{
							// hàm xuất thông tin độc giả đang mượn sách
							gotoXY(0, 29); cout << "                                                                              ";
							TextColor(15);
							Xuat_Thong_Tin_Doc_Gia_Theo_Ma(t, maso, tdy + 4);
							TextColor(7);
							// hàm kiểm tra trạng thái độc giả. Kiem_Tra_Dieu_Kien == true ==> trạng thái độc giả có thể mượn sách
							Kiem_Tra_Trang_Thai_Doc_Gia(t, maso, Kiem_Tra_Dieu_Kien);
							// hàm trả về số lượng sách quá hạn mượn
							int soluong = So_Luong_Sach_Qua_Han_Muon(t, l, sach, maso);
							if(soluong >= 3)
							{
								TextColor(12);
								gotoXY(0, y + 2);
								cout << "Doc gia bi tuoc quyen muon sach(tra sach qua han 3 lan). Xin kiem tra lai";
								getch();
								gotoXY(0, y + 2);
								cout << "                                                                                       ";
								TextColor(7);
							}
							else if(Kiem_Tra_Dieu_Kien == false)
							{
								TextColor(12);
								gotoXY(0, y + 2);
								cout << "Doc gia bi khoa chuc nang muon sach(so sach muon >= 3). Xin kiem tra lai";
								getch();
								gotoXY(0, y + 2);
								cout << "                                                                                       ";
								TextColor(7);
							}
						}
						else
						{
							TextColor(12);
							gotoXY(20, y + 2);
							cout << "Ma doc gia chua ton tai. Xin kiem tra lai the doc gia";
							getch();
							gotoXY(20, y + 2);
							cout << "                                                          ";
							TextColor(7);
						}

					}

				}while(ma.length() == 0 || Kiem_Tra_Doc_Gia == false || soluong >= 3 || Kiem_Tra_Dieu_Kien == false);



				if(left == true || right == true)
				{
					VT = 2;
				}
				// nhấn phím enter <==> muốn lưu lại thông tin mượn sách
				if(check_enter == true)
				{
					break;
				}
				gotoXY(17 + 35 + masach.length(), y);

			}
			else if(VT == 2) 
			{

				do{

					check_enter = false;
					left = false;
					right = false;
					gotoXY(17 + 35 + masach.length(), y);
					Nhap_Du_Lieu_Chuoi_3(masach, masach.length(), 17 + 35, y, masach_max, Kiem_Tra, check_enter, left, right);
					if(Kiem_Tra == true)
					{
						return;
					}

					if(masach.length() > 10)
					{
						TextColor(12);
						gotoXY(20, y + 1);
						cout << "Ma sach toi da 10 ki tu. Xin kiem tra va nhap lai !";
						getch();
						gotoXY(20, y + 1);
						cout << "                                                       ";
						TextColor(7);
					}

					if(masach.length() != 0)
					{
						KT_Ma_Sach_Ton_Tai = false; // biến kiểm tra mã sách xem có tồn tại trong thư viện chưa
						KT_Trang_Thai_Sach = false; // biến kiểm tra xem mã sách này có thề cho mượn được hay không
						KT_Ma_Sach_Ton_Tai = Kiem_Tra_Ma_Sach(sach, masach); // kiểm tra xem mã sách đang nhập có tồn tại trong thư viện chưa. Trả về true : tồn tại
						KT_Trang_Thai_Sach = Kiem_Tra_Dieu_Kien_Sach(sach, masach); // kiểm tra xem quyển sách đang nhập có thể cho mượn được hay không. Trả về true: cho mượn được

						if(KT_Ma_Sach_Ton_Tai == false)
						{
							TextColor(12);
							gotoXY(20, y + 2);
							cout << "Ma sach chua ton tai. Xin kiem tra lai ";
							getch();
							gotoXY(20, y + 2);
							cout << "                                                 ";
							TextColor(7);
						}

						if(KT_Trang_Thai_Sach == false)
						{
							TextColor(12);
							gotoXY(20, y + 2);
							cout << "Sach khong the muon. Da co doc gia muon. Xin kiem tra lai ";
							getch();
							gotoXY(20, y + 2);
							cout << "                                                                ";
							TextColor(7);
						}

					}


				}while(masach.length() > 10);
				if(left == true || right == true)
				{
					VT = 1;
				}
				// nhấn phím enter <==> muốn lưu lại thông tin mượn sách
				if(check_enter == true)
				{
					break;
				}
				gotoXY(21 + ma.length(), y);
			}
		}

		// nhấn phím enter <==> muốn lưu lại thông tin mượn sách
		if(check_enter == true)
		{
			if(ma.length() != 0 &&  masach.length() != 0 && KT_Ma_Sach_Ton_Tai == true && KT_Trang_Thai_Sach == true)
			{
				gotoXY(30, y + 4);
				while(true)
				{
					gotoXY(30, y + 4);
					bool kiem_tra = Xac_Nhan_2(25, y + 4);

					// nếu lựa chọn lưu thông tin
					if(kiem_tra == true)
					{
						// lưu mã sách vừa mượn vào danh sách mượn trả
						Tim_Doc_Gia_Muon(t, sach, maso, masach); // hàm thêm 1 quyển sách vừa mượn vào danh sách mượn trả của độc giả tương ứng
						Cap_Nhat_Trang_Thai_Doc_Gia_Muon_Sach(t, l, sach, maso); // hàm cập nhật trạng thái mượn sách của độc giả , sau khi mượn 1 quyển sách
						//Cap_Nhat_Trang_Thai_Muon_Sach(sach, masach);
						// xuất ra thông báo cho người dùng xem
						TextColor(15);
						gotoXY(20, y + 2);
						cout << "Luu thanh cong !";
						getch();
						gotoXY(20, y + 2);
						cout << "                    ";

						// xóa ô nhập mã sách và đưa con trỏ về lại ô nhập mã độc giả  <=> bị lỗi độc giả mượn xong quyển đó thì độc giả có thể mượn được
						gotoXY(17 + 35, y);
						cout << "          ";
						gotoXY(0, 29); cout << "                                                                              ";
						masach.resize(0);
						VT = 1;
						break;
					}
					else
					{
						break; // không lưu thoát ra vòng lặp xác nhận
					}

				}
			}
			else if(ma.length() == 0 ||  masach.length() == 0)
			{
				TextColor(12);
				gotoXY(25, y + 4);
				cout << "KHONG THE LUU. DU LIEU CON TRONG\n";
				system("pause");
				gotoXY(25, y + 4);
				cout << "                                   ";
				cout << "                                                    ";
				TextColor(7);
			}
		}

		// vòng lặp có tác dụng in ra danh sách các quyển sách đang có trong thư viện
		TextColor(11);
		In_Khung(tdy + 11);
		int td_y = tdy + 11;
		TextColor(15);
		for(int i = 0; i < size; i++)
		{
			Xuat_Thong_Tin_Sach_1(sach.LIST[i], td_y += 2);
		}
		TextColor(7);
	}
}

// hàm có chức năng trả sách theo mã sách
void Tra_Sach(LIST &l, Tree &t, LISTSACH &sach)
{
	// xóa màn hình console
	clrscr();

	string masach;
	int masach_max = 10;
	string ma;

	int maso = 0;
	int maso_max = 6;
	int VT = 1;
	char c;
	bool KT_ma;
	bool KT_sach;

	DATE date;
	string ngaytra;
	int ngaytra_max = 8;

	// in khung mượn sách
	In_Khung_Tra_Sach(4);
	int x = 5;
	int y = 15;
	int tdy = 25;
	TextColor(10);
	gotoXY(0, 15);   cout << "Nhap ma doc gia:";
	gotoXY(27, 15);  cout << "Nhap ma sach:";
	gotoXY(57, 15);  cout << "Nhap ngay tra:";


	// in thông tin độc giả
	TextColor(13);
	gotoXY(25, tdy);   cout << "***** THONG TIN DOC GIA *****";
	TextColor(11);
	In_Khung_Xuat(tdy + 2);
	TextColor(7);


	// in danh sách các quyển sách hiện có trong thư viện
	int size = sach.size;
	TextColor(14);
	gotoXY(9, tdy + 7);   cout << "***************************************************************";
	gotoXY(9, tdy + 8);
	cout << "*";
	gotoXY(71, tdy + 8);
	cout << "*";

	TextColor(10);
	gotoXY(11, tdy + 8);   cout << " DANH SACH THONG TIN CAC QUYEN SACH HIEN CO TRONG THU VIEN ";

	TextColor(14);
	gotoXY(9, tdy + 9);   cout << "***************************************************************";



	// vòng lặp có tác dụng in ra danh sách các quyển sách đang có trong thư viện
	int td_y = tdy + 11;
	TextColor(11);
	In_Khung(tdy + 11);
	TextColor(15);
	for(int i = 0; i < size; i++)
	{
		Xuat_Thong_Tin_Sach_1(sach.LIST[i], td_y += 2);
	}
	TextColor(7);

	TextColor(10);
	gotoXY(16, td_y += 2) ; cout << "*** DANH SACH QUYEN SACH DA VA DANG MUON ***"; // 44
	TextColor(11);
	In_Khung_Phieu_Muon_Tra(td_y += 2);
	int Y = td_y + 2;
	TextColor(7);


	// các biến kiểm tra 
	bool check_ma = false;
	bool check_sach = false;
	bool check_ngay; // kiểm tra xem ngày tháng năm nhập vào có hợp lệ không
	bool check_enter = false;
	bool left ;
	bool right ;
	bool KT;
	bool check_datra; // true là mã sách đã trả
	bool check_tontai; // true là mã sách chưa trả và có tồn tại

	gotoXY(21 + ma.length(), y);

	// vòng lặp có tác dụng lặp vô tận cho đến khi nhấn phím esc
	while(true)
	{
		// vòng lặp lặp vô tận cho đến khi người dùng nhấn phím enter
		while(true)
		{
			bool Kiem_Tra; // biến có tác dụng kiểm tra nếu bấm ESC thoát

			// nếu chọn = 1 thì vô ô nhập mã độc giả nhập liệu
			if(VT == 1)
			{
				bool KT;
				// vòng lặp có tác dụng nhập liệu cho mã độc giả mượn sách
				do
				{
					check_enter = false;
					left = false;
					right = false;
					gotoXY(16 + ma.length(), y);
					Nhap_So_Nguyen_3(ma, maso, ma.length(), 16, y, maso_max, Kiem_Tra, check_enter, left, right);
					check_ma = true;

					// kiểm tra nếu nhấn phím esc ==> thoát
					if(Kiem_Tra == true)
					{
						return;
					}
					else if(check_enter == true)
					{
						break;
					}
					if(ma.length() != 0)
					{
						// kiểm tra xem mã độc giả có tồn tại trong thư viện chưa
						Kiem_Tra_Ma_Doc_Gia(t, maso, KT);
						if(KT == false)
						{
							TextColor(12);
							gotoXY(20, y + 2);
							cout << "Ma doc gia chua ton tai. Xin kiem tra lai the doc gia";
							getch();
							gotoXY(20, y + 2);
							cout << "                                                          ";
							TextColor(7);
						}
						else
						{
							// hàm xuất thông tin độc giả đang mượn sách
							TextColor(15);
							Xuat_Thong_Tin_Doc_Gia_Theo_Ma(t, maso, tdy + 4);
							Liet_Ke_Sach_1(l, t, maso, Y); // liệt kê các quyển sách mà độc giả đó đã và đang mượn
							TextColor(7);
						}

					}
				}while(ma.length() == 0 || KT == false);

				if(left == true)
				{
					VT = 3;
				}
				else if(right == true)
				{
					VT = 2;
				}
				if(check_enter == true)
				{
					break;
				}

			}
			else if(VT == 2)
			{

				do{

					check_enter = false;
					left = false;
					right = false;
					gotoXY(13 + 27 + masach.length(), y);
					Nhap_Du_Lieu_Chuoi_3(masach, masach.length(), 13 + 27, y, masach_max, Kiem_Tra, check_enter, left, right);
					check_sach = true;
					if(Kiem_Tra == true)
					{
						return;
					}
					// hàm có tác dụng kiểm tra xem mã sách hiện tại muốn trả có tồn tại trong danh sách hay là có tồn tại mà đã trả rồi


					if(masach.length() != 0)
					{
						check_datra = false; // true là mã sách có tồn tại trong danh sách mượn trả và đã được trả
						check_tontai = false; // true là mã sách có tồn tại trong danh sách mượn trả
						KT = Kiem_Tra_Ma_Sach(sach, masach); 
						if(KT == false)
						{
							TextColor(12);
							gotoXY(20, y + 2);
							cout << "Ma sach khong ton tai trong thu vien. Xin kiem tra lai";
							getch();
							gotoXY(20, y + 2);
							cout << "                                                              ";
							TextColor(7);
						}

						Kiem_Tra_Ma_Sach_Danh_Sach_Muon_Tra_Doc_Gia(t, l, masach, maso, check_tontai, check_datra);
						if(check_datra == true)
						{
							TextColor(12);
							gotoXY(10, y + 2);
							cout << "Ma sach da duoc tra cho thu vien. Xin kiem tra lai ";
							getch();
							gotoXY(10, y + 2);
							cout << "                                                            ";
							TextColor(7);
						}
						else if(check_tontai == false)
						{
							TextColor(12);
							gotoXY(10, y + 2);
							cout << "Ma sach khong ton tai trong danh sach muon. Xin kiem tra lai";
							getch();
							gotoXY(10, y + 2);
							cout << "                                                                 ";
							TextColor(7);
						}
					}
					if(masach.length() > 10)
					{
						TextColor(12);
						gotoXY(20, y + 1);
						cout << "Ma sach toi da 10 ki tu. Xin kiem tra va nhap lai !";
						getch();
						gotoXY(20, y + 1);
						cout << "                                                      ";
						TextColor(7);
					}

				}while(masach.length() > 10);

				if(left == true)
				{
					VT = 1;
				}
				else if(right == true)
				{
					VT = 3;
				}
				if(check_enter == true)
				{
					break;
				}
			}

			else if(VT == 3)
			{
				gotoXY(57 + 14 + ngaytra.length(), y);

				check_enter = false; // kiểm tra nhấn phím enter <=> muốn lưu thông tin
				left = false;
				right = false;
				Nhap_Ngay_Tra_Sach(date, ngaytra, ngaytra.length(), 57 + 14, y, ngaytra_max, check_ngay, check_enter, Kiem_Tra, left, right);

				if(Kiem_Tra == true)
				{
					return;
				}

				if(left == true)
				{
					VT = 2;
				}
				else if(right == true)
				{
					VT = 1;
				}
				if(check_enter == true)
				{
					break;
				}
			}
		}

		// nhấn enter <==> muốn lưu thông tin mượn sách
		if(check_enter == true)
		{
			// kiểm tra các thuộc tính
			if(check_ngay == false)
			{
				TextColor(12);
				gotoXY(10, y + 2);
				cout << "Ngay tra sach khong hop le. Xin kiem tra lai !";
				getch();
				gotoXY(10, y + 2);
				cout << "                                                 ";
				TextColor(7);
			}
			else if(check_datra == true)
			{
				TextColor(12);
				gotoXY(10, y + 2);
				cout << "Ma sach da duoc tra cho thu vien. Xin kiem tra lai !";
				getch();
				gotoXY(10, y + 2);
				cout << "                                                         ";
				TextColor(7);
			}
			else if(check_tontai == false)
			{
				TextColor(12);
				gotoXY(10, y + 2);
				cout << "Ma sach khong ton tai trong danh sach muon. Xin kiem tra lai";
				getch();
				gotoXY(10, y + 2);
				cout << "                                                               ";
				TextColor(7);
			}
			else if(KT == false)
			{

				TextColor(12);
				gotoXY(10, y + 2);
				cout << "Ma sach khong ton tai trong thu vien. Xin kiem tra lai";
				getch();
				gotoXY(10, y + 2);
				cout << "                                                               ";
				TextColor(7);
			}
			else if(ma.length() == 0 || masach.length() == 0 || ngaytra.length() != ngaytra_max)
			{
				TextColor(12);
				gotoXY(25, y + 4);
				cout << "KHONG THE LUU. DU LIEU CON TRONG";
				getch();
				gotoXY(25, y + 4);
				cout << "                                   ";
				TextColor(7);
			}
			else if(ma.length() != 0 && masach.length() != 0 && ngaytra.length() == ngaytra_max && check_ngay == true && check_datra == false && check_tontai == true)
			{
				gotoXY(30, y + 4);
				while(true)
				{
					gotoXY(30, y + 4);
					bool kiem_tra = Xac_Nhan_2(25, y + 4);

					// nếu lựa chọn lưu thông tin
					if(kiem_tra == true)
					{

						TextColor(15);
						gotoXY(10, y + 2);
						cout << "Luu thanh cong !";
						getch();
						gotoXY(10, y + 2);
						cout << "                                                ";
						TextColor(7);

						// cập nhật lại thuộc tính của sách và độc giả
						Cap_Nhat_Trang_Thai_Tra_Sach(sach, masach); // cập nhật lại trạng thái sách bằng 0 sau khi trả sách thành công
						Cap_Nhat_Ngay_Trang_Thai_Tra_Sach(t ,l ,sach, date, masach, maso); // cập nhật lại trạng thái sách đã mượn bằng 1 <=> đã trả và cập nhật ngày trả sách
						Cap_Nhat_Trang_Thai_Doc_Gia_Muon_Sach(t, l, sach, maso); // hàm cập nhật trạng thái mượn sách của độc giả , sau khi mượn 1 quyển sách
						// hàm in lại thông tin độc giả nếu như trạng thái thay đổi <=> trả sách quá hạn 15 ngày
						bool KIEMTRA = true; // biến có tác dụng kiểm tra trạng thái độc giả
						Kiem_Tra_Trang_Thai_Doc_Gia(t, maso, KIEMTRA);
						if(KIEMTRA == false)
						{
							// hàm xuất thông tin độc giả đang mượn sách
							TextColor(15);
							Xuat_Thong_Tin_Doc_Gia_Theo_Ma(t, maso, tdy + 4);
							TextColor(7);
						}


						// hàm có tác dụng xuất ra ghi chú nếu như độc giả mượn sách vi phạm qui định thư viện
						int soluong = So_Luong_Sach_Qua_Han_Muon(t, l, sach, maso);
						if(Kiem_Tra_Sach_Muon_Qua_Han(t, l, maso, masach) == true)
						{
							TextColor(12);
							gotoXY(0, y + 2);
							cout << "Thoi gian tra sach qua han( > 15 ngay ).Hinh thuc phat 1.000 VND/quyen/ngay";
							getch();
							gotoXY(0, y + 2);
							cout << "                                                                                 ";
							TextColor(7);
						}

						if(soluong != 0)
						{
							TextColor(12);
							gotoXY(0, y + 2);
							cout << "Tra sach qua han " << soluong << " lan";
							gotoXY(0, y + 3);
							cout << "Tra sach qua han 3 lan tro len se bi tuoc quyen doc gia(khong cho muon sach)";
							getch();
							gotoXY(0, y + 2);
							cout << "                                                                                 ";
							gotoXY(0, y + 3);
							cout << "                                                                                  ";
							TextColor(7);
						}
						// xóa ô nhập mã sách và đưa con trỏ về lại ô nhập mã độc giả  <=> bị lỗi độc giả mượn xong quyển đó thì độc giả có thể mượn được
						gotoXY(27 + 13, y);
						cout << "           ";
						masach.resize(0);
						gotoXY(57 + 14, y);
						cout << "        ";
						ngaytra.resize(0);
						VT = 1;
						break;
					}
					else
					{
						break;
					}

				}
			}

		}

		// vòng lặp có tác dụng in ra cập nhật danh sách các quyển sách đang có trong thư viện
		int td_y = tdy + 11;
		TextColor(11);
		In_Khung(tdy + 11);
		TextColor(15);
		for(int i = 0; i < size; i++)
		{
			Xuat_Thong_Tin_Sach_1(sach.LIST[i], td_y += 2);
		}
		// in ra cập nhật danh sách mượn trả
		TextColor(10);
		gotoXY(16, td_y += 2) ; cout << "*** DANH SACH QUYEN SACH DA VA DANG MUON ***"; // 44
		TextColor(11);
		In_Khung_Phieu_Muon_Tra(td_y += 2);
		Y =  td_y + 2;
		TextColor(15);
		Liet_Ke_Sach_1(l, t, maso, Y); // liệt kê các quyển sách mà độc giả đã và đang mượn
		TextColor(7);
	}

}


// hàm có tác dụng in khung mượn sách
void In_Khung_Muon_Sach(int dty)
{
	TextColor(14);
	gotoXY(28, 0);
	cout << "********************";
	gotoXY(29, 1);
	TextColor(10);
	cout << "   MUC MUON SACH ";
	TextColor(14);
	gotoXY(28, 1);
	cout << "*";
	gotoXY(47, 1);
	cout << "*";
	gotoXY(28, 2);
	TextColor(14);
	cout << "********************";

	TextColor(14);
	gotoXY(0, 4);
	cout << "* * * * * * * * ";
	TextColor(15);
	gotoXY(16, 4); cout << "  HUONG DAN  ";
	TextColor(14);
	gotoXY(29, 4);
	cout << " * * * * * * * * ";

	gotoXY(44, 6); cout << "*";
	gotoXY(44, 8); cout << "*";
	gotoXY(44, 10); cout << "*";

	TextColor(15);
	gotoXY(3, 6); cout << "Bam ESC de thoat ! "; 
	gotoXY(3, 8); cout << "Di chuyen qua lai:   " << (char)26 << "    " << (char)27 ;
	gotoXY(3, 10); cout << "Bam ENTER de luu";
	TextColor(14);
	gotoXY(0, 12); cout << "* * * * * * * * * * * * * * * * * * * * * * *";
	TextColor(7);
}

// hàm in khung liệt kê
void In_Khung_Liet_Ke(int tdy)
{

	TextColor(14);
	gotoXY(28, 0);
	cout << "***********************";
	gotoXY(29, 1);
	TextColor(10);
	cout << "   MUC LIET KE SACH   ";
	TextColor(14);
	gotoXY(28, 1);
	cout << "*";
	gotoXY(50, 1);
	cout << "*";
	gotoXY(28, 2);
	TextColor(14);
	cout << "***********************";

	TextColor(14);
	gotoXY(0, 4);
	cout << "* * * * * * * * ";
	TextColor(15);
	gotoXY(16, 4); cout << "  HUONG DAN  ";
	TextColor(14);
	gotoXY(29, 4);
	cout << " * * * * * * * * ";

	gotoXY(44, 6); cout << "*";
	gotoXY(44, 8); cout << "*";
	gotoXY(44, 10); cout << "*";

	TextColor(15);
	gotoXY(3, 6); cout << "Bam ESC de thoat ! "; 
	gotoXY(3, 8); cout << "Di chuyen qua lai:   " << (char)26 << "    " << (char)27 ;
	gotoXY(3, 10); cout << "Bam ENTER de xem  ";
	TextColor(14);
	gotoXY(0, 12); cout << "* * * * * * * * * * * * * * * * * * * * * * *";
	TextColor(7);
}


// hàm in giao diện trả sách
void In_Khung_Tra_Sach(int tdy)
{
	TextColor(14);
	gotoXY(28, 0);
	cout << "********************";
	gotoXY(29, 1);
	TextColor(10);
	cout << "   MUC TRA SACH ";
	TextColor(14);
	gotoXY(28, 1);
	cout << "*";
	gotoXY(47, 1);
	cout << "*";
	gotoXY(28, 2);
	TextColor(14);
	cout << "********************";

	TextColor(14);
	gotoXY(0, 4);
	cout << "* * * * * * * * ";
	TextColor(15);
	gotoXY(16, 4); cout << "  HUONG DAN  ";
	TextColor(14);
	gotoXY(29, 4);
	cout << " * * * * * * * * ";

	gotoXY(44, 6); cout << "*";
	gotoXY(44, 8); cout << "*";
	gotoXY(44, 10); cout << "*";

	TextColor(15);
	gotoXY(3, 6); cout << "Bam ESC de thoat ! "; 
	gotoXY(3, 8); cout << "Di chuyen qua lai:   " << (char)26 << "    " << (char)27 ;
	gotoXY(3, 10); cout << "Bam ENTER de luu";
	TextColor(14);
	gotoXY(0, 12); cout << "* * * * * * * * * * * * * * * * * * * * * * *";
	TextColor(7);
}

// Menu xử lí
void Menu_Xu_Li(Tree &t, LIST &l, LISTSACH &sach)
{
	int luachon;
	do{
		clrscr();
		cout << "\n\n\t\t ---------------------- Menu ----------------------";
		cout << "\n1. Danh muc sach";
		cout << "\n2. Danh muc doc gia";
		cout << "\n3. Muon sach";
		cout << "\n4. Tra sach";
		cout << "\n5. Liet ke";
		cout << "\n6. Xuat";
		cout << "\n7. Ngay qua han";
		cout << "\n8. Xoa doc gia";
		cout << "\n9. Sua doc gia";
		cout << "\n10. Xoa sach";
		cout << "\n11. Sua sach";
		cout << "\n12. Top sach";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ---------------------- End -----------------------";

		cout << "\nNhap lua chon: ";
		luachon = Nhap_So_Nguyen();

		if(luachon < 0 || luachon > 12)
		{
			cout << "\nLua chon khong hop le. Xin nhap lai";
			system("pause");
		}
		else
		{
			if(luachon == 0)
			{
				break;
			}
			else if(luachon == 1)
			{
				Menu_Xu_Li(sach); // danh mục sách
			}
			else if(luachon == 2)
			{
				Menu_Xu_Li(t); // danh mục độc giả
			}
			else if(luachon == 3)
			{
				Muon_Sach(l, t, sach);
			}
			else if(luachon == 4)
			{
				Tra_Sach(l, t, sach);
			}
			else if(luachon == 5)
			{
				Tim_Kiem_Thong_Tin_Doc_Gia(l, t, sach);
			}
			else if(luachon == 6)
			{
				clrscr();
				int tdy = 0;
				Xuat(t, tdy);
				system("pause");
			}
			else if(luachon == 7)
			{
				clrscr();
				Danh_Sach_Doc_Gia_Qua_Han_Giam_Dan(t, l);
				system("pause");
			}
			else if(luachon == 8)
			{
				clrscr();
				Xoa_Doc_Gia(t);
			}
			else if(luachon == 9)
			{
				clrscr();
				Sua_Doc_Gia(t);
				/*DOCGIA x;
				bool kt;
				Lay_Thong_Tin_Doc_Gia(t, x, kt, 2);
				Xuat_Thong_Tin_Doc_Gia(x);
				int tdy = 0;
				Xuat_Danh_Sach_Phieu_Muon_Tra(x.l, tdy);*/
				cout << endl << endl;
				system("pause");
			}
			else if(luachon == 10)
			{
				clrscr();
				Xoa_Sach(sach);
				cout << endl;
				system("pause");
			}
			else if(luachon == 11)
			{
				clrscr();
				Sua_Thong_Tin_Sach(sach, t);
				cout << endl;
				system("pause");
			}
			else if(luachon == 12)
			{
				clrscr();
				ofstream FileOut;
				Top_10_Sach_Muon_Nhieu_Nhat(FileOut, t, sach, 3);
				system("pause");
			}
		}
	}while((luachon < 0 || luachon > 12) || luachon != 0);
}

// hàm có tác dụng thông báo người dùng
bool Xac_Nhan_2(int x, int y)
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
					cout << "                                        ";
					gotoXY(x + 5, y + 2);
					cout << "          ";
					gotoXY(x + 10, y + 2);
					cout << "           ";
					TextColor(7);
					return KT;
				}
			}
		}
	}
}


// hàm có tác dụng thông báo người dùng
bool Xac_Nhan_3(int x, int y)
{
	char c ;

	TextColor(15);
	gotoXY(x, y);
	cout << "Ban co muon tiep tuc khong ?";
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


void Nhap_Ngay_Tra_Sach(DATE &ngaytra, string &str, int cd, int x, int y, int cd_max, bool &Kiem_Tra, bool &check_enter, bool &check_esc, bool &left, bool &right)
{
	char c;
	int length = cd;
	do{

		// vòng lặp lặp vô tận cho đến khi ta nhấn các phím điều khiển <=> kết thúc việc nhập
		while(true)
		{
			c = getch(); // nhập kí tự đầu tiên
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
			else if((int)c == 27)
			{
				check_esc = true;
				return;
			}
			else if((int)c == 13)
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
						cout << "Du lieu phai co 8 so. Xin kiem tra lai\n";
						system("pause");
						gotoXY(20, y + 2);
						cout << "                                           ";
						gotoXY(0, y + 3);
						cout << "                                             ";
						TextColor(7);
						gotoXY(x + length, y);
					}
					else if(str.length() == 8)
					{
						int ngay, thang, nam;
						Tach_Ngay_Thang_Nam(str, ngay, thang, nam);

						ngaytra.Ngay_Hien_Tai = ngay;
						ngaytra.Thang_Hien_Tai = thang;
						ngaytra.Nam_Hien_Tai = nam;

						bool a = true;
						bool b = true;
						bool c = true; 
						// hàm có tác dụng kiểm tra ngày tháng năm của ngày trả nhập vào 
						Kiem_Tra = Kiem_Tra_Tinh_Hop_Le(ngaytra, a, b, c);

						if(Kiem_Tra == false)
						{
							if(a == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Ngay tra khong hop le\n";
								system("pause");
								gotoXY(20, y + 2);
								cout << "                         ";
								gotoXY(0, y + 3);
								cout << "                                                  ";
								TextColor(7);

							}
							if(b == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Thang tra khong hop le\n";
								system("pause");
								gotoXY(20, y + 2);
								cout << "                             ";
								gotoXY(0, y + 3);
								cout << "                                                  ";
								TextColor(7);
							}

							if(c == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Nam tra khong hop le\n";
								system("pause");
								gotoXY(20, y + 2);
								cout << "                          ";
								gotoXY(0, y + 3);
								cout << "                                                  ";
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
						cout << "Du lieu phai co 8 so. Xin kiem tra lai\n";
						system("pause");
						gotoXY(20, y + 2);
						cout << "                                           ";
						gotoXY(0, y + 3);
						cout << "                                             ";
						TextColor(7);
						gotoXY(x + length, y);
					}
					else if(str.length() == 8)
					{
						int ngay, thang, nam;
						Tach_Ngay_Thang_Nam(str, ngay, thang, nam);

						ngaytra.Ngay_Hien_Tai = ngay;
						ngaytra.Thang_Hien_Tai = thang;
						ngaytra.Nam_Hien_Tai = nam;

						bool a = true;
						bool b = true;
						bool c = true; 
						// hàm có tác dụng kiểm tra ngày tháng năm của ngày trả nhập vào 
						Kiem_Tra = Kiem_Tra_Tinh_Hop_Le(ngaytra, a, b, c);

						if(Kiem_Tra == false)
						{
							if(a == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Ngay tra khong hop le\n";
								system("pause");
								gotoXY(20, y + 2);
								cout << "                         ";
								gotoXY(0, y + 3);
								cout << "                                                  ";
								TextColor(7);

							}
							if(b == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Thang tra khong hop le\n";
								system("pause");
								gotoXY(20, y + 2);
								cout << "                             ";
								gotoXY(0, y + 3);
								cout << "                                                  ";
								TextColor(7);
							}

							if(c == false)
							{
								TextColor(12);
								gotoXY(20, y + 2);
								cout << "Nam tra khong hop le\n";
								system("pause");
								gotoXY(20, y + 2);
								cout << "                          ";
								gotoXY(0, y + 3);
								cout << "                                                  ";
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
			cout << "Du lieu phai co 8 so. Xin kiem tra lai\n";
			system("pause");
			gotoXY(20, y + 2);
			cout << "                                           ";
			gotoXY(0, y + 3);
			cout << "                                             ";
			TextColor(7);
			gotoXY(x + length, y);
		}
		else if(str.length() == 8)
		{
			int ngay, thang, nam;
			Tach_Ngay_Thang_Nam(str, ngay, thang, nam);

			ngaytra.Ngay_Hien_Tai = ngay;
			ngaytra.Thang_Hien_Tai = thang;
			ngaytra.Nam_Hien_Tai = nam;

			bool a = true;
			bool b = true;
			bool c = true; 
			// hàm có tác dụng kiểm tra ngày tháng năm của ngày trả nhập vào 
			Kiem_Tra = Kiem_Tra_Tinh_Hop_Le(ngaytra, a, b, c);

			if(Kiem_Tra == false)
			{
				if(a == false)
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Ngay tra khong hop le\n";
					system("pause");
					gotoXY(20, y + 2);
					cout << "                         ";
					gotoXY(0, y + 3);
					cout << "                                                  ";
					TextColor(7);

				}
				if(b == false)
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Thang tra khong hop le\n";
					system("pause");
					gotoXY(20, y + 2);
					cout << "                             ";
					gotoXY(0, y + 3);
					cout << "                                                  ";
					TextColor(7);
				}

				if(c == false)
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Nam tra khong hop le\n";
					system("pause");
					gotoXY(20, y + 2);
					cout << "                          ";
					gotoXY(0, y + 3);
					cout << "                                                  ";
					TextColor(7);
				}
			}
		}

	}while(str.length() < 8);

}



void Liet_Ke_Sach_Doc_Gia_Dang_Muon(LIST l, Tree t, LISTSACH sach)
{
	// xóa màn hình
	clrscr();

	// các biến lưu dữ liệu nhập từ bàn phím
	string ma;
	int maso = 0;
	int maso_max = 6;
	int VT = 1;
	char c;


	// in khung liệt kê
	In_Khung_Liet_Ke(12);

	// in danh sách các độc giả hiện có trong thư viện
	TextColor(14);
	gotoXY(9, 14);
	cout << "**************************************************************";
	gotoXY(9, 15);
	cout << "*";
	gotoXY(70, 15);
	cout << "*";

	TextColor(10);
	gotoXY(11, 15);
	cout << "  DANH SACH THONG TIN CAC DOC GIA HIEN CO TRONG THU VIEN  ";

	TextColor(14);
	gotoXY(9, 16);
	cout << "**************************************************************";

	int tdy = 18;
	// vòng lặp có tác dụng in ra danh sách các độc giả hiện có trong thư viện
	TextColor(11);
	In_Khung_Xuat(18);
	TextColor(15);
	Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(t, tdy);
	TextColor(7);


	int x = 5;
	int y = tdy;
	TextColor(13);
	gotoXY(0, y + 2);  cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";

	TextColor(10);
	gotoXY(0, y + 5);  cout << "Nhap ma doc gia:";


	// in thông tin độc giả
	TextColor(13);
	gotoXY(25, y + 10); cout << "***** THONG TIN DOC GIA *****";
	TextColor(11);
	In_Khung_Xuat(y + 12);
	TextColor(7);

	// in giao diện các quyển sách đang mượn của 1 độc giả
	TextColor(14);
	gotoXY(9, y + 16);  cout << "**************************************************************";
	gotoXY(9, y + 17);  cout << "*";
	gotoXY(70, y + 17); cout << "*";

	TextColor(10);
	gotoXY(11, y + 17);  cout << "      DANH SACH CAC QUYEN SACH CUA DOC GIA DANG MUON   ";

	TextColor(14);
	gotoXY(9, y + 18);  cout << "**************************************************************";

	// in khung phiếu mượn
	TextColor(11);
	In_Khung_Phieu_Muon_Tra(y + 20);
	TextColor(7);
	gotoXY(16 + ma.length(), y + 5);
	bool check_ma = false;
	bool check_enter = false;

	// vòng lặp lặp vô tận cho đến khi người dùng nhập liệu xong tất cả các thuộc tính và lưu lại
	while(true)
	{
		bool Kiem_Tra; // biến có tác dụng kiểm tra nếu bấm ESC thoát
		bool KT;
		// vòng lặp có tác dụng nhập liệu cho mã độc giả mượn sách
		do
		{
			check_enter = false;
			gotoXY(16 + ma.length(), y + 5);
			Nhap_So_Nguyen_2(ma, maso, ma.length(), 16, y + 5, maso_max, Kiem_Tra, check_enter);

			// hàm xuất thông tin độc giả đang mượn sách
			TextColor(15);
			Xuat_Thong_Tin_Doc_Gia_Theo_Ma(t, maso, y + 14);
			TextColor(7);

			// nếu nhấn esc thì thoát
			if(Kiem_Tra == true)
			{
				return;
			}

			// hàm kiểm tra mã độc giả có tồn tại trong thư viện chưa
			Kiem_Tra_Ma_Doc_Gia(t, maso, KT);  
			if(KT == false)
			{
				TextColor(12);
				gotoXY(20, y + 7);
				cout << "Ma doc gia chua ton tai. Xin kiem tra lai the doc gia\n";
				system("pause");
				gotoXY(20, y + 7);
				cout << "                                                          ";
				gotoXY(0, y + 8);
				cout << "                                                          ";
				TextColor(7);
			}

		}while(KT == false);


		// nhấn phím enter <==> muốn xem thông tin mượn sách
		if(check_enter == true)
		{
			if(ma.length() != 0)
			{
				int td_y = y + 22;
				Liet_Ke_Sach(l, t, maso, td_y);
				break;

			}
			else 
			{
				TextColor(12);
				gotoXY(25, y + 8);
				cout << "Chua nhap ma doc gia. Xin kiem tra lai\n";
				system("pause");
				gotoXY(25, y + 8);
				cout << "                                              ";
				gotoXY(0, y + 9);
				cout << "                                           ";
				TextColor(7);
			}
		}

	}
	system("pause");
}

// hàm có tác dụng liệt kê các quyển sách đang mượn của 1 độc giả với mã độc giả bất kì tồn tại trong thư viện
void Liet_Ke_Sach(LIST l, Tree t, int madocgia, int &tdy)
{
	if(t == NULL)
	{
		return;
	}
	if(t->data.Ma_Doc_Gia < madocgia)
	{
		Liet_Ke_Sach(l, t->pRight, madocgia, tdy);
	}
	else if(t->data.Ma_Doc_Gia > madocgia)
	{
		Liet_Ke_Sach(l, t->pLeft, madocgia, tdy);
	}
	else
	{
		for(NODE *k = t->data.l.pHead; k != NULL; k =  k->pNext)
		{
			// chỉ xuất những quyển sách đang mượn
			if(k->data.Trang_Thai == '0')
			{
				Xuat_Thong_Tin_Phieu_Muon_Tra_1(k->data, tdy += 2);
			}
		}
		return; // sau khi xuất danh sách mượn trả của 1 độc giả thì dừng ngay
	}
}

// hàm có tác dụng liệt kê các quyển sách đã và đang mượn của 1 độc giả với mã độc giả bất kì tồn tại trong thư viện
void Liet_Ke_Sach_1(LIST l, Tree t, int madocgia, int &tdy)
{
	if(t == NULL)
	{
		return;
	}
	if(t->data.Ma_Doc_Gia < madocgia)
	{
		Liet_Ke_Sach_1(l, t->pRight, madocgia, tdy);
	}
	else if(t->data.Ma_Doc_Gia > madocgia)
	{
		Liet_Ke_Sach_1(l, t->pLeft, madocgia, tdy);
	}
	else
	{
		for(NODE *k = t->data.l.pHead; k != NULL; k =  k->pNext)
		{
			Xuat_Thong_Tin_Phieu_Muon_Tra_1(k->data, tdy += 2);
		}
		return; // sau khi xuất danh sách mượn trả của 1 độc giả thì dừng ngay
	}
}

void Danh_Sach_Doc_Gia_Qua_Han_Giam_Dan_File(Tree t, LIST l)
{

	ofstream FileOut;
	FileOut.open("DOC_GIA_QUA_HAN_GIAM_DAN.TXT", ios::out);
	int dem = 0;
	So_Luong_Doc_Gia(t, dem);


	DOCGIA *temp = new DOCGIA[dem]; // khai báo mảng tuyến tính chứa các độc giả mượn sách quá hạn 
	int *songay; // khai báo ra mảng tuyến tính chứa số ngày mượn quá hạn tương ứng của từng độc giả
	int size = 0; // biến số lượng độc giả mượn sách quá hạn

	// hàm có tác dụng lấy thông tin những độc giả mượn sách quá hạn bỏ qua mảng tuyến tính temp 
	Doc_Gia_Muon_Sach_Qua_Han(t, temp, songay, size, l); 
	// hàm sắp xếp theo số ngày mượn quá hạn giảm dần
	Sap_Xep(temp, songay, size);

	FileOut << "\t\t\t ****** DANH SACH DOC GIA MUON SACH QUA HAN THEO THOI GIAN GIAM DAN ******";
	// vòng lặp có tác dụng in danh sách độc giả mượn sách quá hạn giảm dần theo số ngày quá hạn mượn
	for(int i = 0; i < size; i++)
	{
		FileOut << "\n\n\t\t*  THONG TIN DOC GIA THU " << i + 1 << "  *";
		In_Thong_Tin_File(FileOut, temp[i]);
		FileOut << "\n\t\t * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	}

	// xóa vùng nhớ tự tạo
	delete[] songay;
	delete[] temp;

	// đóng file
	FileOut.close(); 
	//Xuat_Danh_Sach_Doc_Gia(b);
}

// hàm in danh sách độc giả mượn sách quá hạn giảm dần theo thời gian mượn 
void Danh_Sach_Doc_Gia_Qua_Han_Giam_Dan(Tree t, LIST l)
{
	int dem = 0;
	So_Luong_Doc_Gia(t, dem);
	DOCGIA *temp = new DOCGIA[dem]; // khai báo mảng tuyến tính chứa các độc giả mượn sách quá hạn 
	//temp = NULL;
	int *songay; // khai báo ra mảng tuyến tính chứa số ngày mượn quá hạn tương ứng của từng độc giả
	//songay = NULL;
	int size = 0; // biến số lượng độc giả mượn sách quá hạn

	// hàm có tác dụng lấy thông tin những độc giả mượn sách quá hạn bỏ qua mảng tuyến tính temp 
	Doc_Gia_Muon_Sach_Qua_Han(t, temp, songay, size, l); 

	// hàm sắp xếp theo số ngày mượn quá hạn giảm dần
	Sap_Xep(temp, songay, size);


	// in giao diện
	TextColor(14);
	gotoXY(5, 0); cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	TextColor(10);
	gotoXY(5, 1); cout << "    DANH SACH DOC GIA MUON SACH QUA HAN THEO THOI GIAN GIAM DAN    ";
	TextColor(14);
	gotoXY(5, 1); cout << "*";
	gotoXY(71, 1); cout << "*";
	gotoXY(5, 2); cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

	// vòng lặp có tác dụng xuất tất cả các độc giả mượn sách quá hạn theo thứ tự giảm dần số ngày quá hạn
	int tdy = 2;
	for(int i = 0; i < size; i++)
	{
		In_Thong_Tin(temp[i], songay[i], tdy += 3);
		TextColor(14);
		gotoXY(20, tdy += 3); cout << "*                   *                   *";
	}
	TextColor(7);


	//// xóa vùng nhớ tự tạo
	//if(songay != NULL)
	//{
	//	delete[] songay;
	//}
	//if(temp != NULL)
	//{
	//	delete[] temp;
	//}
	getch();
}

// hàm tính tổng ngày quá hạn trả sách của  danh sách mượn sách của độc giả 
int Tong_Ngay_Qua_Han(LIST l)
{
	int Tong = 0;
	// duyệt vòng lặp những quyển sách của 1 độc giả đang mượn
	for(NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		if(k->data.Trang_Thai == '1') // quyển sách đó đã trả mới có ngày trả 
		{
			// lấy ngày trả trừ đi ngày mượn nếu như kết quả lớn hơn 15 ngày(số ngày tối đa cho mượn sách) thì số ngày quá hạn sẽ là : kết quả - 15
			int x = So_Ngay_Qua_Han(k->data.Ngay_Muon, k->data.Ngay_Tra);
			if(x > 15)
			{
				Tong +=  (x - 15); // tổng số ngày mượn quá hạn
			}
		}
	}
	return Tong;
}

void Xuat_Ngay_Qua_Han(Tree t)
{
	if(t != NULL)
	{
		Xuat_Ngay_Qua_Han(t->pLeft);


		Xuat_Thong_Tin_Doc_Gia(t->data);
		cout << "\nTong ngay quan han: " << Tong_Ngay_Qua_Han(t->data.l) << endl << endl;

		Xuat_Ngay_Qua_Han(t->pRight);
	}
}


void Xuat_Danh_Sach_Doc_Gia(Tree t)
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

// hàm có tác dụng lấy những độc giả có thời gian mượn sách quá hạn bỏ qua mảng tuyến tính temp
void Doc_Gia_Muon_Sach_Qua_Han(Tree t, DOCGIA *&temp, int *&songay, int &size, LIST l)
{
	if(t != NULL)
	{
		Doc_Gia_Muon_Sach_Qua_Han(t->pLeft, temp, songay, size, l);

		// nếu tổng ngày mượn sách quá hạn của 1 độc giả khác 0 <=> độc giả đang xét mượn sách quá hạn cho phép(15 ngày)
		int x = Tong_Ngay_Qua_Han(t->data.l);
		if(x != 0)
		{
			if(size ==  0)
			{
				songay = new int;

			}
			else
			{
				Cap_Phat_Lai_Bo_Nho_1(songay, size, size + 1);
			}
			songay[size] = x; // mảng chứa tổng số ngày mượn quá hạn
			temp[size] = t->data; // mảng chứa các độc giả mượn sách quá hạn
			size++;
		}
		Doc_Gia_Muon_Sach_Qua_Han(t->pRight, temp, songay, size, l);
	}
}


// hàm cấp phát lại vùng nhớ cho con trỏ
void Cap_Phat_Lai_Bo_Nho_1(int *&songay, int size_old, int size_new)
{
	int *TEMP = new int[size_old];
	for(int i = 0; i < size_old; i++)
	{
		TEMP[i] = songay[i];
	}
	songay = new int[size_new];
	for(int i = 0; i < size_new; i++)
	{
		songay[i] = TEMP[i];
	}
	delete [] TEMP;
}


// hàm hoán vị vị trí của 2 đối tượng trong mảng tuyến tính
template<class T>
void Hoan_Vi(T &x, T &y)
{
	T temp  = x;
	x = y;
	y = temp;
}

// hàm sắp xếp giảm dần theo số ngày mượn sách quá hạn
void Sap_Xep(DOCGIA *&docgia, int *&songay, int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			if(songay[i] < songay[j])
			{
				Hoan_Vi<int >(songay[i], songay[j]);
				Hoan_Vi<DOCGIA>(docgia[i], docgia[j]);
			}
		}
	}
}


// hàm có tác dụng in ra thông tin của 1 độc giả ra file
void In_Thong_Tin_File(ofstream &file, DOCGIA x)
{
	Xuat_Thong_Tin_Doc_Gia_File(file, x);
	file << "\n\n";
	file << "\t\t * DANH SACH CAC QUYEN SACH DA VA DANG MUON *";
	Xuat_Danh_Sach_Phieu_Muon_Tra_File(file, x.l);
}

// hàm có tác dụng in thông tin độc giả mượn sách quá hạn
void In_Thong_Tin(DOCGIA x, int songay, int &tdy)
{
	// in giao diện thông tin độc giả
	TextColor(13);
	gotoXY(25, tdy += 3); cout << "***** THONG TIN DOC GIA *****";


	TextColor(10);
	In_Khung_Xuat(tdy += 2);

	// xuất thông tin độc giả trên giao diện đó
	TextColor(15);
	Xuat_Thong_Tin_Doc_Gia_1(x, tdy += 2);

	// xuất số ngày mượn quá hạn
	TextColor(13);
	gotoXY(25, tdy += 3); cout << "* SO NGAY MUON SACH QUA HAN *";
	TextColor(15);
	gotoXY(40, tdy += 1); cout << songay;

	// xuất danh sách quyển sách độc giả đã và đang mượn
	TextColor(13);
	gotoXY(20, tdy += 3); cout << "***** DANH SACH SACH DA VA DANG MUON *****";

	TextColor(10);
	In_Khung_Phieu_Muon_Tra(tdy += 2);

	// vòng lặp xuất các quyển sách
	TextColor(15);
	for(NODE *k = x.l.pHead; k != NULL; k = k->pNext)
	{
		Xuat_Thong_Tin_Phieu_Muon_Tra_1(k->data, tdy += 2);
	}
	TextColor(7);
}


// hàm có tác dụng cập nhật lại trạng thái và ngày trả quyển sách trong danh sách mượn trả của 1 độc giả sau khi đem trả <=> trạng thái = 1
void Cap_Nhat_Ngay_Trang_Thai_Tra_Sach(Tree &t, LIST &l, LISTSACH &sach, DATE x, string masach, int madocgia)
{
	if(t->data.Ma_Doc_Gia < madocgia)
	{
		Cap_Nhat_Ngay_Trang_Thai_Tra_Sach(t->pRight, l, sach, x, masach, madocgia);
	}
	else if(t->data.Ma_Doc_Gia > madocgia)
	{
		Cap_Nhat_Ngay_Trang_Thai_Tra_Sach(t->pLeft, l, sach, x, masach, madocgia);
	}
	else
	{
		// vòng lặp có tác dụng cập nhật lại trạng thái quyển sách đã mượn ==> trạng thái = 1 <=> đã trả. Và cập nhật ngày trả sách
		for(NODE *k = t->data.l.pHead; k != NULL; k = k->pNext)
		{
			if(k->data.Trang_Thai == '0' && stricmp(k->data.Ma_Sach.c_str(), masach.c_str()) == 0)
			{
				k->data.Trang_Thai = '1'; // trạng thái đã trả cho thư viện 
				k->data.Ngay_Tra.Ngay_Hien_Tai = x.Ngay_Hien_Tai;
				k->data.Ngay_Tra.Thang_Hien_Tai = x.Thang_Hien_Tai;
				k->data.Ngay_Tra.Nam_Hien_Tai = x.Nam_Hien_Tai;
			}
		}
	}
}

// hàm có tác dụng cập nhật lại trạng thái của quyển sách khi được độc giả đem đi trả
void Cap_Nhat_Trang_Thai_Tra_Sach(LISTSACH &sach, string masach)
{
	int size = sach.size;
	for(int i = 0; i < size; i++)
	{
		if(sach.LIST[i].Trang_Thai == '1' && stricmp(sach.LIST[i].Ma_Sach.c_str(), masach.c_str()) == 0)
		{
			sach.LIST[i].Trang_Thai = '0'; // trạng thái = 0 <=> cho mượn được
			break;
		}
	}
}

// hàm có tác dụng cập nhật lại trạng thái của quyển sách khi được độc giả mượn
void Cap_Nhat_Trang_Thai_Muon_Sach(LISTSACH &sach, string masach)
{
	int size = sach.size;
	for(int i = 0; i < size; i++)
	{
		if(stricmp(sach.LIST[i].Ma_Sach.c_str(), masach.c_str()) == 0)
		{
			sach.LIST[i].Trang_Thai = '1'; // trạng thái = 1 <=> không cho mượn được
			break;
		}
	}
}

// hàm kiểm tra xem quyển sách của độc giả đem trả có tồn tài trong danh sách mượn trả không , và kiểm tra xem quyển sách đó đã trả chưa
void Kiem_Tra_Ma_Sach_Danh_Sach_Muon_Tra_Doc_Gia(Tree t, LIST l, string masach, int madocgia, bool &check_tontai, bool &check_datra)
{
	if(t->data.Ma_Doc_Gia < madocgia)
	{
		Kiem_Tra_Ma_Sach_Danh_Sach_Muon_Tra_Doc_Gia(t->pRight, l, masach, madocgia, check_tontai, check_datra);
	}
	else if(t->data.Ma_Doc_Gia > madocgia)
	{
		Kiem_Tra_Ma_Sach_Danh_Sach_Muon_Tra_Doc_Gia(t->pLeft, l, masach, madocgia, check_tontai, check_datra);
	}
	else
	{
		for(NODE *k = t->data.l.pHead; k != NULL; k = k->pNext)
		{
			if(stricmp(k->data.Ma_Sach.c_str(), masach.c_str()) == 0 && k->data.Trang_Thai == '0')
			{
				check_tontai = true; // mã sách có tồn tại trong danh sách mượn trả của độc giả tương ứng
				check_datra = false; // mã sách chưa dược trả cho thư viện
			}
			else if(stricmp(k->data.Ma_Sach.c_str(), masach.c_str()) == 0 && k->data.Trang_Thai == '1')
			{
				check_tontai = false; // mã sách có tồn tại trong danh sách mượn trả của độc giả tương ứng  
				check_datra = true; // mã sách này đã được trả cho thư viện
			}
		}

	}
}


// hàm có tác dụng thêm 1 quyển sách vào danh sách mượn trả 
void Muon_Sach_1(LIST &l, LISTSACH &sach, string masach)
{
	//vòng lặp có tác dụng cập nhật lại trạng thái cho sách được mượn
	int n = sach.size;
	for(int i = 0; i < n; i++)
	{
		if(stricmp(sach.LIST[i].Ma_Sach.c_str(), masach.c_str()) == 0)
		{
			sach.LIST[i].Trang_Thai = '1'; // mã sách này đã được mượn
			break;
		}
	}
	PHIEUMUONTRA x;
	Chuan_Hoa_In_Hoa(masach);
	x.Ma_Sach = masach;
	Nhap_Thong_Tin_Phieu_Muon(x);
	NODE *p = GetNode(x);
	AddTail(l, p);
}

// hàm có tác dụng tìm kiếm độc giả cần mượn sách sau đó thêm quyển sách đó vào danh sách mượn trả của 1 độc giả
void Tim_Doc_Gia_Muon(Tree &t, LISTSACH &sach, int madocgia, string masach)
{
	if(t != NULL)
	{
		Tim_Doc_Gia_Muon(t->pLeft, sach, madocgia, masach);
		if(t->data.Ma_Doc_Gia == madocgia)
		{
			Muon_Sach_1(t->data.l, sach, masach);
			return;
		}
		Tim_Doc_Gia_Muon(t->pRight, sach, madocgia, masach);
	}
}

// trả về số sách mà 1 độc giả đang mượn
int Kiem_Tra_Doc_Gia(Tree t, LIST l, int madocgia)
{
	if(t->data.Ma_Doc_Gia > madocgia)
	{
		Kiem_Tra_Doc_Gia(t->pLeft, l, madocgia);
	}
	else if(t->data.Ma_Doc_Gia < madocgia)
	{
		Kiem_Tra_Doc_Gia(t->pRight, l, madocgia);
	}
	else
	{
		int soluong = 0;
		for(NODE *k = t->data.l.pHead; k != NULL; k = k->pNext)
		{

			// chỉ đếm những quyển sách mà đang mượn <==> trangthai == '0'  trong danh sách, còn những quyển đã trả thì bỏ qua.
			if(k->data.Trang_Thai == '0')
			{
				soluong++;
			}
		}
		return soluong;
	}

}

// hàm có tác dụng kiểm tra xem trong danh sách các sách đang mượn có quyển sách nào mà ngày trả quá hạn 15 ngày không. Nếu có trả về false. Ngược lại trả về true
int So_Luong_Sach_Qua_Han_Muon(Tree t, LIST l, LISTSACH sach, int madocgia)
{
	if(t == NULL)
	{
		return 0;
	}
	else if(t->data.Ma_Doc_Gia > madocgia)
	{
		So_Luong_Sach_Qua_Han_Muon(t->pLeft, l, sach, madocgia);
	}
	else if(t->data.Ma_Doc_Gia < madocgia)
	{
		So_Luong_Sach_Qua_Han_Muon(t->pRight, l, sach, madocgia);
	}
	else if(t->data.Ma_Doc_Gia == madocgia)
	{
		int soluong = 0;
		for(NODE *k = t->data.l.pHead; k != NULL; k = k->pNext)
		{
			// nếu như ngày trả sách không trống
			if(k->data.Trang_Thai == '1')
			{

				if(So_Ngay_Qua_Han(k->data.Ngay_Muon, k->data.Ngay_Tra) > 15 )
				{
					soluong++;
				}
			}
		}
		return soluong;
	}
}

// hàm có tác dụng cập nhật lại trạng thái của độc giả
void Cap_Nhat_Trang_Thai_Doc_Gia_Muon_Sach(Tree &t, LIST l, LISTSACH sach, int madocgia)
{
	if(t->data.Ma_Doc_Gia < madocgia)
	{
		Cap_Nhat_Trang_Thai_Doc_Gia_Muon_Sach(t->pRight, l, sach, madocgia);
	}
	else if(t->data.Ma_Doc_Gia > madocgia)
	{
		Cap_Nhat_Trang_Thai_Doc_Gia_Muon_Sach(t->pLeft, l, sach, madocgia);
	}
	else
	{
		// nếu như mà độc giả thỏa mãn điều kiện là số sách đang mượn không lớn hơn 3 
		int soluong = So_Luong_Sach_Qua_Han_Muon(t, l, sach, madocgia);
		if(Kiem_Tra_Doc_Gia(t, l, madocgia) < 3 && soluong < 3)
		{
			t->data.Trang_Thai = true; // cập nhật lại trạng thái độc giả có thể mượn sách , nếu như số sách mượn không lớn hơn 3
			return; // cho mượn được
		}
		else
		{
			t->data.Trang_Thai = false; // cập nhật lại trạng thái độc giả không được mượn sách nữa, vì vi phạm quy định thư viện
			return; // không cho mượn được 
		}
	}
}

// hàm có tác dụng kiểm tra 1 quyển sách xem có đủ điều kiện cho mượn không <=> trạng thái bằng 0
bool Kiem_Tra_Dieu_Kien_Sach(LISTSACH sach, string str)
{
	int size = sach.size;
	for(int i = 0; i < size; i++)
	{
		if(stricmp(sach.LIST[i].Ma_Sach.c_str(), str.c_str()) == 0)
		{
			if(sach.LIST[i].Trang_Thai == '0')
			{
				return true;
			}
			else
			{
				return false;
			}

		}
	}
}

// hàm kiểm tra trạng thái độc giả. Trạng thái = true ==> trả về true. Ngược lại trả về false
void Kiem_Tra_Trang_Thai_Doc_Gia(Tree t, int madocgia, bool &check)
{
	if(t == NULL)
	{
		return;
	}
	if(t->data.Ma_Doc_Gia < madocgia)
	{
		Kiem_Tra_Trang_Thai_Doc_Gia(t->pRight, madocgia, check);
	}
	else if(t->data.Ma_Doc_Gia > madocgia)
	{
		Kiem_Tra_Trang_Thai_Doc_Gia(t->pLeft, madocgia, check);
	}
	else
	{
		if(t->data.Trang_Thai == true)
		{
			check = true;
			return; // trạng thái có thể mượn sách
		}
		else
		{
			check = false;
			return; // trạng thái không cho mượn sách
		}
	}
}

// hàm trả về số ngày quá hạn. Tính số ngày chênh lệch giữa 2 mốc thời gian
int So_Ngay_Qua_Han(DATE x, DATE y)
{
	int Tong_Ngay = 0;

	// tính số ngày theo độ chênh lệch giữa 2 năm
	while(x.Nam_Hien_Tai < y.Nam_Hien_Tai)
	{
		if(Kiem_Tra_Nam_Nhuan(y.Nam_Hien_Tai) ==  true)// là năm nhuận
		{
			Tong_Ngay += 366;
		}
		else
		{
			Tong_Ngay += 365;
		}
		y.Nam_Hien_Tai--;

	}

	// tính số ngày theo độ chênh lệch giữa 2 tháng
	while(x.Thang_Hien_Tai < y.Thang_Hien_Tai)
	{
		if(x.Thang_Hien_Tai == 4 || x.Thang_Hien_Tai == 6 || x.Thang_Hien_Tai == 9 || x.Thang_Hien_Tai == 11)
		{
			Tong_Ngay += 30;
		}
		else if(x.Thang_Hien_Tai == 2)
		{
			if(Kiem_Tra_Nam_Nhuan(x.Nam_Hien_Tai) == true)
			{
				Tong_Ngay += 29;
			}
			else
			{
				Tong_Ngay += 28;
			}
		}
		else
		{
			Tong_Ngay += 31;
		}
		x.Thang_Hien_Tai++;
	}
	return (Tong_Ngay - x.Ngay_Hien_Tai) + y.Ngay_Hien_Tai;
}

bool Kiem_Tra_Sach_Muon_Qua_Han(Tree t, LIST l, int madocgia, string masach)
{
	if(t == NULL)
	{
		return false;
	}
	else if(t->data.Ma_Doc_Gia < madocgia)
	{
		Kiem_Tra_Sach_Muon_Qua_Han(t->pRight, l, madocgia, masach);
	}
	else if(t->data.Ma_Doc_Gia > madocgia)
	{
		Kiem_Tra_Sach_Muon_Qua_Han(t->pLeft, l, madocgia, masach);
	}
	else if(t->data.Ma_Doc_Gia == madocgia) 
	{
		for(NODE *k = t->data.l.pHead; k != NULL; k = k->pNext)
		{
			if(stricmp(k->data.Ma_Sach.c_str() , masach.c_str()) == 0)
			{
				if(So_Ngay_Qua_Han(k->data.Ngay_Muon, k->data.Ngay_Tra) > 15)
				{

					return true;
				}
				return false;
			}
		}
	}
}

/*                                                         ĐỌC GHI FILE DANH SÁCH ĐỘC GIẢ                                                      */

// đưa dữ liệu các quyển sách mà độc giả tương ứng đã và đang mượn vào danh sách mượn trả
void Muon_Sach_2(PHIEUMUONTRA x, LIST &l, LISTSACH &sach, string masach)
{
	Chuan_Hoa_In_Hoa(masach);
	x.Ma_Sach = masach;
	NODE *p = GetNode(x);
	AddTail(l, p);
}

// hàm có tác dụng tìm độc giả vừa được đọc từ file để đưa các quyển sách vào danh sách mượn trả
void Tim_Doc_Gia_Muon_Sach_File(ifstream &file, Tree &t, LISTSACH &sach, int madocgia, int size)
{
	if(t->data.Ma_Doc_Gia > madocgia)
	{
		Tim_Doc_Gia_Muon_Sach_File(file, t->pLeft, sach, madocgia, size);
	}
	else if(t->data.Ma_Doc_Gia < madocgia)
	{
		Tim_Doc_Gia_Muon_Sach_File(file, t->pRight, sach, madocgia, size);
	}
	else if(t->data.Ma_Doc_Gia == madocgia)
	{
		// vòng lặp đọc tiếp file: các quyển sách của độc giả hiện có
		for(int i = 0; i < size; i++)
		{

			PHIEUMUONTRA x;
			Doc_File_Thong_Tin_Phieu_Muon_Tra(file, x);// đọc file: thông tin của 1 quyển sách mà độc giả đó đã mượn
			Muon_Sach_2(x, t->data.l, sach, x.Ma_Sach); // hàm đưa thông tin quyển sách đó vào danh sách mượn trả của độc giả tương ứng 
		}
		return;
	}

}

// hàm đọc file danh sách độc giả
void Doc_File_Danh_Sach_Doc_Gia(ifstream &file, Tree &t, LIST &l, LISTSACH &sach)
{
	string n;
	getline(file, n);
	int dem = Chuoi_Sang_So(n); // số lượng độc giả hiện có trong thư viện


	// vòng lặp cho đến cuối file
	for(int i = 0; i < dem; i++)
	{
		DOCGIA x;
		Doc_File_Thong_Tin_Doc_Gia(file, x); // đọc thông tin của 1 độc giả từ file 
		Init(x.l); // khởi tạo cho mỗi độc giả 1 danh sách mượn trả
		Insert(t, x); // thêm 1 độc giả mới vào danh sách

		// khắc phục kí tự enter cuối dòng
		string m;
		getline(file , m);
		int size = Chuoi_Sang_So(m);
		Tim_Doc_Gia_Muon_Sach_File(file, t, sach, x.Ma_Doc_Gia, size); // đọc dữ liệu thông tin của các quyển sách mà độc giả đó đã và đang mượn từ file 
	}
}

// hàm có tác dụng trả về số lượng sách mà 1 độc giả đã và đang mượn
int So_Luong_Danh_Sach_Muon_Tra(Tree t, LIST l, int madocgia)
{
	if(t->data.Ma_Doc_Gia < madocgia)
	{
		So_Luong_Danh_Sach_Muon_Tra(t->pRight, l, madocgia);
	}
	else if(t->data.Ma_Doc_Gia > madocgia)
	{
		So_Luong_Danh_Sach_Muon_Tra(t->pLeft, l, madocgia);
	}
	else
	{
		int soluong = 0;
		for(NODE *k = t->data.l.pHead; k != NULL; k = k->pNext)
		{
			soluong++;

		}
		return soluong;
	}
}

void Ghi_File_Danh_Sach_Doc_Gia(ofstream& file, Tree t, LIST l)
{
	if(t != NULL)
	{
		Ghi_File_Danh_Sach_Doc_Gia(file, t->pLeft, l);

		Ghi_File_Thong_Tin_Doc_Gia(file, t->data);

		int soluong = So_Luong_Danh_Sach_Muon_Tra(t, l, t->data.Ma_Doc_Gia);
		file << ", " << soluong << endl;

		for(NODE *k = t->data.l.pHead; k != NULL; k = k->pNext)
		{
			Ghi_File_Thong_Tin_Phieu_Muon_Tra(file, k->data);
			file << endl;
		}

		Ghi_File_Danh_Sach_Doc_Gia(file, t->pRight, l);
	}
}


/*                                                 ĐỌC GHI FILE DANH SÁCH SÁCH                                                  */

// hàm đọc danh sách sách từ file
void Doc_Danh_Sach_Thong_Tin_Sach_File(ifstream &file, LISTSACH &x)
{

	SACH y;
	int dem;
	string n;
	getline(file, n);
	dem = Chuoi_Sang_So(n);


	for(int i = 0; i < dem; i++)
	{
		Doc_Thong_Tin_Sach_File(file, y);
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

// hàm ghi dữ liệu danh sách sách lên file
void Ghi_Danh_Sach_Thong_Tin_Sach_File(ofstream &file, LISTSACH x)
{
	int dem = x.size;
	file << dem << endl;
	for(int i = 0; i < dem; i++)
	{
		Ghi_Thong_Tin_Sach_File(file, x.LIST[i]);
		file << endl;
	}
}


// hàm có tác dụng load dữ liệu lên chương trình
void Doc_File(ifstream& FileIn, Tree &t, LIST &l, LISTSACH &sach)
{

	FileIn.open("DANH_SACH_SACH.TXT", ios::in);
	if(FileIn != NULL)
	{
		Doc_Danh_Sach_Thong_Tin_Sach_File(FileIn, sach);
	}
	FileIn.close();

	FileIn.open("DANH_SACH_DOC_GIA.TXT", ios::in);
	if(FileIn != NULL)
	{
		Doc_File_Danh_Sach_Doc_Gia(FileIn, t, l, sach);
	}
	FileIn.close();
}

// hàm có tác dụng load dữ liệu xuống file
void Ghi_File(ofstream& FileOut, Tree t, LIST l, LISTSACH sach)
{
	FileOut.open("DANH_SACH_SACH.TXT", ios::out);

	Ghi_Danh_Sach_Thong_Tin_Sach_File(FileOut, sach);
	FileOut.close();

	FileOut.open("DANH_SACH_DOC_GIA.TXT", ios::out);
	int dem = 0;
	So_Luong_Doc_Gia(t, dem);
	FileOut << dem << endl;
	Ghi_File_Danh_Sach_Doc_Gia(FileOut, t, l);
	FileOut.close();

	delete[] sach.LIST;
}


// vòng lặp có tác dụng duyệt danh sách độc giả để tìm ra số lượt mượn của từng mã sách(quyển sách) trong danh sách sách
void Duyet_Doc_Gia_Muon_Sach(Tree t, LISTSACH sach, int *&luot_muon)
{
	if(t != NULL)
	{
		Duyet_Doc_Gia_Muon_Sach(t->pLeft, sach, luot_muon);

		int n = sach.size;
		// vòng lặp lấy từng mã sách(quyển sách) trong danh sách sách đem duyệt
		for(int i = 0; i < n; i++)
		{

			int sum = 0;
			// vòng lặp duyệt từng mã sách(quyển sách) của danh sách sách với từng mã sách(quyển sách) trong danh sách mượn trả của 1 độc giả  
			for(NODE *k = t->data.l.pHead; k != NULL; k = k->pNext)
			{

				if(stricmp(sach.LIST[i].Ma_Sach.c_str(), k->data.Ma_Sach.c_str()) == 0)
				{
					sum++;
				}
			}
			luot_muon[i] += sum;
		}

		Duyet_Doc_Gia_Muon_Sach(t->pRight, sach, luot_muon);
	}
}



// hàm sắp xếp giảm dần lượt mượn sách của 1 quyển sách  
void Sap_Xep_1(LISTSACH &sach, int *&luot_muon, int x)
{
	int dem = 0;
	int n = sach.size;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(luot_muon[i] < luot_muon[j])
			{
				dem++;
				Hoan_Vi<int>(luot_muon[i], luot_muon[j]);
				Hoan_Vi<SACH>(sach.LIST[i], sach.LIST[j]);
			}
			if(dem == x)
			{
				return;
			}
		}
	}
}




/* Ý tưởng

- Nhập vào mã độc giả cần xóa
- Kiểm tra nếu mã độc giả cần xóa tồn tại trong thư viện thì thực hiện chức năng xóa
- Xóa độc giả trong cây phân theo cơ chế
+ nếu độc giả đó là node lá: xóa bình thường delete
+ nếu độc giả đó là node có 1 con: thì kiểm tra nếu t->pLeft == NULL , xóa t->pRight và ngược lại
+ nếu độc giả đó là node có 2 con: thì duyệt tìm phần tử thế mạng theo cơ chế " trái nhất của phải " để xóa phần tử thế mạng đó

*/
// hàm xóa độc giả
void Xoa_Doc_Gia(Tree &t)
{
	// in khung xóa độc giả

	TextColor(14);
	gotoXY(23, 0);      cout << "* * * * * * * * * * * * * * * *";
	TextColor(10);
	gotoXY(23, 1);      cout << "     XOA THONG TIN DOC GIA     ";
	TextColor(14);
	gotoXY(23, 1);      cout << "*";
	gotoXY(23 + 30, 1); cout << "*";
	gotoXY(23, 2);      cout << "* * * * * * * * * * * * * * * *";


	TextColor(15);
	gotoXY(30, 4); cout << "Bam ESC de thoat !";

	TextColor(15);
	gotoXY(0, 8);  cout << "Nhap ma doc gia can xoa:";
	int length = 0;



	TextColor(14);
	gotoXY(21, 14); cout << "* * * * * * * * * * * * * * * * * * *";
	gotoXY(21, 15); cout << "*";
	gotoXY(57, 15); cout << "*";

	TextColor(10); 
	gotoXY(23, 15); cout << "    THONG TIN DOC GIA CAN XOA    ";

	TextColor(14);
	gotoXY(21, 16); cout << "* * * * * * * * * * * * * * * * * * *";

	TextColor(11);
	In_Khung_Doc_Gia(18);


	// in danh sách các độc giả hiện có trong thư viện
	TextColor(14);
	gotoXY(6, 25);    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	gotoXY(6, 26);    cout << "*";
	gotoXY(74, 26);   cout << "*";
	TextColor(10);
	gotoXY(7, 26);    cout << "       DANH SACH THONG TIN CAC DOC GIA HIEN CO TRONG THU VIEN     ";
	TextColor(14);
	gotoXY(6, 27);    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

	// in danh sách thông tin độc giả ra màn hình
	int td_y = 29;
	int y = 8;
	TextColor(11);
	In_Khung_Doc_Gia(29);
	TextColor(15);
	Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(t, td_y);
	TextColor(7);



	string str;
	char c;
	int cd_max = 6;
	int madocgia;
	bool Kiem_Tra_Doc_Gia;

	// vòng lặp lặp vô tận cho đến khi ta nhấn phím enter <=> kết thúc việc nhập
	while(true)
	{
		gotoXY(24 + str.length(), 8);
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
				gotoXY(24 + str.length(), 8);
				TextColor(7);
			}

		}
		else if((int)c == 27)
		{
			return;
		}
		else if((int)c ==  13)
		{
			if(str.length() != 0)
			{
				madocgia = Chuoi_Sang_So(str);
				// hàm kiểm tra mã độc giả có tồn tại trong thư viện chưa. Kiem_Tra_Doc_Gia == true ==> có tồn tại
				Kiem_Tra_Ma_Doc_Gia_In(t, madocgia, Kiem_Tra_Doc_Gia, 20);
				if(Kiem_Tra_Doc_Gia == true)
				{
					while(true)
					{
						gotoXY(30, y + 2);
						bool kiem_tra = Xac_Nhan_3(25, y + 2);

						// nếu lựa chọn lưu có
						if(kiem_tra == true)
						{
							// hàm có chức năng xóa thông tin độc giả theo mã độc giả
							Xoa_Theo_Ma_Doc_Gia(t, madocgia);

							// xóa danh sách thông tin độc giả đã in ra màn hình, để cập nhật và in lại
							for(int i = 31; i <= td_y; i += 2)
							{
								gotoXY(0, i);
								cout << "                                                                                       ";
							}
							// xóa thông tin độc giả in ra màn hình THONG TIN DOC GIA CAN XOA
							gotoXY(0, 20);
							cout << "                                                                                       ";

							// in danh sách thông tin độc giả ra màn hình
							TextColor(15);
							td_y = 29;
							Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(t, td_y);
							TextColor(7);
							str.resize(0);
							gotoXY(24 , 8);
							cout << "           ";
							break;
						}
						else
						{
							break; // không xóa và tiếp tục
						}

					}
				}
				else
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Ma doc gia chua ton tai trong thu vien. Xin kiem tra lai !";
					getch();
					gotoXY(20, y + 2);
					cout << "                                                                    ";
					gotoXY(24 + str.length(), 8);
					TextColor(7);
				}
			}
			else
			{
				TextColor(12);
				gotoXY(20, y + 2);
				cout << "DU LIEU KHONG DUOC DE TRONG.";
				getch();
				gotoXY(20, y + 2);
				cout << "                                           ";
				gotoXY(24 + str.length(), 8);
				TextColor(7);
			}
		}
	}

}
/* ý tưởng 
- Nhập vào mã độc giả. Kiểm tra mã độc giả có tồn tại trong thư viện hya không? . Nếu tồn tại
- Xuất thông tin độc giả cần sửa ra màn hình
- Đổ thông tin dữ liệu từ độc giả muốn sửa sang cho độc giả temp
+ Đổ dữ liệu lên các thuộc tính của độc giả để sửa 
- Nếu sau khi sửa:
+ mã độc giả không thay đổi <=> không sửa mã độc giả
- đổ dữ liệu từ các thuộc tính đã sửa sang cho độc giả hiện tại đang sửa
+ mã độc giả thay đổi
B0: kiểm tra nếu mã độc giả thay đổi đã tồn tại trong thư viện thì không cho thực hiện thao tác các bước tiếp theo
B1: lấy thông tin dữ liệu của độc giả A (sửa) sau khi sửa xong sang độc giả B
B2: xóa độc giả A (theo mã độc giả)
B3: thêm vào danh sách độc giả B (mã độc giả)
*/




// hàm cho phép sửa thông tin độc giả hiện có trong thư viện
void Sua_Doc_Gia(Tree &t)
{
	// in khung sửa độc giả
	TextColor(14);
	gotoXY(23, 0);      cout << "* * * * * * * * * * * * * * * *";
	TextColor(10);
	gotoXY(23, 1);      cout << "     SUA THONG TIN DOC GIA     ";
	TextColor(14);
	gotoXY(23, 1);      cout << "*";
	gotoXY(23 + 30, 1); cout << "*";
	gotoXY(23, 2);      cout << "* * * * * * * * * * * * * * * *";



	TextColor(14);
	gotoXY(0, 4);
	cout << "* * * * * * * * ";
	TextColor(15);
	gotoXY(16, 4); cout << "  HUONG DAN  ";
	TextColor(14);
	gotoXY(29, 4);
	cout << " * * * * * * * * ";

	gotoXY(44, 6); cout << "*";
	gotoXY(44, 8); cout << "*";
	gotoXY(44, 10); cout << "*";

	TextColor(15);
	gotoXY(3, 6); cout << "Bam ESC de thoat ! "; 
	gotoXY(3, 8); cout << "Di chuyen qua lai:   " << (char)26 << "    " << (char)27 ;
	gotoXY(3, 10); cout << "Bam ENTER de luu";
	TextColor(14);
	gotoXY(0, 12); cout << "* * * * * * * * * * * * * * * * * * * * * * *";
	TextColor(7);



	TextColor(15);
	gotoXY(0, 15);  cout << "Nhap ma doc gia can sua:";


	TextColor(14);
	gotoXY(21, 21); cout << "* * * * * * * * * * * * * * * * * * *";
	gotoXY(21, 22); cout << "*";
	gotoXY(57, 22); cout << "*";

	TextColor(10); 
	gotoXY(23, 22); cout << "    THONG TIN DOC GIA CAN SUA    ";

	TextColor(14);
	gotoXY(21, 23); cout << "* * * * * * * * * * * * * * * * * * *";

	TextColor(11);
	In_Khung_Xuat(25);


	// in danh sách các độc giả hiện có trong thư viện
	TextColor(14);
	gotoXY(6, 32);    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	gotoXY(6, 33);    cout << "*";
	gotoXY(74, 33);   cout << "*";
	TextColor(10);
	gotoXY(7, 33);    cout << "       DANH SACH THONG TIN CAC DOC GIA HIEN CO TRONG THU VIEN     ";
	TextColor(14);
	gotoXY(6, 34);    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";


	// in danh sách thông tin độc giả ra màn hình
	int td_y = 36; // biến tọa độ in ra các thông tin độc giả
	int y = 15; // biến tọa độ xuất ra thông báo 
	TextColor(11);
	In_Khung_Xuat(36);
	TextColor(15);
	Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(t, td_y);
	TextColor(7);

	string str;
	int length = 0;
	char c;
	int cd_max = 6;
	int ma;
	bool Kiem_Tra_Doc_Gia;

	// vòng lặp lặp cho đến khi nhấn esc thoát
	while(true)
	{
		// vòng lặp có tác dụng nhập mã độc giả và kiểm tra xem độc giả đó có tồn tại trong thư viện hay không. Nếu tồn tại thì in ra và thoát khỏi
		while(true)
		{
			gotoXY(24 + str.length(), 15);
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
					gotoXY(24 + str.length(), 8);
					TextColor(7);
				}

			}
			else if((int)c == 27)
			{
				return;
			}
			else if(c == 13)
			{
				if(str.length() != 0)
				{
					ma = Chuoi_Sang_So(str);
					// hàm kiểm tra mã độc giả có tồn tại trong thư viện chưa. Kiem_Tra_Doc_Gia == true ==> có tồn tại
					Kiem_Tra_Ma_Doc_Gia(t, ma, Kiem_Tra_Doc_Gia);
					if(Kiem_Tra_Doc_Gia == true)
					{
						break;
					}
					else
					{
						TextColor(12);
						gotoXY(20, y + 2);
						cout << "Ma doc gia chua ton tai trong thu vien. Xin kiem tra lai !";
						getch();
						gotoXY(20, y + 2);
						cout << "                                                                     ";
						gotoXY(24 + str.length(), 15);
						TextColor(7);
					}

				}
				else
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "DU LIEU KHONG DUOC DE TRONG.";
					getch();
					gotoXY(20, y + 2);
					cout << "                                           ";
					gotoXY(24 + str.length(), 15);
					TextColor(7);
				}
			}
		}

		DOCGIA a;
		// xuất thông tin độc giả cần sửa thông tin
		Xuat_Sua_Doc_Gia(t, a, ma, 27);

		int X = 0;
		int Y = 27;


		char s[8]; // chứa 7 kí tự
		int madocgia = a.Ma_Doc_Gia;
		string ma_doc_gia;
		itoa(a.Ma_Doc_Gia, s, 10);
		int n = strlen(s);
		for(int i = 0; i < n; i++)
		{
			ma_doc_gia.push_back(s[i]);
		}
		string ho = a.Ho;
		string ten = a.Ten;


		// sao chép ngày sinh từ A sang B
		string ngaysinh;
		int ngay = a.ngaysinh.Ngay_Hien_Tai;
		int thang = a.ngaysinh.Thang_Hien_Tai;
		int nam = a.ngaysinh.Nam_Hien_Tai;

		if(ngay <= 9)
		{
			ngaysinh.push_back('0');
			ngaysinh.push_back((ngay +  48));
		}
		else
		{
			itoa(ngay, s, 10);
			for(int i = 0; i < 2; i++)
			{
				ngaysinh.push_back(s[i]);
			}

		}
		if(thang <= 9)
		{
			ngaysinh.push_back('0');
			ngaysinh.push_back((thang + 48));
		}
		else
		{
			itoa(thang, s, 10);
			for(int i = 0; i < 2; i++)
			{
				ngaysinh.push_back(s[i]);
			}
		}
		itoa(nam, s, 10);
		for(int i = 0; i < 4; i++)
		{
			ngaysinh.push_back(s[i]);
		}


		string phai = a.Phai;


		int VT = 1;
		int madocgia_max = 10;
		int ho_max = 10;
		int ten_max = 20;
		int ngaysinh_max = 8;
		int phai_max = 5;

		// các biến kiểm tra
		bool check_enter = false;
		bool left = false;
		bool right = false;

		// vòng lặp lặp vô tận cho đến khi người dùng nhập liệu xong tất cả các thuộc tính và lưu lại
		gotoXY(0 + ma_doc_gia.length(), Y);
		while(true)
		{
H:
			bool kt = false;
			bool Kiem_Tra_ESC = false;

			if(VT == 1)
			{

				bool KT;
				gotoXY(0 + ma_doc_gia.length(), Y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_So_Nguyen_3(ma_doc_gia, madocgia, ma_doc_gia.length(), X, Y, madocgia_max, Kiem_Tra_ESC, check_enter, left, right); 

				if(Kiem_Tra_ESC == true)
				{
					return;
				}

				if(check_enter == true)
				{
					break;
				}
				if(left == true)
				{
					VT = 5;
				}
				else if(right == true)
				{
					VT = 2;
				}
				gotoXY(15 + ho.length(), Y);
			}
			else if(VT == 2)
			{

				gotoXY(15 + ho.length(), Y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_Ten_2(ho, ho.length(), X + 15, Y, ho_max, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					return;
				}

				if(check_enter == true)
				{
					break;
				}
				if(left == true)
				{
					VT = 1;
				}
				else if(right == true)
				{
					VT = 3;
				}
				gotoXY(30 + ten.length(), Y);
			}
			else if(VT == 3)
			{

				gotoXY(30 + ten.length(), Y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_Ten_2(ten, ten.length(), X + 30, Y, ten_max, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					return;
				}
				if(check_enter == true)
				{
					break;
				}
				if(left == true)
				{
					VT = 2;
				}
				else if(right == true)
				{
					VT = 4;
				}
				gotoXY(55 + ngaysinh.length(), Y);
			}
			else if(VT == 4)
			{
				bool check_1 = false; // có tác dụng nếu như ngày tháng năm nhập vào hợp lệ thì giữ giá trị true
				// vòng lặp có tác dụng lặp đến khi nào độ dài khác 0 và khác 8 hay check_1 bằng false và độ dài bằng 8 
				do{

					gotoXY(55 + ngaysinh.length(), Y);
					check_enter = false;
					left = false;
					right = false;
					Nhap_Ngay_Sinh(a.ngaysinh, ngaysinh, ngaysinh.length(), X + 55, Y, ngaysinh_max, check_1, Kiem_Tra_ESC, check_enter, left, right);
					if(Kiem_Tra_ESC == true)
					{
						return;
					}


				}while((check_1 == false && ngaysinh.length() == 8) || (ngaysinh.length() != 8 && ngaysinh.length() != 0));

				if(check_enter == true)
				{
					break;
				}
				if(left == true)
				{
					VT = 3;
				}
				else if(right == true)
				{
					VT = 5;
				}
				gotoXY(70 + phai.length(), Y);
			}
			else if(VT == 5)
			{
				gotoXY(70 + phai.length(), Y);

				check_enter = false;
				left = false;
				right = false;
				Nhap_Ten_2(phai,phai.length(), X + 70, Y, phai_max, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					return;
				}
				if(check_enter == true)
				{
					break;
				}

				if(left == true)
				{
					VT = 4;
				}
				else if(right == true)
				{
					VT = 1;
				}
				gotoXY(0 + ma_doc_gia.length(), Y);
			}
		}

		if(ma_doc_gia.length() != 0 && ho.length() != 0 && ten.length() != 0 && phai.length() != 0 && ngaysinh.length() != 0)
		{
			while(true)
			{
				gotoXY(30, Y + 2);
				bool kiem_tra = Xac_Nhan_1(25, Y + 2);
				if(kiem_tra == true)
				{

					// nếu mã độc giả được sửa 
					bool kiem_tra_trung = false;
					if(ma != madocgia)
					{

						Kiem_Tra_Ma_Doc_Gia(t, madocgia, kiem_tra_trung);
						if(kiem_tra_trung == true)
						{
							TextColor(12);
							gotoXY(25, Y + 2);
							cout << "Khong the luu. Ma doc gia da ton tai trong thu vien";
							getch();
							gotoXY(25, Y + 2);
							cout << "                                                         ";
							TextColor(7);
							break;
						}
						else
						{
							DOCGIA b;
							Lay_Thong_Tin_Doc_Gia(t, b, ma); // chuyển thông tin độc giả A qua B. Chuyển danh sách mượn trả
							// hàm có chức năng xóa thông tin độc giả theo mã độc giả.  Xóa A
							Xoa_Theo_Ma_Doc_Gia(t, ma);

							b.Ma_Doc_Gia = madocgia;
							b.Ho = ho;
							b.Ten = ten;
							b.Phai = phai;
							// chuẩn hóa theo qui tắc chuẩn
							Chuan_Hoa(b.Ho);
							Chuan_Hoa(b.Ten);
							Chuan_Hoa(b.Phai);
							Insert(t, b); // thêm 1 độc giả mới vào danh sách. Insert lại B có tất cả những thông tin của A 
						}

					}
					else // nếu mã độc giả không được sửa
					{
						a.Ma_Doc_Gia = madocgia;
						a.Ho = ho;
						a.Ten = ten;
						a.Phai = phai;
						// chuẩn hóa theo qui tắc chuẩn
						Chuan_Hoa(a.Ho);
						Chuan_Hoa(a.Ten);
						Chuan_Hoa(a.Phai);
						Thay_Doi_Thong_Tin_Doc_Gia(t, a, madocgia); // thay đổi thông tin 
					}
					if(kiem_tra_trung == false)
					{
						// xóa danh sách thông tin độc giả đã in ra màn hình, để cập nhật và in lại
						for(int i = 38; i <= td_y; i += 2)
						{
							gotoXY(0, i);
							cout << "                                                                                       ";
						}

						// xóa thông tin độc giả in ra màn hình THONG TIN DOC GIA CAN XOA
						gotoXY(0, 27);
						cout << "                                                                                       ";

						// in danh sách thông tin độc giả ra màn hình
						TextColor(15);
						td_y = 36;
						Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(t, td_y);
						TextColor(7);
						str.resize(0);
						gotoXY(24 , 15);
						cout << "           ";
						break;
					}
				}
				else
				{
					// xóa thông tin độc giả in ra màn hình THONG TIN DOC GIA CAN XOA
					gotoXY(0, 27);
					cout << "                                                                                       ";
					break;
				}
			}

		}
		else
		{
			TextColor(12);
			gotoXY(25, Y + 2);
			cout << "KHONG THE LUU. DU LIEU CON TRONG";
			getch();
			gotoXY(25, Y + 2);
			cout << "                                      ";
			TextColor(7);
			goto H;
		}
	}

}



// hàm có tác dụng lấy thông tin độc giả A chuyển sang B
void Lay_Thong_Tin_Doc_Gia(Tree t, DOCGIA &x, int madocgia)
{
	if(t == NULL)
	{
		return;
	}
	if(t->data.Ma_Doc_Gia > madocgia)
	{
		Lay_Thong_Tin_Doc_Gia(t->pLeft, x, madocgia);
	}
	else if(t->data.Ma_Doc_Gia < madocgia)
	{
		Lay_Thong_Tin_Doc_Gia(t->pRight, x, madocgia);
	}
	else if(t->data.Ma_Doc_Gia == madocgia)
	{
		// gán tất cả các thuộc tính của độc giả A sang cho độc giả B
		x.Ma_Doc_Gia = madocgia;
		x.Ho = t->data.Ho;
		x.Ten = t->data.Ten;

		x.ngaysinh = t->data.ngaysinh;

		x.Phai = t->data.Phai;
		x.Trang_Thai = t->data.Trang_Thai;

		Init(x.l); // khởi tạo ra danh sách mượn trả

		// vòng lặp lấy tất cả các quyển sách đã và đang mượn của độc giả A chuyền qua danh sách mượn trả của độc giả B
		for(NODE *k = t->data.l.pHead; k != NULL; k = k->pNext)
		{
			PHIEUMUONTRA a;
			a.Ma_Sach = k->data.Ma_Sach;
			a.Ngay_Muon = k->data.Ngay_Muon;
			a.Ngay_Tra = k->data.Ngay_Tra;
			a.Trang_Thai = k->data.Trang_Thai;
			NODE *p = GetNode(a);
			AddTail(x.l, p);
		}
	}
}


// hàm thay đổi thông tin A khi sửa thông tin A
void Thay_Doi_Thong_Tin_Doc_Gia(Tree &t, DOCGIA x, int madocgia)
{
	if(t == NULL)
	{
		return;
	}
	if(t->data.Ma_Doc_Gia > madocgia)
	{
		Thay_Doi_Thong_Tin_Doc_Gia(t->pLeft, x, madocgia);
	}
	else if(t->data.Ma_Doc_Gia < madocgia)
	{
		Thay_Doi_Thong_Tin_Doc_Gia(t->pRight, x, madocgia);
	}
	else if(t->data.Ma_Doc_Gia == madocgia)
	{
		// thay đổi thông tin độc giả
		t->data.Ho = x.Ho;
		t->data.Phai = x.Phai;
		t->data.Ten = x.Ten;
		t->data.ngaysinh.Ngay_Hien_Tai = x.ngaysinh.Ngay_Hien_Tai;
		t->data.ngaysinh.Thang_Hien_Tai = x.ngaysinh.Thang_Hien_Tai;
		t->data.ngaysinh.Nam_Hien_Tai = x.ngaysinh.Nam_Hien_Tai;
		return;
	}
}


// hàm có tác dụng xóa 1 quyển sách theo mã sách
void Xoa_Sach(LISTSACH &sach)
{
	// in khung xóa sách

	TextColor(14);
	gotoXY(27, 0);      cout << "* * * * * * * * * * * * * * *";
	TextColor(10);
	gotoXY(27, 1);      cout << "      XOA THONG TIN SACH    "; // 30
	TextColor(14);
	gotoXY(27, 1);      cout << "*";
	gotoXY(25 + 30, 1); cout << "*";
	gotoXY(27, 2);      cout << "* * * * * * * * * * * * * * *";


	TextColor(15);
	gotoXY(30, 4); cout << "Bam ESC de thoat !";

	TextColor(15);
	gotoXY(0, 8);  cout << "Nhap ma sach can xoa:"; // 21


	// in khung thông tin 1 quyển sách
	TextColor(14);
	gotoXY(21, 14); cout << "* * * * * * * * * * * * * * * * * * * *";
	gotoXY(21, 15); cout << "*";
	gotoXY(23 + 36, 15); cout << "*";

	TextColor(10); 
	gotoXY(23, 15); cout << "       THONG TIN SACH CAN XOA       "; // 36

	TextColor(14);
	gotoXY(21, 16); cout << "* * * * * * * * * * * * * * * * * * * *";

	TextColor(11);
	In_Khung(18); // in khung sách


	// in danh sách các độc giả hiện có trong thư viện
	TextColor(14);
	gotoXY(6, 25);    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	gotoXY(6, 26);    cout << "*";
	gotoXY(72, 26);   cout << "*";
	TextColor(10);
	gotoXY(7, 26);    cout << "    DANH SACH THONG TIN CAC QUYEN SACH HIEN CO TRONG THU VIEN    "; // 67
	TextColor(14);
	gotoXY(6, 27);    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	TextColor(7);

	// in danh sách thông tin sách ra màn hình
	int td_y = 29;
	int y = 8;
	TextColor(11);
	In_Khung(29); // in khung sách
	TextColor(15);
	int n = sach.size;
	for(int i = 0; i < n; i++)
	{
		Xuat_Thong_Tin_Sach_1(sach.LIST[i], td_y += 2);
	}
	TextColor(7);




	string str;
	char c;
	int cd_max = 8;// chiều dài tối đa của 1 mã sách
	int length = 0;
	gotoXY(21 + str.length() ,8);


	while(true)
	{
F:      
		gotoXY(21 + str.length() , 8);
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
			// nếu nhấn kí tự ESC thì thoát
			return;
		}
		else if((int)c ==  13)
		{
			// kiểm tra xem mã sách có toàn khoảng trắng hay không
			if(Kiem_Tra_Khoang_Trang(str) == false)
			{
				str.erase(0);
				TextColor(12);
				gotoXY(20, y + 2);
				cout << "Du lieu khong duoc de trong. Xin kiem tra lai !";
				getch();
				gotoXY(20, y + 2);
				cout << "                                                                ";
				TextColor(7);
			}
			else
			{
				int size;
				Chuan_Hoa_Khoang_Trang(str); // chuẩn hóa khoảng trắng
				bool KT_Ma_Sach_Ton_Tai = Kiem_Tra_Ma_Sach(sach, str); // kiểm tra xem mã sách đang nhập có tồn tại trong thư viện chưa. Trả về true : tồn tại
				bool KT_Trang_Thai_Sach = Kiem_Tra_Dieu_Kien_Sach(sach, str); // kiểm tra xem quyển sách đang nhập có thể xóa được hay không. Trả về true: có thể xóa
				// mã sách đã thỏa điều kiện có thể xóa được <=> trạng thái = 0 và mã sách đã tồn tại trong thư viện
				if(KT_Ma_Sach_Ton_Tai == true && KT_Trang_Thai_Sach == true) // trạng thái bằng 0
				{
					size = sach.size;
					// vòng lặp xuất ra thông tin độc giả
					for(int i = 0; i < size; i++)
					{
						// kiểm tra mã sách độc giả
						if(stricmp(sach.LIST[i].Ma_Sach.c_str(), str.c_str()) == 0)
						{
							TextColor(15);
							Xuat_Thong_Tin_Sach_1(sach.LIST[i], 20);
							TextColor(7);
							break;
						}

					}

					bool kiem_tra = Xac_Nhan_3(25, y + 2);
					// xác nhận có tiếp tục
					if(kiem_tra == true)
					{
						// vòng lặp có tác dụng duyệt tìm mã sách trong danh sách sách 
						size = sach.size;
						for(int i = 0; i < size; i++)
						{
							// kiểm tra mã sách
							if(stricmp(sach.LIST[i].Ma_Sach.c_str(), str.c_str()) == 0) // hàm stricmp() : so sánh 2 chuỗi ko phân biệt hoa thường
							{
								Xoa_Vi_Tri_Bat_Ki(sach, i); // xóa 1 phần tử tại vị trí i
								break;
							}
						}

						gotoXY(21 ,8);  cout << "                  ";
						gotoXY(0, 20);       cout << "                                                                                    ";

						// xóa danh sách thông tin độc giả đã in ra màn hình, để cập nhật và in lại
						for(int i = 31; i <= td_y; i += 2)
						{
							gotoXY(0, i);
							cout << "                                                                                       ";
						}

						// sau khi xóa thì xuất ra danh sách sách hiện tại
						td_y = 29;
						TextColor(15);
						size = sach.size;
						for(int i = 0; i < size; i++)
						{
							Xuat_Thong_Tin_Sach_1(sach.LIST[i], td_y += 2);
						}
						TextColor(7);
						str.resize(0);
					}
					else
					{
						gotoXY(0, 20);   cout << "                                                                                    ";
					}

				}
				else if(KT_Ma_Sach_Ton_Tai == false)
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Ma sach khong ton tai trong thu vien. Xin kiem tra lai !";
					getch();
					gotoXY(20, y + 2);
					cout << "                                                                ";
					TextColor(7);
				}
				else if(KT_Trang_Thai_Sach == false)
				{
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Ma sach da co doc gia muon, khong the xoa(Trang thai = 1). Xin kiem tra lai !";
					getch();
					gotoXY(20, y + 2);
					cout << "                                                                                  ";
					TextColor(7);
				}

			}
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
				gotoXY(21 + str.length() ,8);
				TextColor(7);
			}

		}
	}
}

// hàm có chức năng sửa thông tin sách
void Sua_Thong_Tin_Sach(LISTSACH &sach, Tree &t)
{
	// in khung sửa sách

	TextColor(14);
	gotoXY(27, 0);      cout << "* * * * * * * * * * * * * * *";
	TextColor(10);
	gotoXY(27, 1);      cout << "      SUA THONG TIN SACH    "; // 30
	TextColor(14);
	gotoXY(27, 1);      cout << "*";
	gotoXY(25 + 30, 1); cout << "*";
	gotoXY(27, 2);      cout << "* * * * * * * * * * * * * * *";


	TextColor(15);
	gotoXY(30, 4); cout << "Bam ESC de thoat !";

	TextColor(15);
	gotoXY(0, 8);  cout << "Nhap ma sach can sua:"; // 21


	// in khung thông tin 1 quyển sách
	TextColor(14);
	gotoXY(21, 14); cout << "* * * * * * * * * * * * * * * * * * * *";
	gotoXY(21, 15); cout << "*";
	gotoXY(23 + 36, 15); cout << "*";

	TextColor(10); 
	gotoXY(23, 15); cout << "       THONG TIN SACH CAN SUA       "; // 36

	TextColor(14);
	gotoXY(21, 16); cout << "* * * * * * * * * * * * * * * * * * * *";

	TextColor(11);
	In_Khung_1(18); // in khung sách


	// in danh sách các độc giả hiện có trong thư viện
	TextColor(14);
	gotoXY(6, 25);    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	gotoXY(6, 26);    cout << "*";
	gotoXY(72, 26);   cout << "*";
	TextColor(10);
	gotoXY(7, 26);    cout << "    DANH SACH THONG TIN CAC QUYEN SACH HIEN CO TRONG THU VIEN    "; // 67
	TextColor(14);
	gotoXY(6, 27);    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	TextColor(7);

	// in danh sách thông tin sách ra màn hình
	int td_y = 29;
	int y = 8;
	TextColor(11);
	In_Khung(29); // in khung sách
	TextColor(15);
	int n = sach.size;
	for(int i = 0; i < n; i++)
	{
		Xuat_Thong_Tin_Sach_1(sach.LIST[i], td_y += 2);
	}
	TextColor(7);


	// nếu nhập kí tự enter thì chuỗi hiểu đó là kí tự kết thúc chuỗi <=> length = 0, ko tính là 1 kí tự
	bool KT;
	int cd_max = 8;
	int length ; // biến cho con trỏ dịch đến cuối
	char c;

	string str; // biến nhập mã độc giả cần sửa thông tin
	gotoXY(21 + str.length(), 8);

	while(true)
	{
		while(true)
		{
F:         
			gotoXY(21 + str.length() , 8);
			c = getch();
			length = str.length();
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
				// nếu nhấn kí tự ESC thì thoát
				return;
			}
			else if((int)c ==  13)
			{
				// kiểm tra xem mã sách có toàn khoảng trắng hay không
				if(Kiem_Tra_Khoang_Trang(str) == false)
				{
					str.erase(0);
					TextColor(12);
					gotoXY(20, y + 2);
					cout << "Du lieu khong duoc de trong. Xin kiem tra lai !";
					getch();
					gotoXY(20, y + 2);
					cout << "                                                                ";
					TextColor(7);
				}
				else
				{
					int size;
					Chuan_Hoa_Khoang_Trang(str); // chuẩn hóa khoảng trắng
					bool KT_Ma_Sach_Ton_Tai = Kiem_Tra_Ma_Sach(sach, str); // kiểm tra xem mã sách đang nhập có tồn tại trong thư viện chưa. Trả về true : tồn tại
					bool KT_Trang_Thai_Sach = Kiem_Tra_Dieu_Kien_Sach(sach, str); // kiểm tra xem quyển sách đang nhập có thể xóa được hay không. Trả về true: có thể xóa
					// mã sách đã thỏa điều kiện có thể xóa được <=> trạng thái = 0 và mã sách đã tồn tại trong thư viện
					if(KT_Ma_Sach_Ton_Tai == true && KT_Trang_Thai_Sach == true) // trạng thái bằng 0
					{
						size = sach.size;
						// vòng lặp xuất ra thông tin độc giả
						for(int i = 0; i < size; i++)
						{
							// kiểm tra mã sách độc giả
							if(stricmp(sach.LIST[i].Ma_Sach.c_str(), str.c_str()) == 0)
							{
								Xuat_Thong_Tin_Sach_2(sach.LIST[i], 20);
								break;
							}

						}

						bool kiem_tra = Xac_Nhan_3(25, y + 2);
						// xác nhận có tiếp tục
						if(kiem_tra == true)
						{
							break;
						}
						else
						{
							gotoXY(0, 20);   cout << "                                                                                    ";
						}

					}
					else if(KT_Ma_Sach_Ton_Tai == false)
					{
						TextColor(12);
						gotoXY(20, y + 2);
						cout << "Ma sach khong ton tai trong thu vien. Xin kiem tra lai !";
						getch();
						gotoXY(20, y + 2);
						cout << "                                                                ";
						TextColor(7);
					}
					else if(KT_Trang_Thai_Sach == false)
					{
						TextColor(12);
						gotoXY(20, y + 2);
						cout << "Ma sach da co doc gia muon, khong the sua(Trang thai = 1). Xin kiem tra lai !";
						getch();
						gotoXY(20, y + 2);
						cout << "                                                                                  ";
						TextColor(7);
					}

				}
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
					gotoXY(22 + str.length() ,8);
					TextColor(7);
				}
			}
		}


		SACH a = Lay_Thong_Tin_Sach(sach, str);

		// các biến có chức năng lưu thông tin của các thuộc tính SÁCH
		string masach = a.Ma_Sach;
		string tensach = a.Ten_Sach;
		int sotrang = a.So_Trang;
		char s[8]; // chứa 7 kí tự 
		string so_trang = itoa(a.So_Trang, s, 10);
		string tacgia = a.Tac_Gia;
		int namxuatban = a.Nam_Xuat_Ban;
		string nam_xuat_ban = itoa(a.Nam_Xuat_Ban, s, 10);
		string vitri = a.Vi_Tri;
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
		int X = 0;
		int Y = 20;


		while(true)
		{

			bool kt = false;
			bool Kiem_Tra_ESC = false;

H: 
			if(VT == 1)
			{

				gotoXY(0 + masach.length(), Y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_Du_Lieu_Chuoi_3(masach, masach.length(), X, Y, masach_max, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					return;
				}

				if(check_enter == true)
				{
					break;
				}
				if(left == true)
				{

					VT = 6;
				}
				else if(right == true)
				{

					VT = 2;
				}

			}
			else if(VT == 2)
			{

				gotoXY(10 + tensach.length(), Y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_Du_Lieu_Chuoi_3(tensach, tensach.length(), X + 10, Y, tensach_max, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					return;
				}
				if(check_enter == true)
				{
					break;
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

				gotoXY(30 + tacgia.length(), Y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_Ten_2(tacgia, tacgia.length(), X + 30, Y, tacgia_max, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					return ;
				}
				if(check_enter == true)
				{
					break;
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
				gotoXY(50 + so_trang.length(), Y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_So_Nguyen_3(so_trang,sotrang, so_trang.length(), X + 50, Y, sotrang_max, Kiem_Tra_ESC, check_enter, left, right);
				if(Kiem_Tra_ESC == true)
				{
					return;
				}
				if(check_enter == true)
				{
					break;
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
					gotoXY(60 + nam_xuat_ban.length(), Y);

					check_enter = false;
					left = false;
					right = false;
					Nhap_So_Nguyen_3(nam_xuat_ban,namxuatban, nam_xuat_ban.length(), X + 60, Y, namxuatban_max, Kiem_Tra_ESC, check_enter, left, right);
					if(Kiem_Tra_ESC == true)
					{
						return;

					}
					else if(nam_xuat_ban.length() != 0 && nam_xuat_ban.length() != namxuatban_max)
					{
						TextColor(12);
						gotoXY(25, Y + 3);
						cout << "Du lieu phai co " << namxuatban_max << " so. Xin kiem tra lai\n";
						system("pause");
						gotoXY(25, Y + 3);
						cout << "                                                                  ";
						gotoXY(0, Y + 4);
						cout << "                                                 ";
						TextColor(7);
					}
					else if(nam_xuat_ban[0] == '0')
					{
						TextColor(12);
						gotoXY(25, Y + 3);
						cout << "Nam xuat ban khong hop le. Xin kiem tra lai\n";
						system("pause");
						gotoXY(25, Y + 3);
						cout << "                                                                  ";
						gotoXY(0, Y + 4);
						cout << "                                                 ";
						TextColor(7);
					}


				}while((nam_xuat_ban.length() != 0 && nam_xuat_ban.length() != namxuatban_max) || nam_xuat_ban[0] == '0');

				if(check_enter == true)
				{
					break;
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
				gotoXY(70 + vitri.length(), Y);
				check_enter = false;
				left = false;
				right = false;
				Nhap_Du_Lieu_Chuoi_3(vitri, vitri.length(), X + 70, Y, vitri_max, Kiem_Tra_ESC, check_enter, left, right); 
				if(Kiem_Tra_ESC == true)
				{
					return;
				}

				if(check_enter == true)
				{
					break;
				}
				if(left == true)
				{
					VT = 5;
				}
				else if(right == true)
				{
					VT = 1;
				}
			}
		}




		// nếu nhấn enter thì ra ngoài thao tác
		if(check_enter == true)
		{
			if(masach.length() != 0 && tensach.length() != 0 && so_trang.length() != 0 && tacgia.length() != 0 && nam_xuat_ban.length() != 0 && vitri.length() != 0)
			{
				while(true)
				{
					gotoXY(30, y + 2);
					bool kiem_tra = Xac_Nhan_1(25, y + 2);
					if(kiem_tra == true)
					{
						bool KT = Kiem_Tra_Ma_Sach(sach, masach);

						if(KT == true)
						{
							TextColor(12);
							gotoXY(20, y + 2);
							cout << "Ma sach da ton tai. Xin kiem tra lai !\n";
							system("pause");
							gotoXY(20, y + 2);
							cout << "                                                  ";
							gotoXY(0, y + 3);
							cout << "                                                ";
							TextColor(7);
						}
						else
						{
							a.Ma_Sach = masach;
							a.Tac_Gia = tacgia;
							a.Ten_Sach = tensach;
							a.So_Trang = sotrang;
							a.Vi_Tri = vitri;
							a.Nam_Xuat_Ban = namxuatban;
							// chuẩn hóa theo dạng chuẩn mặc định
							Chuan_Hoa(a.Tac_Gia);
							Chuan_Hoa(a.Ten_Sach);
							Chuan_Hoa_Khoang_Trang(a.Ma_Sach);
							Chuan_Hoa_Khoang_Trang(a.Vi_Tri);
							Chuan_Hoa_In_Hoa(a.Ma_Sach);
							Chuan_Hoa_In_Hoa(a.Vi_Tri);

							// hàm thay đổi thông tin theo mã sách sau khi sửa thông tin sách
							Thay_Doi_Thong_Tin_Sach(sach, a, str);

							// hàm xuất ra lại danh sách sách sau khi thay đổi thông tin
							TextColor(15);
							int size = sach.size;
							td_y = 29;
							for(int i = 0; i < size; i++)
							{
								Xuat_Thong_Tin_Sach_1(sach.LIST[i], td_y += 2);
							}
							TextColor(7);

							gotoXY(21, 8);
							cout << "           ";
							gotoXY(0, 20); 
							cout << "                                                                                                 ";
							str.resize(0);
							break;
						}
					}
					else
					{
						gotoXY(21, 8);
						cout << "           ";
						gotoXY(0, 20); 
						cout << "                                                                                                 ";
						str.resize(0);
						break;
					}
				}

			}
			else if(masach.length() == 0 || tensach.length() == 0 || so_trang.length() == 0 || tacgia.length() == 0 || nam_xuat_ban.length() == 0 || vitri.length() == 0)
			{

				TextColor(12);
				gotoXY(25, y + 2);
				cout << "KHONG THE LUU. DU LIEU CON TRONG\n";
				system("pause");
				gotoXY(25, y + 2);
				cout << "                                      ";
				gotoXY(0,  y + 3);
				cout << "                                             ";
				TextColor(7);
				goto H;
			}
		}
	}
}

// hàm lấy thông tin sách theo masach
SACH Lay_Thong_Tin_Sach(LISTSACH sach, string masach)
{
	int n = sach.size;
	for(int i = 0; i < n; i++)
	{
		// kiểm tra mã sách 
		if(stricmp(sach.LIST[i].Ma_Sach.c_str(), masach.c_str()) == 0)
		{
			return sach.LIST[i];
		}
	}
}

// hàm thay đổi thông tin sách sau khi sửa
void Thay_Doi_Thong_Tin_Sach(LISTSACH &sach, SACH x, string masach)
{
	int n = sach.size;
	for(int i = 0; i < n; i++)
	{
		// kiểm tra mã sách
		if(stricmp(sach.LIST[i].Ma_Sach.c_str(), masach.c_str()) == 0)
		{
			sach.LIST[i].Ma_Sach = x.Ma_Sach;
			sach.LIST[i].Nam_Xuat_Ban = x.Nam_Xuat_Ban;
			sach.LIST[i].So_Trang = x.So_Trang;
			sach.LIST[i].Tac_Gia = x.Tac_Gia;
			sach.LIST[i].Ten_Sach = x.Ten_Sach;
			sach.LIST[i].Vi_Tri = x.Vi_Tri;
			break;
		}
	}
}


void Tim_Kiem_Thong_Tin_Doc_Gia(LIST l, Tree t, LISTSACH sach)
{
	// xóa màn hình
	clrscr();

	// các biến lưu dữ liệu nhập từ bàn phím
	string ma;
	int maso = 0;
	int maso_max = 6;
	int VT = 1;
	char c;


	// in khung liệt kê
	In_Khung_Liet_Ke(12);

	// in danh sách các độc giả hiện có trong thư viện
	TextColor(14);
	gotoXY(9, 14);
	cout << "**************************************************************";
	gotoXY(9, 15);
	cout << "*";
	gotoXY(70, 15);
	cout << "*";

	TextColor(10);
	gotoXY(11, 15);
	cout << "  DANH SACH THONG TIN CAC DOC GIA HIEN CO TRONG THU VIEN  ";

	TextColor(14);
	gotoXY(9, 16);
	cout << "**************************************************************";

	int tdy = 18;
	// vòng lặp có tác dụng in ra danh sách các độc giả hiện có trong thư viện
	TextColor(11);
	In_Khung_Xuat(18);
	TextColor(15);
	Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(t, tdy);
	TextColor(7);


	int x = 5;
	int y = tdy;
	TextColor(13);
	gotoXY(0, y + 2);  cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";

	TextColor(10);
	gotoXY(0, y + 5);  cout << "Nhap ma doc gia:";


	// in thông tin độc giả
	TextColor(13);
	gotoXY(25, y + 10); cout << "***** THONG TIN DOC GIA *****";
	TextColor(11);
	In_Khung_Xuat(y + 12);
	TextColor(7);

	// in giao diện các quyển sách đang mượn của 1 độc giả
	TextColor(14);
	gotoXY(9, y + 16);  cout << "*****************************************************************";
	gotoXY(9, y + 17);  cout << "*";
	gotoXY(73, y + 17); cout << "*";

	TextColor(10);
	gotoXY(11, y + 17);  cout << "     DANH SACH CAC QUYEN SACH CUA DOC GIA DA VA DANG MUON   ";

	TextColor(14);
	gotoXY(9, y + 18);  cout << "*****************************************************************";

	// in khung phiếu mượn
	TextColor(11);
	In_Khung_Phieu_Muon_Tra(y + 20);
	TextColor(7);
	gotoXY(16 + ma.length(), y + 5);
	bool check_ma = false;
	bool check_enter = false;

	// vòng lặp lặp vô tận cho đến khi người dùng nhập liệu xong tất cả các thuộc tính và lưu lại
	while(true)
	{
		bool Kiem_Tra; // biến có tác dụng kiểm tra nếu bấm ESC thoát
		bool KT;
		// vòng lặp có tác dụng nhập liệu cho mã độc giả mượn sách
		do
		{
			check_enter = false;
			gotoXY(16 + ma.length(), y + 5);
			Nhap_So_Nguyen_2(ma, maso, ma.length(), 16, y + 5, maso_max, Kiem_Tra, check_enter);

			// nếu nhấn esc thì thoát
			if(Kiem_Tra == true)
			{
				return;
			}

			// hàm kiểm tra mã độc giả có tồn tại trong thư viện chưa
			Kiem_Tra_Ma_Doc_Gia(t, maso, KT);  
			if(KT == false)
			{
				TextColor(12);
				gotoXY(20, y + 7);
				cout << "Ma doc gia chua ton tai. Xin kiem tra lai the doc gia\n";
				system("pause");
				gotoXY(20, y + 7);
				cout << "                                                          ";
				gotoXY(0, y + 8);
				cout << "                                                          ";
				TextColor(7);
			}

		}while(KT == false);
		// hàm xuất thông tin độc giả đang kiem tra sách
		TextColor(15);
		Xuat_Thong_Tin_Doc_Gia_Theo_Ma(t, maso, y + 14);
		TextColor(7);

		// nhấn phím enter <==> muốn xem thông tin mượn sách
		if(check_enter == true)
		{
			if(ma.length() != 0)
			{
				TextColor(15);
				int td_y = y + 22;
				Liet_Ke_Sach_1(l, t, maso, td_y);
				TextColor(7);
				break;

			}
			else 
			{
				TextColor(12);
				gotoXY(25, y + 8);
				cout << "Chua nhap ma doc gia. Xin kiem tra lai\n";
				system("pause");
				gotoXY(25, y + 8);
				cout << "                                              ";
				gotoXY(0, y + 9);
				cout << "                                           ";
				TextColor(7);
			}
		}

	}
}



void Khung_Quan_Li_Sach(int x, int y)
{

	TextColor(350);
	gotoXY(x, y++); cout << "                   " ;
	gotoXY(x, y++); cout << "                   " ; 
	gotoXY(x, y++); cout << "                   " ;

	gotoXY(x + 2, y - 2);
	cout << "QUAN LI SACH";
	TextColor(7);


}

void Khung_Quan_Li_Doc_Gia(int x, int y)
{
	TextColor(350);
	gotoXY(x, y++); cout << "                   " ;
	gotoXY(x, y++); cout << "                   " ; 
	gotoXY(x, y++); cout << "                   " ;
	gotoXY(x + 2, y - 2);
	cout << "QUAN LI DOC GIA";
	TextColor(7);

}

void Khung_Quan_Li_Thong_Ke(int x, int y)
{
	TextColor(350);
	gotoXY(x, y++); cout << "                   " ;
	gotoXY(x, y++); cout << "                   " ; 
	gotoXY(x, y++); cout << "                   " ;
	gotoXY(x + 2, y - 2);
	cout << "THONG KE";
	TextColor(7);
}

void Khung_Thu_Vien(int x, int y)
{
	for(int i = 1; i <= 3 ; i++)
	{
		gotoXY(x, y++);
		TextColor(350);
		cout << "                             " << endl;
	}
	gotoXY(x + 2, y - 2);
	cout << "HE THONG QUAN LI THU VIEN";
	TextColor(7);
}

void Menu(Tree &t, LIST &l, LISTSACH &sach)
{

	bool up;
	bool down;
	bool left;
	bool right;

	// in giao diện cố định
	TextColor(350);
	gotoXY(0, 0);   cout << "                         ";// 25
	gotoXY(0, 1);   cout << "                         ";
	gotoXY(0, 2);   cout << "                         ";
	gotoXY(0, 3);   cout << "                         ";
	gotoXY(0, 4);   cout << "                         ";

	gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
	gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
	gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


	TextColor(170);
	gotoXY(25, 0);   cout << " ";
	gotoXY(25, 1);   cout << " ";
	gotoXY(25, 2);   cout << " ";
	gotoXY(25, 3);   cout << " ";
	gotoXY(25, 4);   cout << " ";

	TextColor(350);
	gotoXY(26, 0);   cout << "                                                      "; // 54 
	gotoXY(26, 1);   cout << "                                                      ";
	gotoXY(26, 2);   cout << "                                                      ";
	gotoXY(26, 3);   cout << "                                                      ";
	gotoXY(26, 4);   cout << "                                                      ";

	gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
	gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
	gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19



	char c;
	int x = 25;
	int y = 10;
	int VT = 1;

	Khung_Thu_Vien(25, y);
	Khung_Quan_Li_Sach(5, y + 5); // VT = 1
	Khung_Quan_Li_Doc_Gia(5, y + 10); // VT = 2
	Khung_Quan_Li_Thong_Ke(5, y + 15); // VT = 3


	// vòng lặp có tác dụng di chuyển giữa các chức năng trong thư viện
	gotoXY(25, y + 5);
	while(true)
	{

		c = getch();
F:
		if(c == 27)
		{
			clrscr();
			system("color 3e");
			return;
		}
		else if(c == -32)
		{
			c = getch();
H:
			if(c == 80) // down
			{
				if(VT < 3)
				{
					VT++;
				}
				else if(VT == 3)
				{
					VT = 1;
				}
			}
			else if(c == 72) // 72 up
			{
				if(VT > 1)
				{
					VT--;
				}
				else if(VT == 1)
				{
					VT = 3;
				}
			}
		}

		if(VT == 1)
		{
			// xóa giao diện chi tiết VT = 2
			system("color 3e");
			gotoXY(x - 1, y + 10);        cout << "                                            ";
			gotoXY(x - 1, y + 2 + 10);    cout << "                                            ";
			gotoXY(x - 1, y + 4 + 10);    cout << "                                            ";
			gotoXY(x - 1, y + 6 + 10);    cout << "                                            ";
			gotoXY(x - 1, y + 8 + 10);    cout << "                                            ";
			gotoXY(x - 1, y + 10 + 10);    cout << "                                            ";

			// xóa giao diện chi tiết 3 
			gotoXY(x - 1, y + 15);        cout << "                                                  ";
			gotoXY(x - 1, y + 2 + 15);    cout << "                                                  ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y + 5); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y + 10); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y + 15); // VT = 3




			int Y = y + 5;
			int X = 26;
			for(int i = 1; i <= 16; i++)
			{
				gotoXY(X - 1, Y++);
				TextColor(350);
				cout << "                             ";
			}

			int length_1 = 17;
			TextColor(650);
			gotoXY(X, y + 5);  cout << "CAP NHAT SACH MOI";

			int length_2 = 27;
			TextColor(650);
			gotoXY(X, y + 2 + 5);  cout << "THEM SACH TAI VI TRI BAT KI";

			int length_3 = 9;
			TextColor(650);
			gotoXY(X, y + 4 + 5); cout << "MUON SACH";

			int length_4 = 8;
			TextColor(650);
			gotoXY(X, y + 6 + 5);  cout << "TRA SACH";

			int length_5 = 8;
			TextColor(650);
			gotoXY(X, y + 8 + 5);  cout << "XOA SACH";

			int length_6 = 8;
			TextColor(650);
			gotoXY(X, y + 10 + 5);  cout << "SUA SACH";

			int length_7 = 8;
			TextColor(650);
			gotoXY(X, y + 12 + 5);  cout << "TIM KIEM";

			int length_8 = 19;
			TextColor(650);
			gotoXY(X, y + 14 + 5);  cout << "XUAT DANH SACH SACH";

			gotoXY(25, y + 5);
			c = getch();
			if(c == -32)
			{
				c = getch();
				if(c == 77)
				{
					Quan_Li_Sach(l, sach, t, X, y + 5);
					goto F;
				}
				goto H;
			}
		}
		else if(VT == 2)
		{
			// xóa giao diện chi tiết VT = 1
			system("color 3e");
			gotoXY(x - 1, y + 5);        cout << "                                            ";
			gotoXY(x - 1, y + 2 + 5);    cout << "                                            ";
			gotoXY(x - 1, y + 4 + 5);    cout << "                                            ";
			gotoXY(x - 1, y + 6 + 5);    cout << "                                            ";
			gotoXY(x - 1, y + 8 + 5);    cout << "                                            ";
			gotoXY(x - 1, y + 10 + 5);   cout << "                                            ";
			gotoXY(x - 1, y + 12 + 5);   cout << "                                            ";
			gotoXY(x - 1, y + 14 + 5);   cout << "                                            ";

			// xóa giao diện chi tiết 3
			gotoXY(x - 1, y + 15);        cout << "                                                 ";
			gotoXY(x - 1, y + 2 + 15);    cout << "                                                 ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y + 5); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y + 10); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y + 15); // VT = 3



			int Y = y + 10;
			int X = 26;

			for(int i = 1; i <= 12; i++)
			{
				gotoXY(X - 1, Y++);
				TextColor(350);
				cout << "                                 ";
			}

			int length_1 = 15;
			TextColor(650);
			gotoXY(X, y + 10);  cout << "DANG KI DOC GIA";

			int length_2 = 30;
			TextColor(650);
			gotoXY(X, y + 2 + 10);  cout << "LIET KE SACH DOC GIA DANG MUON";

			int length_3 = 11;
			TextColor(650);
			gotoXY(X, y + 4 + 10); cout << "XOA DOC GIA";

			int length_4 = 11;
			TextColor(650);
			gotoXY(X, y + 6 + 10);  cout << "SUA DOC GIA";

			int length_5 = 24;
			TextColor(650);
			gotoXY(X, y + 8 + 10);  cout << "TIM KIEM DOC GIA THEO MA";

			int length_6 = 22;
			TextColor(650);
			gotoXY(X, y + 10 + 10);  cout << "XUAT DANH SACH DOC GIA";

			gotoXY(25, y + 10);
			c = getch();
			if(c == -32)
			{
				c = getch();
				if(c == 77)
				{
					Quan_Li_Doc_Gia(l, sach, t , X, y + 10);
					goto F;
				}
				goto H;
			}

		}
		else if(VT == 3)
		{
			// xóa giao diện chi tiết VT = 2
			system("color 3e");
			gotoXY(x - 1, y + 10);        cout << "                                            ";
			gotoXY(x - 1, y + 2 + 10 );    cout << "                                            ";
			gotoXY(x - 1, y + 4 + 10);    cout << "                                            ";
			gotoXY(x - 1, y + 6 + 10);    cout << "                                            ";
			gotoXY(x - 1, y + 8 + 10);    cout << "                                            ";
			gotoXY(x - 1, y + 10 + 10);    cout << "                                            ";


			// xóa giao diện chi tiết VT = 1
			//system("color 3e");
			gotoXY(x - 1, y + 5);        cout << "                                            ";
			gotoXY(x - 1, y + 2 + 5);    cout << "                                            ";
			gotoXY(x - 1, y + 4 + 5);    cout << "                                            ";
			gotoXY(x - 1, y + 6 + 5);    cout << "                                            ";
			gotoXY(x - 1, y + 8 + 5);    cout << "                                            ";
			gotoXY(x - 1, y + 10 + 5);   cout << "                                            ";
			gotoXY(x - 1, y + 12 + 5);   cout << "                                            ";
			gotoXY(x - 1, y + 14 + 5);   cout << "                                            ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";
			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y + 5); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y + 10); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y + 15); // VT = 3





			int Y = y + 15;
			int X = 26;
			for(int i = 1; i <= 4; i++)
			{
				gotoXY(X - 1, Y++);
				TextColor(350);
				cout << "                                       ";
			}

			int length_1 = 35;
			TextColor(650);
			gotoXY(X, y + 15);  cout << "DANH SACH DOC GIA MUON SACH QUA HAN";

			int length_2 = 34;
			TextColor(650);
			gotoXY(X, y + 2 + 15);  cout << "10 SACH CO SO LUOT MUON NHIEU NHAT";

			gotoXY(25, y + 15);
			c = getch();
			if(c == -32)
			{
				c = getch();
				if(c == 77)
				{
					Quan_Li_Thong_Ke(l, sach, t , X, y + 15);
					goto F;
				}
				goto H;
			}
		}

	}

}

// menu quản lí sách
void Quan_Li_Sach(LIST &l, LISTSACH &sach, Tree &t, int x, int y)
{
	char c;
	int VT = 1;
	// vòng lặp lặp lại vô tận cho đến khi nhấn phím thoát mặc định
	while(true)
	{

		int Y = y;
		for(int i = 1; i <= 16; i++)
		{
			gotoXY(x - 1, Y++);
			TextColor(350);
			cout << "                             ";
		}

		int length_1 = 17;
		TextColor(650);
		gotoXY(x, y);  cout << "CAP NHAT SACH MOI";

		int length_2 = 27;
		TextColor(650);
		gotoXY(x, y + 2);  cout << "THEM SACH TAI VI TRI BAT KI";

		int length_3 = 9;
		TextColor(650);
		gotoXY(x, y + 4); cout << "MUON SACH";

		int length_4 = 8;
		TextColor(650);
		gotoXY(x, y + 6);  cout << "TRA SACH";

		int length_5 = 8;
		TextColor(650);
		gotoXY(x, y + 8);  cout << "XOA SACH";

		int length_6 = 8;
		TextColor(650);
		gotoXY(x, y + 10);  cout << "SUA SACH";

		int length_7 = 8;
		TextColor(650);
		gotoXY(x, y + 12);  cout << "TIM KIEM";

		int length_8 = 19;
		TextColor(650);
		gotoXY(x, y + 14);  cout << "XUAT DANH SACH SACH";

		TextColor(11);
		gotoXY(x - 1, y);
		cout << (char)16;
		gotoXY(x + length_1, y);
		cout << (char)17;
		TextColor(7);

		// vòng lặp có tác dụng di chuyển qua lại giữa các chức năng
		while(true)
		{
			c = getch();
			if(c == -32)
			{
				c = getch();
				if(c == 72) // phím lên
				{
					if(VT > 1)
					{
						VT--;
					}
					else if(VT == 1)
					{
						VT = 8;
					}
				}
				else if(c == 80) // phím xuống
				{
					if(VT < 8)
					{
						VT++;
					}
					else if(VT == 8)
					{
						VT = 1;
					}
				}
				else if(c == 75)
				{
					return;
				}

			}
			else if(c == 13)
			{
				clrscr();
				break;
			}
			else if(c == 27)
			{

			}
			if(VT == 1)
			{

				// xóa 2 mũi tên chọn tại chức năng 2 3 4 5 6 7 8
				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 12);
				cout << " ";
				gotoXY(x + length_7, y + 12);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 14);
				cout << " ";
				gotoXY(x + length_8, y + 14);
				cout << " ";
				TextColor(7);

				Khung_1(x, y);

				// cho 2 mũi tên chọn chức năng 1 
				TextColor(11);
				gotoXY(x - 1, y);
				cout << (char)16;
				gotoXY(x + length_1, y);
				cout << (char)17;
				TextColor(7);


			}
			else if(VT == 2)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 3 4 5 6 7 8
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 12);
				cout << " ";
				gotoXY(x + length_7, y + 12);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 14);
				cout << " ";
				gotoXY(x + length_8, y + 14);
				cout << " ";
				TextColor(7);

				Khung_1(x, y);

				// cho 2 mũi tên chọn chức năng 2 
				TextColor(11);
				gotoXY(x - 1, y + 2);
				cout << (char)16;
				gotoXY(x + length_2, y + 2);
				cout << (char)17;
				TextColor(7);
			}
			else if(VT == 3)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 2 4 5 6 7 8
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 12);
				cout << " ";
				gotoXY(x + length_7, y + 12);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 14);
				cout << " ";
				gotoXY(x + length_8, y + 14);
				cout << " ";
				TextColor(7);

				Khung_1(x, y);

				// cho 2 mũi tên chọn chức năng 3 
				TextColor(11);
				gotoXY(x - 1, y + 4);
				cout << (char)16;
				gotoXY(x + length_3, y + 4);
				cout << (char)17;
				TextColor(7);



			}
			else if(VT == 4)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 2 3 5 6 7 8
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 12);
				cout << " ";
				gotoXY(x + length_7, y + 12);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 14);
				cout << " ";
				gotoXY(x + length_8, y + 14);
				cout << " ";
				TextColor(7);

				Khung_1(x, y);

				// cho 2 mũi tên chọn chức năng 4 
				TextColor(11);
				gotoXY(x - 1, y + 6);
				cout << (char)16;
				gotoXY(x + length_4, y + 6);
				cout << (char)17;
				TextColor(7);
			}
			else if(VT == 5)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 2 3 4 6 7 8
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 12);
				cout << " ";
				gotoXY(x + length_7, y + 12);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 14);
				cout << " ";
				gotoXY(x + length_8, y + 14);
				cout << " ";
				TextColor(7);

				Khung_1(x, y);

				// cho 2 mũi tên chọn chức năng 5
				TextColor(11);
				gotoXY(x - 1, y + 8);
				cout << (char)16;
				gotoXY(x + length_5, y + 8);
				cout << (char)17;
				TextColor(7);
			}
			else if(VT == 6)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 2 3 4 5 7 8
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 12);
				cout << " ";
				gotoXY(x + length_7, y + 12);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 14);
				cout << " ";
				gotoXY(x + length_8, y + 14);
				cout << " ";
				TextColor(7);

				Khung_1(x, y);

				// cho 2 mũi tên chọn chức năng 6
				TextColor(11);
				gotoXY(x - 1, y + 10);
				cout << (char)16;
				gotoXY(x + length_6, y + 10);
				cout << (char)17;
				TextColor(7);
			}
			else if(VT == 7)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 2 3 4 5 6 8
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 14);
				cout << " ";
				gotoXY(x + length_8, y + 14);
				cout << " ";
				TextColor(7);

				Khung_1(x, y);

				// cho 2 mũi tên chọn chức năng 7
				TextColor(11);
				gotoXY(x - 1, y + 12);
				cout << (char)16;
				gotoXY(x + length_7, y + 12);
				cout << (char)17;
				TextColor(7);
			}
			else if(VT == 8)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 2 3 4 5 6 7
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 12);
				cout << " ";
				gotoXY(x + length_7, y + 12);
				cout << " ";
				TextColor(7);

				Khung_1(x, y);

				// cho 2 mũi tên chọn chức năng 8
				TextColor(11);
				gotoXY(x - 1, y + 14);
				cout << (char)16;
				gotoXY(x + length_8, y + 14);
				cout << (char)17;
				TextColor(7);
			}
		}
		// nếu nhấn enter ==> xử lí

		// xóa các nền của chức năng
		gotoXY(x, y);      cout << "                                       ";
		gotoXY(x, y + 2);  cout << "                                       ";
		gotoXY(x, y + 4);  cout << "                                       ";
		gotoXY(x, y + 6);  cout << "                                       ";
		gotoXY(x, y + 8);  cout << "                                       ";
		gotoXY(x, y + 10);  cout << "                                       ";
		gotoXY(x, y + 12);  cout << "                                       ";
		gotoXY(x, y + 14);  cout << "                                       ";

		clrscr();
		// đưa màn hình console về màu đen
		system("color e");
		TextColor(7);

		// kiểm tra nếu chọn chức năng gì thì sẽ chạy vô thực hiện chức năng đó
		if(VT == 1)
		{

			TextColor(7);
			Cap_Nhat_Sach(sach);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);   cout << "                                            ";
			gotoXY(x - 1, y + 12);   cout << "                                            ";
			gotoXY(x - 1, y + 14);   cout << "                                             ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 2)
		{
			TextColor(7);
			Them_Vao_Vi_Tri_Bat_Ki(sach);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);   cout << "                                            ";
			gotoXY(x - 1, y + 12);   cout << "                                            ";
			gotoXY(x - 1, y + 14);   cout << "                                             ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19

			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;

		}
		else if(VT == 3)
		{

			TextColor(7);
			Muon_Sach(l, t, sach);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);   cout << "                                            ";
			gotoXY(x - 1, y + 12);   cout << "                                            ";
			gotoXY(x - 1, y + 14);   cout << "                                             ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 4)
		{

			TextColor(7);
			Tra_Sach(l, t, sach);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);   cout << "                                            ";
			gotoXY(x - 1, y + 12);   cout << "                                            ";
			gotoXY(x - 1, y + 14);   cout << "                                             ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19

			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 5)
		{   
			TextColor(7);
			Xoa_Sach(sach);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);   cout << "                                            ";
			gotoXY(x - 1, y + 12);   cout << "                                            ";
			gotoXY(x - 1, y + 14);   cout << "                                             ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 6)
		{
			TextColor(7);
			Sua_Thong_Tin_Sach(sach, t);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);   cout << "                                            ";
			gotoXY(x - 1, y + 12);   cout << "                                            ";
			gotoXY(x - 1, y + 14);   cout << "                                             ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 7)
		{
			TextColor(7);
			Tim_Kiem_Theo_Ten_Sach(sach);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);   cout << "                                            ";
			gotoXY(x - 1, y + 12);   cout << "                                            ";
			gotoXY(x - 1, y + 14);   cout << "                                             ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 8)
		{
			TextColor(7);
			Xuat_Danh_Sach_Thong_Tin_Sach(sach);
			getch();
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);   cout << "                                            ";
			gotoXY(x - 1, y + 12);   cout << "                                            ";
			gotoXY(x - 1, y + 14);   cout << "                                             ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}

	}
}

// chức năng quản lí độc giả
void Quan_Li_Doc_Gia(LIST &l, LISTSACH &sach, Tree &t, int x, int y)
{
	char c;
	int VT = 1;
	// vòng lặp lặp lại vô tận cho đến khi nhấn phím thoát mặc định
	while(true)
	{

		int Y = y;
		for(int i = 1; i <= 12; i++)
		{
			gotoXY(x - 1, Y++);
			TextColor(350);
			cout << "                                 ";
		}

		int length_1 = 15;
		TextColor(650);
		gotoXY(x, y);  cout << "DANG KI DOC GIA";

		int length_2 = 30;
		TextColor(650);
		gotoXY(x, y + 2);  cout << "LIET KE SACH DOC GIA DANG MUON";

		int length_3 = 11;
		TextColor(650);
		gotoXY(x, y + 4); cout << "XOA DOC GIA";

		int length_4 = 11;
		TextColor(650);
		gotoXY(x, y + 6);  cout << "SUA DOC GIA";

		int length_5 = 24;
		TextColor(650);
		gotoXY(x, y + 8);  cout << "TIM KIEM DOC GIA THEO MA";

		int length_6 = 22;
		TextColor(650);
		gotoXY(x, y + 10);  cout << "XUAT DANH SACH DOC GIA";

		TextColor(11);
		gotoXY(x - 1, y);
		cout << (char)16;
		gotoXY(x + length_1, y);
		cout << (char)17;
		TextColor(7);

		// vòng lặp có tác dụng di chuyển qua lại giữa các chức năng
		while(true)
		{
			c = getch();
			if(c == -32)
			{
				c = getch();
				if(c == 72) // phím lên
				{
					if(VT > 1)
					{
						VT--;
					}
					else if(VT == 1)
					{
						VT = 6;
					}
				}
				else if(c == 80) // phím xuống
				{
					if(VT < 6)
					{
						VT++;
					}
					else if(VT == 6)
					{
						VT = 1;
					}
				}
				else if(c == 75)
				{
					return;
				}

			}
			else if(c == 13)
			{
				clrscr();
				break;
			}
			else if(c == 27)
			{

			}
			if(VT == 1)
			{

				// xóa 2 mũi tên chọn tại chức năng 2 3 4 5 6
				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);

				Khung_2(x, y);

				// cho 2 mũi tên chọn chức năng 1 
				TextColor(11);
				gotoXY(x - 1, y);
				cout << (char)16;
				gotoXY(x + length_1, y);
				cout << (char)17;
				TextColor(7);


			}
			else if(VT == 2)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 3 4 5 6
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);
				Khung_2(x, y);

				// cho 2 mũi tên chọn chức năng 2 
				TextColor(11);
				gotoXY(x - 1, y + 2);
				cout << (char)16;
				gotoXY(x + length_2, y + 2);
				cout << (char)17;
				TextColor(7);
			}
			else if(VT == 3)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 2 4 5 6
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);

				Khung_2(x, y);

				// cho 2 mũi tên chọn chức năng 3 
				TextColor(11);
				gotoXY(x - 1, y + 4);
				cout << (char)16;
				gotoXY(x + length_3, y + 4);
				cout << (char)17;
				TextColor(7);

			}
			else if(VT == 4)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 2 3 5 6
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);

				Khung_2(x, y);

				// cho 2 mũi tên chọn chức năng 4 
				TextColor(11);
				gotoXY(x - 1, y + 6);
				cout << (char)16;
				gotoXY(x + length_4, y + 6);
				cout << (char)17;
				TextColor(7);
			}
			else if(VT == 5)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 2 3 4 6
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 10);
				cout << " ";
				gotoXY(x + length_6, y + 10);
				cout << " ";
				TextColor(7);

				Khung_2(x, y);

				// cho 2 mũi tên chọn chức năng 5
				TextColor(11);
				gotoXY(x - 1, y + 8);
				cout << (char)16;
				gotoXY(x + length_5, y + 8);
				cout << (char)17;
				TextColor(7);
			}
			else if(VT == 6)
			{
				// xóa 2 mũi tên chọn tại chức năng 1 2 3 4 5
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 4);
				cout << " ";
				gotoXY(x + length_3, y + 4);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 6);
				cout << " ";
				gotoXY(x + length_4, y + 6);
				cout << " ";
				TextColor(7);

				TextColor(10);
				gotoXY(x - 1, y + 8);
				cout << " ";
				gotoXY(x + length_5, y + 8);
				cout << " ";
				TextColor(7);

				Khung_2(x, y);

				// cho 2 mũi tên chọn chức năng 6
				TextColor(11);
				gotoXY(x - 1, y + 10);
				cout << (char)16;
				gotoXY(x + length_6, y + 10);
				cout << (char)17;
				TextColor(7);
			}
		}
		// nếu nhấn enter ==> xử lí

		// xóa các nền của chức năng
		gotoXY(x, y);      cout << "                                       ";
		gotoXY(x, y + 2);  cout << "                                       ";
		gotoXY(x, y + 4);  cout << "                                       ";
		gotoXY(x, y + 6);  cout << "                                       ";
		gotoXY(x, y + 8);  cout << "                                       ";
		gotoXY(x, y + 10); cout << "                                        ";
		clrscr();
		// đưa màn hình console về màu đen
		system("color e");
		TextColor(7);

		// kiểm tra nếu chọn chức năng gì thì sẽ chạy vô thực hiện chức năng đó
		if(VT == 1)
		{

			TextColor(7);
			Dang_Ki_Doc_Gia(t);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);    cout << "                                            ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 2)
		{
			TextColor(7);
			Liet_Ke_Sach_Doc_Gia_Dang_Muon(l, t, sach);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);    cout << "                                            ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 3)
		{

			TextColor(7);
			Xoa_Doc_Gia(t);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);    cout << "                                            ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 4)
		{

			TextColor(7);
			Sua_Doc_Gia(t);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);    cout << "                                            ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 5)
		{   
			TextColor(7);
			Tim_Kiem_Thong_Tin_Doc_Gia(l, t, sach);
			getch();
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);    cout << "                                            ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 6)
		{
			TextColor(7);
			Xuat_Danh_Sach_Thong_Tin_Doc_Gia_2(t);
			getch();
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";
			gotoXY(x - 1, y + 4);    cout << "                                            ";
			gotoXY(x - 1, y + 6);    cout << "                                            ";
			gotoXY(x - 1, y + 8);    cout << "                                            ";
			gotoXY(x - 1, y + 10);    cout << "                                            ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
	}
}


void Quan_Li_Thong_Ke(LIST &l, LISTSACH &sach, Tree &t, int x, int y)
{
	char c;
	int VT = 1;
	// vòng lặp lặp lại vô tận cho đến khi nhấn phím thoát mặc định
	while(true)
	{

		int Y = y;
		for(int i = 1; i <= 5; i++)
		{
			gotoXY(x - 1, Y++);
			TextColor(350);
			cout << "                                        ";
		}

		int length_1 = 35;
		TextColor(650);
		gotoXY(x, y);  cout << "DANH SACH DOC GIA MUON SACH QUA HAN";

		int length_2 = 34;
		TextColor(650);
		gotoXY(x, y + 2);  cout << "10 SACH CO SO LUOT MUON NHIEU NHAT";

		TextColor(11);
		gotoXY(x - 1, y);
		cout << (char)16;
		gotoXY(x + length_1, y);
		cout << (char)17;
		TextColor(7);

		// vòng lặp có tác dụng di chuyển qua lại giữa các chức năng
		while(true)
		{
			c = getch();
			if(c == -32)
			{
				c = getch();
				if(c == 72) // phím lên
				{
					if(VT > 1)
					{
						VT--;
					}
					else if(VT == 1)
					{
						VT = 2;
					}
				}
				else if(c == 80) // phím xuống
				{
					if(VT < 2)
					{
						VT++;
					}
					else if(VT == 2)
					{
						VT = 1;
					}
				}
				else if(c == 75)
				{
					return;
				}

			}
			else if(c == 13)
			{
				clrscr();
				break;
			}
			else if(c == 27)
			{

			}
			if(VT == 1)
			{

				// xóa 2 mũi tên chọn tại chức năng 2 
				TextColor(10);
				gotoXY(x - 1, y + 2);
				cout << " ";
				gotoXY(x + length_2, y + 2);
				cout << " ";
				TextColor(7);

				Khung_3(x, y);

				// cho 2 mũi tên chọn chức năng 1 
				TextColor(11);
				gotoXY(x - 1, y);
				cout << (char)16;
				gotoXY(x + length_1, y);
				cout << (char)17;
				TextColor(7);


			}
			else if(VT == 2)
			{
				// xóa 2 mũi tên chọn tại chức năng 1
				TextColor(10);
				gotoXY(x - 1, y);
				cout << " ";
				gotoXY(x + length_1, y);
				cout << " ";
				TextColor(7);

				Khung_3(x, y);

				// cho 2 mũi tên chọn chức năng 2 
				TextColor(11);
				gotoXY(x - 1, y + 2);
				cout << (char)16;
				gotoXY(x + length_2, y + 2);
				cout << (char)17;
				TextColor(7);
			}

		}
		// nếu nhấn enter ==> xử lí

		// xóa các nền của chức năng
		gotoXY(x, y);      cout << "                                       ";
		gotoXY(x, y + 2);  cout << "                                       ";

		clrscr();
		// đưa màn hình console về màu đen
		system("color e");
		TextColor(7);

		// kiểm tra nếu chọn chức năng gì thì sẽ chạy vô thực hiện chức năng đó
		if(VT == 1)
		{

			TextColor(7);
			Danh_Sach_Doc_Gia_Qua_Han_Giam_Dan(t, l);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}
		else if(VT == 2)
		{
			TextColor(7);
			ofstream FileIn;
			Top_10_Sach_Muon_Nhieu_Nhat(FileIn, t, sach, 10);
			clrscr();
			system("color 3e");
			// in đè lên vị trí cũ sau khi thoát ra khỏi chức năng hiện tại
			gotoXY(x - 1, y);        cout << "                                            ";
			gotoXY(x - 1, y + 2);    cout << "                                            ";

			// in đè lên lại các khung chức năng
			// in giao diện cố định
			TextColor(350);
			gotoXY(0, 0);   cout << "                         ";// 25
			gotoXY(0, 1);   cout << "                         ";
			gotoXY(0, 2);   cout << "                         ";
			gotoXY(0, 3);   cout << "                         ";
			gotoXY(0, 4);   cout << "                         ";

			gotoXY(4, 0);   cout << "HO TEN HOC VIEN";
			gotoXY(0, 2);   cout << "1. Nguyen Thien Tam";
			gotoXY(0, 4);   cout << "2. Hoang Nguyen Thu Hang";


			TextColor(170);
			gotoXY(25, 0);   cout << " ";
			gotoXY(25, 1);   cout << " ";
			gotoXY(25, 2);   cout << " ";
			gotoXY(25, 3);   cout << " ";
			gotoXY(25, 4);   cout << " ";

			TextColor(350);
			gotoXY(26, 0);   cout << "                                                      "; // 54 
			gotoXY(26, 1);   cout << "                                                      ";
			gotoXY(26, 2);   cout << "                                                      ";
			gotoXY(26, 3);   cout << "                                                      ";
			gotoXY(26, 4);   cout << "                                                      ";

			gotoXY(26 + 20, 0);       cout << "BAO CAO DE TAI CUOI KHOA"; // 24
			gotoXY(26 + 17, 2);       cout << "CAU TRUC DU LIEU & GIAI THUAT"; // 29
			gotoXY(26 + 20, 4);       cout << "NGUYEN VIET NAM SON"; // 19


			Khung_Thu_Vien(25, y);
			Khung_Quan_Li_Sach(5, y); // VT = 1
			Khung_Quan_Li_Doc_Gia(5, y); // VT = 2
			Khung_Quan_Li_Thong_Ke(5, y); // VT = 3
			return;
		}

	}
}


void Khung_1(int x, int y)
{
	// in lại giao diện của quản lí sách
	int Y = y;

	for(int i = 1; i <= 16; i++)
	{
		gotoXY(x - 1, Y++);
		TextColor(350);
		cout << "                             ";
	}

	int length_1 = 17;
	TextColor(650);
	gotoXY(x, y);  cout << "CAP NHAT SACH MOI";

	int length_2 = 27;
	TextColor(650);
	gotoXY(x, y + 2);  cout << "THEM SACH TAI VI TRI BAT KI";

	int length_3 = 9;
	TextColor(650);
	gotoXY(x, y + 4); cout << "MUON SACH";

	int length_4 = 8;
	TextColor(650);
	gotoXY(x, y + 6);  cout << "TRA SACH";

	int length_5 = 8;
	TextColor(650);
	gotoXY(x, y + 8);  cout << "XOA SACH";

	int length_6 = 8;
	TextColor(650);
	gotoXY(x, y + 10);  cout << "SUA SACH";

	int length_7 = 8;
	TextColor(650);
	gotoXY(x, y + 12);  cout << "TIM KIEM";

	int length_8 = 19;
	TextColor(650);
	gotoXY(x, y + 14);  cout << "XUAT DANH SACH SACH";
}

void Khung_2(int x, int y)
{
	int Y = y;
	for(int i = 1; i <= 12; i++)
	{
		gotoXY(x - 1, Y++);
		TextColor(350);
		cout << "                                 ";
	}

	int length_1 = 15;
	TextColor(650);
	gotoXY(x, y);  cout << "DANG KI DOC GIA";

	int length_2 = 30;
	TextColor(650);
	gotoXY(x, y + 2);  cout << "LIET KE SACH DOC GIA DANG MUON";

	int length_3 = 11;
	TextColor(650);
	gotoXY(x, y + 4); cout << "XOA DOC GIA";

	int length_4 = 11;
	TextColor(650);
	gotoXY(x, y + 6);  cout << "SUA DOC GIA";

	int length_5 = 24;
	TextColor(650);
	gotoXY(x, y + 8);  cout << "TIM KIEM DOC GIA THEO MA";

	int length_6 = 22;
	TextColor(650);
	gotoXY(x, y + 10);  cout << "XUAT DANH SACH DOC GIA";
}

void Khung_3(int x, int y)
{
	int Y = y;
	for(int i = 1; i <= 4; i++)
	{
		gotoXY(x - 1, Y++);
		TextColor(350);
		cout << "                                       ";
	}

	int length_1 = 35;
	TextColor(650);
	gotoXY(x, y);  cout << "DANH SACH DOC GIA MUON SACH QUA HAN";

	int length_2 = 34;
	TextColor(650);
	gotoXY(x, y + 2);  cout << "10 SACH CO SO LUOT MUON NHIEU NHAT";
}


// hàm có tác dụng in ra top 10 quyển sách có số lượt mượn nhiều nhất
void Top_10_Sach_Muon_Nhieu_Nhat(ofstream& file, Tree t, LISTSACH sach, int x)
{

	// in giao diện
	TextColor(14);
	gotoXY(5, 0); cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
	TextColor(10);
	gotoXY(5, 1); cout << "            TOP " << x << " QUYEN SACH CO SO LUOT MUON NHIEU NHAT      ";
	TextColor(14);
	gotoXY(5, 1); cout << "*";
	gotoXY(71, 1); cout << "*";
	gotoXY(5, 2); cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";


	int n = sach.size;
	int *luot_muon = new int[n]; // mảng tuyến tính chứa số lượt mượn của danh sách sách


	// vòng lặp truyền giá trị lượt mượn ban đầu cho tất cả các mã sách bằng 0 <=> lượt mượn = 0
	for(int i = 0; i < n; i++)
	{
		luot_muon[i] = 0;
	}


	Duyet_Doc_Gia_Muon_Sach(t, sach, luot_muon); // hàm duyệt độc giả để kiểm tra số lần mượn của từng quyển sách
	Sap_Xep_1(sach, luot_muon, x); // hàm sắp xếp giảm dần sách theo số lượt mượn

	int tdx = 0;
	int tdy = 2;
	// vòng lặp có tác dụng in ra danh sách các quyển sách đang có trong thư viện
	TextColor(11);
	In_Khung(tdy + 2);
	int td_y = tdy + 2;
	TextColor(15);
	if(x <= n)
	{
		for(int i = 0; i < x; i++)
		{
			Xuat_Thong_Tin_Sach_1(sach.LIST[i], td_y += 2);
		}
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			Xuat_Thong_Tin_Sach_1(sach.LIST[i], td_y += 2);
		}
	}
	TextColor(7);



	// in danh sách các quyển sách hiện có trong thư viện
	TextColor(14);
	gotoXY(7, td_y + 2);  cout << "***************************************************************";
	gotoXY(7, td_y + 3);  cout << "*";
	gotoXY(69, td_y + 3); cout << "*";
	TextColor(10);
	gotoXY(9, td_y + 3); cout << " DANH SACH THONG TIN CAC QUYEN SACH HIEN CO TRONG THU VIEN ";
	TextColor(14);
	gotoXY(7, td_y + 4); cout << "***************************************************************";


	// vòng lặp có tác dụng in ra danh sách các quyển sách đang có trong thư viện
	TextColor(11);
	In_Khung(td_y + 6);
	td_y = td_y + 8;
	TextColor(15);
	for(int i = 0; i < n; i++)
	{
		Xuat_Thong_Tin_Sach_1(sach.LIST[i], td_y += 2);
	}
	TextColor(7);


	// in x quyển sách có số lượt mượn nhiều nhất ra file
	file.open("TOP 10 SACH MUON NHIEU NHAT.TXT", ios::out);
	file << "\t\t\t **** TOP " << x << " QUYEN SACH CO SO LUOT MUON NHIEU NHAT ***" << endl;
	file << x << endl;

	if(x <= n)
	{
		for(int i = 0; i < x; i++)
		{
			Ghi_Thong_Tin_Sach_File(file, sach.LIST[i]);
			file << endl;
		}
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			Ghi_Thong_Tin_Sach_File(file, sach.LIST[i]);
			file << endl;
		}
	}
	file.close();

	delete[] luot_muon;
	getch();
}