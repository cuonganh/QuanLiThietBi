#indef THIETBI_H
#define THIETBI_H
#include <iostream>
#include <fstream>

using namespace std;

class ThietBi
{
private:
    char maSo[10], tenThietBi[20], viTri[15], nguoiQuanLi[20], tinhTrang[10], ngayNhap[15];

public:
    static int objCount = 0, numTB = 0;
    char key;
    ThietBi();

    void setMaSo(char *);
    void setTenThietBi(char *);
    void setViTri(char *);
    void setNguoiQuanLi(char *);
    void setTinhTrang(char *);
    void setNgayNhap(char *);

    char *getMaSo();
    char *getTenThietBi();
    char *getViTri();
    char *getNguoiQuanLi();
    char *getTinhTrang();
    char *getNgayNhap();

    friend istream &operator>>(istream &, ThietBi &);
    friend ostream &operator<<(ostream &, ThietBi &);
    friend ifstream &operator>>(ifstream &, ThietBi &);
    friend ofstream &operator<<(ofstream &, ThietBi &);

    void docFile(istream &);
    void ghiFile(ofstream &);

    void nhap();
    void capNhat();
    void thongKe();
    void xoa();

    void hienThi();

    ~ThietBi();
};

#endif