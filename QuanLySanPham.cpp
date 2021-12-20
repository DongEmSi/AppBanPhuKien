#include "QuanLySanPham.h"

QuanLySanPham::~QuanLySanPham() {
    for(auto i : QuanLyManHinh) 
        delete i;
    for(auto i : QuanLyBanPhim) 
        delete i;
    for(auto i : QuanLyChuot) 
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
    double gia;
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
    if(found == 0) cout << "Khong tim thay san pham!\n";
}

void QuanLySanPham::TimSanPhamTheoBienThe(string bt) {
    bienthe temp;
    bool found = 0;
    if (bt == "gaming" || bt == "Gaming") temp = gaming;
    else if (bt == "ToiGian" || bt == "Toi Gian" || bt== "toi gian" || bt == "toigian" || bt == "Toi gian") temp = toigian;
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
    int ran = rand() % 3;
    int sp;
    switch (ran) {
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

Item* QuanLySanPham::RandomLoai(loai in) {
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

void QuanLySanPham::ThanhToan() {
    double Tien = 0;
    for (auto i : VoHang) {
        i->XuatThongTin();
        Tien += i->Gia;
    }
    cout << "So tien phai thanh toan la: " << Tien << endl;
    VoHang.clear();
}


