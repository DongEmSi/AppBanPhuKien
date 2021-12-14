#include "AbstractFactory.h"
#include "BanPhimToiGian.h"
#include "ChuotToiGian.h"
#include "ManHinhToiGian.h"

class ToiGianFactory : public AbstractFactory {
public:
    BanPhim *CreateBanPhim(string loai, string bienthe, string ten, string mau, double gia, int sl) const {
        return new BanPhimToiGian(loai, bienthe, ten, mau, gia, sl);
    }
    ManHinh *CreateManHinh(string loai, string bienthe, string ten, string mau, double gia, int sl) const {
        return new ManHinhToiGian(loai, bienthe, ten, mau, gia, sl);
    }
    Chuot *CreateChuot(string loai, string bienthe, string ten, string mau, double gia, int sl) const {
        return new ChuotToiGian(loai, bienthe, ten, mau, gia, sl);
    }
};