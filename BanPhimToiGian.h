#include "BanPhim.h"

class BanPhimToiGian : public BanPhim {
public:
    BanPhimToiGian(string Loai, string BienThe, string Ten, string Mau, double Gia, int Sl) {
        this->Loai = Loai;
        this->BienThe = BienThe;
        this->Ten = Ten;
        this->Mau = Mau;
        this->Gia = Gia;
        this->SL = Sl;
    }
};