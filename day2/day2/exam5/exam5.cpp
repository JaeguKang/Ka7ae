// exam5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int money;//급여
	int bonus;//보너스

	printf("본봉과 보너스를 입력하세요 :");
	scanf_s("%d %d", &money, &bonus);

	int all = money + bonus;//총급여
	int tax = all * 0.09;//세금

	printf("%lf %d \n", all * 0.09, tax);

	printf("실지급액 : %d 만원\n", all - tax);
	

    return 0;
}

