#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;


class sach;
class dausach;
class phieumuon;

class bandoc
{
   friend class phieumuon;

private:
   char *ten;
   char *ma;
   phieumuon *sachmuon[5];
   int somuon;
   static int sobandoc;
   static bandoc *cacbandoc[100];

public:
   bandoc(char *m, char *t)
   {
      ma = new char[strlen(m) + 1];
      ten = new char[strlen(t) + 1];
      strcpy(ma, m);
      strcpy(ten, t);
      somuon = 0;
   }
   ~bandoc()
   {
      delete[] ma;
      delete[] ten;
   }
   static void dangki();
   static bandoc *timbd(char *);
   phieumuon *muon(char *);
   void tra(dausach *);
   static void xoadl();
   void muon(dausach *dausach);
   static void inds();
};

class sach
{
   friend class dausach;

private:
   char *ma;
   char *ten;
   int sodausach;
   dausach **cacdausach;
   static int sosach;
   static sach *khosach[500];

public:
   sach(char *m, char *t, int n);
   ~sach();
   dausach *timchuamuon();
   static sach *timsach(char *masach);
   static dausach *timdausach(char *, int);
   static void nhapsach();
   static void xoadl();
   static void inds();
};

class phieumuon
{
   friend class bandoc;

private:
   dausach *dausach1;
   bandoc *bandoc1;

public:
   phieumuon(dausach *ds, bandoc *bd) : dausach1(ds), bandoc1(bd)
   {
   }
};

class dausach
{
   friend class phieumuon;
   friend class bandoc;
   friend class sach;

private:
   sach *sach1;
   int id;
   phieumuon *muon;

public:
   dausach(sach *right, int _id)
       : sach1(right), id(_id), muon(0)
   {
   }
   ~dausach()
   {
      if (muon)
         delete muon;
   }
   int chuamuon()
   {
      return muon == 0;
   }
   phieumuon *chomuon(bandoc *bd)
   {
      muon = new phieumuon(this, bd);
      return muon;
   }
   void tra()
   {
      delete[] muon;
      muon = 0;
   }
};

int bandoc::sobandoc = 0;

bandoc *bandoc::cacbandoc[100];

void bandoc::dangki()
{
   char ma[80];

   ofstream outfile;
   outfile.open("bandoc.txt", ios::app);
   cout << "\nMa ban doc : ";
   // cin.getline(ma, sizeof(ma));

   cin.getline(ma, 80);
   outfile << ma;

   char ten[80];
   cout << "\nTen ban doc : ";
   // cin.getline(ten, sizeof(ten));
   cin.getline(ten, 80);

   outfile << ", ";

   outfile << ten;
   outfile << "\n";

   cacbandoc[sobandoc++] = new bandoc(ma, ten);
   cout << " Ban doc "
        << "' " << ten << " '"
        << " da duoc dang ki \n ";
   outfile.close();
}

bandoc *bandoc::timbd(char *ma)
{
   for (int i = 0; i < sobandoc; i++)
      if (strcmp(ma, cacbandoc[i]->ma) == 0)
         return cacbandoc[i];
   return 0;
}

void bandoc::xoadl()
{
   for (int i = 0; i < sobandoc; i++)
      delete[] cacbandoc[i];
   sobandoc = 0;
}

phieumuon *bandoc::muon(char *masach)
{
   if (somuon == 5)
   {
      cout << "Ban da muon du 5 dau sach \n";
      return 0;
   }
   sach *sach = sach ::timsach(masach);
   if (sach == 0)
   {
      cout << "Khong co ma sach " << masach << " trong kho \n";
      return 0;
   }
   dausach *dausach = sach->timchuamuon();
   if (dausach == 0)
   {
      cout << "Sach nay da bi muon het \n";
      return 0;
   }
   phieumuon *phieu = dausach->chomuon(this);
   sachmuon[somuon++] = phieu;
   cout << "Ban da duoc dau sach so " << dausach->id << endl;
   return phieu;
}

void bandoc::muon(dausach *dausach)
{
   sachmuon[somuon++] = dausach->chomuon(this);
}

void bandoc::tra(dausach *right)
{
   for (int i = 0; i < somuon; i++)
      if (sachmuon[i]->dausach1 == right)
      {
         right->tra();
         for (int j = i + 1; j < somuon; j++)
            sachmuon[j - 1] = sachmuon[j];
         somuon--;
         cout << "Ban da tra xong sach \n";
         return;
      }
   cout << "Ban da ko muon quyen sach nay \n";
}

void bandoc::inds()
{

   for (int i = 0; i <= sobandoc; i++)
   {
      ifstream infile;
      infile.open("bandoc.txt");
      cout << "\n";
      string a;
      getline(infile, a, ',');
      string b;
      infile >> b;
      cout << "\nDanh sach ban doc la: ";
      cout << "\n"
           << a << "\t" << b;

      for (int i = 0; i <= 100; i++)
      {
         string a;
         getline(infile, a, ',');
         string b;
         infile >> b;
         cout << a << "\t" << b;
      }
      infile.close();
   }
}

int sach::sosach = 0;

sach *sach::khosach[500];

sach::sach(char *ma_, char *ten_, int n)
{
   ma = new char[strlen(ma_) + 1];
   ten = new char[strlen(ten_) + 1];
   strcpy(ma, ma_);
   strcpy(ten, ten_);
   sodausach = n;
   cacdausach = new dausach *[sodausach];
   for (int i = 0; i < sodausach; i++)
      cacdausach[i] = new dausach(this, i + 1);
}

sach::~sach()
{
   delete[] ma;
   delete[] ten;
   for (int i = 0; i < sodausach; i++)
      delete cacdausach[i];
   delete[] cacdausach;
}

dausach *sach::timchuamuon()
{
   for (int i = 0; i < sodausach; i++)
      if (cacdausach[i]->chuamuon())
         return cacdausach[i];
   return 0;
}

sach *sach::timsach(char *masach)
{
   for (int i = 0; i < sosach; i++)
      if (strcmp(khosach[i]->ma, masach) == 0)
         return khosach[i];
   return 0;
}

dausach *sach::timdausach(char *masach, int id)
{
   sach *sach1 = timsach(masach);
   if (sach1 == 0)
      return 0;
   for (int i = 0; i < sach1->sodausach; i++)
      if (sach1->cacdausach[i]->id == id)
         return sach1->cacdausach[i];
   return 0;
}

void sach::nhapsach()
{
   cin.sync();
   char ma[80];
   ofstream outfile;
   outfile.open("sach.txt", ios::app);
   outfile << "\n";
   cout << "\nMa sach :";
   cin.getline(ma, 80);
   outfile << ma;
   outfile << ", ";

   cout << "\nSo dau sach: ";
   char number[80];
   cin.getline(number, 80);
   outfile << number;
   outfile << ", ";
   
   char ten[80];
   cout << "\nTen sach : ";
   cin.getline(ten, 80);
   outfile << ten;
   int n;
   khosach[sosach++] = new sach(ma, ten, n);
   cout << "\nSach nay da duoc nhap vao !!!\n";
   outfile.close();
}

void sach::xoadl()
{
   for (int i = 0; i < sosach; i++)
      delete khosach[i];
   sosach = 0;
}

void sach::inds()
{

   for (int i = 0; i <= sosach; i++)
   {
      ifstream infile;
      infile.open("sach.txt");
      cout << "\n";

      string a;
      getline(infile, a, ',');
      string b;
      getline(infile, b, ',');
      string c;
      infile >> c;
      cout << "\nDanh sach sach la: ";
      cout << "\n"
           << a << "\t" << b << "\t" << c;
      infile >> c;
      for (int i = 0; i <= 20; i++)
      {
         string a;
         getline(infile, a, ',');
         string b;
         getline(infile, b, ',');
         string c;
         // infile >> b;
         infile >> c;
         cout << a << "\t" << b << "\t" << c;
      }

      infile.close();
   }
}

void muon()
{
   char mabd[80];
   cout << "\nMa sach :";
   cin.getline(mabd, sizeof(mabd));
   bandoc *bd = bandoc::timbd(mabd);
   if (bd == 0)
   {
      cout << "\nMa ban doc nay chua duoc dang ki \n ";
      return;
   }
   char mas[80];
   cout << "Ma sach muon: ";
   cin.getline(mas, sizeof(mas));
   bd->muon(mas);
}

void tra()
{
   char mabd[80];
   cout << "Ma ban doc : ";
   cin.getline(mabd, sizeof(mabd));
   bandoc *bd = bandoc::timbd(mabd);
   if (bd == 0)
   {
      cout << "Ma ban doc nay chua duoc dang ki \n";
      return;
   }
   char mas[80];
   cout << "Ma sach tra : ";
   cin.getline(mas, sizeof(mas));
   int id;
   cout << "Ma dau sach : ";
   cin >> id;
   dausach *ds = sach::timdausach(mas, id);
   if (ds == 0)
   {
      cout << " ko co dau sach nay \n ";
      return;
   }
   bd->tra(ds);
}


void menu()
{

   cout << "\n\n\n===== CHUONG TRINH QUAN LY THU VIEN =====\n\n";
   cout << "\n\n**** TRAN VAN QUYEN ****";
   cout << "\n Nhap lua chon cua ban: \n";
   cout << " 1. Dang ki ban doc \n";
   cout << " 2. Nhap sach \n";
   cout << " 3. Muon sach \n";
   cout << " 4. Tra sach \n";
   cout << " 5. In danh sach ban doc\n";
   cout << " 6. In danh sach sach\n";
   cout << " 7. Thoat khoi chuong trinh !!!\n";
   cout << "Moi nhap: ";
}

int main()
{
   while (1)
   {
      menu();
      int i = _getch();
      switch (i)
      {
      case '1':
      {
         bandoc::dangki();
         break;
      }
      case '2':
      {
         sach::nhapsach();
         break;
      }
      case '3':
      {
         muon();
         break;
      }
      case '4':
      {
         tra();
         break;
      }
      case '5':
      {
         bandoc::inds();

         break;
      }
      case '6':
         sach::inds();
      }

      if (i == '7')
         break;
         _getch(); 
   }
   
}
