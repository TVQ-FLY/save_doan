#ifndef _danhsachthongtindocgia_
#define _danhsachthongtindocgia_
#include"ThongTinDocGia.h"

#pragma pack(1)

struct _node{

	DOCGIA data;
	struct _node *pLeft;
	struct _node *pRight;
};
typedef struct _node _Node;

typedef _Node* Tree;


/* CÁC HÀM XỬ LÍ CHÍNH */

void Init(Tree &); // khởi tạo cây
void Insert(Tree &, DOCGIA ); // thêm node vào cây nhị phân theo mã độc giả
void Nhap_Danh_Sach_Thong_Tin_Doc_Gia(Tree &);
DOCGIA Nhap_Thong_Tin_Doc_Gia_1(Tree , int , int , bool &, bool &);
void Xuat_Danh_Sach_Thong_Tin_Doc_Gia(Tree ); // duyệt cây nhị phân: LNR
void Xuat_Danh_Sach_Thong_Tin_Doc_Gia_1(Tree , int &); // hàm xuất danh sách độc giả. Đồ họa
void Xuat_Sua_Doc_Gia(Tree , DOCGIA &, int , int );
void Dang_Ki_Doc_Gia(Tree &);
void Xuat_Danh_Sach_Thong_Tin_Doc_Gia_2(Tree );

void Xuat_Thong_Tin_Doc_Gia_Theo_Ma(Tree , int , int );
void Menu_Xoa(Tree & ); // menu làm nhiệm vụ xóa theo các tiêu chí do người dùng định nghĩa
void Menu_Sua(Tree & ); // menu làm nhiệm vụ sửa thông tin 1 quyển sách theo các tiêu chí do người dùng định nghĩa
void Menu_Tim_Kiem(Tree ); // menu làm nhiệm vụ tìm kiếm thông tin 1 quyển sách theo các tiêu chí do người dùng định nghĩa
void Menu_Xu_Li(Tree &); // hàm xử lí các chức năng

/* CÁC HÀM XÓA */
void Xoa_Theo_Ma_Doc_Gia(Tree &, int );// hàm có chức năng xóa 1 độc giả bất kì theo mã độc giả
void TimPhanTuTheMang(Tree &, Tree &); // Phần tử p đang được thế mạng cho phần tử q

void Xoa_Theo_Ten_Doc_Gia(Tree &, string ); // hàm có tác dụng xóa 1 độc giả theo tên bất kì
void Count_Ten(Tree , string , int &); // hàm có tác dụng đếm xem trong thư viện có bao nhiêu độc giả có cùng tên

void Xoa_Theo_Trang_Thai(Tree &); // hàm có tác dụng xóa tất cả các độc giả có trạng thái == 0
void Count_Trang_Thai(Tree , int &); // hàm có tác dụng đếm xem trong thư viện có bao nhiêu độc giả có cùng trạng thái = 0

/* CÁC HÀM TÌM KIẾM */
void Tim_Kiem_Ma_Doc_Gia(Tree t, int ); // hàm có chức năng tìm kiếm thông tin độc giả theo mã độc giả. Nếu tồn tại thì in ra còn không tồn tại thì không in


/* CÁC HÀM HỖ TRỢ */

/* bị lỗi trả về true */
int Nhap_Ma_Doc_Gia(Tree ); // hàm nhập mã độc giả .Cây nhị phân tìm kiếm thì mã độc giả ko được phép trùng nhau
void Kiem_Tra_Ma_Doc_Gia(Tree , int , bool &); // hàm có tác dụng duyệt xem mã độc giả có bị trùng trong cây nhị phân chưa. Nếu trùng trả về true. Ngược lại trả về false
void Kiem_Tra_Ma_Doc_Gia_In(Tree , int , bool &, int ); // kiểm tra mã độc giả nếu mã độc giả tồn tại thì gán bool = true, và in ra thông tin độc giả đó
char Kiem_Tra_Ten(Tree , string ); // hàm có tác dụng duyệt (LNR) xem tên độc giả có bị trùng trong cây nhị phân chưa. Nếu trùng trả về true. Ngược lại trả về false
void So_Luong_Doc_Gia(Tree , int &); // hàm có tác dụng trả về số lượng độc giả hiện có trong thư viện


#endif _danhsachthongtindocgia_