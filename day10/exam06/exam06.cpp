// exam06.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int a, b;
	scanf_s("%d %d", &a, &b);

	(a > b) ? printf_s("a가 커요 \n") : printf_s("b가 커요 \n");

	printf_s("%d %d \n", 5 + 7 * 9, (5 + 7) * 9);

    return 0;
}

