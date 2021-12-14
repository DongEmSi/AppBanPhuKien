#include "AbstractFactory.h"
#include "ChuotGaming.h"
#include "BanPhimGaming.h"
#include "ManHinhGaming.h"

class GamingFactory : public AbstractFactory {
public:
    BanPhim *CreateBanPhim(string loai, string bienthe, string ten, string mau, double gia, int sl) const {
        return new BanPhimGaming(loai, bienthe, ten, mau, gia, sl);
    }
    ManHinh *CreateManHinh(string loai, string bienthe, string ten, string mau, double gia, int sl) const {
        return new ManHinhGaming(loai, bienthe, ten, mau, gia, sl);
    }
    Chuot *CreateChuot(string loai, string bienthe, string ten, string mau, double gia, int sl) const {
        return new ChuotGaming(loai, bienthe, ten, mau, gia, sl);
    }
};