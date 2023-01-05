#ifndef _thongtinsach_
#define _thongtinsach_
#include<iostream>
using namespace std;
#include<string>
#include<string.h>
#include<cmath>
#include<conio.h>
#include"console.h"
#include<fstream>


#pragma pack(1)

struct Sach{

	string Ma_Sach;
	string Ten_Sach;
	int So_Trang;
	string Tac_Gia;
	int Nam_Xuat_Ban;
	char Trang_Thai;
	string Vi_Tri;
};
typedef struct Sach SACH;
#endif _thongtinsach_

/* HÀM XỬ LÍ CHÍNH */

void Nhap_Thong_Tin_Sach(SACH &);
void Doc_Thong_Tin_Sach_File(ifstream&, SACH &);
void Ghi_Thong_Tin_Sach_File(ofstream&, SACH );
void Nhap_Thong_Tin_Sach_1(SACH &);
void Xuat_Thong_Tin_Sach(SACH );
void Xuat_Thong_Tin_Sach_1(SACH , int);
void Xuat_Thong_Tin_Sach_2(SACH , int );

/* HÀM HỖ TRỢ */

string Nhap_Ten(string ); // Hàm nhập dữ liệu toàn kí tự . VD: họ, tên, giới tính. Kí tự bắt đầu phải là kí tự 
string Nhap_Du_Lieu_Chuoi(int , int ); // Hàm nhập dữ liệu chuỗi bình thường , kí tự số và kí tự 
void Chuan_Hoa(string &); // hàm chuẩn hóa chuỗi theo nguyên tắc: viết hoa chữ cái đầu và mỗi từ cách nhau 1 khoảng trắng 
void Chuan_Hoa_Khoang_Trang(string &); // hàm loại bỏ các khoảng trắng dư thừa
void Chuan_Hoa_In_Hoa(string &); // hàm chuẩn hóa chuỗi theo nguyên tắc in hoa tất cả các kí tự
bool Kiem_Tra_Khoang_Trang(string ); // hàm kiểm tra xem chuỗi có toàn khoảng trắng hay không
bool Kiem_Tra_Du_Lieu(string ); // hàm kiểm tra dữ liệu của chuỗi nhập vào phải là các kí tự số hoặc kí tự chữ cái. Ngược lại sai trả về false 
bool Kiem_Tra_Ki_Tu_So(char ); // hàm kiểm tra nếu là kí tự số thì trả về true. Ngược lại trả về false
int Nhap_So_Nguyen(); // hàm có tác dụng như là biến phụ cho việc nhập kiểu dữ liệu số nguyên. Chỉ cho phép người dùng nhập số nguyên
int Chuoi_Sang_So(string ); // hàm có chức năng chuyển đổi chuỗi kí tự số sang số nguyên
void In_Khung(int ); // Hàm in cấu trúc của 1 thông tin sách với tham số là tọa độ y
bool Xac_Nhan(); // Hàm xác nhận có muốn tiếp tục làm yêu cầu hiện tại hay không
bool Xac_Nhan_1(int ,int );

/* DO HOA */

string Nhap_Ten_1(int , int ); // Hàm nhập dữ liệu . VD: họ, tên, giới tính. Kí tự bắt đầu phải là kí tự 
void Nhap_Ten_2(string &, int , int , int , int &, bool &, bool &, bool &, bool &); // Hàm nhập dữ liệu . VD: họ, tên, giới tính. Toàn kí tự không có số . Đồ họa
string Nhap_Du_Lieu_Chuoi_1(int , int ); // Hàm nhập dữ liệu chuỗi bình thường , kí tự số và kí tự 
void Nhap_Du_Lieu_Chuoi_2(string &, int , int , int , int &); // Hàm nhập dữ liệu chuỗi bình thường , kí tự số và kí tự. Đồ họa
void Nhap_Du_Lieu_Chuoi_3(string &, int , int , int , int &, bool &, bool &, bool &, bool &); // đồ họa

int Nhap_So_Nguyen_1(int , int ); // hàm có tác dụng như là biến phụ cho việc nhập kiểu dữ liệu số nguyên. Chỉ cho phép người dùng nhập số nguyên
void Nhap_So_Nguyen_2(string &, int &, int, int, int , int &, bool &, bool &); // hàm nhập số nguyên 2 . Đồ họa
void Nhap_So_Nguyen_3(string &, int &, int, int, int , int &, bool &, bool &, bool &, bool &); // đồ họa
void In_Khung_1(int ); // tham số tọa độ y
void In_Khung_Them_Vi_Tri_Bat_Ki(int ); // tọa độ y
void Nhap_Thong_Tin_Sach_1(SACH &, int , int );



