#include "BanPhim.h"
#include "BanPhimGaming.h"
#include "BanPhimHienDai.h"
#include "BanPhimToiGian.h"
#include "ManHinh.h"
#include "ManHinhGaming.h"
#include "ManHinhHienDai.h"
#include "ManHinhToiGian.h"
#include "Chuot.h"
#include "ChuotGaming.h"
#include "ChuotHienDai.h"
#include "ChuotToiGian.h"

class AbstractFactory {
public: 
    virtual BanPhim *CreateBanPhim() const = 0;
    virtual ManHinh *CreateManHinh() const = 0;
    virtual Chuot *CreateChuot() const = 0;
}