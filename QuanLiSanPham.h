#include "ManHinh.h"
#include "BanPhim.h"
#include "Chuot.h"
#include <vector>

class QuanLiQuanPham {
private:
    vector<ManHinh*> QuanLiManHinh;
    vector<BanPhim*> QuanLiBanPhim;
    vector<Chuot*> QuanLiChuot;

public:
    void DocFile(const char* filename) {
        ifstream inFile(filename);
        string Loai;
        while (!inFile.eof()) {
            inFile >> Loai;

            if (Loai == "ManHinh") {
                BanPhim* newBanPham = new 
            }
        }
    }
    void GhiFile(const char* filename);

}