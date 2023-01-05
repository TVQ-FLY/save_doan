#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

using namespace std;

class book
{

  int book_no;
  char name[30];
  char nxb[50];

public:
  void main_menu();     // to dispay the main menu
  void add();           // to book a room
  void display();       // to display the customer record
  void showbook();      // to display alloted showbook
  void edit();          // to edit the customer record
  int check(int);       // to check room status
  void modify(int);     // to modify the record
  void delete_rec(int); // to delete the record
  void bill(int);       // for the bill of a record
};

void book::main_menu()
{

  int choice;
  while (choice != 5)
  {

    system("cls");
    cout << "\n\t\t\t\t*************************";
    cout << "\n\t\t\t\t Khach San Di Dau Cung Duoc ";
    cout << "\n\t\t\t\t      * Menu Chinh *";
    cout << "\n\t\t\t\t*************************";
    cout << "\n\n\n\t\t\t1.Them Sach";
    cout << "\n\t\t\t2.Kiem Tra Sach";
    cout << "\n\t\t\t3.Danh sach Sach";
    cout << "\n\t\t\t4.Doi, Tra Sach";
    cout << "\n\t\t\t5.Dong Ung Dung";
    cout << "\n\n\t\t\tNhap Hanh Dong Cua Ban: ";
    cin >> choice;

    switch (choice)
    {

    case 1:
      add();
      break;

    case 2:
      display();
      break;

    case 3:
      showbook();
      break;

    case 4:
      edit();
      break;

    case 5:
      break;

      // default:
      // {

      // cout<<"\n\n\t\t\tWrong choice.....!!!";
      // cout<<"\n\t\t\tPress any key to   continue....!!";
      // getch();

      // }
    }
  }
}
void book::add()
{

  system("cls");
  int r, flag;
  ofstream fout("Record.txt", ios::app);

  cout << "\n\t\t\t\t  Nhap Thong Tin Sach";
  cout << "\n\t\t\t\t      * Menu Them Sach *";
  cout << "\n ----------------------";

  cout << "\n Nhap ID sach :- " << endl;
  cin >> r;

  flag = check(r);

  if (flag)
    cout << "\n Trung roi";

  else
  {

    book_no = r;
    cout << " Ten sach: ";
    cin >> name;
    cout << " NhaXB: ";
    cin >> nxb;

    fout.write((char *)this, sizeof(book));
    cout << "\n Da them sach...!!!";
  }

  cout << "\n Press any key to continue.....!!";

  getch();
  fout.close();
}

void book::display()
{

  system("cls");

  ifstream fin("Record.txt", ios::in);
  int r, flag;

  cout << "\n Nhap ID sach :- " << endl;
  cin >> r;

  while (true)
  {

    fin.read((char *)this, sizeof(book));
    if (fin.eof() || fin.fail())
    {
      break;
    }
    if (book_no == r)
    {

      system("cls");
      cout << "\n Thong tin sach:";
      cout << "\n ----------------";
      cout << "\n\n ID sach: " << book_no;
      cout << "\n Ten sach: " << name;
      cout << "\n NXB: " << nxb;
      flag = 1;
      break;
    }
  }

  if (flag == 0)
    cout << "\n ID sach khong ton tai....!!";
  cout << "\n\n Press any key to continue....!!";

  getch();
  fin.close();
}

void book::showbook()
{

  system("cls");

  ifstream fin("Record.txt", ios::in);
  cout << "\n\t\t\t    LIST BOOK!!!!";
  cout << "\n\t\t\t    ----------------------";
  cout << "\n\n ID Sach\tTen sach\tNXB\n";

  while (true)
  {

    fin.read((char *)this, sizeof(book));
    if (fin.eof() || fin.fail())
    {
      break;
    }
    cout << "\n\n " << book_no << "\t\t" << name;
    cout << "\t\t" << nxb;
  }

  cout << "\n\n\n\t\t\tPress any key to continue.....!!";
  getch();
  fin.close();
}

void book::edit()
{

  system("cls");

  int choice, r;
  cout << "\n Menu Doi, Tra Phong";
  cout << "\n ---------";
  cout << "\n\n 1.Edit";
  cout << "\n 2.Delete";
  cout << "\n Nhap Hanh Dong Cua Ban: ";

  cin >> choice;
  system("cls");

  cout << "\n Nhap ID sach: ";
  cin >> r;

  switch (choice)
  {

  case 1:
    modify(r);
    break;

  case 2:
    delete_rec(r);
    break;

    break;

  default:
    cout << "\n Wrong Choice.....!!";
  }
  cout << "\n Press any key to continue....!!!";

  getch();
}

int book::check(int r)
{

  int flag = 0;

  ifstream fin("Record.txt", ios::in);

  while (true)
  {

    fin.read((char *)this, sizeof(book));
    if (fin.eof() || fin.fail())
    {
      break;
    }
    if (book_no == r)
    {

      flag = 1;
      break;
    }
  }

  fin.close();
  return (flag);
}

void book::modify(int r)
{

  long pos, flag = 0;

  fstream file("Record.txt", ios::in | ios::out | ios::binary);

  while (true)
  {
    pos = file.tellg();

    file.read((char *)this, sizeof(book));
    if (file.eof() || file.fail())
    {
      break;
    }

    if (book_no == r)
    {

      cout << "\n Nhap Thong Tin Moi";
      cout << "\n -----------------";
      cout << "\n Ten sach: ";
      cin >> name;

      cout << " NXB: ";
      cin >> nxb;
      file.seekg(pos);
      file.write((char *)this, sizeof(book));
      cout << "\n Thong Tin Da Duoc Sua Doi....!!";
      flag = 1;
      break;
    }
  }

  if (flag == 0)
    cout << "\n Khong ton tai ID !!";
  file.close();
}

void book::delete_rec(int r)
{

  int flag = 0;
  char ch;
  ifstream fin("Record.txt", ios::in);
  ofstream fout("temp.txt", ios::out);

  while (true)
  {

    fin.read((char *)this, sizeof(book));
    if (fin.eof() || fin.fail())
    {
      break;
    }

    if (book_no == r)

    {

      cout << "\n Ten sach: " << name;
      cout << "\n NXB: " << nxb;
      cout << "\n\n Ban Co Muon Xoa Thong Tin Khong?(y/n): ";
      cin >> ch;

      if (ch == 'n')
        fout.write((char *)this, sizeof(book));
      flag = 1;
    }

    else
      fout.write((char *)this, sizeof(book));
  }

  fin.close();
  fout.close();

  if (flag == 0)
    cout << "\n Khong ton tai ID !!";

  else
  {

    remove("Record.txt");
    rename("temp.txt", "Record.txt");
  }
}

void book::bill(int r)
{

  book h1;
  ifstream f1;
  f1.open("record.txt", ios::in | ios::binary);

  if (!f1)
    cout << "cannot open";

  else
  {

    f1.read((char *)&h1, sizeof(book));
    while (f1)

    {

      f1.read((char *)&h1, sizeof(book));
    }

    if (h1.book_no == r)
    {

      if (h1.book_no >= 1 && h1.book_no <= 30)
        cout << "Tien Phong = 2000";

      else if (h1.book_no >= 35 && h1.book_no <= 45)
        cout << "Tien Phong = 5000";

      else
        cout << "Tien Phong = 7000";
    }

    else
    {
      cout << "Khong Tim Thay Phong";
    }
  }

  f1.close();
  getch();
}

int main()
{

  book h;

  system("cls");

  cout << "\n\t\t\t**********************************";
  cout << "\n\t\t\t* Dung pham *";
  cout << "\n\t\t\t**********************************";
  cout << "\n\n\n\n\n\n\n\t\t\tNhan Phim Bat Ky De Vao App....!!";

  getch();

  h.main_menu();
  return 0;
}
