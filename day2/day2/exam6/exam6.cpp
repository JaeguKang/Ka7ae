// exam6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	double fuseElec;//사용량
	double fTotal;//총사용요금
	
	printf("전기사용량을 입력하세요 : ");
	scanf_s("%lf", &fuseElec);

	fTotal = 660+(fuseElec * 88.5);
	double fTax = fTotal * 0.09;

	printf("사용요금 : %lf \n", fTotal - fTax);
	

    return 0;
}

