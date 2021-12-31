#include "Screen.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void fontsize(int a, int b)
{
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(console, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(console, 0, lpConsoleCurrentFontEx);
}

void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size)
{
	if (size == 0)
		size = 20;

	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

void hidingCursor()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void Textcolor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}

void printShop()
{
	Textcolor(6);
	gotoxy(10, 5);  wcout << L" ::::::::";
	gotoxy(10, 6);  wcout << L":+:    :+:";
	gotoxy(10, 7);  wcout << L"+:+";
	gotoxy(10, 8);  wcout << L"+#++:++#++";
	gotoxy(10, 9);  wcout << L"       +#+";
	gotoxy(10, 10); wcout << L"#+#    #+#";
	gotoxy(10, 11); wcout << L" ######## ";

	gotoxy(25, 5);  wcout << L":::    :::";
	gotoxy(25, 6);  wcout << L":+:    :+:";
	gotoxy(25, 7);  wcout << L"+:+    +:+";
	gotoxy(25, 8);  wcout << L"+#++:++#++";
	gotoxy(25, 9);  wcout << L"+#+    +#+";
	gotoxy(25, 10); wcout << L"#+#    #+#";
	gotoxy(25, 11); wcout << L"###    ###";

	gotoxy(40, 5);  wcout << L" :::::::: ";
	gotoxy(40, 6);  wcout << L":+:    :+:";
	gotoxy(40, 7);  wcout << L"+:+    +:+";
	gotoxy(40, 8);  wcout << L"+#+    +:+";
	gotoxy(40, 9);  wcout << L"+#+    +:+";
	gotoxy(40, 10); wcout << L"#+#    #+#";
	gotoxy(40, 11); wcout << L" ######## ";

	gotoxy(55, 5);  wcout << L"::::::::: ";
	gotoxy(55, 6);  wcout << L":+:    :+:";
	gotoxy(55, 7);  wcout << L"+:+    +:+";
	gotoxy(55, 8);  wcout << L"+#++:++#+ ";
	gotoxy(55, 9);  wcout << L"+#+";
	gotoxy(55, 10); wcout << L"#+#";
	gotoxy(55, 11); wcout << L"###";

	gotoxy(70, 5);  wcout << L"	   :::    ";
	gotoxy(70, 6);  wcout << L"  :+: :+:  ";
	gotoxy(70, 7);  wcout << L" +:+   +:+";
	gotoxy(70, 8);  wcout << L"+#++:++#++:";
	gotoxy(70, 9);  wcout << L"+#+     +#+";
	gotoxy(70, 10); wcout << L"#+#     #+#";
	gotoxy(70, 11); wcout << L"###     ###";
	Textcolor(15);
}

void printSanPham()
{
	Textcolor(3);
	gotoxy(40, 2);  wcout << "___   _   _  _   ___ _  _   _   __  __ ";
	gotoxy(40, 3); wcout << "/ __| /_\\ | \\| | | _ \\ || | /_\\ |  \\/  |";
	gotoxy(40, 4); wcout << "\\__ \\/ _ \\| .` | |  _/ __ |/ _ \\| |\\/| |";
	gotoxy(40, 5); wcout << "|___/_/ \\_\\_|\\_| |_| |_||_/_/ \\_\\_|  |_|";
	Textcolor(15);

	gotoxy(15, 7); wcout << "	 ,.";
	gotoxy(15, 8); wcout << " __.'_";
	gotoxy(15, 9); wcout << "|__|__|";
	gotoxy(15, 10); wcout << "|     |";
	gotoxy(15, 11); wcout << "|-___-|";
	gotoxy(15, 12); wcout << "'.___.'";

	gotoxy(50, 8); wcout << "|----------------|";
	gotoxy(50, 9); wcout << "|[][][][][][][][]|";
	gotoxy(50, 10); wcout << "|[][][][][][][][]|";
	gotoxy(50, 11); wcout << "|[][]______[][][]|";
	gotoxy(50, 12); wcout << "|----------------|";

	gotoxy(95, 7); wcout << ".---------.";
	gotoxy(95, 8); wcout << "|.-\"\"\"\"\"-.|";
	gotoxy(95, 9); wcout << "||       ||";
	gotoxy(95, 10); wcout << "||       ||";
	gotoxy(95, 11); wcout << "|'-.....-'|";
	gotoxy(95, 12); wcout << "`\"\")---(\"\"\"";
}

void printGioHang()
{
	Textcolor(3);                                         
	gotoxy(30, 2);  wcout << " _______ ___ _______     ___ ___ _______ ______  _______";
	gotoxy(30, 3);  wcout << "|   _   |   |   _   |   |   Y   |   _   |   _  \\|   _   |";
	gotoxy(30, 4);	wcout << "|.  |___|.  |.  |   |   |.  1   |.  1   |.  |   |.  |___|";
	gotoxy(30, 5);  wcout << "|.  |   |.  |.  |   |   |.  _   |.  _   |.  |   |.  |   |";
	gotoxy(30, 6);  wcout << "|:  1   |:  |:  1   |   |:  |   |:  |   |:  |   |:  1   |";
	gotoxy(30, 7);  wcout << "|::.. . |::.|::.. . |   |::.|:. |::.|:. |::.|   |::.. . |";
	gotoxy(30, 8);  wcout << "`-------`---`-------'   `--- ---`--- ---`--- ---`-------'";
}

void printLoaiSP()
{
	Textcolor(4);
	gotoxy(30, 2);  wcout << " _     ___    _    ___   ____    _    _   _   ____  _   _    _    __  __";
	gotoxy(30, 3);  wcout << "| |   / _ \\  / \\  |_ _| / ___|  / \\  | \\ | | |  _ \\| | | |  / \\  |  \\/  |";
	gotoxy(30, 4);  wcout << "| |  | | | |/ _ \\  | |  \\___ \\ / _ \\ |  \\| | | |_) | |_| | / _ \ | |\\/| |";
	gotoxy(30, 5);  wcout << "| |__| |_| / ___ \\ | |   ___) / ___ \\| |\\  | |  __/|  _  |/ ___ \\| |  | |";
	gotoxy(30, 6);  wcout << "|_____\\___/_/   \\_|___| |____/_/   \\_|_| \\_| |_|   |_| |_/_/   \\_|_|  |_|";

	Textcolor(5);
	gotoxy(15, 9); wcout << " __   __  _    _ _    __ ";
	gotoxy(15, 10); wcout << "/ /`_/ /\\| |\\/| | |\\ / /`_";
	gotoxy(15, 11); wcout << "\\_\\_/_/--|_|  |_|_| \\\\_\\_/ ";

	Textcolor(6);
	gotoxy(60, 9); wcout << "|\\/|  _   _|  _  ._ ._ ";
	gotoxy(60, 10); wcout << "|  | (_) (_| (/_ |  | | ";
	gotoxy(60, 11); wcout << "|  | -------------------";

	Textcolor(7);
	gotoxy(100, 9); wcout << "~|~ _ _ _  _|  |_ | _";
	gotoxy(100, 10); wcout << "_|_| | (/_(_|_(|_)|(/_";
	gotoxy(100, 11); wcout << "_______________________";
	Textcolor(15);
}

wstring utf8ToUtf16(const string& utf8Str)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
	return conv.from_bytes(utf8Str);
}
