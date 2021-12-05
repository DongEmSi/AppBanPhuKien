#include "AbstractFactory.h"

class ToiGianFactory : public AbstractFactory {
public:
    BanPhim *CreateBanPhim() const {
        return new BanPhimToiGian();
    }
    ManHinh *CreateManHinh() const {
        return new ManHinhToiGian();
    }
    Chuot *CreateChuot() const {
        return new ChuotToiGian();
    }
}