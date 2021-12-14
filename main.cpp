#include "QuanLySanPham.h"
#include "ManHinh.h"
#include "Chuot.h"
#include "BanPhim.h"
#include "Item.h"
#include "AbstractFactory.h"

int main() {
    QuanLySanPham ql;

    ql.DocFile("ListSP.txt");

    ql.GhiFile("output.txt");

    return 0;
}
