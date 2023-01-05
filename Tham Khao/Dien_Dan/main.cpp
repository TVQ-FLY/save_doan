#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<iomanip>
 
using namespace std;
 
int n, m1=9999, m2= 10000,m;
class Nguoi
{
      protected:
              char ht[30], dc[30],sdt[12];
      public:
             Nguoi(){}
             Nguoi(char ht1[], char dc1[], char sdt1[]);
};
//====== class Nguoi  ========
class BanDoc:private Nguoi
{
      private:
              char loai[20];
              int ma;
      public:
             BanDoc (): Nguoi(){}
             BanDoc(char ht1[], char dc1[], char sdt1[], char loai1[]):Nguoi (ht1, dc1, sdt1)
             {
                          ma = m1;
                          strcpy (loai,loai1);
             }
             void init (char *ht1,char *dc1, char *sdt1, int m1);
             friend class BangQL;
             friend istream& operator>> (istream& in, BanDoc &a);
             friend ostream& operator<< (ostream& out, const BanDoc &a);
             void result ()
             {
                  cout<<endl<<ma<<setw (20)<<ht<<setw(20)<<dc<<setw (15)<<sdt<<setw (18)<<loai;
             }
             
};
 
BanDoc dsbd[100];
 
//==========  class Sach  =========
class Sach
{
      private:
              int ms, nxb;
              char ten[30], tgia[30], nganh[30];
      public:
             Sach(){}
             Sach (char ten1[], char tgia1[], char nganh1[], int m2, int nxb1);
             void init (char *ten1, char *tgia1, char *nganh1,int m2, int nxb1);
             friend class BangQL;
             friend istream& operator>> (istream& in, Sach &a);
             friend ostream& operator<< (ostream& out, const Sach &a);
             void result ();
};
 Sach dssach[100];
 
//======= class BangQL  ===========
 
class BangQL
{
      private:
              BanDoc bandoc;
              Sach sach;
              int soluong;
      public:
             void init (BanDoc a, int masach);
             void result ()
             {
                  cout.setf(ios::left);
                  cout<<endl<<setw(20)<<bandoc.ht<<setw(20)<<sach.ten<<setw(7)<<soluong;
             }
             char* getbd ()
             {
                   return bandoc.ht;
             }
             char *getsach ()
             {
                  return sach.ten;
             }
             int slg ()
             {
                 return soluong;
             }
             int getma ()
             {
                 return sach.ms;
             }
};
 
BangQL dsBangQL [100];
 
 
//========= Dinh nghia cac phuong thuc cua  lop BanDoc ===============
 
Nguoi::Nguoi (char ht1[], char dc1[], char sdt1[])
{
             strcpy (ht, ht1); strcpy (dc, dc1); strcpy (sdt,sdt1);
}
 
 
void BanDoc::init (char *ht1, char *dc1, char *sdt1, int m1)
{
             strcpy (ht,ht1); strcpy (dc,dc1); strcpy (sdt,sdt1); ma=m1;
}
istream& operator>> (istream& in, BanDoc &a)
{
         if ( in== cin)
            {
                   cout<<endl<<"Ma ban doc: "<<++m1;
                   a.ma = m1;
                   in.ignore (1);
            }
         else
             {
                   in>>a.ma;
                   in.ignore (1);
             }
         if (in==cin)
            {
                     cout<<endl<<"Nhap ho ten ban doc: "; in.getline (a.ht,30);
            }
         else
             in.getline (a.ht,30);
         if (in==cin)
            {
                     cout<<endl<<"Nhap dia chi ban doc: "; in.getline (a.dc,30);
            }
         else
             in.getline (a.dc,30);
         if (in==cin)
            {
                     cout<<endl<<"Nhap SDT: "; in.getline (a.sdt,12);
            }
         else
             in.getline (a.sdt,12);
         if (in==cin)
            {
                     cout<<endl<<"1. Sinh vien ";
                     cout<<endl<<"2. Hoc vien cao hoc ";
                     cout<<endl<<"3. Giao vien ";
                     cout<<endl<<"Moi ban chon "; int chon; cin>>chon;
                     if (chon==1)     strcpy (a.loai, "Sinh vien ");
                     if (chon==2)     strcpy (a.loai, "Hoc vien cao hoc ");
                     if (chon==3)     strcpy (a.loai, "Giao vien ");
            }
         else
             in.getline (a.loai, 20);
         return in;
}
 
ostream& operator<< (ostream& out, const BanDoc &a)
{
         if (out==cout)
            {
                       
                       out.setf (ios::left);
                       out<<endl<<setw (8)<<a.ma<<setw (20)<<a.ht<<setw (20)<<a.dc<<setw (15)<<a.sdt<<setw(18)<<a.loai;
            }
         else
         out<<endl<<a.ma<<a.ht<<endl<<a.dc<<a.sdt<<a.loai;
         return out;
}
//...........Ham nhap them va in thong tin ban doc..........
 
void init_BD()
{
     cout<<endl<<"Nhap so luong ban doc muon them vao: "; cin>>n;
     ofstream f("BD.DAT",ios::app);
     for (int i=1; i<=n;i++)
     {
         cout<<endl<<"---------------------------";
         cout<<endl<<"Thong tin ban doc thu "<<i<<"la: "<<endl;
         cin>>dsbd[i];
         f<<dsbd[i];
     }
     f.close();
}
 
void result_BD ()
{
     int i=0;
     ifstream f ("BD.DAT");
     if (f.bad())
        cout<<endl<<"Khong the mo tap tin ";
     else
     {
         cout<<endl<<"DANH SACH BAN DOC CO TRONG FILE BD.DAT LA:  "<<endl;
         cout<<endl<<"----------------------------------------------";
         while (f>>dsbd[i])
         {
               cout<<dsbd[i];
               i++;
         }
         m+=i;
     }
     f.close();
}
//====== Dinh nghia cac phuong thuc lop Sach======
 
Sach::Sach (char ten1[], char tgia1[], char nganh1[], int m2, int nxb1)
{
           strcpy (ten,ten1); strcpy (tgia,tgia1);strcpy (nganh,nganh1);
           ms=m2; nxb=nxb1;
}
void Sach::init (char *ten1, char *tgia1, char *nganh1,int m2, int nxb1)
{
     strcpy (ten,ten1);strcpy (tgia,tgia1);strcpy (nganh,nganh1); nxb=nxb1; ms=m2;
}
 
istream& operator>> (istream& in, Sach &a)
{
       
         if (in==cin)
         {
                     cout<<endl<<"Ma sach: "<<++m2;
                     a.ms=m2;
                     in.ignore (1);
         }
         else
         {
             in>>a.ms;
             in.ignore(1);
         }
         if (in==cin)
         {
                     cout<<endl<<"Nhap ten sach: "; in.getline(a.ten,30);
         }
         else
             in.getline (a.ten,30);
         if (in==cin)
         {
                     cout<<endl<<"Nhap ten tac gia: "; in.getline (a.tgia,30);
         }
         else
             in.getline(a.tgia,30);
         if (in==cin)
         {
                      cout<<endl<<"1. Khoa hoc tu nhien ";
                      cout<<endl<<"2. Van hoa - Nghe thuat ";
                      cout<<endl<<"3. Dien tu vien thong ";
                      cout<<endl<<"4. Cong nghe thong tin ";
                      cout<<endl<<"Moi ban chon "; int chon; cin>>chon;
                      if (chon==1)     strcpy (a.nganh,"Khoa hoc tu nhien ");
                      if (chon==2)     strcpy (a.nganh,"Van hoc nghe thuat ");
                      if (chon==3)     strcpy (a.nganh,"Dien tu vien thong ");
                      if (chon==4)     strcpy (a.nganh,"Cong nghe thong tin ");
         }
         else
             in.getline (a.nganh,30);
         if (in==cin)
            {
                     cout<<endl<<"Nhap nam xuat ban: "; in>>a.nxb;
            }
         else
             in>>a.nxb;
           
         return in;
}
 
ostream& operator<< (ostream& out, const Sach &a)
{
         if (out==cout)
         {
                     
                       out.setf(ios::left);
                       out<<endl<<setw(8)<<a.ms<<setw(25)<<a.ten<<setw(17)<<a.tgia<<setw(25)<<a.nganh<<setw(9)<<a.nxb;
         }
         else
           out<<endl<<a.ms<<endl<<a.ten<<endl<<a.tgia<<endl<<a.nganh<<endl<<a.nxb;
         return out;
}
//.........Ham nhap va in them thong tin sach moi.......
 
void init_sach ()
{
     ofstream f("SACH.DAT",ios::app);
     cout<<endl<<"Nhap vao so luong dau sach muon them vao: "; cin>>m;
     for (int i=1; i<=m; i++)
     {
         cout<<endl<<"------------------------------------";
         cout<<endl<<"Thong tin dau sach thu "<<i<<" la: "<<endl;
         cin>>dssach[i];
         f<<dssach[i];
     }
     f.close();
}
 
void result_sach()
{
     int i=0;
     ifstream f("SACH.DAT");
     if (f.bad())
        cout<<endl<<"khong the mo tap tin ";
     else
     {
         cout<<endl<<"DANH SACH DAU SACH CO TRONG FILR LA: "<<endl;
         cout<<endl<<"--------------------------------------------"<<endl;
         while (f>>dssach[i])
         {
               cout<<dssach[i];
               i++;
         }
         m+=i;
     }
     f.close();
}
// === Dinh nghia cac phuong thuc cua lop BangQL=======
 
 
//=========== Ham chinh ================
 
int main()
 
{
    while (1)
    {
          system ("cls");
          cout<<endl<<"1. Nhap them dau sach moi. In ra danh sach sach co trong file ";
          cout<<endl<<"2. Nhap them ban doc moi. In ra danh sach ban doc co trong file ";
          cout<<endl<<"0. Thoat ";
          cout<<endl<<"Moi ban chon "; int chon; cin>>chon;
          if (chon==0)     break;
          switch(chon)
          {
                      case 1: {
                               init_sach();
                               result_sach();
                               break;
                               }
                      case 2:{
                              init_BD();
                              result_BD();
                              break;
                              }
          }
          getch();
    }
    getch();
}