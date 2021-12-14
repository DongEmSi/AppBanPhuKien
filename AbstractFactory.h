#pragma once
#include "BanPhim.h"
#include "ManHinh.h"
#include "Chuot.h"
#include <string>

class AbstractFactory {
public: 
    virtual BanPhim *CreateBanPhim(string loai, string bienthe, string ten, string mau, double gia, int sl) const = 0;
    virtual ManHinh *CreateManHinh(string loai, string bienthe, string ten, string mau, double gia, int sl) const = 0;
    virtual Chuot *CreateChuot(string loai, string bienthe, string ten, string mau, double gia, int sl) const = 0;
};