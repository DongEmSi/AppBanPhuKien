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
}
void QuanLySanPham::DocFile(const char* filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Cannot open file \"" << filename << "\"" << endl;
        return;
    }

    string loai, bienthe;
    string ten, mau;
    double gia;
    int sl;

    while (!inFile.eof()) {
        getline(inFile, loai, ',');
        getline(inFile, bienthe, ',');
        getline(inFile, ten, ',');
        getline(inFile, mau, ',');
        inFile >> gia;
        inFile.ignore();
        inFile >> sl;
        inFile.ignore();

        if (loai == "Man hinh") {
            if (bienthe == "Gaming") {
                QuanLyManHinh.push_back(gf.CreateManHinh(loai, bienthe, ten, mau, gia, sl));
            }
            else if (bienthe == "Hien dai") {
                QuanLyManHinh.push_back(hf.CreateManHinh(loai, bienthe, ten, mau, gia, sl));
            }
            else if (bienthe == "Toi gian") {
                QuanLyManHinh.push_back(tf.CreateManHinh(loai, bienthe, ten, mau, gia, sl));
            }
        }
        else if (loai == "Ban phim") {
            if (bienthe == "Gaming") {
                QuanLyBanPhim.push_back(gf.CreateBanPhim(loai, bienthe, ten, mau, gia, sl));
            }
            else if (bienthe == "Hien dai") {
                QuanLyBanPhim.push_back(hf.CreateBanPhim(loai, bienthe, ten, mau, gia, sl));
            }
            else if (bienthe == "Toi gian") {
                QuanLyBanPhim.push_back(tf.CreateBanPhim(loai, bienthe, ten, mau, gia, sl));
            }
        }
        else if (loai == "Chuot") {
            if (bienthe == "Gaming") {
                QuanLyChuot.push_back(gf.CreateChuot(loai, bienthe, ten, mau, gia, sl));
            }
            else if (bienthe == "Hien dai") {
                QuanLyChuot.push_back(hf.CreateChuot(loai, bienthe, ten, mau, gia, sl));
            }
            else if (bienthe == "Toi gian") {
                QuanLyChuot.push_back(tf.CreateChuot(loai, bienthe, ten, mau, gia, sl));
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

    for (auto i : QuanLyBanPhim)
        i->Xuat(outFile);
    for (auto i : QuanLyChuot)
        i->Xuat(outFile);
    for (auto i : QuanLyManHinh)
        i->Xuat(outFile);

    outFile.close();
}
