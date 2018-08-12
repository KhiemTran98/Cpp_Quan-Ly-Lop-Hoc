#include<conio.h>
#include"CLopHoc.h"
void main()
{
	CLopHoc* x = new CLopHoc();

	cout << "Nhap thong tin lop hoc" << endl;
	x->Nhap();
	cout << "\nThong tin lop hoc" << endl;
	x->Xuat();

	cout << "\nSo SV nu: " << x->DemSVNu();

	int thang;
	cout << "\nNhap thang SV nam can tim: ";
	cin >> thang;
	cout << "So SV nam sinh thang " << thang << ": " << x->DemSVNamTrongThangX(thang) << endl;
	
	CSinhVien* svLonNhat = x->TimSVLonNhat();
	if (svLonNhat == NULL)
		cout << "\nKhong co SV lon nhat";
	else
	{
		cout << "\nSV lon nhat" << endl;
		svLonNhat->Xuat();
	}
	
	CSinhVien* svNuLonNhat = x->TimSVNuLonNhat();
	
	if (svNuLonNhat == NULL)
		cout << "\nKhong co SV nu lon nhat";
	else
	{
		cout << "\nSV nu lon nhat" << endl;
		svNuLonNhat->Xuat();
	}

	cout << "\nSap xep MSSV tang dan" << endl;
	x->SapXepMSSVTangDan();
	x->Xuat();

	delete x;

	_getch();
}