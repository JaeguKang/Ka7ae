// exam01.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include"../../engine//tge.h"

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	TGE::setCursor(GetStdHandle(STD_OUTPUT_HANDLE), 0, 26);

	TGE::clearScreenBuffer(0x2c, 0x0007);

	TGE::drawLineH(7, 5, 15, 0x20, 0x00a0);
	TGE::drawLineV(14, 3, 10, 0x00, 0x00c0);
	
	TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	return 0;
}

