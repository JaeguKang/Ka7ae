// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nHeight = 0;
	int nDays = 0;
	int nDepth;

	printf("우물의 깊이를 정해요.");
	scanf_s("%d", &nDepth);

	do {
		printf("%d 일째 %d cm 등반완료\n", nDays, nHeight);
		nHeight = nHeight + 55;
		nDays = nDays + 1;
	} while (nHeight < 300);

	nHeight = 0;
	while (nHeight<300) {
		printf("%d 일째 %d cm 등반완료 \n", nDays, nHeight);
		nDays = nDays + 1;
		nHeight = nHeight + 55;
	}
	printf("끝났습니다.");

    return 0;
}

