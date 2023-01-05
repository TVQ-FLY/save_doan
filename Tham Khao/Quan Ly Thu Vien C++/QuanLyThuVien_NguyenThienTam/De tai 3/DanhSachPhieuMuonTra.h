#ifndef _danhsachphieumuontra_
#define _danhsachphieumuontra_
#include"ThongTinPhieuMuonTra.h"
#include<fstream>

// Khai báo cấu trúc danh sách liên kết đơn thông tin của phiếu mượn trả
struct Node{

	PHIEUMUONTRA data;
	struct Node *pNext;
};
typedef struct Node NODE;

struct List{

	NODE *pTail;
	NODE *pHead;
};
typedef struct List LIST;

void Init(LIST &); // hàm khởi tạo danh sách liên kết đơn

NODE *GetNode(PHIEUMUONTRA ); // hàm tạo 1 node mới

void AddHead(LIST &, NODE *); // hàm thêm vào đầu danh sách

void AddTail(LIST &, NODE *); // hàm thêm vào cuối danh sách
 
 
void Nhap_Danh_Sach_Phieu_Muon_Tra(LIST &); // hàm nhập danh sách phiếu mượn trả
void Nhap_Danh_Sach_Phieu_Muon_Tra_1(LIST &);
void Xuat_Danh_Sach_Phieu_Muon_Tra(LIST , int &); // hàm xuất danh sách các quyển sách mà 1 độc giả đang mượn
void Xuat_Danh_Sach_Phieu_Muon_Tra_File(ofstream& , LIST );
bool Kiem_Tra_Ma_Sach_1(LIST , string ); // hàm kiểm tra nếu trong danh sách mượn trả của độc giả đã tồn tại mã sách muốn mượn thì không hợp lệ  
string Nhap_Ma_Sach(LIST); // hàm nhập mã sách cần mượn

/* CÁC HÀM HỖ TRỢ */


#endif _danhsachphieumuontra_
