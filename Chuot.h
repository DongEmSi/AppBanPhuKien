#pragma once
#include "Item.h"

class Chuot : public Item {
protected:
    bienthe BienThe;
public:
    void Xuat(ostream &os) {
        os << Loai << "," << BienThe << "," << Ten << "," << Mau << "," << Gia << "," << SL << endl;
    }
    void XuatThongTin() {
        if (Loai == 0) cout << "Ban phim ";
        else if (Loai == 1) cout << "Chuot ";
        else cout << "Man hinh";
        if (BienThe == 0) cout << "gaming ";
        else if (BienThe == 1) cout << "toi gian ";
        else cout << "hien dai ";
        cout << Ten << endl;
        cout << "Mau: " << Mau << endl;
        cout << "Gia: " << Gia << endl;
    }
    friend class QuanLySanPham;
};
