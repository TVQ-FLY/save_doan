#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void login();
void regstr();
void forgot();
int main()
{
	int ch;
	cout<<"1. Dang nhap\n2. Dang ky\n3. Quen mat khau\nEnter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			login();
			break;
		case 2:
			regstr();
			break;
		case 3:
			forgot();
			break;
		default:
			cout<<"Xin loi ! Tai khoan khong ton tai =(("<<endl;
	}
	cout<<endl;
	int x;
	cout<<"Bam nut bat ky de tiep tuc:";
	cin>>x;
	if(x)
	{
		main();
	}
	else
	{
		return 0;
	}
}
void regstr()
{
	int t=0;
	string usr,pas,u,p;
	system("cls");
	cout<<"Nhap Username:";
	cin>>usr;
	ofstream write("username.txt",ios::app); // username file created which of append type 
	ifstream read("username.txt");
	while(read>>u>>p)
	{
		if(u==usr)
		{
			t=1;
			break;
		}
	}
	if(t==1)
	{
		cout<<"Username da duoc dang ky =(("<<endl;
	}
	else
	{
		cout<<"Nhap password:";
		cin>>pas;
		write<<usr<<" "<<pas<<endl;
		cout<<"Dang ky thanh cong"<<endl;
	}
	write.close();
}
void login()
{
	int t=0;
	string usr,pas,u,p;
	cout<<"Nhap Username: ";
	cin>>usr;
	cout<<"Nhap Password: ";
	cin>>pas;
	ifstream read("username.txt"); //ifstream uses here for reading the file
	while(read>>u>>p) // while loop uses here for reading the file till end and in each iteration registered username and password store in u and p respectively
	{
		if(u==usr && p==pas)
		{
			t=1;
			break;
		}
	}
	read.close();
	if(t==1)
	{
		cout<<"Dang nhap thanh cong"<<endl;
	}
	else
	{
		cout<<"Dang nhap that bai"<<endl;
	}
}
void forgot()
{
	int ch;
	system("cls");
	cout<<"1.Tim tai khoan bang Username\n2.Tim tai khoan bang Password\n3.Quay lai Menu\n4.Nhap lua chon cua ban:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				int t=0;
				string su,u,p;
				cout<<"Nhap Username cua ban:";
				cin>>su;
				ifstream read("username.txt");
				while(read>>u>>p)
				{
					if(su==u)
					{
						t=1;
						break;
					}
				}
				read.close();
				if(t==1)
				{
					cout<<"Thanh cong ! Da tim thay tai khoan \nPassword la: "<<p<<endl;
				}
				else
				{
					cout<<"Khong tim thay tai khoan =(("<<endl;
				}
				break;
			}
		case 2:
			{
				int t=0;
				string sp,u,p;
				cout<<"Nhap vao Password cua ban:";
				cin>>sp;
				ifstream read("username.txt");
				while(read>>u>>p)
				{
					if(sp==p)
					{
						t=1;
						break;
					}
				}
				read.close();
				if(t==1)
				{
					cout<<"Thanh cong ! Da tim thay tai khoan \nUsername la: "<<u<<endl;
				}
				else
				{
					cout<<"Khong tim thay tai khoan =(("<<endl;
				}
				break;
			}
	    case 3:
		    {
		    	cout<<endl;
		    	main();
		    	break;
			}
		default:
			{
				cout<<"Lua chon sai, nham Enter de thu lai =(("<<endl;
				forgot();
			}
			
	}
}

