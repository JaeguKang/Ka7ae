// exam03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

struct score
{
	const char *pName;
	int kor, eng, mat;
};

int main()
{
	score a;
	score *pA = &a;
	printf_s("%8d %8d \n", sizeof(a), sizeof(pA));

	pA->pName = "Amugae";	//(*pA).pName = "아무개";
	pA->kor = 20;
	pA->eng = 30;
	pA->mat = 50;
	printf_s("%s \n", pA->pName);

    return 0;
}

