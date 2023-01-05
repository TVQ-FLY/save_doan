#ifndef _thongtindocgia_
#define _thongtindocgia_
#include"DanhSachPhieuMuonTra.h"
#include"ThongTinSach.h"
#include"Date.h"

#pragma pack(1)

struct DocGia{

	int Ma_Doc_Gia;
	string Ho;
	string Ten;
	DATE ngaysinh;
	string Phai;
	bool Trang_Thai;// Trạng thái mặc định là độc giả có thể mượn sách <=> true
	LIST l; // con trỏ trỏ đến danh sách mượn trả
	
};
typedef struct DocGia DOCGIA;




#endif _thongtindocgia_

void Nhap_Thong_Tin_Doc_Gia(DOCGIA &);
void Xuat_Thong_Tin_Doc_Gia(DOCGIA );
void Xuat_Thong_Tin_Doc_Gia_File(ofstream& , DOCGIA );
void Doc_File_Thong_Tin_Doc_Gia(ifstream &, DOCGIA &);
void Ghi_File_Thong_Tin_Doc_Gia(ofstream &, DOCGIA );
void Xuat_Thong_Tin_Doc_Gia_1(DOCGIA , int );
void Xuat_Thong_Tin_Sua_Doc_Gia(DOCGIA , int );

/* HÀM HỖ TRỢ */
void In_Khung_Doc_Gia(int ); // hàm có tác dụng in ra khung độc giả. Đồ họa
void In_Khung_Xuat(int );
void Tach_Ngay_Thang_Nam(string , int &, int &, int &);
void Nhap_Ngay_Sinh(DATE &, string &, int , int , int , int , bool &, bool &, bool &, bool &, bool &); // hàm nhập ngày sinh
