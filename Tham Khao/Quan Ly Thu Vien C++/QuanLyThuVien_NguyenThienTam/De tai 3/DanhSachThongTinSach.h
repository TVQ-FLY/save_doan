#ifndef _danhsachthongtinsach_
#define _danhsachthongtinsach_
#include"ThongTinSach.h"

struct ListSach{

	SACH *LIST; // con trỏ quản lí các quyển sách của thư viện
	int size; // kích thước của mảng

};
typedef struct ListSach LISTSACH;

/* CÁC HÀM XỬ LÍ CHÍNH */

void Menu_Xoa(LISTSACH & ); // menu làm nhiệm vụ xóa theo các tiêu chí do người dùng định nghĩa
void Menu_Sua(LISTSACH & ); // menu làm nhiệm vụ sửa thông tin 1 quyển sách theo các tiêu chí do người dùng định nghĩa
void Menu_Tim_Kiem(LISTSACH ); // menu làm nhiệm vụ tìm kiếm thông tin 1 quyển sách theo các tiêu chí do người dùng định nghĩa
void Menu_Xu_Li(LISTSACH &); // hàm xử lí các chức năng
void Cap_Nhat_Sach(LISTSACH &);
void Them_Vao_Vi_Tri_Bat_Ki(LISTSACH &);

SACH Nhap_Thong_Tin_Sach_2(LISTSACH , int , int , bool &, bool &); // nhập thông tin sách 2 
SACH Nhap_Thong_Tin_Sach_3(LISTSACH , int , int , bool &, bool &, int &); // nhập thông tin sách 3. Thêm sách vào vị trí bất kì trong thư viện

void Nhap_Danh_Sach_Thong_Tin_Sach(LISTSACH &); // Hàm thêm danh sách sách
void Them_Vi_Tri_Bat_Ki(LISTSACH &, int ,SACH ); // Hàm thêm 1 quyển sách mới vào vị trí bất kì
void Xoa_Vi_Tri_Bat_Ki(LISTSACH &, int ); // Hàm xóa sách tại 1 vị trí bất kì
void Xoa_Theo_Ma_Sach(LISTSACH &); // hàm xóa dựa vào mã sách 
void Xoa_Theo_Ten_Sach(LISTSACH &); // hàm xóa dựa vào tên sách 
void Xoa_Theo_Trang_Thai(LISTSACH &); // hàm xóa dựa vào trạng thái

void Tim_Kiem_Theo_Ma_Sach(LISTSACH ); // hàm tìm kiếm theo mã sách
void Tim_Kiem_Theo_Ten_Sach(LISTSACH ); // hàm tìm kiếm theo tên sách
void Tim_Kiem_Theo_Tac_Gia(LISTSACH ); // hàm tìm kiếm theo tên tác giả

void Sua_Sach(); // Hàm sửa thông tin 1 quyển sách tại vị trí bất kì 
void Xuat_Danh_Sach_Thong_Tin_Sach(LISTSACH ); // Hàm xuất danh sách sách 



/* CÁC HÀM HỖ TRỢ */

void Cap_Phat_Lai_Bo_Nho(LISTSACH &, int , int ); // Hàm cấp phát lại kích thước vùng nhớ cho con trỏ
bool Kiem_Tra_Ma_Sach(LISTSACH , string ); // Hàm kiểm tra mã sách vừa nhập có tồn tại hay chưa. Nếu tồn tại trả về true
string Nhap_Ma_Sach(LISTSACH ); // Hàm nhập mã sách 



#endif _danhsachthongtinsach_
