#include "AbstractFactory.h"
#include "BanPhimToiGian.h"
#include "ChuotToiGian.h"
#include "ManHinhToiGian.h"

class ToiGianFactory : public AbstractFactory {
public:
    BanPhim* CreateBanPhim(loai Loai, bienthe BienThe, string Ten, string Mau, long Gia, int Sl) const {
        return new BanPhimToiGian(Loai, BienThe, Ten, Mau, Gia, Sl);
    }
    ManHinh* CreateManHinh(loai Loai, bienthe BienThe, string Ten, string Mau, long Gia, int Sl) const {
        return new ManHinhToiGian(Loai, BienThe, Ten, Mau, Gia, Sl);
    }
    Chuot* CreateChuot(loai Loai, bienthe BienThe, string Ten, string Mau, long Gia, int Sl) const {
        return new ChuotToiGian(Loai, BienThe, Ten, Mau, Gia, Sl);
    }
};