#include"Date.h"


// hàm lấy thời gian thực từ hệ thống máy tính
void Thoi_Gian_Thuc(DATE &x)
{
	time_t t = time(0);
	struct tm *now = localtime(&t);
	x.Ngay_Hien_Tai = now ->tm_mday;
	x.Thang_Hien_Tai = now ->tm_mon + 1;
	x.Nam_Hien_Tai = now ->tm_year + 1900;
}
//
//// hàm nhập ngày tháng năm
//void Nhap_Ngay_Thang_Nam(DATE &x)
//{
//	do
//	{
//		// nhập ngày và kiểm tra tính hợp lệ
//		do
//		{
//			cout << "\nNhap ngay: ";
//			cin >> x.Ngay_Hien_Tai;
//			if(x.Ngay_Hien_Tai < 0 || x.Ngay_Hien_Tai > 31)
//			{
//				cout << "\nNgay khong hop le. Xin nhap lai";
//				system("pause");
//			}
//		}while(x.Ngay_Hien_Tai < 0 || x.Ngay_Hien_Tai > 31);
//
//		// nhập tháng và kiểm tra tính hợp lệ
//		do
//		{
//			cout << "\nNhap thang: ";
//			cin >> x.Thang_Hien_Tai;
//			if(x.Thang_Hien_Tai < 0 || x.Thang_Hien_Tai > 31)
//			{
//				cout << "\nThang khong hop le. Xin nhap lai";
//				system("pause");
//			}
//		}while(x.Thang_Hien_Tai < 0 || x.Thang_Hien_Tai > 31);
//
//		// nhập năm và kiểm tra tính hợp lệ
//		do
//		{
//			cout << "\nNhap nam: ";
//			cin >> x.Nam_Hien_Tai;
//			if(x.Nam_Hien_Tai < 1900)
//			{
//				cout << "\nThang khong hop le. Xin nhap lai";
//				system("pause");
//			}
//		}while(x.Nam_Hien_Tai < 1900);
//
//		if(Kiem_Tra_Tinh_Hop_Le(x) == false)
//		{
//			cout << "\nNgay thang nam khong hop le. Xin kiem tra lai";
//			system("pause");
//		}
//
//	}while(Kiem_Tra_Tinh_Hop_Le(x) == false);
//
//}

// hàm kiểm tra tính hợp lệ của ngày tháng năm nhập vào
bool Kiem_Tra_Tinh_Hop_Le(DATE x, bool &Ngay, bool &Thang, bool &Nam)
{
	// hàm lấy thời gian thực từ hệ thống máy tính
	time_t t = time(0);
	struct tm *now = localtime(&t);

	// kiểm tra tính đúng của ngày tháng năm
	if(x.Ngay_Hien_Tai < 0 || x.Ngay_Hien_Tai > 31)
	{
		Ngay = false;
		return false;
	}
	if(x.Thang_Hien_Tai < 0 || x.Thang_Hien_Tai > 12)
	{
		Thang = false;
		return false;
	}
	if(x.Nam_Hien_Tai < 1900)
	{
		Nam = false;
		return false;
	}

	// kiểm tra xem ngày tháng năm nhập vào có nhỏ hơn ngày tháng năm hiện tại không
	if(x.Nam_Hien_Tai < now->tm_year + 1900)
	{
		Nam = false;
		return false;
	}
	else if(x.Nam_Hien_Tai == now->tm_year + 1900)
	{
		if(x.Thang_Hien_Tai < now ->tm_mon + 1)
		{
			Thang = false;
			return false;
		}
		else if(x.Thang_Hien_Tai == now ->tm_mon + 1)
		{
			if(x.Ngay_Hien_Tai < now ->tm_mday)
			{
				Ngay = false;
				return false;
			}
		}
	}

	// kiểm tra số ngày của từng tháng tương ứng
	if(x.Thang_Hien_Tai == 4 || x.Thang_Hien_Tai == 6 || x.Thang_Hien_Tai == 9 || x.Thang_Hien_Tai == 11)
	{
		if(x.Ngay_Hien_Tai > 30)
		{
			Ngay = false;
			return false;
		}
	}
	else if(x.Thang_Hien_Tai == 2)
	{
		if(Kiem_Tra_Nam_Nhuan(x.Nam_Hien_Tai) == true)
		{
			if(x.Ngay_Hien_Tai > 29)
			{
				Ngay = false;
				return false;
			}
		}
		else 
		{
			if(x.Ngay_Hien_Tai > 28)
			{
				Ngay = false;
				return false;
			}
		}
	}
	else 
	{
		if(x.Ngay_Hien_Tai > 31)
		{
			Ngay = false;
			return false;
		}
	}
	return true; // ngày tháng năm đều hợp lệ
}


// hàm có tác dụng kiểm tra ngày tháng năm của năm sinh 
bool Kiem_Tra_Tinh_Hop_Le_1(DATE x, bool &Ngay, bool &Thang, bool &Nam)
{
	// hàm lấy thời gian thực từ hệ thống máy tính
	time_t t = time(0);
	struct tm *now = localtime(&t);

	// kiểm tra tính đúng của ngày tháng năm
	if(x.Ngay_Hien_Tai < 0 || x.Ngay_Hien_Tai > 31)
	{
		Ngay = false;
		return false;
	}
	if(x.Thang_Hien_Tai < 0 || x.Thang_Hien_Tai > 12)
	{
		Thang = false;
		return false;
	}
	if(x.Nam_Hien_Tai < 1900)
	{
		Nam = false;
		return false;
	}

	// kiểm tra xem ngày tháng năm nhập vào có nhỏ hơn ngày tháng năm hiện tại không
	if(x.Nam_Hien_Tai > now->tm_year + 1900)
	{
		Nam = false;
		return false;
	}
	else if(x.Nam_Hien_Tai == now->tm_year + 1900)
	{
		if(x.Thang_Hien_Tai > now ->tm_mon + 1)
		{
			Thang = false;
			return false;
		}
		else if(x.Thang_Hien_Tai == now ->tm_mon + 1)
		{
			if(x.Ngay_Hien_Tai > now ->tm_mday)
			{
				Ngay = false;
				return false;
			}
		}
	}

	// kiểm tra số ngày của từng tháng tương ứng
	if(x.Thang_Hien_Tai == 4 || x.Thang_Hien_Tai == 6 || x.Thang_Hien_Tai == 9 || x.Thang_Hien_Tai == 11)
	{
		if(x.Ngay_Hien_Tai > 30)
		{
			Ngay = false;
			return false;
		}
	}
	else if(x.Thang_Hien_Tai == 2)
	{
		if(Kiem_Tra_Nam_Nhuan(x.Nam_Hien_Tai) == true)
		{
			if(x.Ngay_Hien_Tai > 29)
			{
				Ngay = false;
				return false;
			}
		}
		else 
		{
			if(x.Ngay_Hien_Tai > 28)
			{
				Ngay = false;
				return false;
			}
		}
	}
	else 
	{
		if(x.Ngay_Hien_Tai > 31)
		{
			Ngay = false;
			return false;
		}
	}
	return true; // ngày tháng năm đều hợp lệ
}

// hàm kiểm tra năm nhuận
bool Kiem_Tra_Nam_Nhuan(int nam)
{
	if((nam % 4 == 0 && nam % 100 != 0) || nam  % 400 == 0)
	{
		return true;
	}
	return false;
}


// hàm đọc file ngày tháng năm
void Doc_File_Ngay_Thang_Nam(ifstream &file, DATE &x)
{
	file >> x.Ngay_Hien_Tai;
	file.seekg(1, 1);
	file >> x.Thang_Hien_Tai;
	file.seekg(1, 1);
	file >> x.Nam_Hien_Tai;
	file.seekg(2, 1);
}

// hàm ghi file ngày tháng năm
void Ghi_File_Ngay_Thang_Nam(ofstream &file, DATE x)
{
	file << x.Ngay_Hien_Tai << "/" << x.Thang_Hien_Tai << "/" << x.Nam_Hien_Tai;
}