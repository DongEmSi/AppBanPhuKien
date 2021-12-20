#pragma once
#include "BanPhim.h"
#include "ManHinh.h"
#include "Chuot.h"
#include <string>

class AbstractFactory {
public: 
    virtual BanPhim *CreateBanPhim(loai Loai, bienthe BienThe, string Ten, string Mau, double Gia, int Sl) const = 0;
    virtual ManHinh *CreateManHinh(loai Loai, bienthe BienThe, string Ten, string Mau, double Gia, int Sl) const = 0;
    virtual Chuot *CreateChuot(loai Loai, bienthe BienThe, string Ten, string Mau, double Gia, int Sl) const = 0;
};