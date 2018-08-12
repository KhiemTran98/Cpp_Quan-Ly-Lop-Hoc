#include"CDate.h"
#include<string>
#include<iostream>
using namespace std;
class CSinhVien
{
private:
	int MSSV;
	string HoTen;
	CDate* NTNS;
	bool Phai;
public:
	~CSinhVien();
	void Nhap();
	void Xuat();
	bool LaSVNu();
	CDate* GetNTNS();
	int GetMSSV();
};