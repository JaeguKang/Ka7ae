// exam01.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char _ch;

	printf_s("getchar 로 입력받기 : ");
	_ch = getchar();
	putchar(_ch);

	printf_s("getc 로 입력받기 : ");		//엔터를 안쳐도 입력받음.
	_ch = _getch(); 
	putchar(_ch); 

	printf_s("추가적인 스트림 처리");
	_ch = getchar();
	putchar(_ch);
	
	printf_s("\n");

    return 0;
}

