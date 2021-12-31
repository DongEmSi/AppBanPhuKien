#include "AbstractFactory.h"
#include "ChuotGaming.h"
#include "BanPhimGaming.h"
#include "ManHinhGaming.h"

class GamingFactory : public AbstractFactory {
public:
    BanPhim* CreateBanPhim(loai Loai, bienthe BienThe, string Ten, string Mau, long Gia, int Sl) const {
        return new BanPhimGaming(Loai, BienThe, Ten, Mau, Gia, Sl);
    }
    ManHinh* CreateManHinh(loai Loai, bienthe BienThe, string Ten, string Mau, long Gia, int Sl) const {
        return new ManHinhGaming(Loai, BienThe, Ten, Mau, Gia, Sl);
    }
    Chuot* CreateChuot(loai Loai, bienthe BienThe, string Ten, string Mau, long Gia, int Sl) const {
        return new ChuotGaming(Loai, BienThe, Ten, Mau, Gia, Sl);
    }
};