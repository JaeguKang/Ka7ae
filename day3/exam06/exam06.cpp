// exam06.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

													//P.170 . P.172 논리연산자!
int main()
{
	printf("%d \n", 10 > 20);
	printf("%d \n", 10 < 20); // 참은 1 거짓은 0

	printf("=====================================\n");
	int A;
	printf("정수를 입력하세요.");
	scanf_s("%d", &A);
	if (A < 0) {
		A = A * -1;
	}															//if문법 (줄맞추기 등등) P.174~~
		printf("absolute => %d \n", A);
	
    return 0;
}

//if 참이면 다음문장 거짓이면 다음문장 건너뜀