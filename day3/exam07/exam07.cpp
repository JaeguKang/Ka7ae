// exam07.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

																//Exercise 6-2
int main()
{
	int nAge;
	printf("나이를 입력하세요!");
	scanf_s("%d", &nAge);

	if (nAge <= 6 || nAge >= 70) {								//&&(and), ||(or), !(not) <<논리연산자!!!
		printf("무료입장입니다~~\n");
	}
	else {
		printf("입장료는 3만원입니다.\n");
	}
																//ctr+spc=자동완성!
    return 0;
}

