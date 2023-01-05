#include"DanhSachThongTinSach.h"
#include"DanhSachPhieuMuonTra.h"
#include"DanhSachThongTinDocGia.h"


void Xuat(Tree , int &);
void Xuat_Danh_Sach_Doc_Gia(Tree );
void Nhap(Tree &, int );



/*                                               CÁC HÀM CHỨC NĂNG CHÍNH CỦA CHƯƠNG TRÌNH                                                        */

void Quan_Li_Sach(LIST &, LISTSACH &, Tree &, int , int ); // hàm có chức năng quản lí sách
void Quan_Li_Doc_Gia(LIST &, LISTSACH &, Tree &, int , int ); // hàm có chức năng quản lí độc giả
void Quan_Li_Thong_Ke(LIST &, LISTSACH &, Tree &, int , int ); // hàm có chức năng quản lí thống kê
void Muon_Sach(LIST &, Tree &, LISTSACH &); // hàm có chức năng cho 1 độc giả mượn sách khi nhập mã độc giả và mã sách
void Tra_Sach(LIST& , Tree &, LISTSACH &); // hàm có chức năng nhập mã độc giả và mã sách cần trả
void Liet_Ke_Sach_Doc_Gia_Dang_Muon(LIST , Tree , LISTSACH ); // hàm có tác dụng liệt kê các quyển sách mà 1 độc giả đang mượn
void Top_10_Sach_Muon_Nhieu_Nhat(ofstream& , Tree , LISTSACH, int ); // hàm có tác dụng in ra 10 quyển sách có số lượt mượn nhiều nhất
void Top_10_Sach_Muon_Nhieu_Nhat_Console(Tree , LISTSACH, int ); // hàm in ra console

/* XÓA THÔNG TIN ĐỘC GIẢ */
void Xoa_Doc_Gia(Tree &); // hàm có tác dụng xóa thông tin 1 độc giả theo mã độc giả
void Tim_Kiem_Thong_Tin_Doc_Gia(LIST , Tree , LISTSACH );


/* XÓA THÔNG TIN SÁCH */
void Xoa_Sach(LISTSACH &); // hàm có chức năng xóa thông tin 1 quyển sách theo mã sách. Trạng thái = 0 <=> chưa có độc giả mượn 


/* SỬA THÔNG TIN ĐỘC GIẢ */
void Sua_Doc_Gia(Tree &);
void Thay_Doi_Thong_Tin_Doc_Gia(Tree &, DOCGIA , int ); // hàm có tác dụng thay đổi thông tin độc giả khi thực hiện chức năng sửa
void Lay_Thong_Tin_Doc_Gia(Tree , DOCGIA &, int ); // hàm có tác dụng chuyển toàn bộ dữ liệu của độc giả A sang cho độc giả B


/* SỬA THÔNG TIN SÁCH */
void Sua_Thong_Tin_Sach(LISTSACH &, Tree &); // hàm có chức năng cho phép sửa thông tin 1 quyển sách
SACH Lay_Thong_Tin_Sach(LISTSACH , string ); // hàm có tác dụng lấy thông tin 1 quyển sách dựa vào mã sách
void Thay_Doi_Thong_Tin_Sach(LISTSACH &, SACH , string );
void Thay_Doi_Thong_Tin_Sach_Doc_Gia_Muon(Tree &, SACH , string );


/* DANH SÁCH ĐỘC GIẢ MƯỢN SÁCH QUÁ HẠN GIẢM DẦN THEO THỜI GIAN QUÁ HẠN */
void Danh_Sach_Doc_Gia_Qua_Han_Giam_Dan_File(Tree , LIST); // hàm có tác dụng in ra những độc giả có thời gian mượn sách quá hạn giảm dần theo số ngày quá hạn
void Danh_Sach_Doc_Gia_Qua_Han_Giam_Dan(Tree , LIST); // hàm có tác dụng in danh sách độc giả quá hạn giảm dần ra console

/* CÁC MỤC TRONG THƯ VIỆN */
void Xu_Li_Sua_Thong_Tin_Doc_Gia(Tree);
void Menu(Tree &, LIST &, LISTSACH &);
void Khung_Quan_Li_Sach(int , int );
void Khung_Quan_Li_Doc_Gia(int , int );
void Khung_Quan_Li_Thong_Ke(int , int );
void Khung_Thu_Vien(int , int );
void Khung_1(int , int );
void Khung_2(int , int );
void Khung_3(int , int );








/*                                               CÁC HÀM HỖ TRỢ CÁC HÀM CHỨC NĂNG CHÍNH                                                              */

void Nhap_Ngay_Tra_Sach(DATE &, string &, int , int , int , int, bool &, bool &, bool &, bool &, bool &); // hàm có tác dụng nhập ngày tháng năm trả sách
void In_Khung_Tra_Sach(int ); // tọa độ y
void Tim_Doc_Gia_Muon(Tree &, LISTSACH &, int , string ); // hàm có chức năng tìm độc giả trong danh sách độc giả và thêm quyển sách đó vào danh sách mượn trả của độc giả tương ứng
void In_Khung_Muon_Sach(int ); // tọa độ y. In giao diện đồ họa cho chức năng mượn sách
void Menu_Xu_Li(Tree &, LIST &, LISTSACH &); // Hàm có chức năng chính là xử lí các chức năng của thư viện
bool Xac_Nhan_2(int , int ); // tọa độ x,  y . Xuất cho người dùng thông báo
bool Xac_Nhan_3(int  , int ); // tọa độ x, y. Xuất cho người dùng thông báo . Bạn có muốn tiếp tục không
int Kiem_Tra_Doc_Gia(Tree , LIST , int ); // hàm trả về số sách mà 1 độc giả đang mượn
int So_Luong_Sach_Qua_Han_Muon(Tree , LIST , LISTSACH , int); // hàm trả về số lượng sách mượn quá hạn
bool Kiem_Tra_Sach_Muon_Qua_Han(Tree , LIST , int , string ); // hàm kiểm tra ngày trả sách có quá hạn 15 ngày không
void Cap_Nhat_Trang_Thai_Doc_Gia_Muon_Sach(Tree &, LIST , LISTSACH , int ); // nếu 1 độc giả đủ điều kiện mượn sách thì trả về true. Ngược lại trả về false
bool Kiem_Tra_Dieu_Kien_Sach(LISTSACH , string ); // hàm kiểm tra điều kiện 1 quyển sách. Nếu sách chưa cho mượn thì trả về true. Ngược lại trả về false
void Kiem_Tra_Trang_Thai_Doc_Gia(Tree , int , bool& ); // hàm kiểm tra trạng thái độc giả. Nếu trạng thái = 1 <=> cho mượn tiếp. Ngược lại thì không cho mượn 
// hàm có tác dụng cập nhật lại trạng thái và ngày trả quyển sách trong danh sách mượn trả của 1 độc giả sau khi đem trả <=> trạng thái = 1
void Cap_Nhat_Ngay_Trang_Thai_Tra_Sach(Tree &, LIST &, LISTSACH &, DATE, string , int ); 
void Cap_Nhat_Trang_Thai_Tra_Sach(LISTSACH &, string ); // hàm cập nhật lại trạng thái sách sau khi 1 độc giả đem trả <=> trạng thái = 0
void Cap_Nhat_Trang_Thai_Muon_Sach(LISTSACH &, string ); // hàm cập nhật lại trạng thái sách sau khi quyển sách đó được độc giả mượn <=> trạng thái = 1
// hàm kiểm tra xem quyển sách của độc giả đem trả có tồn tài trong danh sách mượn trả không , và kiểm tra xem quyển sách đó đã trả chưa
void Kiem_Tra_Ma_Sach_Danh_Sach_Muon_Tra_Doc_Gia(Tree , LIST , string , int , bool &, bool &);
void Cap_Phat_Lai_Bo_Nho_1(int *&, int , int ); // hàm cấp phát lại bộ nhớ cho mảng tuyến tính số nguyên
 
template<class T>
void Hoan_Vi(T &, T &);// hàm hoán vị
void Sap_Xep(DOCGIA *&, int *& ,int ); // hàm sắp xếp câu 4
void Sap_Xep_1(LISTSACH &, int *&, int ); // hàm sắp xếp câu 5  

void In_Khung_Liet_Ke(int ); // hàm in giao diện khung liệt kê
void Liet_Ke_Sach(LIST , Tree , int , int &); // hàm có tác dụng liệt kê các quyển sách mà độc giả đang mượn
void Liet_Ke_Sach_1(LIST , Tree, int , int &); // hàm có tác dụng liệt kê các quyển sách mà độc giả đã và đang mượn
int So_Ngay_Qua_Han(DATE , DATE ); // tham số đầu tiên là ngày mượn, tham số thứ 2 là ngày trả.Hàm có tác dụng tính độ chênh lệch giữa 2 mốc thời gian
void Temp(Tree , Tree &); // hàm có chức năng lấy những độc giả mượn sách quá hạn từ danh sách liên kết chính bỏ sang danh sách liên kết tạm
int Tong_Ngay_Qua_Han(LIST ); // hàm có tác dụng tính tổng ngày quá hạn của 1 độc giả từ danh sách mượn trả
void Xuat_Ngay_Qua_Han(Tree );
void Doc_Gia_Muon_Sach_Qua_Han(Tree , DOCGIA *&, int *&, int &, LIST ); // hàm có tác dụng kiểm tra xem độc giả có mượn sách quá hạn 15 ngày hay không
void In_Thong_Tin_File(ofstream &, DOCGIA );
void In_Thong_Tin(DOCGIA , int , int &);

void Duyet_Doc_Gia_Muon_Sach(Tree , LISTSACH , int *&);




/*                                              LƯU DỮ LIỆU VÀO FILE VÀ ĐỌC LÊN KHI MỞ CHƯƠNG TRÌNH                                                  */

// hàm có tác dụng đọc file dữ liệu của danh sách sách và danh sách độc giả
void Doc_File(ifstream& , Tree &, LIST &, LISTSACH &);
void Ghi_File(ofstream& , Tree , LIST , LISTSACH );




 
/*                                                     ĐỌC - GHI FILE DANH SÁCH ĐỘC GIẢ                                                              */
 
// hàm có tác dụng đọc thông tin dữ liệu độc giả từ file
void Doc_File_Danh_Sach_Doc_Gia(ifstream& , Tree &, LIST &, LISTSACH &);
// hàm có tác dụng ghi dữ liệu thông tin lên file
void Ghi_File_Danh_Sach_Doc_Gia(ofstream& , Tree , LIST );
// hàm có tác dụng tìm độc giả tương ứng trong cây nhị phân và đưa danh sách các quyển sách mượn trả vào độc giả đó
void Tim_Doc_Gia_Muon_Sach_File(ifstream &, Tree &, LISTSACH & , int , int);
// đưa dữ liệu các quyển sách mà độc giả tương ứng đã và đang mượn vào danh sách mượn trả. đọc file
void Muon_Sach_2(PHIEUMUONTRA , LIST &, LISTSACH &, string );
// hàm có tác dụng trả về số lượng sách mà 1 độc giả đã và đang mượn
int So_Luong_Danh_Sach_Muon_Tra(Tree , LIST , int );



/*                                                      ĐỌC - GHI FILE DANH SÁCH SÁCH                                                              */

// hàm có tác dụng đọc dữ liệu thông tin sách từ file 
void Doc_Danh_Sach_Thong_Tin_Sach_File(ifstream& , LISTSACH &);
// hàm có tác dụng ghi dữ liệu thông tin lên file
void Ghi_Danh_Sach_Thong_Tin_Sach_File(ofstream&, LISTSACH );