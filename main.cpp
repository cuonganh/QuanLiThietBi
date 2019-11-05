#include "Thietbi.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

void menu()
{

    ThietBi tb[30];
    int numC;
    do
    {
        cout << "\nQuan li thiet bi:\n1. Them thiet bi.\n2.Cap nhat.";
        cout << "\n3. Thong ke.\n4. Xoa.\n0. Thoat.";
        cin >> inputC;

        switch (inputC)
        {
        case 0:
            break;
        case 1:
            ofstream ofs("Output.out", ios::app);
            nhap();
            ofs.close();
            break;
        case 2:
            capNhat();
            break;
        case 3:
            ifstream ifs("Output.out");
            thongKe();
            ifs.close();
            break;
        case 4:
            xoa();
            break;
        }
    } while (inputC);

}

int main(int argc, char **argv)
{
    menu();
    return 0;
}
