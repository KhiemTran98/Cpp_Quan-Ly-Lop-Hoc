#include<iostream>
#include"CDate.h"
using namespace std;
CDate::~CDate() {}
void CDate::Nhap()
{
	cout << "  Nhap ngay: ";
	cin >> d;
	cout << "  Nhap thang: ";
	cin >> m;
	cout << "  Nhap nam: ";
	cin >> y;
	if (!LaHopLe())
	{
		cout << "  NTNS khong hop le. Nhap lai" << endl;
		Nhap();
	}
}
void CDate::Xuat()
{
	cout << d << "/" << m << "/" << y;
}
bool CDate::LaHopLe()
{
	if (y < 1)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (d < 1)
		return false;
	if (d > TimSoNgayTrongThang())
		return false;
	return true;
}
int CDate::TimSoNgayTrongThang()
{
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return 30;
	if (m == 2)
		if (LaNamNhuan())
			return 29;
	return 28;
	return 31;
}
bool CDate::LaNamNhuan()
{
	if (y % 400 == 0)
		return true;
	if (y % 4 == 0 && y % 100 != 0)
		return true;
	return false;
}
int CDate::GetThang()
{
	return m;
}
int CDate::SoSanh(CDate* x)
{
	if (y < x->y)
		return -1;
	if (y > x->y)
		return 1;
	if (m < x->m)
		return -1;
	if (m > x->m)
		return 1;
	if (d < x->d)
		return -1;
	if (d > x->d)
		return 1;
	return 0;
}