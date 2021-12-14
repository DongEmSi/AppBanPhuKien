#include "ManHinh.h"
#include "BanPhim.h"
#include "Chuot.h"
#include "GamingFactory.h"
#include "ToiGianFactory.h"
#include "HienDaiFactory.h"
#include <vector>
#include <fstream>

class QuanLySanPham {
private:
    GamingFactory gf;
    ToiGianFactory tf;
    HienDaiFactory hf;
    vector<ManHinh*> QuanLyManHinh;
    vector<BanPhim*> QuanLyBanPhim;
    vector<Chuot*> QuanLyChuot;

public:
    ~QuanLySanPham();
    void DocFile(const char* filename);
    void GhiFile(const char* filename);
    void TimSanPham();
};
