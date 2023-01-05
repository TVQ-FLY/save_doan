#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "data.cpp"
#include <stdlib.h>
#include "book.cpp"
#include <sstream>
#include "goto_draw.cpp"
#include "update.cpp"
#include "inkhung.cpp"
#include <algorithm>
void docfile(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach){
int t=-1;
ifstream ip("data.csv");
  string username;
  string password;
  string borroww;
  string hotenn;
  while (ip.peek()!=EOF)
{
	t++;
    getline(ip,username,',');
    getline(ip,password,',');
    getline(ip,hotenn,',');
    getline(ip,borroww,'\n');
   
	hocsinh tam; tam.setUserName(username);tam.setPassword(password);tam.hoten = hotenn;tam.borrow = borroww;	
    hs.push_back(tam);
  }
sohs = t;
ip.close();

ifstream ip2("danhsachsach.csv");
t=-1;
  while (ip2.peek()!=EOF)
{
	t++;
	book ta;
	getline(ip2,ta.code,',');
    getline(ip2,ta.bookname,',');
    getline(ip2,ta.category,',');
    getline(ip2,ta.amount,'\n');
  //  getline(ip2,ta.price,'\n');
    sach.push_back(ta);
  }
sosach = t;
ip2.close();
}
