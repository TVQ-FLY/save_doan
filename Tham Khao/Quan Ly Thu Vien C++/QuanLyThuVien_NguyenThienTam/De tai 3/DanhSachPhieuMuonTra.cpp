#include"DanhSachPhieuMuonTra.h"


void Init(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}


NODE *GetNode(PHIEUMUONTRA x)
{
	NODE *p = new NODE;
	if(p == NULL)
	{
		cout << "\nBo nho khong du cap phat. Xin kiem tra lai";
		return NULL;
		system("pause");
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void AddHead(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void AddTail(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else 
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}


void Nhap_Danh_Sach_Phieu_Muon_Tra(LIST &l)
{
	int luachon;
	do{
		clrscr();
		cout << "\n\n\t\t ---------------- MENU PHIEU MUON TRA ----------------";
		cout << "\n1. Nhap thong tin phieu muon tra";
		cout << "\n2. Thoat";
		cout << "\n\t * Note *";
		cout << "\nTrang thai: ";
		cout << "\n+ 0: Sach dang cho muon";
		cout << "\n+ 1: Sach da tra";
		cout << "\n+ 2: Sach bi mat";
		cout << "\n\n\t\t ----------------------- END ------------------------- ";

		cout << "\nNhap lua chon: \n";
		luachon = Nhap_So_Nguyen();

		if(luachon != 1 && luachon != 2)
		{
			cout << "\nLua chon khong hop le . Xin kiem tra lai";
			system("pause");
		}

		if(luachon == 1)
		{
			PHIEUMUONTRA x;
			fflush(stdin);
			string str;
			cout << "\nNhap ma sach can muon: ";
			getline(cin , str);
			x.Ma_Sach = str;

			Nhap_Thong_Tin_Phieu_Muon(x);
			NODE *p = GetNode(x);
			AddTail(l, p);
			system("pause");
		}
		else if(luachon == 2)
		{
			break;
		}
	}while((luachon != 1 && luachon != 2 && luachon != 3) || luachon != 3);
}

void Xuat_Danh_Sach_Phieu_Muon_Tra(LIST l, int &tdy)
{
	gotoXY(20, tdy);
	cout << "* DANH SACH CAC QUYEN SACH DOC GIA MUON *";
	In_Khung_Phieu_Muon_Tra(tdy += 3);
	for(NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		
		Xuat_Thong_Tin_Phieu_Muon_Tra_1(k->data, tdy += 2);
	}
}

/* CÁC HÀM HỖ TRỢ */
bool Kiem_Tra_Ma_Sach_1(LIST l, string str)
{
	for(NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		if(str == k->data.Ma_Sach)
		{
			return true;
		}
	}
	return false;
}

string Nhap_Ma_Sach(LIST l)
{
	bool KT;
	string str;
	do
	{

		fflush(stdin);
		cout << "\nNhap ma sach: ";
		getline(cin, str);
		KT = Kiem_Tra_Ma_Sach_1(l, str);
		if(KT == true)
		{
			cout << "\nMa sach da ton tai. Xin kiem tra lai he thong";
			system("pause");
		}
	}while(KT == true);
	return str;
}

// hàm in danh sách phiếu mượn trả ra file
void Xuat_Danh_Sach_Phieu_Muon_Tra_File(ofstream &file, LIST l)
{
	int i = 1;
	for(NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		file << "\n\n\t* THONG TIN QUYEN SACH MUON THU " << i++ << " *";
		Xuat_Thong_Tin_Phieu_Muon_Tra_File(file, k->data);
	}
}
