#include "QuanLySanPham.h"

QuanLySanPham::~QuanLySanPham() {
    for (auto i : QuanLyManHinh)
        delete i;
    for (auto i : QuanLyBanPhim)
        delete i;
    for (auto i : QuanLyChuot)
        delete i;

    QuanLyManHinh.clear();
    QuanLyBanPhim.clear();
    QuanLyChuot.clear();
    ManHinh.clear();
    BanPhim.clear();
    Chuot.clear();
}

void QuanLySanPham::DocFile(const char* filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Cannot open file \"" << filename << "\"" << endl;
        return;
    }

    string temp;
    string loai, bienthe;
    string ten, mau;
    long gia;
    int sl;
    if (!inFile.eof()) {
        getline(inFile, temp, '|');
        getline(inFile, temp, '\n');
    }
    while (!inFile.eof()) {
        getline(inFile, loai, ',');
        getline(inFile, bienthe, ',');
        getline(inFile, ten, ',');
        getline(inFile, mau, ',');
        inFile >> gia;
        inFile.ignore();
        inFile >> sl;
        inFile.ignore();

        if (loai == "0") {
            if (bienthe == "0") {
                QuanLyBanPhim.push_back(gf.CreateBanPhim(banphim, gaming, ten, mau, gia, sl));
            }
            else if (bienthe == "1") {
                QuanLyBanPhim.push_back(tf.CreateBanPhim(banphim, toigian, ten, mau, gia, sl));
            }
            else if (bienthe == "2") {
                QuanLyBanPhim.push_back(hf.CreateBanPhim(banphim, hiendai, ten, mau, gia, sl));
            }
        }
        else if (loai == "1") {
            if (bienthe == "0") {
                QuanLyChuot.push_back(gf.CreateChuot(chuot, gaming, ten, mau, gia, sl));
            }
            else if (bienthe == "1") {
                QuanLyChuot.push_back(tf.CreateChuot(chuot, toigian, ten, mau, gia, sl));
            }
            else if (bienthe == "2") {
                QuanLyChuot.push_back(hf.CreateChuot(chuot, hiendai, ten, mau, gia, sl));
            }
        }
        else if (loai == "2") {
            if (bienthe == "0") {
                QuanLyManHinh.push_back(gf.CreateManHinh(manhinh, gaming, ten, mau, gia, sl));
            }
            else if (bienthe == "1") {
                QuanLyManHinh.push_back(tf.CreateManHinh(manhinh, toigian, ten, mau, gia, sl));
            }
            else if (bienthe == "2") {
                QuanLyManHinh.push_back(hf.CreateManHinh(manhinh, hiendai, ten, mau, gia, sl));
            }
        }
    }

    inFile.close();
}

void QuanLySanPham::GhiFile(const char* filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Cannot open the file.\n";
        return;
    }
    outFile << note;
    for (auto i : QuanLyBanPhim)
        i->Xuat(outFile);
    for (auto i : QuanLyChuot)
        i->Xuat(outFile);
    for (auto i : QuanLyManHinh)
        i->Xuat(outFile);

    outFile.close();
}

void QuanLySanPham::TimSanPhamTheoTen(string name) {
    bool found = 0;
    for (auto i : QuanLyManHinh) {
        if (i->Ten.find(name) != string::npos) {
            i->XuatThongTin();
            found = 1;
        }
    }
    for (auto i : QuanLyChuot) {
        if (i->Ten.find(name) != string::npos) {
            i->XuatThongTin();
            found = 1;
        }
    }
    for (auto i : QuanLyBanPhim) {
        if (i->Ten.find(name) != string::npos) {
            i->XuatThongTin();
            found = 1;
        }
    }
    if (found == 0) cout << "Khong tim thay san pham!\n";
}

void QuanLySanPham::TimSanPhamTheoBienThe(string bt) {
    bienthe temp;
    bool found = 0;
    if (bt == "gaming" || bt == "Gaming") temp = gaming;
    else if (bt == "ToiGian" || bt == "Toi Gian" || bt == "toi gian" || bt == "toigian" || bt == "Toi gian") temp = toigian;
    else if (bt == "HienDai" || bt == "Hien Dai" || bt == "hien dai" || bt == "hiendai" || bt == "Hien dai") temp = hiendai;
    else {
        cout << "Khong ton tai bien the!\n";
        return;
    }
    for (auto i : QuanLyBanPhim) {
        if (i->BienThe == temp) {
            i->XuatThongTin();
            found = 1;
        }
    }
    for (auto i : QuanLyManHinh) {
        if (i->BienThe == temp) {
            i->XuatThongTin();
            found = 1;
        }
    }
    for (auto i : QuanLyChuot) {
        if (i->BienThe == temp) {
            i->XuatThongTin();
            found = 1;
        }
    }
    if (found == 0) cout << "Khong tim thay san pham!\n";
}

void QuanLySanPham::TimSanPhamTheoLoai(string l) {
    loai temp;
    if (l == "banphim" || l == "Ban Phim" || l == "ban phim" || l == "BanPhim" || l == "Ban phim") {
        for (auto i : QuanLyBanPhim) {
            i->XuatThongTin();
        }
    }
    else if (l == "chuot" || l == "Chuot") {
        for (auto i : QuanLyChuot) {
            i->XuatThongTin();
        }
    }
    else if (l == "manhinh" || l == "ManHinh" || l == "man hinh" || l == "Man Hinh" || l == "Man hinh") {
        for (auto i : QuanLyManHinh) {
            i->XuatThongTin();
        }
    }
    else {
        cout << "Khong tim thay san pham!\n";
        return;
    }
}

void QuanLySanPham::StartCheck() {
    ManHinh.resize(QuanLyManHinh.size(), 0);
    BanPhim.resize(QuanLyBanPhim.size(), 0);
    Chuot.resize(QuanLyChuot.size(), 0);
}

Item* QuanLySanPham::RandomSanPham() {
    if (CheckAllFull() == true) return nullptr;
    int sp;
    bool avai = 0;
    while (avai == 0) {
        int ran = rand() % 3;
        switch (ran) {
        case 0:
            if (CheckLoaiFull(banphim) == true) break;
            avai = 1;
            sp = rand() % QuanLyBanPhim.size();
            while (BanPhim[sp] != 0)
                sp = rand() % QuanLyBanPhim.size();
            BanPhim[sp] = 1;
            return QuanLyBanPhim[sp];
            break;
        case 1:
            if (CheckLoaiFull(chuot) == true) break;
            avai = 1;
            sp = rand() % QuanLyChuot.size();
            while (Chuot[sp] != 0)
                sp = rand() % QuanLyChuot.size();
            Chuot[sp] = 1;
            return QuanLyChuot[sp];
            break;
        case 2:
            if (CheckLoaiFull(manhinh) == true) break;
            avai = 1;
            sp = rand() % QuanLyManHinh.size();
            while (ManHinh[sp] != 0)
                sp = rand() % QuanLyManHinh.size();
            ManHinh[sp] = 1;
            return QuanLyManHinh[sp];
            break;
        }
    }
}

Item* QuanLySanPham::RandomLoai(loai in) {
    if (CheckLoaiFull(in) == true) return nullptr;
    int sp;
    switch (in) {
    case 0:
        sp = rand() % QuanLyBanPhim.size();
        while (BanPhim[sp] != 0)
            sp = rand() % QuanLyBanPhim.size();
        BanPhim[sp] = 1;
        return QuanLyBanPhim[sp];
        break;
    case 1:
        sp = rand() % QuanLyChuot.size();
        while (Chuot[sp] != 0)
            sp = rand() % QuanLyChuot.size();
        Chuot[sp] = 1;
        return QuanLyChuot[sp];
        break;
    case 2:
        sp = rand() % QuanLyManHinh.size();
        while (ManHinh[sp] != 0)
            sp = rand() % QuanLyManHinh.size();
        ManHinh[sp] = 1;
        return QuanLyManHinh[sp];
        break;
    }
}

Item* QuanLySanPham::RandomBienThe(bienthe in) {
    if (CheckBientheFull(in) == true) return nullptr;
    int sp;
    bool avai = 0;
    while (avai == 0) {
        int ran = rand() % 3;
        switch (ran) {
        case 0:
            for (int i = 0; i < BanPhim.size(); i++) {
                if (QuanLyBanPhim[i]->BienThe == in && BanPhim[i] == 0)
                    avai = 1;
            }
            if (avai == 1) {
                sp = rand() % QuanLyBanPhim.size();
                while (BanPhim[sp] != 0 || QuanLyBanPhim[sp]->BienThe != in)
                    sp = rand() % QuanLyBanPhim.size();
                BanPhim[sp] = 1;
                return QuanLyBanPhim[sp];
                break;
            }
            break;
        case 1:
            for (int i = 0; i < Chuot.size(); i++) {
                if (QuanLyChuot[i]->BienThe == in && Chuot[i] == 0)
                    avai = 1;
            }
            if (avai == 1) {
                sp = rand() % QuanLyChuot.size();
                while (Chuot[sp] != 0 || QuanLyChuot[sp]->BienThe != in)
                    sp = rand() % QuanLyChuot.size();
                Chuot[sp] = 1;
                return QuanLyChuot[sp];
                break;
            }
            break;
        case 2:
            for (int i = 0; i < ManHinh.size(); i++) {
                if (QuanLyManHinh[i]->BienThe == in && ManHinh[i] == 0)
                    avai = 1;
            }
            if (avai == 1) {
                sp = rand() % QuanLyManHinh.size();
                while (ManHinh[sp] != 0 || QuanLyManHinh[sp]->BienThe != in)
                    sp = rand() % QuanLyManHinh.size();
                ManHinh[sp] = 1;
                return QuanLyManHinh[sp];
                break;
            }
            break;
        }
    }
}

void QuanLySanPham::ThemSanPham(Item* in) {
    VoHang.push_back(in);
}

void QuanLySanPham::GoiYSanPham(Item* in)
{
    GoiY.push_back(in);
}

void QuanLySanPham::XuatManHinhGoiY()
{
    for (auto e : GoiY)
        e->XuatThongTin();
}

void QuanLySanPham::ThanhToan() {
    long Tien = 0;
    for (auto i : VoHang) {
        i->XuatThongTin();
        Tien += i->Gia;
    }
    cout << "So tien phai thanh toan la: " << Tien << endl;
    VoHang.clear();
}

void QuanLySanPham::XuatManHinhGioHang()
{
    int sp = VoHang.size();
    gotoxy(50, 12); wcout << L"Tong san pham: " << utf8ToUtf16(to_string(sp));

    long Tien = 0;
    for (auto i : VoHang) {
        Tien += i->Gia;
    }
    string T = to_string(Tien);
    gotoxy(50, 13); wcout << L"Tong so tien: " << utf8ToUtf16(T);
    gotoxy(50, 14); wcout << L"San pham: ";

    int y = 15;
    for (int i = 0; i < VoHang.size(); i++)
    {
        VoHang[i]->XuatThongTinGio(y);
    }
}

Item* QuanLySanPham::RandomBienThevaLoai(loai in1, bienthe in2) 
{ //  neu khong co thi tra ve con tro null
    if (CheckLoaiFull(in1) == true)
        return nullptr;
    int sp;
    bool avai = 0;
    switch (in1) {
    case 0:
        for (auto i : QuanLyBanPhim) {
            if (i->BienThe == in2) avai = 1;
        }
        if (avai == 0) return nullptr;
        else if (avai == 1) {
            sp = rand() % QuanLyBanPhim.size();
            while (BanPhim[sp] != 0 || QuanLyBanPhim[sp]->BienThe != in2)
                sp = rand() % QuanLyBanPhim.size();
            BanPhim[sp] = 1;
            return QuanLyBanPhim[sp];
        }
        break;
    case 1:
        for (auto i : QuanLyChuot) {
            if (i->BienThe == in2) avai = 1;
        }
        if (avai == 0) return nullptr;
        else if (avai == 1) {
            sp = rand() % QuanLyChuot.size();
            while (Chuot[sp] != 0 || QuanLyChuot[sp]->BienThe != in2)
                sp = rand() % QuanLyChuot.size();
            Chuot[sp] = 1;
            return QuanLyChuot[sp];
        }
        break;
    case 2:
        for (auto i : QuanLyManHinh) {
            if (i->BienThe == in2) avai = 1;
        }
        if (avai == 0) return nullptr;
        else if (avai == 1) {
            sp = rand() % QuanLyManHinh.size();
            while (BanPhim[sp] != 0 || QuanLyManHinh[sp]->BienThe != in2)
                sp = rand() % QuanLyManHinh.size();
            ManHinh[sp] = 1;
            return QuanLyManHinh[sp];
        }
        break;
    }
}

bool QuanLySanPham::CheckAllFull() {
    for (auto i : BanPhim) {
        if (i == 0) return false;
    }
    for (auto i : ManHinh) {
        if (i == 0) return false;
    }
    for (auto i : Chuot) {
        if (i == 0) return false;
    }
    return true;
}

bool QuanLySanPham::CheckLoaiFull(loai in) {
    switch (in) {
    case 0:
        for (auto i : BanPhim) {
            if (i == 0) return false;
        }
        return true;
    case 1:
        for (auto i : Chuot) {
            if (i == 0) return false;
        }
        return true;
    case 2:
        for (auto i : ManHinh) {
            if (i == 0) return false;
        }
        return true;
    }
}

bool QuanLySanPham::CheckBientheFull(bienthe in) {
    for (int i = 0; i < BanPhim.size(); i++) {
        if (BanPhim[i] == 0 && QuanLyBanPhim[i]->BienThe == in)
            return false;
    }
    for (int i = 0; i < Chuot.size(); i++) {
        if (Chuot[i] == 0 && QuanLyChuot[i]->BienThe == in)
            return false;
    }
    for (int i = 0; i < ManHinh.size(); i++) {
        if (ManHinh[i] == 0 && QuanLyManHinh[i]->BienThe == in)
            return false;
    }
    return true;
}

void QuanLySanPham::ThemVaoMucTG(Item* in)
{
    MucToiGian.push_back(in);
}

void QuanLySanPham::ThemVaoMucGM(Item* in)
{
    MucGaming.push_back(in);
}

void QuanLySanPham::ThemVaoMucHD(Item* in)
{
    MucHD.push_back(in);
}

void QuanLySanPham::XuatManHinhMuc()
{
    int x = 13, y = 13, z = 13;

    for (int i = 0; i < MucGaming.size(); i++)
    {
        switch (MucGaming[i]->Loai)
        {
        case 0:
            gotoxy(15, x); wcout << L"Loai: Ban phim";
            break;
        case 1: 
            gotoxy(15, x); wcout << L"Loai: Chuot";
            break;
        case 2:
            gotoxy(15, x); wcout << L"Loai: Man hinh";
            break;
        }

        x++; gotoxy(15, x); wcout << L"Gia: " << MucGaming[i]->Gia;
        x++; gotoxy(15, x); wcout << L"Mau: " << utf8ToUtf16(MucGaming[i]->Mau);
        x += 2;
    }

    for (int i = 0; i < MucHD.size(); i++)
    {
        switch (MucHD[i]->Loai)
        {
        case 0:
            gotoxy(60, y); wcout << L"Loai: Ban phim";
            break;
        case 1:
            gotoxy(60, y); wcout << L"Loai: Chuot";
            break;
        case 2:
            gotoxy(60, y); wcout << L"Loai: Man hinh";
            break;
        }

        y++; gotoxy(60, y); wcout << L"Gia: " << MucHD[i]->Gia;
        y++; gotoxy(60, y); wcout << L"Mau: " << utf8ToUtf16(MucHD[i]->Mau);
        y += 2;
    }

    for (int i = 0; i < MucToiGian.size(); i++)
    {
        switch (MucToiGian[i]->Loai)
        {
        case 0:
            gotoxy(100, z); wcout << L"Loai: Ban phim";
            break;
        case 1:
            gotoxy(100, z); wcout << L"Loai: Chuot";
            break;
        case 2:
            gotoxy(100, z); wcout << L"Loai: Man hinh";
            break;
        }

        z++; gotoxy(100, z); wcout << L"Gia: " << MucToiGian[i]->Gia;
        z++; gotoxy(100, z); wcout << L"Mau: " << utf8ToUtf16(MucToiGian[i]->Mau);
        z += 2;
    }
}