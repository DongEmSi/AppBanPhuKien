#include "BanPhim.h"

class BanPhimGaming : public BanPhim {
public:
    BanPhimGaming(string Loai, string BienThe, string Ten, string Mau, double Gia, int Sl) {
        this->Loai = Loai;
        this->BienThe = BienThe;
        this->Ten = Ten;
        this->Mau = Mau;
        this->Gia = Gia;
        this->SL = Sl;
    }
};