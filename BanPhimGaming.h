#include "BanPhim.h"

class BanPhimGaming : public BanPhim {
public:
    BanPhimGaming(loai Loai, bienthe BienThe, string Ten, string Mau, double Gia, int Sl) {
        this->Loai = Loai;
        this->BienThe = BienThe;
        this->Ten = Ten;
        this->Mau = Mau;
        this->Gia = Gia;
        this->SL = Sl;
    }
    void XuatThongTin() {
        if (Loai == 0) cout << "Ban phim ";
        else if (Loai == 1) cout << "Chuot ";
        else cout << "Man hinh";
        if (BienThe == 0) cout << "gaming ";
        else if (BienThe == 1) cout << "toi gian ";
        else cout << "hien dai ";
        cout << Ten << endl;
        cout << "Mau: " << Mau << endl;
        cout << "Gia: " << Gia << endl;
    }
};