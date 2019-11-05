#include "Thietbi.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

ThietBi::ThietBi();
{
    // cout << "Ham khoi tao thiet bi duoc goi";
    objCount++;
}

//Setter
void ThietBi::setMaSo(char maso[])
{
    strcpy(this->maSo, maso);
}
void ThietBi::setTenThietBi(char ten[])
{
    strcpy(this->tenThietBi, ten);
}
void ThietBi::setViTri(char vitri[])
{
    strcpy(this->viTri, vitri);
}
void ThietBi::setNguoiQuanLi(char quanli[])
{
    strcpy(this->nguoiQuanLi, quanli);
}
void ThietBi::setTinhTrang(char trangthai[])
{
    strcpy(this->tinhTrang, trangthai);
}
void ThietBi::setNgayNhap(char ngaynhap[])
{
    strcpy(this->ngayNhap, ngaynhap);
}

// Getter
char *ThietBi::getMaSo()
{
    return this->maSo;
}
char *ThietBi::getTenThietBi()
{
    return this->tenThietBi;
}
char *ThietBi::getViTri()
{
    return this->viTri;
}
char *ThietBi::getNguoiQuanLi()
{
    return this->nguoiQuanLi;
}
char *ThietBi::getTinhTrang()
{
    return this->tinhTrang;
}
char *ThietBi::getNgayNhap()
{
    return this->ngayNhap;
}

// OVerloading Operator
istream &operator>>(istream &in, ThietBi &thb)
{
    char maso[10], ten[20], vitri[15], quanli[20], trangthai[10], ngaynhap[15];

    // in >> (ThietBi &)thb;
    fflush(stdin);

    cout << "Nhap ma so: ";
    in.getline(maso, 10);
    cout << "Ten thiet bi: ";
    in.getline(ten, 20);
    cout << "Vi tri: ";
    in.getline(vitri, 15);
    cout << "Nguoi quan li: ";
    in.getline(quanli, 20);
    cout << "Tinh trang: ";
    in.getline(trangthai, 10);
    cout << "Ngay nhap: ";
    in.getline(ngaynhap, 15);

    thb.setMaSo(maso);
    thb.setTenThietBi(ten);
    thb.setViTri(vitri);
    thb.setNguoiQuanLi(quanli);
    thb.setTinhTrang(trangthai);
    thb.setNgayNhap(ngaynhap);
}

ostream &operator<<(ostream &out, ThietBi &thb)
{
    // out << (ThietBi &)thb;
    out << left << setw(10) << thb.getMaSo() << setw(20) << thb.getTenThietBi() << setw(10) << thb.getViTri()
        << setw(20) << thb.getNguoiQuanLi() << setw(10) << thb.getTinhTrang() << setw(15) << thb.getNgayNhap() << endl;
}

ifstream &operator>>(ifstream &in, ThietBi &thb)
{
    char maso[10], ten[20], vitri[15], quanli[20], trangthai[10], ngaynhap[15];

    // in >> (ThietBi &)thb;
    fflush(stdin);

    in.getline(maso, 10);
    in.getline(ten, 20);
    in.getline(vitri, 15);
    in.getline(quanli, 20);
    in.getline(trangthai, 10);
    in.getline(ngaynhap, 15);

    thb.setMaSo(maso);
    thb.setTenThietBi(ten);
    thb.setViTri(vitri);
    thb.setNguoiQuanLi(quanli);
    thb.setTinhTrang(trangthai);
    thb.setNgayNhap(ngaynhap);
}

ofstream &operator<<(ofstream &out, ThietBi &thb)
{
    // out << (ThietBi &)thb;
    out << left << setw(10) << thb.getMaSo() << setw(20) << thb.getTenThietBi() << setw(10) << thb.getViTri()
        << setw(20) << thb.getNguoiQuanLi() << setw(10) << thb.getTinhTrang() << setw(15) << thb.getNgayNhap() << endl;
}

// Hienthi
void ThietBi::hienThi()
{
    cout << left << setw(10) << getMaSo() << setw(20) << getTenThietBi() << setw(10) << getViTri()
         << setw(20) << getNguoiQuanLi() << setw(10) << getTinhTrang() << setw(15) << getNgayNhap() << endl;
}

ThietBi::~ThietBi()
{
    // cout << "Ham huy da duoc goi."
}

// Them, Sua, Xoa, Cap nhat, Thong ke, ...
void Thietbi::nhap()
{
    cout << "So thiet bi can nhap: ";
    cin >> numTB;

    for (int i = 0; i < numTB; i++)
    {
        cin >> thb[i];
    }

    // Ghi file BIN
    for (int i = 0; i < numTB; i++)
    {
        thb[i].ghiFile(ofs);
    }
    ofs.close();
}

void Thietbi::capNhat()
{
    cout << "Nhap vao ma so thiet bi can cap nhat:";
    // char *key;
    cin << key;
}

void Thietbi::xoa()
{
    cout << "Nhap vao ma so thiet bi can xoa";
    cin >> key;
}

void Thietbi::thongKe()
{
    int soluong = 0;   //trong file
    while (!ifs.eof()) // ?endOfFile
    {
        thb[n].docFile(ifs); //doc tuan tu
        if (!ifs.eof())
        {
            n++;
        }
    }
    cout << "\nThong ke danh sach thiet bi:" << endl;
    cout < < left << setw(10) << "Ma so" << setw(20) << "Ten thiet bi" << setw(10) << "Vi tri"
                  << setw(20) << "Nguoi quan li" << setw(10) << "Tinh trang" << setw(15) << "Ngay nhap" << endl;
    for (int i = 0; i < soluong; i++)
    {
        cout << thb[i];
    }
}

// Doc va ghi file
void ThietBi::docFile(ifstream &in)
{
    in.read(reinterpret_cast<char *>(this), sizeof(ThietBi));

    // char maso[10], ten[20], vitri[15], quanli[20], trangthai[10], ngaynhap[15];
    // fflush(stdin);

    // in.getline(maso, 10);
    // in.getline(ten, 20);
    // in.getline(vitri, 15);
    // in.getline(quanli, 20);
    // in.getline(trangthai, 10);
    // in.getline(ngaynhap, 15);

    // this->.setMaSo(maso); //no(thb) | has(thb) | this-> set | get
    // this->.setTenThietBi(ten);
    // this->.setViTri(vitri);
    // this->.setNguoiQuanLi(quanli);
    // this->.setTinhTrang(trangthai);
    // this->.setNgayNhap(ngaynhap);
}

void ThietBi::ghiFile(ofstream &ofs)
{
    ofs.write(reinterpret_cast<const char *>(this), sizeof(ThietBi));

    // ofs << this->getMaSo() << endl
    //     << this->getTenThietBi() << endl
    //     << this->getViTri() << endl
    //     << this->getNguoiQuanLi() << endl
    //     << this->getTinhTrang() << endl
    //     << this->getNgayNhap() << endl;
}