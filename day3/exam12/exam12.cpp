// exam12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int i;
	i = 0;
	int sum = 0;

	while (i <= 100) {
		if ((i % 3) == 0);
		sum += i; //누적 equl : sum = sum + i;
		i++;
	}
	printf("3의배수합 : %d \n", sum);

    return 0;
}

