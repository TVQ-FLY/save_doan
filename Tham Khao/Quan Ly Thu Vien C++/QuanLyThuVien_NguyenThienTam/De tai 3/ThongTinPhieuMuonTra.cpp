#include"ThongTinPhieuMuonTra.h"


void Nhap_Thong_Tin_Phieu_Muon(PHIEUMUONTRA &x)
{
	// phiếu mượn trả chỉ cần nhập mã sách . ngày mượn sẽ được cập nhật từ hệ thống thời gian thực, trạng thái sẽ mặc định = 0 nghĩa là sách đó đang mượn
	Thoi_Gian_Thuc(x.Ngay_Muon);
	x.Ngay_Tra.Ngay_Hien_Tai = 0; 
	x.Ngay_Tra.Thang_Hien_Tai = 0;
	x.Ngay_Tra.Nam_Hien_Tai = 0;
	x.Trang_Thai = '0'; // trạng thái mặc định là độc giả đang mượn quyển sách 
}


void Xuat_Thong_Tin_Phieu_Muon_Tra(PHIEUMUONTRA x)
{
	cout << "\nMa sach: " << x.Ma_Sach;
	cout << "\nNgay muon sach: " << x.Ngay_Muon.Ngay_Hien_Tai << "/" << x.Ngay_Muon.Thang_Hien_Tai << "/" << x.Ngay_Muon.Nam_Hien_Tai;
	cout << "\nNgay tra sach: " << x.Ngay_Tra.Ngay_Hien_Tai << "/" << x.Ngay_Tra.Thang_Hien_Tai << "/" << x.Ngay_Tra.Nam_Hien_Tai;
	cout << "\nTrang thai sach: " << x.Trang_Thai;
}

void Xuat_Thong_Tin_Phieu_Muon_Tra_1(PHIEUMUONTRA x, int tdy)
{
	gotoXY(0, tdy);
	cout << x.Ma_Sach;

	// xuất ngày mượn sách
	int ngay = x.Ngay_Muon.Ngay_Hien_Tai;
	int thang = x.Ngay_Muon.Thang_Hien_Tai;
	if(ngay <= 9 && thang <= 9)
	{

		gotoXY(10, tdy);
		cout << "0" << x.Ngay_Muon.Ngay_Hien_Tai << "/0" << x.Ngay_Muon.Thang_Hien_Tai << "/" << x.Ngay_Muon.Nam_Hien_Tai;
	}
	else if(ngay <= 9 || thang <= 9)
	{
		gotoXY(10, tdy);
		if(ngay <= 9)
		{
			cout << "0" << x.Ngay_Muon.Ngay_Hien_Tai << "/" << x.Ngay_Muon.Thang_Hien_Tai << "/" << x.Ngay_Muon.Nam_Hien_Tai;
		}
		else if(thang <= 9)
		{
			cout << x.Ngay_Muon.Ngay_Hien_Tai << "/0" << x.Ngay_Muon.Thang_Hien_Tai << "/" << x.Ngay_Muon.Nam_Hien_Tai;
		}
	}
	else
	{
		gotoXY(10, tdy);
		cout << x.Ngay_Muon.Ngay_Hien_Tai << "/" << x.Ngay_Muon.Thang_Hien_Tai << "/" << x.Ngay_Muon.Nam_Hien_Tai;
	}


	// xuất ngày trả sách
	ngay = x.Ngay_Tra.Ngay_Hien_Tai;
	thang = x.Ngay_Tra.Thang_Hien_Tai;

	if(ngay != 0)
	{
		if(ngay <= 9 && thang <= 9)
		{
			
			gotoXY(35, tdy);
			cout << "0" << x.Ngay_Tra.Ngay_Hien_Tai << "/0" << x.Ngay_Tra.Thang_Hien_Tai << "/" << x.Ngay_Tra.Nam_Hien_Tai;
		}
		else if(ngay <= 9 || thang <= 9)
		{
			gotoXY(35, tdy);
			if(ngay <= 9)
			{
				
				cout << "0" << x.Ngay_Tra.Ngay_Hien_Tai << "/" << x.Ngay_Tra.Thang_Hien_Tai << "/" << x.Ngay_Tra.Nam_Hien_Tai;
			}
			else if(thang <= 9)
			{
				cout << x.Ngay_Tra.Ngay_Hien_Tai << "/0" << x.Ngay_Tra.Thang_Hien_Tai << "/" << x.Ngay_Tra.Nam_Hien_Tai;
			}
		}
		else
		{
			gotoXY(35, tdy);
			cout << x.Ngay_Tra.Ngay_Hien_Tai << "/" << x.Ngay_Tra.Thang_Hien_Tai << "/" << x.Ngay_Tra.Nam_Hien_Tai;
		}
	}
	else
	{
		gotoXY(35, tdy);
		cout << "00/00/0000";
	}

	gotoXY(60, tdy);
	cout << x.Trang_Thai;
}

/* CÁC HÀM HỖ TRỢ */




// hàm in khung phiếu mượn trả
void In_Khung_Phieu_Muon_Tra(int tdy)
{
	gotoXY(0, tdy);
	cout << "Ma sach";
	gotoXY(10, tdy);
	cout << "Ngay muon";
	gotoXY(35, tdy);
	cout << "Ngay tra";
	gotoXY(60, tdy);
	cout << "Trang thai";
}


// hàm in giao diện phiếu mượn trả trong file
void In_Khung_Phieu_Muon_Tra_File(ofstream &file)
{
	file << "MA SACH";
	file << "             ";
	file << "NGAY MUON";
	file << "             ";
	file << "NGAY TRA";
	file << "             ";
	file << "TRANG THAI";

}

// hàm in thông tin phiếu mượn trả ra file
void Xuat_Thong_Tin_Phieu_Muon_Tra_File(ofstream &file, PHIEUMUONTRA x)
{
	file << "\nMASACH: " << x.Ma_Sach;
	file << "\nNGAY MUON: " << x.Ngay_Muon.Ngay_Hien_Tai << "/" << x.Ngay_Muon.Thang_Hien_Tai << "/" << x.Ngay_Muon.Nam_Hien_Tai;
	file << "\nNGAY TRA: " << x.Ngay_Tra.Ngay_Hien_Tai << "/" << x.Ngay_Tra.Thang_Hien_Tai << "/" << x.Ngay_Tra.Nam_Hien_Tai;
	file << "\nTRANG THAI: " << x.Trang_Thai;
}

// hàm đọc file thông tin phiếu mượn trả
void Doc_File_Thong_Tin_Phieu_Muon_Tra(ifstream &file, PHIEUMUONTRA &x)
{
	getline(file, x.Ma_Sach, ',');
	file.seekg(1, 1);
	Doc_File_Ngay_Thang_Nam(file, x.Ngay_Muon);
	Doc_File_Ngay_Thang_Nam(file, x.Ngay_Tra);
	// có kí tự enter ở cuối dòng
	string temp;
	getline(file,temp);
	x.Trang_Thai = temp[0];
}

// hàm ghi file thông tin phiếu mợn trả
void Ghi_File_Thong_Tin_Phieu_Muon_Tra(ofstream &file, PHIEUMUONTRA x)
{
	file << x.Ma_Sach << ", ";
	Ghi_File_Ngay_Thang_Nam(file, x.Ngay_Muon);
	file << ", ";
	Ghi_File_Ngay_Thang_Nam(file, x.Ngay_Tra);
	file << ", ";
	file << x.Trang_Thai;
}