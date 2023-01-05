#include<iostream>
using namespace std;
#include"XuLi.h"
#include<string.h>
#include<conio.h>


int main()
{
	// các biến struct
	Tree t;
	Init(t);
	LIST l;
	LISTSACH sach;
	sach.size = 0;

	// file đọc và ghi dữ liệu
	ifstream FileIn;
	ofstream FileOut;

	Doc_File(FileIn, t, l, sach);
	system("color 3e");
	Menu(t, l, sach);
	//Menu_Xu_Li(t, l, sach);
	Ghi_File(FileOut, t, l, sach);


	cout << "\n\n\n\n";
	system("pause");
	return 0;
}

