#include"CSinhVien.h"
class CLopHoc
{
private:
	int MaLop;
	int SoSV;
	CSinhVien* *DanhSachSV;
public:
	~CLopHoc();
	void Nhap();
	void Xuat();
	int DemSVNu();
	int DemSVNamTrongThangX(int x);
	CSinhVien* TimSVLonNhat();
	CSinhVien* TimSVNuLonNhat();
	void SapXepMSSVTangDan();
};