#ifndef _date_
#define _date_
#include<iostream>
using namespace std;
#include<ctime>
#include<fstream>
#pragma pack(1)

struct date
{
	int Ngay_Hien_Tai;
	int Thang_Hien_Tai;
	int Nam_Hien_Tai;
};
typedef struct date DATE;

void Thoi_Gian_Thuc(DATE &); // hàm lấy thời gian thực từ hệ thống máy tính

void Nhap_Ngay_Thang_Nam(DATE &); // hàm nhập ngày tháng năm
void Doc_File_Ngay_Thang_Nam(ifstream& , DATE &);
void Ghi_File_Ngay_Thang_Nam(ofstream& , DATE x);
bool Kiem_Tra_Tinh_Hop_Le(DATE , bool &, bool &, bool &); // hàm kiểm tra tính hợp lệ của ngày tháng năm dùng cho Ngày Trả sách
bool Kiem_Tra_Tinh_Hop_Le_1(DATE , bool &, bool &, bool &); //hàm kiểm tra tính hợp lệ của ngày tháng năm sinh
bool Kiem_Tra_Nam_Nhuan(int ); // hàm kiểm tra năm nhuận



