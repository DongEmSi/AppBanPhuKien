#pragma once
#include "Item.h"

class ManHinh : public Item {
protected:
    string BienThe;
public:
    void Xuat(ostream &os) {
        os << Loai << "," << BienThe << "," << Ten << "," << Mau << "," << Gia << "," << SL << endl;
    }
};
