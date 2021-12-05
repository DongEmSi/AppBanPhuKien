#include "AbstractFactory.h"

class HienDaiFactory : public AbstractFactory {
public:
    BanPhim *CreateBanPhim() const {
        return new BanPhimHienDai();
    }
    ManHinh *CreateManHinh() const {
        return new ManHinhHienDai();
    }
    Chuot *CreateChuot() const {
        return new ChuotHienDai();
    }
}