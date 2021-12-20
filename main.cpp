#include "QuanLySanPham.h"
#include "ManHinh.h"
#include "Chuot.h"
#include "BanPhim.h"
#include "Item.h"
#include "AbstractFactory.h"

int main() {
    srand(time(0));
    QuanLySanPham ql;

    ql.DocFile("ListSP.txt");
    ql.StartCheck();
    ql.ThemSanPham(ql.RandomSanPham());
    ql.ThemSanPham(ql.RandomSanPham());
    ql.ThemSanPham(ql.RandomSanPham());
    ql.ThanhToan();
    //ql.TimSanPhamTheoBienThe("toi gian");
    //ql.TimSanPhamTheoLoai("ban phim");
    //ql.TimSanPhamTheoTen("A00");
    ql.GhiFile("ListSP.txt");

    return 0;
}
