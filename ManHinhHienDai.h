#include "ManHinh.h"

class ManHinhHienDai : public ManHinh {
public:
    ManHinhHienDai(string Loai, string BienThe, string Ten, string Mau, double Gia, int Sl) {
        this->Loai = Loai;
        this->BienThe = BienThe;
        this->Ten = Ten;
        this->Mau = Mau;
        this->Gia = Gia;
        this->SL = Sl;
    }
};