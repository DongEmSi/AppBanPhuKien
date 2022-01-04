#pragma once
#include "QuanLySanPham.h"
#include "ManHinh.h"
#include "Chuot.h"
#include "BanPhim.h"
#include "Item.h"
#include "AbstractFactory.h"

QuanLySanPham ql;
void menuThemVaoGio(QuanLySanPham& ql);
void gioHang(QuanLySanPham& ql);
void menuTheoMuc(QuanLySanPham& ql);

void menu()
{
	bool running = true;

	while (running)
	{
		HWND console = GetConsoleWindow();
		RECT ConsoleRect;
		GetWindowRect(console, &ConsoleRect);
		MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 500, TRUE);

		system("cls");
		int x = 40, y = 20;
		int check = 1;

		hidingCursor();
		printShop();

		Textcolor(9);
		gotoxy(40, 20); wcout << L"1. MUA SAM";
		Textcolor(7);
		gotoxy(40, 21); wcout << L"2. GIO HANG";
		gotoxy(40, 22); wcout << L"3. TIM THEO MUC";
		gotoxy(40, 23); wcout << L"4. THOAT UNG DUNG";
		gotoxy(40, 25); wcout << L"W-S DE DI CHUYEN";

		while (check)
		{
			if (_kbhit())
			{
				switch (_getch())
				{
				case 'w':
				{
					if (y > 20)
					{
						y--;
						gotoxy(x, y);
					}

					if (y == 20)
					{
						printShop();

						Textcolor(9);
						gotoxy(40, 20); wcout << L"1. MUA SAM";
						Textcolor(7);
						gotoxy(40, 21); wcout << L"2. GIO HANG";
						gotoxy(40, 22); wcout << L"3. TIM THEO MUC";
						gotoxy(40, 23); wcout << L"4. THOAT UNG DUNG";
						gotoxy(40, 25); wcout << L"W-S DE DI CHUYEN";
					}
					if (y == 21)
					{
						printShop();

						gotoxy(40, 20); wcout << L"1. MUA SAM";
						Textcolor(9);
						gotoxy(40, 21); wcout << L"2. GIO HANG";
						Textcolor(7);
						gotoxy(40, 22); wcout << L"3. TIM THEO MUC";
						gotoxy(40, 23); wcout << L"4. THOAT UNG DUNG";
						gotoxy(40, 25); wcout << L"W-S DE DI CHUYEN";
					}
					if (y == 22)
					{
						printShop();

						gotoxy(40, 20); wcout << L"1. MUA SAM";
						gotoxy(40, 21); wcout << L"2. GIO HANG";
						Textcolor(9);
						gotoxy(40, 22); wcout << L"3. TIM THEO MUC";
						Textcolor(7);
						gotoxy(40, 23); wcout << L"4. THOAT UNG DUNG";
						gotoxy(40, 25); wcout << L"W-S DE DI CHUYEN";
					}
					if (y == 23)
					{
						printShop();

						gotoxy(40, 20); wcout << L"1. MUA SAM";
						gotoxy(40, 21); wcout << L"2. GIO HANG";
						gotoxy(40, 22); wcout << L"3. TIM THEO MUC";
						Textcolor(9);
						gotoxy(40, 23); wcout << L"4. THOAT UNG DUNG";
						Textcolor(7);
						gotoxy(40, 25); wcout << L"W-S DE DI CHUYEN";
					}
					break;
				}
				case's':
				{
					if (y < 23)
					{
						y++;
						gotoxy(x, y);
					}

					if (y == 20)
					{
						printShop();

						Textcolor(9);
						gotoxy(40, 20); wcout << L"1. MUA SAM";
						Textcolor(7);
						gotoxy(40, 21); wcout << L"2. GIO HANG";
						gotoxy(40, 22); wcout << L"3. TIM THEO MUC";
						gotoxy(40, 23); wcout << L"4. THOAT UNG DUNG";
						gotoxy(40, 25); wcout << L"W-S DE DI CHUYEN";
					}

					if (y == 21)
					{
						printShop();

						gotoxy(40, 20); wcout << L"1. MUA SAM";
						Textcolor(9);
						gotoxy(40, 21); wcout << L"2. GIO HANG";
						Textcolor(7);
						gotoxy(40, 22); wcout << L"3. TIM THEO MUC";
						gotoxy(40, 23); wcout << L"4. THOAT UNG DUNG";
						gotoxy(40, 25); wcout << L"W-S DE DI CHUYEN";
					}

					if (y == 22)
					{
						printShop();

						gotoxy(40, 20); wcout << L"1. MUA SAM";
						gotoxy(40, 21); wcout << L"2. GIO HANG";
						Textcolor(9);
						gotoxy(40, 22); wcout << L"3. TIM THEO MUC";
						Textcolor(7);
						gotoxy(40, 23); wcout << L"4. THOAT UNG DUNG";
						gotoxy(40, 25); wcout << L"W-S DE DI CHUYEN";
					}

					if (y == 23)
					{
						printShop();

						gotoxy(40, 20); wcout << L"1. MUA SAM";
						gotoxy(40, 21); wcout << L"2. GIO HANG";
						gotoxy(40, 22); wcout << L"3. TIM THEO MUC";
						Textcolor(9);
						gotoxy(40, 23); wcout << L"4. THOAT UNG DUNG";
						Textcolor(7);
						gotoxy(40, 25); wcout << L"W-S DE DI CHUYEN";
					}

					break;
				}
				case 13:
				{
					if (y == 20)
					{
						menuThemVaoGio(ql);
					}

					if (y == 21)
					{
						gioHang(ql);
					}

					if (y == 22)
					{
						menuTheoMuc(ql);
					}

					if (y == 23)
					{
						exit(0);
					}

					break;
				}
				}
			}

		}
	}
}

void menuThemVaoGio(QuanLySanPham& ql)
{
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1500, 500, TRUE);
	system("cls");
	hidingCursor();
	printSanPham();
	srand(time(0));

	ql.DocFile("ListSP.txt");
	ql.StartCheck();
	ql.GoiYSanPham(ql.RandomLoai(chuot));
	ql.GoiYSanPham(ql.RandomLoai(banphim));
	ql.GoiYSanPham(ql.RandomLoai(manhinh));
	ql.XuatManHinhGoiY();

	Textcolor(9);
	gotoxy(10, 20); wcout << L"THEM VAO GIO";
	Textcolor(7);
	gotoxy(50, 20); wcout << L"THEM VAO GIO";
	gotoxy(90, 20); wcout << L"THEM VAO GIO";
	gotoxy(130, 20); wcout << L"TRANG KE";
	gotoxy(170, 20); wcout << L"ROI KHOI";
	gotoxy(50, 25); wcout << L"A-D DE DI CHUYEN";

	int x = 10, y = 20;
	int check = 1;

	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'd':
			{
				if (x < 170)
				{
					x += 40;
					gotoxy(x, y);
				}

				if (x == 10)
				{
					gotoxy(50, 23); wcout << L"                ";
					Textcolor(9);
					gotoxy(10, 20); wcout << L"THEM VAO GIO";
					Textcolor(7);
					gotoxy(50, 20); wcout << L"THEM VAO GIO";
					gotoxy(90, 20); wcout << L"THEM VAO GIO";
					gotoxy(130, 20); wcout << L"TRANG KE";
					gotoxy(170, 20); wcout << L"ROI KHOI";
					gotoxy(50, 25); wcout << L"A-D DE DI CHUYEN";
				}
				if (x == 50)
				{
					gotoxy(50, 23); wcout << L"                ";
					gotoxy(10, 20); wcout << L"THEM VAO GIO";
					Textcolor(9);
					gotoxy(50, 20); wcout << L"THEM VAO GIO";
					Textcolor(7);
					gotoxy(90, 20); wcout << L"THEM VAO GIO";
					gotoxy(130, 20); wcout << L"TRANG KE";
					gotoxy(170, 20); wcout << L"ROI KHOI";
					gotoxy(50, 25); wcout << L"A-D DE DI CHUYEN";
				}
				if (x == 90)
				{
					gotoxy(50, 23); wcout << L"                ";
					gotoxy(10, 20); wcout << L"THEM VAO GIO";
					gotoxy(50, 20); wcout << L"THEM VAO GIO";
					Textcolor(9);
					gotoxy(90, 20); wcout << L"THEM VAO GIO";
					Textcolor(7);
					gotoxy(130, 20); wcout << L"TRANG KE";
					gotoxy(170, 20); wcout << L"ROI KHOI";
					gotoxy(50, 25); wcout << L"A-D DE DI CHUYEN";
				}

				if (x == 130)
				{
					gotoxy(50, 23); wcout << L"                ";
					gotoxy(10, 20); wcout << L"THEM VAO GIO";
					gotoxy(50, 20); wcout << L"THEM VAO GIO";
					gotoxy(90, 20); wcout << L"THEM VAO GIO";
					Textcolor(9);
					gotoxy(130, 20); wcout << L"TRANG KE";
					Textcolor(7);
					gotoxy(170, 20); wcout << L"ROI KHOI";
					gotoxy(50, 25); wcout << L"A-D DE DI CHUYEN";
				}
				if (x == 170)
				{
					gotoxy(50, 23); wcout << L"                ";
					gotoxy(10, 20); wcout << L"THEM VAO GIO";
					gotoxy(50, 20); wcout << L"THEM VAO GIO";
					gotoxy(90, 20); wcout << L"THEM VAO GIO";
					gotoxy(130, 20); wcout << L"TRANG KE";
					Textcolor(9);
					gotoxy(170, 20); wcout << L"ROI KHOI";
					Textcolor(7);
					gotoxy(50, 25); wcout << L"A-D DE DI CHUYEN";
				}
				break;
			}
			case'a':
			{
				if (x > 10)
				{
					x -= 40;
					gotoxy(x, y);
				}

				if (x == 10)
				{
					gotoxy(50, 23); wcout << L"                ";
					Textcolor(9);
					gotoxy(10, 20); wcout << L"THEM VAO GIO";
					Textcolor(7);
					gotoxy(50, 20); wcout << L"THEM VAO GIO";
					gotoxy(90, 20); wcout << L"THEM VAO GIO";
					gotoxy(130, 20); wcout << L"TRANG KE";
					gotoxy(170, 20); wcout << L"ROI KHOI";
					gotoxy(50, 25); wcout << L"A-D DE DI CHUYEN";
				}
				if (x == 50)
				{
					gotoxy(50, 23); wcout << L"                ";
					gotoxy(10, 20); wcout << L"THEM VAO GIO";
					Textcolor(9);
					gotoxy(50, 20); wcout << L"THEM VAO GIO";
					Textcolor(7);
					gotoxy(90, 20); wcout << L"THEM VAO GIO";
					gotoxy(130, 20); wcout << L"TRANG KE";
					gotoxy(170, 20); wcout << L"ROI KHOI";
					gotoxy(50, 25); wcout << L"A-D DE DI CHUYEN";
				}
				if (x == 90)
				{
					gotoxy(50, 23); wcout << L"                ";
					gotoxy(10, 20); wcout << L"THEM VAO GIO";
					gotoxy(50, 20); wcout << L"THEM VAO GIO";
					Textcolor(9);
					gotoxy(90, 20); wcout << L"THEM VAO GIO";
					Textcolor(7);
					gotoxy(130, 20); wcout << L"TRANG KE";
					gotoxy(170, 20); wcout << L"ROI KHOI";
					gotoxy(50, 25); wcout << L"A-D DE DI CHUYEN";
				}
				if (x == 130)
				{
					gotoxy(50, 23); wcout << L"                ";
					gotoxy(10, 20); wcout << L"THEM VAO GIO";
					gotoxy(50, 20); wcout << L"THEM VAO GIO";
					gotoxy(90, 20); wcout << L"THEM VAO GIO";
					Textcolor(9);
					gotoxy(130, 20); wcout << L"TRANG KE";
					Textcolor(7);
					gotoxy(170, 20); wcout << L"ROI KHOI";
					gotoxy(50, 25); wcout << L"A-D DE DI CHUYEN";
				}
				if (x == 170)
				{
					gotoxy(50, 23); wcout << L"                ";
					gotoxy(10, 20); wcout << L"THEM VAO GIO";
					gotoxy(50, 20); wcout << L"THEM VAO GIO";
					gotoxy(90, 20); wcout << L"THEM VAO GIO";
					gotoxy(130, 20); wcout << L"TRANG KE";
					Textcolor(9);
					gotoxy(170, 20); wcout << L"ROI KHOI";
					Textcolor(7);
					gotoxy(50, 25); wcout << L"A-D DE DI CHUYEN";
				}
				break;
			}

			case 13:
			{
				if (x == 10)
				{
					ql.ThemSanPham(ql.GoiY[0]);
					gotoxy(50, 23); wcout << L"Them thanh cong!";
				}

				if (x == 50)
				{
					ql.ThemSanPham(ql.GoiY[1]);
					gotoxy(50, 23); wcout << L"Them thanh cong!";
				}

				if (x == 90)
				{
					ql.ThemSanPham(ql.GoiY[2]);
					gotoxy(50, 23); wcout << L"Them thanh cong!";
				}
				if (x == 130)
				{
					ql.GoiY.clear();
			
					for (int i = 13; i <= 16; i++)
					{
						gotoxy(10, i); wcout << L"                       ";
						gotoxy(50, i); wcout << L"                       ";
						gotoxy(95, i); wcout << L"                       ";
					}
					ql.StartCheck();
					ql.GoiYSanPham(ql.RandomLoai(chuot));
					ql.GoiYSanPham(ql.RandomLoai(banphim));
					ql.GoiYSanPham(ql.RandomLoai(manhinh));
					ql.XuatManHinhGoiY();
				}
				if (x == 170)
				{
					menu();
				}
				break;
			}
			}
		}
	}
}

void gioHang(QuanLySanPham& ql)
{
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1000, 700, TRUE);
	system("cls");
	hidingCursor();

	printGioHang();
	ql.XuatManHinhGioHang(); // 30, 9
	Textcolor(9);
	gotoxy(40, 9); wcout << L"THANH TOAN";
	Textcolor(7);
	gotoxy(60, 9); wcout << L"TRO LAI";

	int x = 40, y = 9;

	while (true)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'd':
			{
				if (x < 60)
				{
					x += 20;
					gotoxy(x, y);
				}
				if (x == 40)
				{
					gotoxy(50, 10); wcout << L"                     ";
					Textcolor(9);
					gotoxy(40, 9); wcout << L"THANH TOAN";
					Textcolor(7);
					gotoxy(60, 9); wcout << L"TRO LAI";
				}
				if (x == 60)
				{
					gotoxy(50, 10); wcout << L"                     ";
					gotoxy(40, 9); wcout << L"THANH TOAN";
					Textcolor(9);
					gotoxy(60, 9); wcout << L"TRO LAI";
					Textcolor(7);
				}
				break;
			}
			case'a':
			{
				if (x > 40)
				{
					x -= 20;
					gotoxy(x, y);
				}
				if (x == 40)
				{
					gotoxy(50, 10); wcout << L"                     ";
					Textcolor(9);
					gotoxy(40, 9); wcout << L"THANH TOAN";
					Textcolor(7);
					gotoxy(60, 9); wcout << L"TRO LAI";
				}
				if (x == 60)
				{
					gotoxy(50, 10); wcout << L"                     ";
					gotoxy(40, 9); wcout << L"THANH TOAN";
					Textcolor(9);
					gotoxy(60, 9); wcout << L"TRO LAI";
					Textcolor(7);
				}
				break;
			}

			case 13:
			{
				if (x == 40)
				{
					for (auto e : ql.VoHang)
						e->GiamSL();
					ql.GhiFile("ListSP.txt");
					gotoxy(50, 10); wcout << L"THANH TOAN THANH CONG";
				}

				if (x == 60)
				{
					menu();
				}
				break;
			}
			}
		}
	}
}

void menuTheoMuc(QuanLySanPham& ql)
{
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1100, 700, TRUE);
	system("cls");
	hidingCursor();
	printLoaiSP();

	ql.DocFile("ListSP.txt");
	ql.StartCheck();
	ql.ThemVaoMucTG(ql.RandomBienThevaLoai(banphim, toigian));
	ql.ThemVaoMucTG(ql.RandomBienThevaLoai(chuot, toigian));
	ql.ThemVaoMucTG(ql.RandomBienThevaLoai(manhinh, toigian));
	ql.ThemVaoMucHD(ql.RandomBienThevaLoai(banphim, hiendai));
	ql.ThemVaoMucHD(ql.RandomBienThevaLoai(chuot, hiendai));
	ql.ThemVaoMucHD(ql.RandomBienThevaLoai(manhinh, hiendai));
	ql.ThemVaoMucGM(ql.RandomBienThevaLoai(banphim, gaming));
	ql.ThemVaoMucGM(ql.RandomBienThevaLoai(chuot, gaming));
	ql.ThemVaoMucGM(ql.RandomBienThevaLoai(manhinh, gaming));
	ql.XuatManHinhMuc();

	Textcolor(9);
	gotoxy(55, 30); wcout << L"1. MUA COMBO GAMING";
	Textcolor(7);
	gotoxy(55, 31); wcout << L"2. MUA COMBO HIEN DAI";
	gotoxy(55, 32); wcout << L"3. MUA COMBO TOI GIAN";
	gotoxy(55, 33); wcout << L"4. COMBO KHAC";
	gotoxy(55, 34); wcout << L"5. VE MAN HINH";
	gotoxy(55, 35); wcout << L"W-S DE DI CHUYEN";

	int x = 55, y = 30;
	while (true)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
			{
				if (y > 30)
				{
					y--;
					gotoxy(x, y);
				}

				if (y == 30)
				{
					printLoaiSP();
					gotoxy(55, 37); wcout << L"                   ";
					Textcolor(9);
					gotoxy(55, 30); wcout << L"1. MUA COMBO GAMING";
					Textcolor(7);
					gotoxy(55, 31); wcout << L"2. MUA COMBO HIEN DAI";
					gotoxy(55, 32); wcout << L"3. MUA COMBO TOI GIAN";
					gotoxy(55, 33); wcout << L"4. COMBO KHAC";
					gotoxy(55, 34); wcout << L"5. VE MAN HINH";
					gotoxy(55, 35); wcout << L"W-S DE DI CHUYEN";
				}
				if (y == 31)
				{
					printLoaiSP();
					gotoxy(55, 37); wcout << L"                   ";
					gotoxy(55, 30); wcout << L"1. MUA COMBO GAMING";
					Textcolor(9);
					gotoxy(55, 31); wcout << L"2. MUA COMBO HIEN DAI";
					Textcolor(7);
					gotoxy(55, 32); wcout << L"3. MUA COMBO TOI GIAN";
					gotoxy(55, 33); wcout << L"4. COMBO KHAC";
					gotoxy(55, 34); wcout << L"5. VE MAN HINH";
					gotoxy(55, 35); wcout << L"W-S DE DI CHUYEN";
				}
				if (y == 32)
				{
					printLoaiSP();
					gotoxy(55, 37); wcout << L"                   ";
					gotoxy(55, 30); wcout << L"1. MUA COMBO GAMING";
					gotoxy(55, 31); wcout << L"2. MUA COMBO HIEN DAI";
					Textcolor(9);
					gotoxy(55, 32); wcout << L"3. MUA COMBO TOI GIAN";
					Textcolor(7);
					gotoxy(55, 33); wcout << L"4. COMBO KHAC";
					gotoxy(55, 34); wcout << L"5. VE MAN HINH";
					gotoxy(55, 35); wcout << L"W-S DE DI CHUYEN";
				}
				if (y == 33)
				{
					printLoaiSP();
					gotoxy(55, 37); wcout << L"                   ";
					gotoxy(55, 30); wcout << L"1. MUA COMBO GAMING";
					gotoxy(55, 31); wcout << L"2. MUA COMBO HIEN DAI";
					gotoxy(55, 32); wcout << L"3. MUA COMBO TOI GIAN";
					Textcolor(9);
					gotoxy(55, 33); wcout << L"4. COMBO KHAC";
					Textcolor(7);
					gotoxy(55, 34); wcout << L"5. VE MAN HINH";
					gotoxy(55, 35); wcout << L"W-S DE DI CHUYEN";
				}
				if (y == 34)
				{
					printLoaiSP();
					gotoxy(55, 37); wcout << L"                   ";
					gotoxy(55, 30); wcout << L"1. MUA COMBO GAMING";
					gotoxy(55, 31); wcout << L"2. MUA COMBO HIEN DAI";
					gotoxy(55, 32); wcout << L"3. MUA COMBO TOI GIAN";
					gotoxy(55, 33); wcout << L"4. COMBO KHAC";
					Textcolor(9);
					gotoxy(55, 34); wcout << L"5. VE MAN HINH";
					Textcolor(7);
					gotoxy(55, 35); wcout << L"W-S DE DI CHUYEN";
				}
				break;
			}
			case's':
			{
				if (y < 35)
				{
					y++;
					gotoxy(x, y);
				}

				if (y == 30)
				{
					printLoaiSP();
					gotoxy(55, 37); wcout << L"                   ";
					Textcolor(9);
					gotoxy(55, 30); wcout << L"1. MUA COMBO GAMING";
					Textcolor(7);
					gotoxy(55, 31); wcout << L"2. MUA COMBO HIEN DAI";
					gotoxy(55, 32); wcout << L"3. MUA COMBO TOI GIAN";
					gotoxy(55, 33); wcout << L"4. COMBO KHAC";
					gotoxy(55, 34); wcout << L"5. VE MAN HINH";
					gotoxy(55, 35); wcout << L"W-S DE DI CHUYEN";
				}
				if (y == 31)
				{
					printLoaiSP();
					gotoxy(55, 37); wcout << L"                   ";
					gotoxy(55, 30); wcout << L"1. MUA COMBO GAMING";
					Textcolor(9);
					gotoxy(55, 31); wcout << L"2. MUA COMBO HIEN DAI";
					Textcolor(7);
					gotoxy(55, 32); wcout << L"3. MUA COMBO TOI GIAN";
					gotoxy(55, 33); wcout << L"4. COMBO KHAC";
					gotoxy(55, 34); wcout << L"5. VE MAN HINH";
					gotoxy(55, 35); wcout << L"W-S DE DI CHUYEN";
				}
				if (y == 32)
				{
					printLoaiSP();
					gotoxy(55, 37); wcout << L"                   ";
					gotoxy(55, 30); wcout << L"1. MUA COMBO GAMING";
					gotoxy(55, 31); wcout << L"2. MUA COMBO HIEN DAI";
					Textcolor(9);
					gotoxy(55, 32); wcout << L"3. MUA COMBO TOI GIAN";
					Textcolor(7);
					gotoxy(55, 33); wcout << L"4. COMBO KHAC";
					gotoxy(55, 34); wcout << L"5. VE MAN HINH";
					gotoxy(55, 35); wcout << L"W-S DE DI CHUYEN";
				}
				if (y == 33)
				{
					printLoaiSP();
					gotoxy(55, 37); wcout << L"                   ";
					gotoxy(55, 30); wcout << L"1. MUA COMBO GAMING";
					gotoxy(55, 31); wcout << L"2. MUA COMBO HIEN DAI";
					gotoxy(55, 32); wcout << L"3. MUA COMBO TOI GIAN";
					Textcolor(9);
					gotoxy(55, 33); wcout << L"4. COMBO KHAC";
					Textcolor(7);
					gotoxy(55, 34); wcout << L"5. VE MAN HINH";
					gotoxy(55, 35); wcout << L"W-S DE DI CHUYEN";
				}
				if (y == 34)
				{
					printLoaiSP();
					gotoxy(55, 37); wcout << L"                   ";
					gotoxy(55, 30); wcout << L"1. MUA COMBO GAMING";
					gotoxy(55, 31); wcout << L"2. MUA COMBO HIEN DAI";
					gotoxy(55, 32); wcout << L"3. MUA COMBO TOI GIAN";
					gotoxy(55, 33); wcout << L"4. COMBO KHAC";
					Textcolor(9);
					gotoxy(55, 34); wcout << L"5. VE MAN HINH";
					Textcolor(7);
					gotoxy(55, 35); wcout << L"W-S DE DI CHUYEN";
				}
				break;
			}
			case 13:
			{
				if (y == 30)
				{	
					for (int i = 0; i < 3; i++)
						ql.ThemSanPham(ql.MucGaming[i]);
					gotoxy(55, 37); wcout << L"Them thanh cong!";
				}
				if (y == 31)
				{
					for (int i = 0; i < 3; i++)
						ql.ThemSanPham(ql.MucHD[i]);
					gotoxy(55, 37); wcout << L"Them thanh cong!";
				}
				if (y == 32)
				{
					for (int i = 0; i < 3; i++)
						ql.ThemSanPham(ql.MucToiGian[i]);
					gotoxy(55, 37); wcout << L"Them thanh cong!";
				}
				if (y == 33)
				{
					ql.MucGaming.clear();
					ql.MucToiGian.clear();
					ql.MucHD.clear();

					for (int i = 13; i <= 23; i++)
					{
						gotoxy(15, i); wcout << L"                  ";
						gotoxy(60, i); wcout << L"                  ";
						gotoxy(100, i); wcout << L"                 ";
					}

					ql.StartCheck();
					ql.ThemVaoMucTG(ql.RandomBienThevaLoai(banphim, toigian));
					ql.ThemVaoMucTG(ql.RandomBienThevaLoai(chuot, toigian));
					ql.ThemVaoMucTG(ql.RandomBienThevaLoai(manhinh, toigian));
					
					ql.ThemVaoMucHD(ql.RandomBienThevaLoai(banphim, hiendai));
					ql.ThemVaoMucHD(ql.RandomBienThevaLoai(chuot, hiendai));
					ql.ThemVaoMucHD(ql.RandomBienThevaLoai(manhinh, hiendai));

					ql.ThemVaoMucGM(ql.RandomBienThevaLoai(banphim, gaming));
					ql.ThemVaoMucGM(ql.RandomBienThevaLoai(chuot, gaming));
					ql.ThemVaoMucGM(ql.RandomBienThevaLoai(manhinh, gaming));
					ql.XuatManHinhMuc();

				}
				if (y == 34)
				{
					system("cls");
					menu();
				}
				break;
			}
			}
		}

	}
}
