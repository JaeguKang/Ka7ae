// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char age;
	printf("나이를 입력하세요 : ");
	scanf_s("%d", &age);
	printf("당신의 10년 전 나이는 %d살입니다. \ㅜ", age - 10);

    return 0;

}

