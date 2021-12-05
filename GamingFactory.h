#include "AbstractFactory.h"

class GamingFactory : public AbstractFactory {
public:
    BanPhim *CreateBanPhim() const {
        return new BanPhimGaming();
    }
    ManHinh *CreateManHinh() const {
        return new ManHinhGaming();
    }
    Chuot *CreateChuot() const {
        return new ChuotGaming();
    }
}