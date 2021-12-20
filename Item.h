#pragma once
#include <iostream>
#include <string>
using namespace std;

enum loai { banphim, chuot, manhinh };
enum bienthe { gaming, toigian, hiendai};

class Item {
protected:
    loai Loai;
    string Ten;
    string Mau;
    int SL;
    double Gia;
public:
    friend class QuanLySanPham;
    virtual void XuatThongTin() = 0;
};