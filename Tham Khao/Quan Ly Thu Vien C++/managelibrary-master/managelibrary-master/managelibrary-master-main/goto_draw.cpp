#pragma once
#include <iostream>
#include <windows.h>
using namespace std;
void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}
void draw(int a,int b,int c, int d){
	   GoTo(a,b);for (int i=a;i<=c;i++) cout << "_";
	   GoTo(a,d);for (int i=a;i<=c;i++) cout << "_";
	   for (int i=1;i<=d-b;i++) {GoTo(a-1,b+i);cout << "|" << endl;}
	   for (int i=1;i<=d-b;i++) {GoTo(c+1,b+i);cout << "|" << endl;}
}
void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
