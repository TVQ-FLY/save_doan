#ifndef _thongtinphieumuontra_
#define _thongtinphieumuontra_
#include<iostream>
using namespace std;
#include<string>
#include"Date.h"
#include"ThongTinSach.h"
#pragma pack(1)

struct PhieuMuonTra{

	string Ma_Sach;
	DATE Ngay_Muon; // hàm lấy thời gian thực từ hệ thống máy tính khi mỗi lần độc giả mượn sách 
	DATE Ngay_Tra; // hàm nhập ngày tháng năm trả sách, kiểm tra tính hợp lệ của ngày tháng năm nhập không được nhỏ hơn ngày tháng năm tr
	char Trang_Thai;

};
typedef struct PhieuMuonTra PHIEUMUONTRA;

void Nhap_Thong_Tin_Phieu_Muon(PHIEUMUONTRA &);
void Nhap_Thong_Tin_Phieu_Tra(PHIEUMUONTRA &);
void Doc_File_Thong_Tin_Phieu_Muon_Tra(ifstream &, PHIEUMUONTRA &);
void Ghi_File_Thong_Tin_Phieu_Muon_Tra(ofstream &, PHIEUMUONTRA );
void Xuat_Thong_Tin_Phieu_Muon_Tra(PHIEUMUONTRA );
void Xuat_Thong_Tin_Phieu_Muon_Tra_File(ofstream &, PHIEUMUONTRA);
void Xuat_Thong_Tin_Phieu_Muon_Tra_1(PHIEUMUONTRA , int );

/* CÁC HÀM HỖ TRỢ */
void In_Khung_Phieu_Muon_Tra(int ); // hàm in khung phiếu mượn trả
void In_Khung_Phieu_Muon_Tra_File(ofstream& ); // hàm in khung phiếu mượn trả trong file
#endif _thongtinphieumuontra_