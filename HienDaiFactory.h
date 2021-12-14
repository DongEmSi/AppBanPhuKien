#include "AbstractFactory.h"
#include "ChuotHienDai.h"
#include "BanPhimHienDai.h"
#include "ManHinhHienDai.h"

class HienDaiFactory : public AbstractFactory {
public:
    BanPhim *CreateBanPhim(string loai, string bienthe, string ten, string mau, double gia, int sl) const {
        return new BanPhimHienDai(loai, bienthe, ten, mau, gia, sl);
    }
    ManHinh *CreateManHinh(string loai, string bienthe, string ten, string mau, double gia, int sl) const {
        return new ManHinhHienDai(loai, bienthe, ten, mau, gia, sl);
    }
    Chuot *CreateChuot(string loai, string bienthe, string ten, string mau, double gia, int sl) const {
        return new ChuotHienDai(loai, bienthe, ten, mau, gia, sl);
    }
};