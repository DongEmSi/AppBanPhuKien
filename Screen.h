#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <algorithm>
#include <codecvt>
using namespace std;

// Design Console
void fontsize(int a, int b);
void gotoxy(int x, int y);
void setcursor(bool visible, DWORD size);
void hidingCursor();
void Textcolor(int color);
void printShop();
void printSanPham();
void printGioHang();
void printLoaiSP();
wstring utf8ToUtf16(const string& utf8Str);
