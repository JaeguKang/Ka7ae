// exam04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

																		//Exercise5-3
int main()
{
	int nKor, nEng, nMath;
	printf("국어 영어 수학 점수를 차례로 입력하세요. :");
	scanf_s("%d %d %d", &nKor, &nEng, &nMath);
	double everage = (nKor + nEng + nMath) / 3;
    
	//하핳ㅎㅎㅎㅎㅎㅎ
	printf(":----------:");
	printf("--------:--");
	printf("------:----");
	printf("----:------");
	printf("--:--------");
	printf("--:\n");

	printf(":   이름   :  국어  :  영어  :  수학  :  총점  :   평균   :\n");
	printf(":----------:");
	printf("--------:--");
	printf("------:----");
	printf("----:------");
	printf("--:--------");
	printf("--:\n");
	
	printf(":홍길동    :");
	printf("%8d:", nKor);
	printf("%8d:", nEng);
	printf("%8d:", nMath);
	printf("%8d:", nKor + nEng + nMath);
	printf("%10.2lf:\n", everage); //.2는 소숫점 2째자리까지 표현

	printf(":----------:");
	printf("--------:--");
	printf("------:----");
	printf("----:------");
	printf("--:--------");
	printf("--:\n");

	return 0;
}

