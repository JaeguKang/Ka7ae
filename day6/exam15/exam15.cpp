// exam15.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int a;
	char szbuf[64];
	scanf_s("%d", &a);
	scanf_s("%s", szbuf, 64);

	printf_s("%d %s \n", a, szbuf);

    return 0;
}

