#include "AbstractFactory.h"
#include "ChuotHienDai.h"
#include "BanPhimHienDai.h"
#include "ManHinhHienDai.h"

class HienDaiFactory : public AbstractFactory {
public:
    BanPhim *CreateBanPhim(loai Loai, bienthe BienThe, string Ten, string Mau, double Gia, int Sl) const {
        return new BanPhimHienDai(Loai, BienThe, Ten, Mau, Gia, Sl);
    }
    ManHinh *CreateManHinh(loai Loai, bienthe BienThe, string Ten, string Mau, double Gia, int Sl) const {
        return new ManHinhHienDai(Loai, BienThe, Ten, Mau, Gia, Sl);
    }
    Chuot *CreateChuot(loai Loai, bienthe BienThe, string Ten, string Mau, double Gia, int Sl) const {
        return new ChuotHienDai(Loai, BienThe, Ten, Mau, Gia, Sl);
    }
};