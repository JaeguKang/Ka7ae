// exam14.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<Windows.h>

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csblnfo;
	WORD wOldColorAttr;

	GetConsoleScreenBufferInfo(hConsole, &csblnfo);

	wOldColorAttr = csblnfo.wAttributes;
	
	// 0000 0000 << 1 byte
	// 8421 8421
	// B.C	F.C		<background color, foreground color
	// iRGB	iRGB
	SetConsoleTextAttribute(hConsole, 0x1e);
	printf_s("Hello mother fxxker !							\n");
	
	SetConsoleTextAttribute(hConsole, 0x2d);
	printf_s("Hello mother fxxker !							\n");

	SetConsoleTextAttribute(hConsole, wOldColorAttr);

    return 0;
}

