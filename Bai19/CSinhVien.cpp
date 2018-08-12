#include"CSinhVien.h"
CSinhVien::~CSinhVien()
{
	delete NTNS;
}
void CSinhVien::Nhap()
{
	cout << " Nhap MSSV: ";
	cin >> MSSV;
	cout << " Nhap ho ten: ";
	cin.ignore();
	getline(cin, HoTen);
	cout << " Nhap NTNS" << endl;
	NTNS = new CDate();
	NTNS->Nhap();
	cout << " Nhap phai (0: Nu | 1: Nam): ";
	cin >> Phai;
}
void CSinhVien::Xuat()
{
	cout << " MSSV: " << MSSV << endl;
	cout << " Ho ten: " << HoTen << endl;
	cout << " NTNS: ";
	NTNS->Xuat();
	cout << endl;
	cout << " Phai: ";
	if (Phai == 0)
		cout << "Nu" << endl;
	else
		cout << "Nam" << endl;
}
bool CSinhVien::LaSVNu()
{
	if (Phai)
		return false;
	return true;
}
CDate* CSinhVien::GetNTNS()
{
	return NTNS;
}
int CSinhVien::GetMSSV()
{
	return MSSV;
}