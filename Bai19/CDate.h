class CDate
{
private:
	int d, m, y;
public:
	~CDate();
	void Nhap();
	void Xuat();
	bool LaHopLe();
	int TimSoNgayTrongThang();
	bool LaNamNhuan();
	int GetThang();
	int SoSanh(CDate* x);
};