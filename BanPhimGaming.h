#include "BanPhim.h"

class BanPhimGaming : public BanPhim {
public:
    BanPhimGaming(loai Loai, bienthe BienThe, string Ten, string Mau, long Gia, int Sl) {
        this->Loai = Loai;
        this->BienThe = BienThe;
        this->Ten = Ten;
        this->Mau = Mau;
        this->Gia = Gia;
        this->SL = Sl;
    }

    void XuatThongTin() {
        int x = 0;
        wstring s = L"";
        if (Loai == 0)
        {
            x = 50;
            gotoxy(50, 13);
            s += L"Ban phim ";
        }
        else if (Loai == 1)
        {
            x = 10;
            gotoxy(10, 13);
            s += L"Chuot ";
        }
        else
        {
            x = 95;
            gotoxy(95, 13);
            s += L"Man hinh ";
        }
        if (BienThe == 0)
        {
            s += L"gaming";
            wcout << s;
        }
        else if (BienThe == 1)
        {
            s += L"toi gian";
            wcout << s;
        }
        else
        {
            s += L"hien dai";
            wcout << s;
        }
        gotoxy(x, 14); wcout << utf8ToUtf16(Ten) << endl;
        gotoxy(x, 15); wcout << L"Mau: " << utf8ToUtf16(Mau) << endl;
        gotoxy(x, 16); wcout << L"Gia: " << utf8ToUtf16(to_string(Gia)) << endl;
    }

    void XuatThongTinGio(int& y)
    {
        wstring s = L"";
        if (Loai == 0)
            s += L"Ban phim ";
        else if (Loai == 1)
            s += L"Chuot ";
        else
            s += L"Man hinh ";

        if (BienThe == 0)
            s += L"gaming.";
        else if (BienThe == 1)
            s += L"toi gian.";
        else
            s += L"hien dai.";

        y++;
        gotoxy(50, y); wcout << L"Ten san pham: " << s;
        y++;
        gotoxy(50, y); wcout << L"Ma san pham: " << utf8ToUtf16(Ten);
        y++;
        gotoxy(50, y); wcout << L"Mau san pham: " << utf8ToUtf16(Mau);
        y++;
    }
};