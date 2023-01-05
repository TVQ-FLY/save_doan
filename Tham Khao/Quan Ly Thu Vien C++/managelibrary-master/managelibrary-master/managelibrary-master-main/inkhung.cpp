#pragma once
#include <iostream>
void inkhung()
{

	cout << "_________________________________________________________________________" << endl;
	cout << setw(2) << left << "|";
	SetColor(0, 11);
	cout << setw(8) << left << "Ma sach";
	SetColor(0, 7);
	cout << setw(11) << left << "|";
	SetColor(0, 11);
	cout << setw(33) << left << "Ten sach";
	SetColor(0, 7);
	cout << setw(5) << left << "|";
	SetColor(0, 11);
	cout << setw(13) << left << "The loai";
	SetColor(0, 7);
	cout << "|" << endl;

	SetColor(0, 7);
	cout << "_________________________________________________________________________" << endl;
}
