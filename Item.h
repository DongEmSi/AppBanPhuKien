#pragma once
#include <iostream>
#include <string>
#include "Screen.h"
using namespace std;

enum loai { banphim, chuot, manhinh };
enum bienthe { gaming, toigian, hiendai };

class Item {
protected:
    loai Loai;
    string Ten;
    string Mau;
    int SL;
    long Gia;
public:
    friend class QuanLySanPham;
    virtual void XuatThongTin() = 0;
    virtual void XuatThongTinGio(int& y) = 0;
    void GiamSL() { SL--; };
};