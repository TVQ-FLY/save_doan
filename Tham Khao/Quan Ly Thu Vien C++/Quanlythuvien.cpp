#include<iostream>
#include <cstring>
#include <conio.h>
#include <iomanip>
#include <windows.h>

using namespace std;

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


class phieumuon
{
   friend class bandoc;

   private:
      dausach *dausach1;
      bandoc *bandoc1;

   public:
      phieumuon(dausach *ds, bandoc *bd) : dausach1(ds), bandoc1(bd){


      }
      
};


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

void bandoc::dangki()
{
   char ma[80];
   cout << "\nMa ban doc : ";
   cin.getline(ma, sizeof(ma));
   char ten[80];
   cout << "\nTen ban doc : ";
   cin.getline(ten, sizeof(ten));
   cacbandoc[sobandoc++] = new bandoc(ma, ten);
   cout << " Ban doc " <<"' " << ten << " '" <<" da duoc dang ki \n ";
}

void TextColor(int x)
{
     HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}





void menu()
{
   cout << "\n\n\n===== CHUONG TRINH QUAN LY THU VIEN =====\n\n";
   cout << "\n\n Nhap lua chon cua ban: \n";
   cout << " 1. Dang ki ban doc \n";
   cout << " 2. Nhap sach \n";
   cout << " 3. Muon sach \n";
   cout << " 4. Tra sach \n";
   cout << " 5. In danh sach ban doc\n";
   cout << " 6. In danh sach sach\n";
   cout << " 7. Thoat khoi chuong trinh !!!\n";
   
}

int main()
{
   TextColor(3);
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
    //   case '2':
    //   {
    //      sach::nhapsach();
    //      break;
    //   }
    //   case '3':
    //   {
    //      muon();
    //      break;
    //   }
    //   case '4':
    //   {
    //      tra();
    //      break;
    //   }
    //   case '5':
    //   {
    //      bandoc::inds();
    //      break;
    //   }
    //   case '6':
    //      sach::inds();
    //   }
      if (i == '7')
         break;
      _getch();
   }
}
