#include"CLopHoc.h"
CLopHoc::~CLopHoc()
{
	for (int i = 0; i < SoSV; i++)
		delete DanhSachSV[i];
	delete[] DanhSachSV;
}
void CLopHoc::Nhap()
{
	cout << "Nhap ma lop: ";
	cin >> MaLop;
	cout << "Nhap so sinh vien: ";
	cin >> SoSV;
	cout << "Nhap danh sach sinh vien" << endl;
	DanhSachSV = new CSinhVien*[SoSV];
	for (int i = 0; i < SoSV; i++)
	{
		cout << "\nNhap sinh vien thu " << i + 1 << endl;
		DanhSachSV[i] = new CSinhVien();
		DanhSachSV[i]->Nhap();
	}
}
void CLopHoc::Xuat()
{
	for (int i = 0; i < SoSV; i++)
	{
		cout << "\nSinh vien thu " << i + 1 << endl;
		DanhSachSV[i]->Xuat();
	}
}
int CLopHoc::DemSVNu()
{
	int d = 0;
	for (int i = 0; i < SoSV; i++)
		if (DanhSachSV[i]->LaSVNu())
			d++;
	return d;
}
int CLopHoc::DemSVNamTrongThangX(int x)
{
	int d = 0;
	for (int i = 0; i < SoSV; i++)
		if (!DanhSachSV[i]->LaSVNu() && DanhSachSV[i]->GetNTNS()->GetThang() == x)
			d++;
	return d;
}
CSinhVien* CLopHoc::TimSVLonNhat()
{
	if (SoSV <= 0)
		return NULL;
	CSinhVien* sv = DanhSachSV[0];
	for (int i = 1; i < SoSV; i++)
		if (DanhSachSV[i]->GetNTNS()->SoSanh(sv->GetNTNS()) == -1)
			sv = DanhSachSV[i];
	return sv;
}
CSinhVien* CLopHoc::TimSVNuLonNhat()
{
	if (SoSV <= 0)
		return NULL;
	CSinhVien* sv = NULL;
	int i = 0;
	for (; i < SoSV; i++)
		if (DanhSachSV[i]->LaSVNu())
		{
			sv = DanhSachSV[i];
			break;
		}
	if (sv == NULL)
		return NULL;
	for (i + 1; i < SoSV; i++)
		if (DanhSachSV[i]->LaSVNu())
			if (sv->GetNTNS()->SoSanh(DanhSachSV[i]->GetNTNS()) == 1)
				sv = DanhSachSV[i];
	return sv;
}
void CLopHoc::SapXepMSSVTangDan()
{
	for (int i = 0; i < SoSV - 1; i++)
		for (int j = i + 1; j < SoSV; j++)
			if (DanhSachSV[i]->GetMSSV() > DanhSachSV[j]->GetMSSV())
			{
				CSinhVien* sv = DanhSachSV[i];
				DanhSachSV[i] = DanhSachSV[j];
				DanhSachSV[j] = sv;
			}
}