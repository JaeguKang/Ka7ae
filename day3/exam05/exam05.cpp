// exam05.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int a, b;
	scanf_s("%d,%d", &a, &b); //구분값안줘도 공백으로됨 . 구분값을 주면 꼭 그 구분값을 넣어야됨
	printf("입력값 : %d,%d \n", a, b);

    return 0;
}

