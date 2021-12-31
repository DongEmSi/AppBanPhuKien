#include "ManHinh.h"
#include "BanPhim.h"
#include "Chuot.h"
#include "GamingFactory.h"
#include "ToiGianFactory.h"
#include "HienDaiFactory.h"
#include <vector>
#include <fstream>
#include <time.h>

const string note = "Vui long khong xoa dong nay\n1, 2, 3, 4, 5 = loai, bien the, ten, mau, gia, so luong\n1 = { 0, 1, 2 } ~{ban phim, chuot, man hinh}\n2 = { 0, 1, 2 } ~{gaming, toi gian, hien dai}\nVui long khong xoa dong nay|\n";

class QuanLySanPham {
private:
    GamingFactory gf;
    ToiGianFactory tf;
    HienDaiFactory hf;
    vector<ManHinh*> QuanLyManHinh;
    vector<BanPhim*> QuanLyBanPhim;
    vector<Chuot*> QuanLyChuot;
    vector <bool> ManHinh;
    vector <bool> BanPhim;
    vector <bool> Chuot;
    bool CheckAllFull();
    bool CheckLoaiFull(loai in);
    bool CheckBientheFull(bienthe in);
public:
    ~QuanLySanPham();
    void StartCheck();
    void DocFile(const char* filename);
    void GhiFile(const char* filename);
    void TimSanPhamTheoTen(string name);
    void TimSanPhamTheoLoai(string loai);
    void TimSanPhamTheoBienThe(string bt);
    Item* RandomSanPham();
    Item* RandomLoai(loai in);
    Item* RandomBienThe(bienthe in);
    void ThemSanPham(Item* in);
    void ThemVaoMucTG(Item* in);
    void ThemVaoMucGM(Item* in);
    void ThemVaoMucHD(Item* in);
    vector <Item*> GoiY;
    vector <Item*> VoHang;
    vector <Item*> MucToiGian;
    vector <Item*> MucGaming;
    vector <Item*> MucHD;
    void GoiYSanPham(Item* in);
    void XuatManHinhGoiY();
    void XuatManHinhGioHang();
    void XuatManHinhMuc();
    Item* RandomBienThevaLoai(loai in1, bienthe in2);
    void ThanhToan();
};
